/*****+**-*-***---*-***------*-**-*--*-*-*-**-******************************
*
*  Homework #: 03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:  A manufacturing facility is evaluating their current
processes by which their primary commercial device is produced. Given the
percentage of defective units produced determine the probability that there
will R defective units from a sample size of N. In addition the program 
should calculate the probability that there will be no defective units from
that same sample
*
******+**-*-***---*-***------*-**-*--*-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>

double nonDU(double percentage, int total_sample);
double DU(double percentage, int total_sample, int DU_sample);
double factorial(double val);

int main(void)
{
  // Variable Definition Section
  double percentage; //Percent probability of the outcome
  int total_sample; //Total sample size
  double p_nodeffect; //Probability for 0 defects
  double p_deffect; //Probability  for defective products
  int DU_sample; //Sample size of defects
  
  // User Input Section
  printf("Enter percentage of defective units produced -> ");
  scanf("%lf", &percentage);
  printf("Enter number of units to sample -> ");
  scanf("%d", &total_sample);
  printf("Enter number of defective units in sample -> ");
  scanf("%d", &DU_sample);

  //Function Call Section
  p_nodeffect = nonDU(percentage, total_sample);
  p_deffect = DU(percentage, total_sample, DU_sample);
  
  //Outputted Results Section
  printf("\nAverage number of defective units: %.2f%%", percentage);
  printf("\nSelecting %d units with 0 being defective has a probability of: %.3f", total_sample,p_nodeffect);
  printf("\nSelecting %d units with %d being defective has a probability of: %.3f\n", total_sample, DU_sample, p_deffect);

  return(0);
}

/*****+**---**--*-*--**-*----***-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: factorial
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double val
*
*  Function Description: Finds the factorial of the value inputted
*
******+**---**--*-*--**-*----***-----*-*-*-**-*****************************/
double factorial(double val)
{
  double factorial = 0; //resulting factorial
  double f1 = 0; //sub operation 1
  double f2 = 0; //sub operation 2
  
  f1 = pow(val, val) * exp(-1 * val);
  f2 = sqrt((2 * val + (1.0 / 3.0)) * M_PI);
  factorial = f1 * f2;

  return (factorial);
}

/*****+*--*--*------***-*-*--*-**----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: nonDu
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double percentage
*    2. int total_sample
*    3. int 0
*
*  Function Description: This function takes 3 inputs and determines pro
*                        bability that the outcome will happen
*
******+*--*--*------***-*-*--*-**----*-*-*-**-*****************************/
double nonDU(double percentage, int total_sample)
{
  double prob = 0; //resulting probability
  double s_factorial = 0; //factorial for sample space
  double no_factorial = 0; //factorial for 0
  
  no_factorial = factorial(0);
  s_factorial = factorial(total_sample);

  prob = ((s_factorial) / ((no_factorial) * (s_factorial)) * pow((percentage / 100.00), 0) * pow((1 - (percentage / 100.00)), total_sample));
  return(prob);
}

/*****+*----**--*-*--**-*-*--*-**----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: DU
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double percentage
*    2. int total_sample
*    3. int DU_sample
*
*  Function Description: This function takes 3 inputs to determine
*                        the probability that the outcome will happen
*
******+*----**--*-*--**-*-*--*-**----*-*-*-**-*****************************/
double DU(double percentage, int total_sample, int DU_sample)
{
  double prob_deffect = 0; //Resulting Probability
  double s_factorial = 0; //factorial for sample space
  double d_factorial = 0; //factorial for defects
  double s_d_factorial = 0; //factorial for sample space - defects
  double sample_deffect = 0; //number of non defective units
  
  sample_deffect = total_sample - DU_sample;
  d_factorial = factorial(DU_sample);
  s_factorial = factorial(total_sample);
  s_d_factorial = factorial(sample_deffect);

  prob_deffect = ((s_factorial) / (d_factorial * s_d_factorial)) * pow((percentage / 100.00), DU_sample) * pow((1 - (percentage / 100.00)), sample_deffect);

  return(prob_deffect);
}

