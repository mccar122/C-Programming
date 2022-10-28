/*****+**----*--*-*-**--*----****-*-********--******************************
*
*  Lab #: 06
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Given the lengths of four potential sides to create a
                        triangle, select and display the three sides that create
                        the largest and smallest possible area of a triangle. Use
                        Heron’s formula to calculate the area of a triangle
*
******+**----*--*-*-**--*----****-*-********--*****************************/
#include <stdio.h>
#include <math.h>

int check_sides(double, double, double);
double max(double, double, double, double, double*, double*, double*);
double min(double, double, double, double, double*, double*, double*);
double find_area(double, double, double);

int main(void)
{
  double sideA; //variable for inputted first side
  double sideB; //variable for inputted second side
  double sideC; //variable for inputted third side
  double sideD; //variable for inputted fourth side
  double max_val; //maximum area produced
  double min_val; //minimum area produced
  double max_sideA; //maximum area side used
  double max_sideB; //maximum area side used
  double max_sideC; //maximum area side used
  double min_sideA; //minimum area side used
  double min_sideB; //minimum area side used
  double min_sideC; //minimum area side used
  int val_check1; //variable to be used in checking if triangle is possible
  int val_check2; //variable to be used in checking if triangle is possible
  int val_check3; //variable to be used in checking if triangle is possible
  int val_check4; //variable to be used in checking if triangle is possible

  //User Input Section
  printf("Enter length of side #1 -> ");
  scanf("%lf", &sideA);
  printf("Enter length of side #2 -> ");
  scanf("%lf", &sideB);
  printf("Enter length of side #3 -> ");
  scanf("%lf", &sideC);
  printf("Enter length of side #4 -> ");
  scanf("%lf", &sideD);

  //Function Call Section for checking valid triangle
  val_check1 = check_sides(sideA, sideB, sideC);
  val_check2 = check_sides(sideA, sideB, sideD);
  val_check3 = check_sides(sideB, sideC, sideD);
  val_check4 = check_sides(sideA, sideC, sideD);

  //Logical Statements and function calls to ensure only valid triangle dimensions are used
  //Additionally prints resulting values after checks and calls are done
  if (val_check1 && val_check2 && val_check3  && val_check4 == 1)
  {
    max_val = max(sideA, sideB, sideC, sideD, &max_sideA, &max_sideB, &max_sideC);
    min_val = min(sideA, sideB, sideC, sideD, &min_sideA, &min_sideB, &min_sideC);
  }
  else if (val_check1 == 1)
  {
    max_val = find_area(sideA, sideB, sideC);
    max_sideA = sideA;
    max_sideB = sideB;
    max_sideC = sideC;
    
    min_val = max_val;
    min_sideA = sideA;
    min_sideB = sideB;
    min_sideC = sideC;
  }
  else if (val_check2 == 1)
  {
    max_val = find_area(sideA, sideB, sideD);
    max_sideA = sideA;
    max_sideB = sideB;
    max_sideC = sideD;

    min_val = max_val;
    min_sideA = sideA;
    min_sideB = sideB;
    min_sideC = sideD;
  }
  else if (val_check3 == 1)
  {
    max_val = find_area(sideB, sideC, sideD);
    max_sideA = sideB;
    max_sideB = sideC;
    max_sideC = sideD;

    min_val = max_val;
    min_sideA = sideB;
    min_sideB = sideC;
    min_sideC = sideD;
  }
  else if (val_check4 == 1)
  {
    max_val = find_area(sideA, sideC, sideD);
    max_sideA = sideA;
    max_sideB = sideC;
    max_sideC = sideD;

    min_val = max_val;
    min_sideA = sideA;
    min_sideB = sideC;
    min_sideC = sideD;
  }
  
  if((val_check1 || val_check2 || val_check3 || val_check4) == 0)
  {
    printf("\nError: No triangles can be created from lengths given!\n");
  }
  else
  {
    printf("\nLargest possible triangle area: %.2f\n", max_val);
    printf("Side values used: %.1f, %.1f, %.1f\n", max_sideA, max_sideB, max_sideC);
    printf("\nSmallest possible triangle area: %.2f\n", min_val);
    printf("Side values used: %.1f, %.1f, %.1f\n", min_sideA, min_sideB, min_sideC);
  }

  return(0);
}

/*****+*----**--*-*--*----*--*-*--*-********--******************************
*
*  Function Information
*
*  Name of Function: check_sides
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. double side1
*    2. double side2
*    3. double side3
*
*  Function Description: this checks the a + b < c rule
*
******+*----**--*-*--*----*--*-*--*-********--*****************************/
int check_sides(double side1, double side2, double side3)
{
  int return_val; //variable used to determine the sides are valid
  if ((((side1 + side2) <= side3) || ((side2 + side3) <= side1) || ((side1 + side3) <= side2)) == 1)
  {
    return_val = 0;
  }
  else
  {
    return_val = 1;
  }

  return(return_val);
}

/*****+**---**--*---**--*----****-*-********--******************************
*
*  Function Information
*
*  Name of Function: find_area
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double side 1
*    2. double side 2
*    3. double side 3
*
*  Function Description: This function calculates the area given 3 of the sides
*
******+**---**--*---**--*----****-*-********--*****************************/
double find_area(double side1, double side2, double side3)
{
  double s; //hueron variable
  double area; //area produced
  
  s = (side1 + side2 + side3) / 2.0;

  area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

  return(area);
}

/*****+*-----*--*---**--*----****-*-********--******************************
*
*  Function Information
*
*  Name of Function: max
*
*  Function Return Type: double
* 
*  Parameters (list data type, name, and comment one per line):
*    1. double area1
*    2. double area2
*    3. double area3
*    4. double area4
*    5. double maximum
*
*  Function Description: Finds the max area given 4 areas
*
******+*-----*--*---**--*----****-*-********--*****************************/
double max(double sideA, double sideB, double sideC, double sideD, double *side1, double *side2, double *side3)
{
  double maximum; //max area
  double area1; //area of abc
  double area2; //area of abd
  double area3; //area of bcd
  double area4; //area of acd
  
  area1 = find_area(sideA, sideB, sideC);
  area2 = find_area(sideA, sideB, sideD);
  area3 = find_area(sideB, sideC, sideD);
  area4 = find_area(sideA, sideC, sideD);

  if (area1 > area2)
  {
    maximum = area1;
    *side1 = sideA;
    *side2 = sideB;
    *side3 = sideC;
  }
  else 
  {
    maximum = area2;
    *side1 = sideA;
    *side2 = sideB;
    *side3 = sideD;
  }

  if (maximum < area3)
  {
    maximum = area3;
    *side1 = sideB;
    *side2 = sideC;
    *side3 = sideD;
  }

  if (maximum < area4)
  {
    maximum = area4;
    *side1 = sideA;
    *side2 = sideC;
    *side3 = sideD;
  }

  return(maximum);
}
/*****+*----***-*-*--*--*----****-*-********--******************************
*
*  Function Information
*
*  Name of Function: min
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double area1
*    2. double area2
*    3. double area3
*    4. double area4
*    5. double minimum
*
*  Function Description: finds smallest area
*
******+*----***-*-*--*--*----****-*-********--*****************************/
double min(double sideA, double sideB, double sideC, double sideD, double *side1, double *side2, double *side3)
{
  double minimum; //smallest area produced
  double area1; //area of abc
  double area2; //area of abd
  double area3; //area of bcd
  double area4; //area of acd
  
  area1 = find_area(sideA, sideB, sideC);
  area2 = find_area(sideA, sideB, sideD);
  area3 = find_area(sideB, sideC, sideD);
  area4 = find_area(sideA, sideC, sideD);

  if (area1 < area2)
  {
    minimum = area1;
    *side1 = sideA;
    *side2 = sideB;
    *side3 = sideC;
  }
  else 
  {
    minimum = area2;
    *side1 = sideA;
    *side2 = sideB;
    *side3 = sideD;
  }

  if (minimum > area3)
  {
    minimum = area3;
    *side1 = sideB;
    *side2 = sideC;
    *side3 = sideD;
  }

  if (minimum > area4)
  {
    minimum = area4;
    *side1 = sideA;
    *side2 = sideC;
    *side3 = sideD;
  }

  return(minimum);
}
