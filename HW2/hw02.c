/*****+**---***-*---***---*--***-----***-*-**-******************************
*
*  Homework #: 02
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Given as input two points on a first road and a
                        third point on a second road that is perpendicular
                        to the first determine the distance from the points
                        on the first road to that on the second and the 
                        coordinate at which the two lines intersect. Both
                        roads form a straight line. All points will be unique 
                        and no lines will be vertical or horizontal.

*
******+**---***-*---***---*--***-----***-*-**-*****************************/
#include <stdio.h>
#include <math.h>

int main(void)
{
  // Initializes all the variables used by the code
  double first_point_x; //This is the first point x variable
  double second_point_x; //This is the second point x variable
  double first_point_y; //This is the first point y variable
  double second_point_y; //This is the second point x variable
  double point_perp_x; //This is the perpendicular point x variable
  double point_perp_y; //This is the perpendicular point y variable
  double distance_1; //Distance from point 1 to perpendicular point
  double distance_2; //Distance from point 2 to perpendicular point
  double intersection_x; //Point of intersection x variable
  double intersection_y; //Point of intersection x variable
  double slope_1; //Slope of original Line
  double slope_2; //Slope of perpendicular Line
  double y_int_1; //Y intercept point of original Line
  double y_int_2; //Y intercept point of perpendicular  Line

  // Prompts user for a set of coordinates and the horizontal line coordinate
  printf("Enter coordinates for first point of road -> ");
  scanf("%lf %lf", &first_point_x, &first_point_y);
  printf("Enter coordinates for second point of road -> ");
  scanf("%lf %lf", &second_point_x, &second_point_y);
  printf("Enter coordinates for point on perpendicular road -> ");
  scanf("%lf %lf", &point_perp_x, &point_perp_y);

  // Calculation Stage for finding distance 
  distance_1 = sqrt(pow((point_perp_x - first_point_x),2) + pow((point_perp_y - first_point_y), 2));
  distance_2 = sqrt(pow((point_perp_x - second_point_x),2) + pow((point_perp_y - second_point_y), 2));
  slope_1 = (second_point_y - first_point_y) / (second_point_x - first_point_x);
  slope_2 = 1 / (slope_1 * -1);
  y_int_1 = first_point_y - slope_1 * first_point_x;
  y_int_2 = point_perp_y - slope_2 * point_perp_x;
  intersection_x = (y_int_2 - y_int_1) / (slope_1 - slope_2);
  intersection_y = slope_1 * intersection_x + y_int_1;
  //printf("slope 1: %.2f y int: %.2f slope 2: %.2f y int: %.2f", slope_1, y_int_1, slope_2, y_int_2);
 
  // Prints Final Outputs
  printf("\nDistance from (%.1f, %.1f) to (%.1f, %.1f): %.1f", first_point_x, first_point_y, point_perp_x, point_perp_y, distance_1);
  printf("\nDistance from (%.1f, %.1f) to (%.1f, %.1f): %.1f", second_point_x, second_point_y, point_perp_x, point_perp_y, distance_2);
  printf("\nCoordinate of intersection: %.1f, %.1f\n", intersection_x, intersection_y);

  return(0);
} 
