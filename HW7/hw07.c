/*****+**-*--**-*-*--**------*-*--*--***-***--******************************
 *
 *  Homework #: 07
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: Given a seed for the random number generator, a
 *                       power (p) of 10 that represents the upper limit of
 *                       the value to generate, begin by creating a data set 
 *                       of 1000 elements in the range from 0 to 10^p - 1. 
 *                       For each number in this data set re-arrange its 
 *                       digits to make the largest integer possible. 
 *                       Display the five largest and smallest value found 
 *                       in the data set.
 ******+**-*--**-*-*--**------*-*--*--***-***--*****************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define SIZE2 8

int getSeed();
int getPower();
void genVals(int, int[]);
void sortVals(int[]);
void printR(int[]);

int main(void)
{
  int seed; //user inputted seed value
  int power; //user inputted power of 10
  int array[SIZE]; //generated array

  seed = getSeed();
  srand(seed);
  power = getPower();
  genVals(power, array);
  sortVals(array);
  printR(array);

  return(0);

}

/*****+**----*--*-*--**------*-*--*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: getSeed
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. NA
 *    2.
 *    3.
 *
 *  Function Description: gets and checks inputted seed value
 *
 ******+**----*--*-*--**------*-*--*--***-***--*****************************/

int getSeed()
{
  int seed = 0; //seed value from user

  do
  {
    printf("Enter seed value -> ");
    scanf("%d", &seed);

    if (seed <= 0)
    {
      printf("\nError! Positive seed values only!!\n\n");
    }

  } while(seed <= 0);

  return(seed);
}

/*****+*-----*--*-*--**------*-*--*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: getPower
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. NA
 *    2.
 *    3.
 *
 *  Function Description: gets and checks power input
 *
 ******+*-----*--*-*--**------*-*--*--***-***--*****************************/

int getPower()
{
  int power = 0; //inputted power varaible from user

  do
  {
    printf("Enter maximum power of ten for range -> ");
    scanf("%d", &power);

    if (power <= 0)
    {
      printf("\nError! Power of ten must be positive!!\n\n");
    }
    if (power > 8)
    {
      printf("\nError! Power of ten cannot exceed eight!\n\n");
    }

  } while((power <= 0 || (power > 8)));

  return(power);
}

/*****+*-----*----*--**------*-*--*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: genVals
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int power
 *    2. int array[]
 *    3.
 *
 *  Function Description: generates values in an array
 *
 ******+*-----*----*--**------*-*--*--***-***--*****************************/
void genVals(int power, int array[])
{
  int i; // Variable for loop counter
  int temp_rand = 0; // Variable for temporary random variable
  int pwr; //calculated value

  pwr = pow(10, power);
  for (i = 0; i < SIZE; i++)
  { 
    temp_rand = (rand() % pwr);
    array[i] = temp_rand;
  }
}

/*****+*----**--*----**------*-*--*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: sortVals
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int array[]
 *    2.
 *    3.
 *
 *  Function Description: this will rearrange values and then sort them
 *
 ******+*----**--*----**------*-*--*--***-***--*****************************/
void sortVals(int array[])
{
  //int x; // Variable for the loop counter
  //int z; // Variable for the inner loop counter
  //int temporary; // Variable for the temporary held value when sorting array

  //for (x = 1; x < SIZE; x++)
  //{
  //  for (z = 0; z < SIZE - x; z++)
  //  {
  //    if (array[z] > array[z + 1])
  //    {
  //      temporary = array[z];
  //      array[z] = array[z + 1];
  //      array[z + 1] = temporary;
  //    }
  //  }
  //}
  int i; //loop control varaible
  int v; // temp varaible for value of array[]
  int temp[SIZE2]; //temporary array
  int a; // helps find largets value
  int b; // for loop control variable
  int c; //for loop control variable
  int d; //for loop control varialbe
  int x;  //bubble sort 
  int n; // variable used in sorting

  for(i = 0; i < 1000; i++)
  {
    v = array[i];
    a = 0;
    while(v != 0)
    {
      temp[a++] = (v % 10);
      v /= 10;
    }
    for(b = 0; b < a; b++)
    {
      for(c = 0; c < a - 1; c++)
      {
        if(temp[c] < temp[c + 1])
        {
          x = temp[c];
          temp[c] = temp[c + 1];
          temp[c + 1] = x;
        }
      }
    }
    n = 0;

    for(b = 0; b < a; b++)
    {
      n = (n * 10) + temp[b];
    }
    array[i] = n;
  }
  for(i = 0; i < 1000; i++)
  {
    for(d = 0; d < 1000 - 1; d++)
    {
      if(array[d] > array[d + 1])
      {
        v = array[d];
        array[d] = array[d + 1];
        array[d + 1] = v;
      }
    }
  }
}
/*****+*----**--*---**--*-*--****----***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function:
 *
 *  Function Return Type:
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.
 *    2.
 *    3.
 *
 *  Function Description:
 *
 ******+*----**--*---**--*-*--****----***-***--*****************************/
void printR(int array[])
{
  int i; //for loop variable

  printf("\nLargest 5 values in data: ");
  for(i = 999; i >= 995; i--)
  {
    printf("%d ", array[i]);
  }
  printf("\nSmallest 5 values in data: ");
  for(i = 0; i < 5; i++)
  {
    printf("%d ", array[i]);
  }
}

