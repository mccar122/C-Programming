/*****+-********--*---*--**-***-***--***-***--******************************
 *
 *  Lab #: 12
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: This is an HOA's and Karens dream :)
 *
 ******+-********--*---*--**-***-***--***-***--*****************************/
#include <stdio.h>
#include <stdlib.h>

int getSeed();
int getSize();
void getData(int [], int);
void Mod9(int [], int);
void findInd(int [], int);
void printLoc(int [], int);

int main()
{
  int *data; //this is array 
  int seed = 0; //variable for seed value
  int setSize = 0; //variable for array size

  seed = getSeed();
  setSize = getSize();
  srand(seed);

  data = (int*)malloc(sizeof(int) * setSize);

  getData(data, setSize);
  Mod9(data, setSize);
  findInd(data, setSize);
  printLoc(data, setSize);

  return(0);
}
/*****+*--*-***------**---*-*****-*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: getSeed
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. void
 *    2. void
 *    3. void
 *
 *  Function Description: gets and checks seed
 *
 ******+*--*-***------**---*-*****-*--***-***--*****************************/

int getSeed()
{
  int seed = 0; //seed value 

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
/*****+**---***------**---*-*****-*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: getsize
 *
 *  Function Return Type: int 
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. na
 *    2.
 *    3.
 *
 *  Function Description: gets size of array
 *
 ******+**---***------**---*-*****-*--***-***--*****************************/

int getSize()
{
  int size = 0; //size variable

  do
  {
    printf("Enter desired data set size -> ");
    scanf("%d", &size);

    if (size <= 0)
    {
      printf("\nError! Positive values only!!\n\n");
    }

  } while(size <= 0);

  return(size);
}
/*****+**---***------**---*-*****-*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: getData
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int values[]
 *    2. int size
 *    3.
 *
 *  Function Description:
 *
 ******+**---***------**---*-*****-*--***-***--*****************************/

void getData(int values[], int Size)
{
  int i; //for loop variable

  for (i = 0; i < Size; i++)
  {
    values[i] = rand() % 1000;
  }
}
/*****+**---***------**---*-*****-*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: Mod9
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int vals[]
 *    2. int Size
 *    3.
 *
 *  Function Description: mods by 9
 *
 ******+**---***------**---*-*****-*--***-***--*****************************/

void Mod9(int vals[], int Size)
{
  int i; //for loop variable

  for (i = 0; i < Size; i++)
  {
    if (vals[i] % 9 == 0)
    {
      vals[i] %= 10;
    }
    else
    {
      vals[i] = -1;
    }
  }
}
/*****+**---***------**---*-*****-*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: findInd
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int vals[]
 *    2. int Size 
 *    3.
 *
 *  Function Description: finds 
 *
 ******+**---***------**---*-*****-*--***-***--*****************************/

void findInd(int vals[], int Size)
{
  int i; //for loop variable

  for(i = 0; i < Size; i++)
  {
    if(vals[i] != -1)
    {
      if (i + vals[i] <= Size)
      {
        vals[i + vals[i]] = 0;
      }

      if (i - vals[i] >= 0)
      {
        vals[i - vals[i]] = 0;
      }
    }
  }
}
/*****+*----***------**---*-*****-*--***-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: printLoc
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int vals[]
 *    2. int Size
 *    3.
 *
 *  Function Description: prints results
 *
 ******+*----***------**---*-*****-*--***-***--*****************************/

void printLoc(int vals[], int Size)
{
  int i; //for loop variable
  int none = 0; //extrenous circumstance check

  for(i = 0; i < Size; i++)
  {
    if (vals[i] == 0)
    {
      none++;
    }
  }

  if(none > 0)
  {
    printf("\nPossible locations:");
    for(i = 0; i < Size; i++)
    {
      if (vals[i] == 0)
      {
        printf(" %d", i);
      }
    }
  }
  else
  {
    printf("\nPossible locations: None");
  }
  printf("\n");
}
