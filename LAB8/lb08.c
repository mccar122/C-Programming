/*****+*--*-**--*----*------*****---**-*****--******************************
 *
 *  Lab #: 8
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: This program takes an input configuration of 1s and 2s,
 *                       then checks for the fewest number of changes to make the
 *                       entire configuration alternating 1s and 2s (ex: 121212)
 *
 ******+*--*-**--*----*------*****---**-*****--*****************************/
#include <stdio.h>
#include <math.h>

int counter(long long);
long long input();
int checkcon(long long);
int changeCalc(long long, int);

int main(void)
{
  long long coni; // contains the initial configuration of numbers
  int count; //contains the number of digits in the configuration
  int compVal; // contains the value for how many required changes;

  coni = input();
  count = counter(coni);
  compVal = changeCalc(coni, count);

  printf("\nFewest # of required changes: %d\n", compVal);

  return(0);
}
/*****+*--*--**---*-***---*-**-**-*--*-*****--******************************
*
*  Function Information
*
*  Name of Function: changeCalc
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int count
*    2. int num
*
*  Function Description: This function determines the minimum number of changes needed for the initial configuration to be alternating
*
******+*--*--**---*-***---*-**-**-*--*-*****--*****************************/

int changeCalc(long long num, int count)
{
  long long val1; //contains a number called value 1 for use in equations
  long long val2; //contains a number called value 2 for use in equations
  int bruh1; //contains a number representing the amount of changes in the first style of configuration
  int bruh2; //contains a number representing the amount of changes in the second style of configuration
  int i; //contains a value for use in the first for loop
  int j; //contains a value for use in the second for loop
  int returnVal; //contains the final value to be returned by the function

  val1 = 0;
  val2 = 0;
  bruh1 = 0;
  bruh2 = 0;

  for(i = 1; i <= count; i++)
  {
    if((i % 2) == 0) 
    {
      val1 += (0.1 * pow(10, i));
      val2 += (0.2 * pow(10, i));
    }
    else
    {
      val1 += (0.2 * pow(10, i));
      val2 += (0.1 * pow(10, i));
    }
  }

  for(j = 0; j < count; j++)
  {
    if((val1 % 10) != (num % 10))
    {
      bruh1 += 1;
    }
    else if((val2 % 10) != (num % 10))
    {
      bruh2 += 1;
    }
    num /= 10;
    val1 /= 10;
    val2 /= 10;
  }
  if(bruh1 > bruh2)
  {
    returnVal = (bruh2);
  }
  else
  {
    returnVal = (bruh1);
  }

  return (returnVal);
}

/*****+**----*--*----*------*****---**-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: counter
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. long long coni // contains the initial configuration of 1s and 2s
 *
 *  Function Description: This will determine how many digits are present in the configuration
 *
 ******+**----*--*----*------*****---**-*****--*****************************/
int counter(long long coni)
{
  //INITIALIZATION
  int count; // contains the number of digits present in the configuration given

  //STATEMENTS
  count = 0;
  do
  {
    coni = coni / 10;
    count ++;
  }while(coni != 0);
  return(count);
}
/*****+*-----**-*-*-***-*-*--****---**-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: input
 *
 *  Function Return Type: int
 *
 *  Function Description: This function obtains the staring configuration
 *
 ******+*-----**-*-*-***-*-*--****---**-*****--*****************************/
long long input(void)
{
  //INITIALIZATION
  long long coni; //contains the input initial configuration
  int tf; //contains a value to indicate whether the configuration is valid with numbers used (1s or 2s)

  //STATEMENTS
  do
  {
    printf("\nEnter the initial configuration -> ");
    scanf("%lld", &coni);
    tf = checkcon(coni);
    if (tf == -1)
    {
      printf("\nError! Input must contain only digits 1 and 2!\n");
    }
  }while(tf == -1);
  return(coni);
}

/*****+*-**--**--****-*-***-*--**-*--*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: checkcon
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. long long coni // contains the initial configuration of the values
 *    2. int count // contains the number of digits in the configuration
 *
 *  Function Description: This function takes an initial configuration and the number
 *                        of digits in it, then checks if any value does is not a 1
 *                        or a 2, and finally returns a 0 or 1 to indicate if a value
 *                        is not a one or two (0) or if the configuration is acceptable
 *
 ******+*-**--**--****-*-***-*--**-*--*-*****--*****************************/
int checkcon(long long coni)
{
  //INITIALIZATION
  int val; // contains the current value being checked within the for loop
  int tf; // contains a 0 or 1 to determine if the configuration is valid or not

//STATEMENTS
  tf = 1;

  do
  {   
    val = (coni % 10);
    if ((val != 1) && (val != 2)) 
    {
      tf = -1;
    }
    coni = coni / 10;
  }while(coni != 0);
  return(tf);
}
