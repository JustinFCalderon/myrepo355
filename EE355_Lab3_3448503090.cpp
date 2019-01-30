#include <iostream>
#include <string>
#include <fstream>

class Pancake{
   public: 
      int Size;
      bool Burnt;          //Burnt = 1 means top side is burnt
      void flip_pancake(){
      Burnt = !Burnt;
      }
};

class PancakePile{
   public:
      int Z;
      Pancake pile[100];
      void pancake_burnt_down(){          //Make Burnt == 0
         for(int i = 0; i < Z; i++){
            if(pile[i].Burnt){
               pile[i].flip_pancake();
            }         
         } 
         
         /*Pancake temp;        
         while (current++ < Z){           
            if(pile[current].Burnt){
               
               for(int i = current; i < Z; i++){
                  if(!pile[Z-1].Burnt){
                     pile[Z-1].flip_pancake();
                  }
                  pile[current] = temp; 
                  pile[current] = pile[Z-1];
                  pile[Z-1] = temp; 
                  pile[current].flip_pancake();
                  pile[Z-1].flip_pancake();
               }
            }
         } */  
         
      }
      void pancake_burnt_up(){            //Make Burnt == 1
         for(int i = 0; i < Z; i++){
            if(!pile[i].Burnt){
               pile[i].flip_pancake();
            }         
         }
         
         /*Pancake temp;
         while (current++ < Z){
            if(!pile[current].Burnt){
               
               for(int i = current; i < Z; i++){
                  if(pile[Z-1].Burnt){
                     pile[Z-1].flip_pancake();
                  }
                  pile[current] = temp; 
                  pile[current] = pile[Z-1];
                  pile[Z-1] = temp; 
                  pile[current].flip_pancake();
                  pile[Z-1].flip_pancake();
               }
            }
         } */
         
      }   
};

class MPancakePiles{
   public:
      int X;
      int Y;
      PancakePile piles[100][100];
      void rearrange_exterior(){
         for(int i = 0; i < X; i++){
            if((i == 0)||(i == (X - 1))){
               for(int j = 0; j < Y; j++){
                  piles[i][j].pancake_burnt_up();
               }
            }
         }
         for(int i = 0; i < Y; i++){
            if((i == 0)||(i == (Y - 1))){
               for(int j = 0; j < X; j++){
                  piles[j][i].pancake_burnt_up();
               }
            }
         }
      }
      void rearrange_interior(){
         for(int i = 1; i < X; i++){
            if(!(i == (X - 1))){
               for(int j = 1; j < (Y - 1); j++){
                  piles[i][j].pancake_burnt_down();
               }
            }
         }
         for(int i = 1; i < Y; i++){
            if(!(i == (Y - 1))){
               for(int j = 1; j < (X - 1); j++){
                  piles[j][i].pancake_burnt_down();
               }
            }
         }
         
      }
};
using namespace std;
int main(){


Pancake pan;
PancakePile stack;
MPancakePiles mPiles;
int X,Y,Z;
char comma;    //accounts for comma character in input file

ifstream input;      // input file
input.open("input.txt");        
ofstream output;     //output file
output.open("output.txt");

input >> X; 
mPiles.X = X;
output << X << ' ';

input >> Y;
mPiles.Y = Y;
output << Y << ' ';

input >> Z;
stack.Z = Z;
output << Z << endl;

for(int x = 0; x < X; x++){         //Gets input from input.txt 
   for(int y = 0; y < Y; y++){
      for(int z = 0; z < Z; z++){
         input >> pan.Size;
         input >> comma;
         input >> pan.Burnt;
         stack.pile[z] = pan;
      }
   mPiles.piles[x][y] = stack; 
   }
}

input.close();

mPiles.rearrange_exterior();
mPiles.rearrange_interior();


for(int x = 0; x < X; x++){      //Writes to output file
   for(int y = 0; y < Y; y++){
      for(int z = 0; z < Z; z++){
         output << mPiles.piles[x][y].pile[z].Size << "," << mPiles.piles[x][y].pile[z].Burnt << " ";
      }
      output << endl;
   }
}

output.close();

return 0;
}





















