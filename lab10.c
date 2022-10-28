/*****+**---***---*-**--*---****-----*-*****--******************************
 *
 *  Lab #: 10
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: This program takes random seed and returns max 
 *                       distance, number of horizontal and vertical lines
 *
 ******+**---***---*-**--*---****-----*-*****--*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARRAYSIZE 500

int seedVal(void);
void genX(int*, int*);
float getDist(int*, int*);
int Horiz(int*, int*);
int Ver(int*, int*);
void OutputResults(int, int, float);

int main()
{
  int sVal = 0; // Variable for the seed value
  int xValues[ARRAYSIZE]; // Variable for list of x values
  int yValues[ARRAYSIZE]; // Variable for the list of y values
  float max = 0; // Variable for the maximum distance
  int Horizontal = 0; // Variable for the number of horizontal lines;
  int Vertical = 0; // Variable for the number of vertical lines;

  sVal = seedVal();
  srand(sVal);

  genX(xValues, yValues);
  max = getDist(xValues, yValues);
  Horizontal = Horiz(yValues, xValues);
  Vertical = Ver(xValues, yValues);

  OutputResults(Horizontal, Vertical, max);
  return(0);
}

/*****+*----***-*----*--*---****-----*-*****--******************************
*
*  Function Information
*
*  Name of Function: seedVal
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*    2.
*    3.
*
*  Function Description: Takes user input seed value
*
******+*----***-*----*--*---****-----*-*****--*****************************/

int seedVal()
{
  int seed = 0; // Variable for the seed value

  do
  {
    printf("Enter seed value -> ");
    scanf("%d", &seed);

    if (seed <= 0)
    {
      printf("\nError! Positive seed values only!!\n\n");
    }
  } while( seed <= 0 );

  return(seed);
}

/*****+**-*--**-*----*--*---****-----*-*****--******************************
*
*  Function Information
*
*  Name of Function: genX
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int xVals
*    2. int yVals
*    3.
*
*  Function Description: creates and array of x and y variables
*
******+**-*--**-*----*--*---****-----*-*****--*****************************/

void genX(int* xVals, int* yVals)
{
  int i; // Variable for loop counter
  int temp_rand = 0; // Variable for temporary random variable

  for (i = 0; i < ARRAYSIZE; i++)
  {
    temp_rand = (rand() % 201 - 100);
    xVals[i] = temp_rand;

    temp_rand = (rand() % 201 - 100);
    yVals[i] = temp_rand;
  }
}

/*****+*-----**-*----*--*---****-----*-*****--******************************
*
*  Function Information
*
*  Name of Function: getDist
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. int xVal
*    2. int yVal
*    3.
*
*  Function Description: takes the variables and returns max distance 
*
******+*-----**-*----*--*---****-----*-*****--*****************************/

float getDist(int* xVal , int* yVal)
{
  float dist = 0; // Variable for the distance between points
  int z; // Variable for loop counter
  int x; // Variable for loop counter
  float max = 0; // Variable for the maximum distance

  for (z = 0; z < ARRAYSIZE - 1; z++)
  {
    for (x = z + 1; x < ARRAYSIZE - 1; x++)
    {
      dist = sqrt(pow(xVal[x] - xVal[z], 2) + pow(yVal[x] - yVal[z], 2));
      if (dist > max)
      {
        max = dist;
      }
    }
  }

  return(max);
}

/*****+**-*-**--*----*--*---****-----*-*****--******************************
*
*  Function Information
*
*  Name of Function: Horiz
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int yVal
*    2. int xVal
*    3.
*
*  Function Description: Counts number of horizontal lines generated
*
******+**-*-**--*----*--*---****-----*-*****--*****************************/

int Horiz(int* yVal, int* xVal)
{
  int numHoriz = 0; // Variable for the number of horizontal lines
  int z; // Variable for loop counter
  int x; // Variable for loop counter
  int slope = 0; // Variable for the slope

  for (z = 0; z < ARRAYSIZE; z++)
  {
    for (x = z + 1; x < ARRAYSIZE; x++)
    {
      slope = ((yVal[z] - yVal[x]));
      if ((slope == 0) && (xVal[z] != xVal[x]))
      {
        numHoriz++;
      }
    }
  }

  return(numHoriz);
}

/*****+*--*-**--*----*--*---****-----*-*****--******************************
*
*  Function Information
*
*  Name of Function: Ver
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int xVal
*    2. int yVal
*    3.
*
*  Function Description: counts and returns the number of vertical lines
*
******+*--*-**--*----*--*---****-----*-*****--*****************************/

int Ver(int* xVal, int* yVal)
{
  int numVer = 0; // Variable for the number of horizontal lines
  int z; // Variable for loop counter
  int x; // Variable for loop counter
  int slope = 0; // Variable for the slope

  for (z = 0; z < ARRAYSIZE;  z++)
  {
    for (x = z + 1; x < ARRAYSIZE; x++)
    {
      slope = ((xVal[z] - xVal[x]));
      if ((slope == 0) && (yVal[z] != yVal[x]))
      {
        numVer++;
      }
    }
  }

  return(numVer);
}

/*****+*----**--*----*--*---****-----*-*****--******************************
*
*  Function Information
*
*  Name of Function: OutputResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int Hor
*    2. int Vert
*    3. float Dist
*
*  Function Description: this is the print statement
*
******+*----**--*----*--*---****-----*-*****--*****************************/

void OutputResults(int Hor, int Vert, float Dist)
{
  printf("\nMaximum Distance: %.1f\n", Dist);
  printf("Horizontal Lines: %d\n", Hor);
  printf("Vertical Lines: %d\n", Vert);
}
