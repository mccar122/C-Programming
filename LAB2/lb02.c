/*****+**-*--*--*-*-***---*-**-**----***-*-**-******************************
*
*  Lab #: 02
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Given a hexagon length this program will find 
                        a series of calculated values relating to area.
*
******+**-*--*--*-*-***---*-**-**----***-*-**-*****************************/
#include <stdio.h>
#include <math.h>
#define PI 3.1416

int main(void)
{ 

  // Initializes all variables calculated in following code
  float length; // Length of hexagon
  float area_hex; // Area of hexagon
  float radius_lc; // Radius of large circle
  float area_lc; // Area of large circle
  float apothem; // Apothem of pentagon
  float base_pent; // Base length of pentagon
  float area_pent; // Area of pentagon
  float area_sc; // Area of small circle

  // Prompts user for side length of the hexagon to be used in calculations
  printf("Enter the hexagon side length -> ");
  scanf("%f", &length);

  // Calculating stage of the code
  area_hex = (3 * sqrt(3) * pow(length,2)) / 2;
  radius_lc = (length * sqrt(3)) / 2;
  area_lc = (PI * 3 * pow(length,2)) / 4;
  base_pent = 2 * radius_lc * sin(PI/5); 
  area_pent= (0.25) * sqrt(5 * (5 + 2 * sqrt(5))) * pow(base_pent, 2);
  apothem = area_pent * 2 / (5 * base_pent);
  area_sc = PI * pow((base_pent) / (2 * tan(PI/5)), 2);

  // Prints final outputs
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nArea of hexagon: %16.2f", area_hex);
  printf("\nRadius of large circle: %9.2f", radius_lc);
  printf("\nArea of large circle: %11.2f", area_lc);
  printf("\nApothem of pentagon: %12.2f", apothem);
  printf("\nBase of pentagon: %15.2f", base_pent);
  printf("\nArea of pentagon: %15.2f", area_pent);
  printf("\nArea of small circle: %11.2f", area_sc);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
}


