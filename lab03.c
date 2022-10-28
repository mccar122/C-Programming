/*****+--***-*-**-----*-***-***--**-**-*-*-**-******************************
*
*  Lab #: 3
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description:
*  This program will receive input of either the value of the inradius 
*  or circumradius and will calculate the apothem, area of pentagon, area of large
*  hexagon, and small circle
******+--***-*-**-----*-***-***--**-**-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>

int main(void)
{

  // Declaration Stage of the code
  float inputVal = 0; // Variable for input value
  char inputChoice = ' '; // Variable for input choice
  int op1 = 0; // Variable to decide if first character
  int op2 = 0; // Variable to decide if second character
  float apothem = 0; // Variable for apothem of pentagon
  float base_pent = 0; // Variable for base length of pentagon
  float area_pent = 0; // Variable for area of pentagon
  float area_lc = 0; // Variable for area of large circle
  float area_hex = 0; // Variable for area of hexagon
  float area_sc = 0; // Variable for area of small circle
  
  // Input stage of the code
  printf("Select the (I)ncircle or (C)ircumcircle radius -> ");
  scanf("%c", &inputChoice);
  printf("Enter the length -> ");
  scanf("%f", &inputVal);
  op1 = inputChoice / 'I';
  op2 = 1 - (inputChoice / 'I');

  // Calculation stage of the code
  apothem = op1 * inputVal + op2 * inputVal * sin(54 * (M_PI / 180));
  base_pent = 2 * apothem * tan(36 * (M_PI / 180)) * op1 + 2 * apothem * tan(36 * (M_PI / 180)) * op2;
  area_pent = (0.25) * sqrt(5 * (5 + 2 * sqrt(5))) * pow(base_pent, 2) * op1 + (0.25) * sqrt(5 * (5 + 2 * sqrt(5))) * pow(base_pent, 2) * op2;
  area_lc = pow(apothem, 2) * M_PI * op1 + pow(apothem, 2) * M_PI * op2;
  area_hex = 6 * sqrt(3) / 4  * pow(apothem, 2) * op1 + 6 * sqrt(3) / 4 * pow(apothem, 2) * op2;
  area_sc = pow(2 * apothem * cos(M_PI / 3), 2) * M_PI * 3 / 4 * op1 + pow(2 * apothem  * cos(M_PI / 3), 2) * M_PI * 3 / 4 * op2;

  // Output Stage of Code
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Apothem of pentagon: %12.2f\n", apothem);
  printf("Base of pentagon: %15.2f\n", base_pent);
  printf("Area of pentagon: %15.2f\n", area_pent);
  printf("Area of large circle: %11.2f\n", area_lc);
  printf("Area of hexagon: %16.2f\n", area_hex);
  printf("Area of small circle: %11.2f\n", area_sc);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
}

