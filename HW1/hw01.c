/*****+**----*-------*----*-*****-*--***-*-**-******************************
*
*  Homework #: 01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:
  This program takes a user inputted mass and velocity (in lbs and ft/s) and
  returns the objects mass in kilograms, velocity in m/s, and the kinetic
  energy in Joules.
*
******+**----*-------*----*-*****-*--***-*-**-*****************************/
#include <stdio.h>
#define LB_KG 0.453592
#define FTS_MS 0.3048

int main(void)
{
  float mass_lb; //creates variable for mass in pounds
  float velocity_fts; //creates variable for velocity in ft per s
  float mass_kg; //creates variable for mass in kilograms
  float velocity_ms; //creates variable for velocity in m per s
  float kinetic_energy; //creates variable for kinetic energy

//This is the input section of the code
  printf("Enter the object mass in pounds -> ");
  scanf("%f", &mass_lb);
  printf("Enter the object velocity ft/s -> ");
  scanf("%f", &velocity_fts);

//This is the calculation section of the code
  mass_kg = mass_lb * LB_KG;
  velocity_ms = velocity_fts * FTS_MS;
  kinetic_energy = 0.5 * mass_kg * velocity_ms * velocity_ms;

//This is the output section of the code
  printf("\nThe mass of the object: %.2f (kg)\n", mass_kg);
  printf("The velocity of the object: %.2f (m/s)\n", velocity_ms);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("The kinetic energy of the object: %.2f (J)\n", kinetic_energy);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);

}  
