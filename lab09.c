/*****+--*******----*-*--*--**--***--*-*****--******************************
 *
 *  Lab #: 9
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description:
 *  This program will take the input of a positive integer and it will return
 *  if it is a semi-square or a square
 ******+--*******----*-*--*--**--***--*-*****--*****************************/
#include <stdio.h>
#include <math.h>

int getInput();
int perfect(int);
int semiCheck(int);
int check(int);

int main(void)
{

  int Val = 0; // Variable for the input integer

  Val = getInput();
  check(Val);

  return(0);
}

/*****+--*-*-***--*-*----**-***-**---*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: getInput
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. void function 
 *    2.
 *    3.
 *
 *  Function Description: gets and checks input from user
 *
 ******+--*-*-***--*-*----**-***-**---*-*****--*****************************/
int getInput()
{
  int input = 1; // Variable for the input of integer

  do
  {

    if (input <=  0)
    {
      printf("\nError! Positive values only!\n\n");
    }

    printf("Enter starting value -> ");
    scanf("%d", &input);
  } while(input <=  0);

  return (input);
}

/*****+--*-*-***--*-*----**-***-**---*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: perfect
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int value
 *    2.
 *    3.
 *
 *  Function Description: checks if value is perfect square
 *
 ******+--*-*-***--*-*----**-***-**---*-*****--*****************************/
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

/*****+-**-*-***--*-*----**-***-**---*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: check
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int a
 *    2.
 *    3.
 *
 *  Function Description: checks if value is semi square or perfect one
 *
 ******+-**-*-***--*-*----**-***-**---*-*****--*****************************/
int check(int a)
{
  int check = 0;  // Variable to check if square or semi-square
  int square = 0; // Variable for to check if square
  int semi = 0; // Variable to check if semi-square

  while(!(check = semiCheck(a)) && !(check = perfect(a)))
  {
    square = perfect(a);
    semi = semiCheck(a);
    a++;
  }

  square = perfect(a);
  semi = semiCheck(a);
  if (square == 1)
  {
    printf("\nIdentified value: %d\n", a);
    printf("Status: Perfect square\n");
  }
  else if (semi == 1)
  {
    printf("\nIdentified value: %d\n", a);
    printf("Status: Semi-square\n");
  }
  return(a);
}
