/*****+**-*--*--*----**-*-*--*-*----**-*****--******************************
 *
 *  Homework #: 05
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: For an integer x, a Boiler Number is the sum of all
 *                       integers from 1 to x inclusive. Given a starting
 *                       integer y and ending integer z, display either the
 *                       even or odd Boiler Numbers generated from the values
 *                       in the range from y to z inclusive.
 *
 ******+**-*--*--*----**-*-*--*-*----**-*****--*****************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int calculations(int boilernum, int starting, int i, int option, int ending);

int main(void)
{
  int val; //value to check first input
  int val1; //value to check second input
  int val2; //value to check third input
  int i; //i for for loop
  int boilernum; //boilernum created
  int starting; //starting value inputted
  int ending; //ending value inputted
  int option; //odd or even option

  val = 2;
  val1 = 2;
  val2 = 2;
  i = 0;
  boilernum = 0;

  //First Input and Check
  while (val == 2)
  {
    printf("\nEnter 0 for even or 1 for odd values -> ");
    scanf("%d", &option);

    if (option == 1 || option == 0)
    {
      val += val;
    }
    else
    {
      printf("\nError! Select a valid option!!\n");
    }
  }

  //Second Input and Check
  while (val1 == 2)
  {
    printf("Enter starting value -> ");
    scanf("%d", &starting);
    if (starting > 0)
    {
      val1 += 1;
    }
    else
    {
      printf("\nError! Starting value must be positive!\n\n");
    }
  }

  //Third Input and Check
  while (val2 == 2)
  {
    printf("Enter ending value -> ");
    scanf("%d", &ending);

    if (ending > starting)
    {
      val2 += 1;
    }
    else
    {
      printf("\nError! Ending value must be > %d\n\n", starting);
    }
  }

  //Calculations
  calculations(boilernum, starting, i, option, ending);

  return(0);
}
/*****+**---***-*-*--**---*-*****-*--*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: calculation
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int boilernum
 *    2. int starting
 *    3. int i
 *    4. int option
 *    5. int ending
 *
 *  Function Description: will calculate and return boilernums
 *
 ******+**---***-*-*--**---*-*****-*--*-*****--*****************************/
int calculations(int boilernum, int starting, int i, int option, int ending)
{
  int val; // value to increase to check if there are existing values
  int boilernum2; // copy of boilernum in order to avoid changes

  val = 0;
  boilernum2 = boilernum;

  for (i = 0; i < starting; i++)
  {
    boilernum += i;
    boilernum2 += i;
  }
  if (option == 1)
  {
    for (i = starting; i <= ending; i++)
    {
      boilernum2 += i;

      if ((boilernum2 % 2) == 1)
      {
        val += 1;
      }
    }
    if (val != 0)
    {
      printf("\nOdd Boiler numbers: ");
      for (i = starting; i <= ending; i++)
      {
        boilernum += i;

        if ((boilernum % 2) == 1)
        {
          printf("%d ", boilernum);
        }
      }
    }
    else
    {
      printf("\nError: No values generated.\n");
    }
  }
  else
  {
    //printf("\nEven Boiler numbers: ");
    for (i = starting; i <= ending; i++)
    {
      boilernum2 += i;
      if ((boilernum2 % 2) == 0)
      {
        val += 1;
        //printf("%d ", boilernum);
      }
    }
    if (val != 0)
    {
      printf("\nEven Boiler numbers: ");
      for (i = starting; i <= ending; i++)
      {
        boilernum += i;
        if ((boilernum % 2) == 0)
        {
          printf("%d ", boilernum);
        }
      }
    }
    else
    {
      printf("\nError: No values generated.\n");
    }
  }
  return(0);
}
