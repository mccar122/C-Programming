/*****+**-*--*--*-*--*----*-*****-*--***-*-**-******************************
*
*  Lab #: 01
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description:
*  Calculates the total volume of a user inputted measurements of a cone/hemisphere object.
******+**-*--*--*-*--*----*-*****-*--***-*-**-*****************************/
#include <stdio.h>
#define PI 3.1416
#define M_I 35.315

int main(void)
{
  float height; //creates a variable for height
  float radius; //creates a variable for radius
  float volume_cone_m; //creates a variable for the volume of the cone in cubic meters
  float volume_hemisphere_m; //creates a variable for the volume of the hemisphere in cubic meters
  float volume_m; //creates a variable for the total volume in cubic meters
  float volume_ft; //creates a variable for the total volume in cubic feet

  // This is the input stage of the code
  printf("Enter the height of the cone in meters -> ");
  scanf("%f", &height);
  printf("Enter the radius of the hemisphere in meters -> ");
  scanf("%f", &radius);

  // This is the calculation stage of the code
  volume_cone_m = PI * radius * radius * height / 3;
  volume_hemisphere_m = PI * 2 / 3 * radius * radius * radius;
  volume_m = volume_cone_m + volume_hemisphere_m;
  volume_ft = volume_m * M_I;
  
  // This is the output stage of the code
  printf("\nThe volume of the hemisphere: %.2f cubic meters\n", volume_hemisphere_m);
  printf("The volume of the cone: %.2f cubic meters\n", volume_cone_m);
  printf("The total volume of the shape: %.2f cubic meters\n", volume_m);
  printf("The total volume of the shape: %.2f cubic feet\n", volume_ft);
  
  return(0);
}
