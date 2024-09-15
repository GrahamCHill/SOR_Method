#include <iostream>
#include <cmath>

int X_ROW = 3; // graph-points in x direction
int Y_ROW = 4; // graph-points in y direction
int MAX_ITER = 150;
int I_DIMENSIONS = X_ROW + 2; // accounting for edges
int J_DIMENSIONS = Y_ROW + 2; // accounting for edges

double OmegaOptimal(int p, int q);
double SOR(double omega, double point1, double point2
          , double point3, double point4, double point5);

int main() {
  double Sol_Array [J_DIMENSIONS][I_DIMENSIONS];
  for( int y = 0; y < J_DIMENSIONS; y++){
    for( int x = 0; x< I_DIMENSIONS; x++)
      Sol_Array[y][x] = 0;
  }
  // This is set up for this question, but can be modified to
  // solve other SOR questions
  // Starting from bottom left following outer edge
  Sol_Array[0][0] = 100; // 0,0
  Sol_Array[0][1] = 70; // 0,1
  Sol_Array[0][2] = 50; // 0,2
  Sol_Array[0][3] = 30; // 0,3
  Sol_Array[0][4] = 0; // 0,4
  Sol_Array[1][4] = 0; // 1,4
  Sol_Array[2][4] = 0; // 2,4
  Sol_Array[3][4] = 0; // 3,4
  Sol_Array[4][4] = 0; // 4,4
  Sol_Array[5][4] = 0; // 5,4
  Sol_Array[5][3] = 50; // 5,3
  Sol_Array [5][2] = 70; // 5,2
  Sol_Array[5][1] = 90; // 5,1
  Sol_Array[5][0] = 100; // 5,0
  Sol_Array[4][0] = 120; // 4,0
  Sol_Array[3][0] = 150; // 3,0
  Sol_Array [2][0] = 150; // 2,0
  Sol_Array[1][0] = 120; // 1,0
  double omega = OmegaOptimal(X_ROW + 1, Y_ROW + 1);
  std::cout << "ω = "<< omega << "\n--*--*--*--*--" << std::endl;
  
  for (int i = 0; i < MAX_ITER ; ++i) {
      for( int y = 1; y < J_DIMENSIONS - 1; y++){
        for( int x = 1; x< I_DIMENSIONS - 1; x++)
          Sol_Array [y][x] = SOR(omega,
              Sol_Array[y][x], // current grid-point
              Sol_Array[y][x+1], // u(i+1) x up
              Sol_Array[y][x-1], // u(i-1) x down
              Sol_Array[y+1][x], // u(j+1) y up
              Sol_Array[y-1][x]); // u(j-1) y down
      }
  }
  for( int y = 1; y < J_DIMENSIONS - 1; y++){
    std::cout << "Row: " << y << " | ";
    
  for( int x = 1; x< I_DIMENSIONS - 1; x++){
      std::cout <<
      Sol_Array[y][x] << "\t | \t";
    }
    std::cout << std::endl;
  }
}


double OmegaOptimal(int p, int q){
  double c = cos( M_PI / p ) + cos( M_PI / q );
  return ( 4 / ( 2 + sqrt( 4 - pow( c, 2 ))));
}

double SOR(double omega, double point1, double point2
          , double point3, double point4, double point5){
  double value, term1, term2;
  term1 = (( 1 - omega ) * point1);
  term2 = ( omega / 4 ) * ( point2 + point3 + point4 + point5);
  value = term1 + term2;
  return value;
}
