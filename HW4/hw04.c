/*****+*----**--*----*--*-*-****--*--*******--******************************
*
*  Homework #: 04
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Given a date as integer, input in the format MMDDYYYY,
*                       display the number of days remaining in the current
*                       month and for the rest of the year.
*
******+*----**--*----*--*-*-****--*--*******--*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int YEAR(int MMDDYYYY); //function for find year
int MONTH(int MMDDYYYY); //function for month
int DAY(int MMDDYYYY); //find day of yr
int check_LY(int year); //checks if leap yr
int days_month(int month, int LY); //determines numbers of month
int numdaysleft(int day, int numdays); //number of days left in month
int numdaysleftyr(int LY, int day, int month, int daysleftinmonth); //number of days left in year

int main(void)
{

  //Variable Declaration Section
  int MMDDYYYY; //inputted date
  int year; //year
  int month; //month
  int day; //day
  int LY; //if leap year or not
  int daysleftinmonth; //days left in the month
  int numdays; //days in a month
  int daysleftinyr; //days left in a year
  
  //User-Input section
  printf("Enter a date in the form MMDDYYYY -> ");
  scanf(" %d", &MMDDYYYY);
  
  //Function call section
  year = YEAR(MMDDYYYY);
  month = MONTH(MMDDYYYY);
  day = DAY(MMDDYYYY);
  LY = check_LY(year);
  numdays = days_month(month, LY);
  daysleftinmonth = numdaysleft(day, numdays);
  daysleftinyr = numdaysleftyr(LY, day, month, daysleftinmonth);
  
  //Print Statement
  //printf("year: %d month %d day %d LY %d numdays %d daysleftinmonth %d daysleftinyr %d", year, month, day, LY, numdays, daysleftinmonth, daysleftinyr);
  if (daysleftinmonth < 0)
  {
    printf("\nError: Date entered is not valid!\n");
  }
  else if ((daysleftinmonth >= 0) && (daysleftinyr >= 0) && (month > 0) && (month < 13) && (31 >= day) && (day > 0))
  {
    printf("\nDays remaining in current month: %d\n", daysleftinmonth);
    printf("Days remaining in current year: %d\n", daysleftinyr);
  }
  else
  {
    printf("\nError: Date entered is not valid!\n");
  }

  return(0);

}
/*****+**-*--**------*--*-*-****--*--*******--******************************
*
*  Function Information
*
*  Name of Function: YEAR
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int MMDDYYYY
*    2.
*    3.
*
*  Function Description: This function will return the year of input
*
******+**-*--**------*--*-*-****--*--*******--*****************************/
int YEAR(int MMDDYYYY)
{

  int year; //year

  year = MMDDYYYY % 10000;

  return(year);

}

/*****+**----**------*--*-*-****--*--*******--******************************
*
*  Function Information
*
*  Name of Function: MONTH
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int MMDDYYYY
*    2.
*    3.
*
*  Function Description: This function will return the month of the input
*
******+**----**------*--*-*-****--*--*******--*****************************/
int MONTH(int MMDDYYYY)
{

  int month; //month

  month = (MMDDYYYY / 1000000);

  return(month);

}

/*****+**-*--*-------*--*-*-****--*--*******--******************************
*
*  Function Information
*
*  Name of Function: DAY
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int MMDDYYYY
*    2.
*    3.
*
*  Function Description: This function will return the day of the input
*
******+**-*--*-------*--*-*-****--*--*******--*****************************/
int DAY(MMDDYYYY)
{

  int day; //day
  int val; //intermediate place holder
  int val2; //another intermediate value

  val = (MMDDYYYY % 1000000);
  val2 = (MMDDYYYY % 10000);
  day = val - val2;
  day /= 10000;

  return(day);

}

/*****+**----*--*-*-***---*-****--*--*******--******************************
*
*  Function Information
*
*  Name of Function: check_LY
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int MMDDYYYY
*    2.
*    3.
*
*  Function Description: This function will check if it is a leap year
*
******+**----*--*-*-***---*-****--*--*******--*****************************/
int check_LY(year)
{

  int leap_year; //leap year variable
  
  if (year % 100 == 0)
  {
    leap_year = 0;
  }
  else if (year % 400 == 0)
  {
    leap_year = 1;
  }
  else if (year % 4 == 0)
  {
    leap_year = 1;
  }
  else
  {
    leap_year = 0;
  }

  return(leap_year);

}

/*****+*--*--*----*-***---*-****--*--*******--******************************
*
*  Function Information
*
*  Name of Function: days_month
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month
*    2. int year
*
*  Function Description: Finds days left in month
*
******+*--*--*----*-***---*-****--*--*******--*****************************/
int days_month(month, LY)
{
  
  int numdays; //number of days in months

  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
  {
    numdays = 31;
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11)
  {
    numdays = 30;
  }
  else if (month == 2 && LY == 1)
  {
    numdays = 29;
  }
  else
  {
    numdays = 28;
  }

  return(numdays);

}
/*****+**-*-**--*---**----*-****--*--*******--******************************
*
*  Function Information
*
*  Name of Function: numdaysleft
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int day
*    2. int month
*    3. int year
*
*  Function Description:
*
******+**-*-**--*---**----*-****--*--*******--*****************************/
int numdaysleft(day, numdays)
{
  
  int daysleftinmonth; // days left in month

  daysleftinmonth = numdays - day;

  return(daysleftinmonth);

}

/*****+*-----**-----**----*-****--*--*******--******************************
*
*  Function Information
*
*  Name of Function: numdaysleftyr
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int LY
*    2. int day
*    3. int month
*
*  Function Description:
*
******+*-----**-----**----*-****--*--*******--*****************************/
int numdaysleftyr(LY, day, month, daysleftinmonth)
{
  
  int daysleftinyr; //days left in year

  if (month == 1)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 31));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 31));
    }
  }
  if (month == 2)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 60));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 59));
    }
  }
  if (month == 3)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 91));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 90));
    }
  }
  if (month == 4)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 121));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 120));
    }
  }
  if (month == 5)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 152));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 151));
    }
  }
  if (month == 6)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 182));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 181));
    }
  }
  if (month == 7)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 213));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 212));
    }
  }
  if (month == 8)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 244));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 243));
    }
  }
  if (month == 9)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 274));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 273));
    }
  }
  if (month == 10)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 305));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 34));
    }
  }
  if (month == 11)
  {
    if (LY == 1)
    {
      daysleftinyr = (daysleftinmonth + (366 - 335));
    }
    else
    {
      daysleftinyr = (daysleftinmonth + (365 - 334));
    }
  }
  if (month == 12)
  {
    daysleftinyr = daysleftinmonth;
  }

  return(daysleftinyr);    

}
