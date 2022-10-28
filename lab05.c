/*****+**---***-*-*--**------*-*--*--*-*-*-**-******************************
*
*  Lab #: 05
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: The user will provide information on two lines that
intersect. Locate that point of intersection to create a triangle. Output
the lengths of each side and the interior angles of the triangle
*
******+**---***-*-*--**------*-*--*--*-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>

double get_distance(double, double, double, double);
double get_inangle(double, double, double);

int main(void)
{
  double x1; //inputted first x variable
  double x2; //inputted second x variable
  double y1; //inputted first y variable
  double y2; //inputted second y variable
  double x3; //x coordinate for 3rd point
  double y3; //y coordinate for 3rd point
  double angle1; //1st external inputted angle
  double angle2; //2nd external inputted angle
  double distance12; //calculated 1st side
  double distance23; //calculated 2nd side
  double distance13; //calculated 3rd side
  double inangle1; //calculated internal angle 1
  double inangle2; //calculated internal angle 2
  double inangle3; //calculated internal angle 3
  double slope1; //calculated slope of side 1
  double slope2; //calculated slope of side 2
 
  //User Input Section
  printf("Enter coordinates for point #1 -> ");
  scanf( "%lf  %lf", &x1, &y1);
  printf("Enter angle at x-axis for line passing through point #1 -> ");
  scanf(" %lf", &angle1);
  printf("Enter coordinates for point #2 -> ");
  scanf(" %lf %lf", &x2, &y2);
  printf("Enter angle at x-axis for line passing through point #2 -> ");
  scanf(" %lf", &angle2);
  
  //Calculations for later use in function calls
  slope1 = tan(angle1 * (M_PI / 180));
  slope2 = tan(angle2 * (M_PI / 180));
  x3 = (((y2 - y1) + (x1 * slope1 - x2 * slope2)) / (slope1 - slope2));
  y3 = y1 + (x3 - x1) * slope1;

  //Function Calls
  distance12 = get_distance(x1, y1, x2, y2);
  distance23 = get_distance(x2, y2, x3, y3);
  distance13 = get_distance(x1, y1, x3, y3);
  inangle1 = get_inangle(distance12, distance13, distance23);
  inangle2 = get_inangle(distance12, distance23, distance13);
  inangle3 = get_inangle(distance13, distance23, distance12);
    
  //Output Statements
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nLine #1 Distance: %5.1lf Angle: %5.1lf", distance12, inangle3);
  printf("\nLine #2 Distance: %5.1lf Angle: %5.1lf", distance23, inangle1);
  printf("\nLine #3 Distance: %5.1lf Angle: %5.1lf", distance13, inangle2);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
}
/*****+**----**------**-*----***-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: get_distance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double x1
*    2. double y1
*    3. double x2
*    4. double y2
*  Function Description: finds distance
*
******+**----**------**-*----***-----*-*-*-**-*****************************/
double get_distance(double x_1, double y_1, double x_2, double y_2)
{
  double distance; //distance between points

  distance = 0; 

  distance = sqrt(pow((x_1 - x_2),2) + pow((y_1 - y_2),2));

  return(distance);
}

/*****+**---**--*-*-**--*----***-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: get_inangle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double distance1
*    2. double distance2
*    3. double distance3
*
*  Function Description: finds angles
*
******+**---**--*-*-**--*----***-----*-*-*-**-*****************************/
double get_inangle(double distance1, double distance2, double distance3)
{
  double inangle; //internal angle variable
  
  inangle = 0; 

  inangle = (180 / M_PI) * (acos((pow(distance1,2) + pow(distance2,2) - pow(distance3,2)) / (2 * distance2 * distance1)));

  return(inangle);
}

