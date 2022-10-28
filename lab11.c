/*****+-**-*****---------**-**---**-****-***--******************************
 *
 *  Lab #: 11
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: Given a positive integer to serve as the seed for 
 *                       the random number generator and the maximum value to
 *                       generate, create a data set of 100 integers ranging
 *                       from 1 to the given maximum value (inclusive of 
 *                       both end points) and display the perfect squares 
 *                       (in sorted order) followed by the semi-squares (in sorted order).
 *
 ******+-**-*****---------**-**---**-****-***--*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100

int getS();
int getMax();
void genVals(int [], int);
void sortValues(int []);
int semiCheck(int);
int perfect(int);
void check(int []);
int main()
{
  int array_vals[SIZE]; // Variable for the values of squares
  int seed = 0; // Variable for the seed
  int max = 0; // Variable for the max integer

  seed = getS();
  srand(seed);
  max = getMax();
  genVals(array_vals, max);
  sortValues(array_vals);
  check(array_vals);

  return(0);
}

/*****+*----***-*----*--*---****-----*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: getS
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

int getS()
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
/*****+*--*--**-*-*-**--*---****----****-***--******************************
*
*  Function Information
*
*  Name of Function: getMax
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*    2.
*    3.
*
*  Function Description: gets max ranges inputted by user
*
******+*--*--**-*-*-**--*---****----****-***--*****************************/

int getMax()
{
  int max = 0; // Variable for the max value

  do
  {
    printf("Enter maximum range value -> ");
    scanf("%d", &max);

    if (max <= 0)
    {
      printf("\nError! Positive range values only!!\n\n");
    }
  } while(max <= 0);

  return(max);
}

/*****+**-*--**-*----*--*---****-----*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: genVals
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int values
 *    2. int max
 *
 *  Function Description: creates and array of x and y variables
 *
 ******+**-*--**-*----*--*---****-----*-*****--*****************************/

void genVals(int values[], int max)
{
  int i; // Variable for loop counter
  int temp_rand = 0; // Variable for temporary random variable

  for (i = 0; i < SIZE; i++)
  {
    temp_rand = (rand() % (max) + 1);
    values[i] = temp_rand;
  }
}

/*****+-**-*-*-*--*-*----**-**---**-****-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: sortValues
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int values // Variable for the list of values
 *
 *  Function Description: This program sorts the values from least to greatest
 * 
 ******+-**-*-*-*--*-*----**-**---**-****-***--*****************************/
void sortValues(int values[])
{
  int x; // Variable for the loop counter
  int z; // Variable for the inner loop counter
  int temporary; // Variable for the temporary held value when sorting array

  for (x = 1; x < SIZE; x++)
  {
    for (z = 0; z < SIZE - x; z++)
    {
      if (values[z] > values[z + 1])
      {
        temporary = values[z];
        values[z] = values[z + 1];
        values[z + 1] = temporary;
      }
    }
  }
}
/*****+**---***-*-*-**--*---****----****-***--******************************
*
*  Function Information
*
*  Name of Function: perfect
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int perfect
*    2.
*    3.
*
*  Function Description: checks if perfect square
*
******+**---***-*-*-**--*---****----****-***--*****************************/

int perfect(int value)
{
  int perfect = 0; // Variable for the perfect square
  int squared = 0; // Variable for the square root value

  squared = sqrt(value);

  if ((squared * squared) == value)
  {
    perfect = 1;
  }

  return(perfect);
}

/*****+-**-*-***--*-*----**-***-**---*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: semiCheck
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int value
 *    2.
 *    3.
 *
 *  Function Description: checks if value is semi square
 *
 ******+-**-*-***--*-*----**-***-**---*-*****--*****************************/
int semiCheck(int value)
{
  int semiPer = 0; // Variable for the semi square
  int c = 1; // Variable for the factor to multiply square root of value is
  int squared = 0; // Variable for the square root value

  do
  {
    squared = sqrt(value / c);
    if ((c > 1) && (c < squared))
    {
      squared = sqrt(value / c);
      if (((perfect(squared*squared)) && (squared * squared * c) == value))
      {
        semiPer = 1;
      }
      c++;
    }
    else
    {
      c++;
    }
  } while((semiPer == 0) && (c <= value));

  return(semiPer);
}
/*****+**---***-*-*-**--*---****----****-***--******************************
*
*  Function Information
*
*  Name of Function: check
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. array int values
*    2.
*    3.
*
*  Function Description: itterates through array and checks values
*
******+**---***-*-*-**--*---****----****-***--*****************************/

void check(int values[])
{
  int i; // Variable for the loop counter
  int checkSemi = 0; // Variable to check if semi exists
  int checkPer = 0; // Variable to check if perfect exists

  for (i = 0; i < SIZE; i++)
  {
    if (perfect(values[i]))
    {
      if(checkPer != 1)
      {
        printf("\nPerfect squares:");
        checkPer = 1;
      }

      printf(" %d", values[i]);
    }
  }

  for (i = 0; i < SIZE; i++)
  {
    if(semiCheck(values[i]) && !(perfect(values[i])))
    {
      if(checkSemi != 1)
      {
        printf("\nSemi-squares:");
        checkSemi = 1;
      }

      printf(" %d", values[i]);
    }
  }

  printf("\n");

  if ((checkSemi == 0) && (checkPer == 0))
  {
    printf("Result: No perfect or semi-squares found.\n");
  }
}
