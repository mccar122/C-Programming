/*****+*----**----*--**-*-*--***-----*-*****--******************************
 *
 *  Homework #: 06
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: Given a seed for the random number generator, 
 *                       create a data set of 75 elements in the range 
 *                       from 1 to 100 (inclusive of both endpoints) and 
 *                       display the mean, standard deviation, values 
 *                       less than one deviation from the mean, and 
 *                       values greater than one deviation from the mean.
 *
 ******+*----**----*--**-*-*--***-----*-*****--*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 75

int seedVal(); //User Input function
void gen(int*, double*, double*); //calculation function

int main(void)
{
  int sVal; //User inputted seed value
  int array[SIZE]; //Generated Array
  double mean; //the mean of the array
  double std; //the standard deviation of the array
  int i; //i for the for loop

  sVal = seedVal();
  srand(sVal);
  gen(array, &mean, &std);

  printf("\nData set mean: %.1f\n", mean);
  printf("Data set standard deviation: %.1f\n", std);
  printf("Values less than one deviation from mean: ");
  for (i = 0; i < SIZE; i++)
  {
    if (array[i] < (mean - std))
    {
      printf("%d ", array[i]);
    }
  }
  printf("\nValues greater than one deviation from mean: ");
  for (i = 0; i < SIZE; i++)
  {
    if (array[i] > (mean + std))
    {
      printf("%d ", array[i]);
    }
  }

  return(0);
}

/*****+**-*--*--*----**-*-*--***-----*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: seedVal
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.
 *    2.
 *    3.
 *
 *  Function Description: User Inputted Function 
 *
 ******+**-*--*--*----**-*-*--***-----*-*****--*****************************/
int seedVal(void)
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

/*****+**----*--*----**-*-*--***-----*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: gen
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int array
 *    2. int meanVal
 *    3. int stdVal
 *
 *  Function Description: This calculates desired values
 *
 ******+**----*--*----**-*-*--***-----*-*****--*****************************/
void gen(int* array, double* meanVal, double* stdVal)
{
  int i; //i for for loop
  int temp; //temp value for array assn
  double sumVal; //used to calc mean and std

  sumVal = 0;
  for (i = 0; i < SIZE; i++)
  {
    temp = (rand() % 100 + 1);
    sumVal += temp;
    array[i] = temp;
    //printf("%d: %d, ", i, array[i]);
  }
  *meanVal = sumVal / SIZE;

  sumVal = 0;
  for (i = 0; i < SIZE; i++)
  {
    sumVal  += pow((array[i] - *meanVal), 2);
  }
  *stdVal = sqrt(sumVal / (SIZE - 1));
}
