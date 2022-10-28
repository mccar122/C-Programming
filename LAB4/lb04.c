/*****+--***-*-**-*------*---**--*--**-*-*-**-******************************
*
*  Lab #: 4
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Given 3 coordinates find the distance of the sides of
*  the triangle, as well as the angles for the intersections of the triangle
*
******+--***-*-**-*------*---**--*--**-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>

double findAngle(double lengthside1, double lengthside2, double lengthside3); //Function that will find the angles
double lengthside(double Point_x, double Point_y, double Point_2x, double Point_2y); //Function that will find the side lengths

int main(void)
{
  double Point_1_y = 0; //Variable for inputted y coordinate
  double Point_1_x = 0; //Variable for inputted x coordinate
  double Point_2_y = 0; //Variable for inputted y coordinate
  double Point_2_x = 0; //Variable for inputted x coordinate
  double Point_3_y = 0; //Variable for inputted y coordinate
  double Point_3_x = 0; //Variable for inputted x coordinate
  double lengthside1 = 0; //Variable for outputted side length
  double lengthside2 = 0; //Variable for outputted side length
  double lengthside3 = 0; //Variable for outputted side length
  double theta1 = 0; //Variable for outputted angle
  double theta2 = 0; //Variable for outputted angle
  double theta3 = 0; //Variable for outputted angle

  //User Input Section
  printf("Enter coordinates for point #1 -> ");
  scanf("%lf %lf", &Point_1_x, &Point_1_y);
  printf("Enter coordinates for point #2 -> ");
  scanf("%lf %lf", &Point_2_x, &Point_2_y);
  printf("Enter coordinates for point #3 -> ");
  scanf("%lf %lf", &Point_3_x, &Point_3_y);
  
  //Function Call Section
  lengthside1 = lengthside(Point_1_x, Point_1_y, Point_2_x, Point_2_y);
  lengthside3 = lengthside(Point_1_x, Point_1_y, Point_3_x, Point_3_y);
  lengthside2 = lengthside(Point_2_x, Point_2_y, Point_3_x, Point_3_y);
  
  theta3 = findAngle(lengthside1, lengthside2, lengthside3);
  theta2 = findAngle(lengthside1, lengthside3, lengthside2);
  theta1 = findAngle(lengthside3, lengthside2, lengthside1);
  
  //Outputted Results Section
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Line #1 Distance: %5.1lf Angle: %5.1lf\n", lengthside1, theta1);
  printf("Line #2 Distance: %5.1lf Angle: %5.1lf\n", lengthside2, theta2);
  printf("Line #3 Distance: %5.1lf Angle: %5.1lf\n", lengthside3, theta3);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
  return(0);
}

/*****+--*-*-*-**-*------*---**--*--**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: lengthside
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. Point_1
*    2. Point_2
*    3. Point_3
*
*  Function Description: This function finds the side lengths of the triangle given 
                          the 3 points given.
*
******+--*-*-*-**-*------*---**--*--**-*-*-**-*****************************/

double lengthside(double Point_x, double Point_y, double Point_2x, double Point_2y)
{ 
  double lengthside = 0; // Variable for side length

  lengthside = sqrt(pow((Point_2x - Point_x),2) + pow((Point_2y - Point_y), 2));

  return (lengthside);
}

/*****+--*-*-*-**-*------*---**--*--**-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: findAngle
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. lengthside1
*    2. lengthside2
*    3. lengthside3
*
*  Function Description: This function will take input of three lines
*  that form a triangle and will then find the angles of the triangle
*
******+--*-*-*-**-*------*---**--*--**-*-*-**-*****************************/
double findAngle(double lengthside1, double lengthside2, double lengthside3)
{
  double theta = 0; // Variable for angle

  theta = (180) / (M_PI) * acos((pow(lengthside3, 2) - pow(lengthside1, 2) - pow(lengthside2, 2)) / (-2 * lengthside1 * lengthside2));

  return (theta);
}

