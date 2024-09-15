# S.O.R. Method
This is an example of the SOR method for a course called APM3711 at UNISA

## Question 
We have a plate of 12 × 15 cm and the temperatures on the edges are held as shown in the sketch below. Take ∆x = ∆y = 3 cm and use the S.O.R. method (successive overrelaxation method) to find the temperatures at all the grid points. First calculate the optimal value of ! and then use this value in the algorithm. Start with all grid values equal to the arithmetic average of the given boundary values.

## About  
This uses standard C++ libraries and has hardcoded values that link to the image below.

![SOR Example](https://github.com/GrahamCHill/SOR_Method/blob/main/SOR_Data.png)

The solution is then as follows:  

ω = 1.21052
--*--*--*--*--
Row: 1 | 87.4043 | 58.119 | 30.1316 |  
Row: 2 | 101.498 | 64.9402 | 32.4074 |  
Row: 3 | 103.649 | 67.7359 | 34.558 |  
Row: 4 | 95.3613 | 67.7965 | 38.0886 |  

Process finished with exit code 0
