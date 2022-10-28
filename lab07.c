/*****+****--*--**-*-----**----**---********--******************************
 *
 *  Lab #: 07
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: 
 *
 ******+****--*--**-*-----**----**---********--*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int blackjack(void);
int makeval(int);
void printcard(int);
void printsuit(int);

int main(void)
{
  //INITIALIZATION
  int seed; //contains value for the seed used with the srand command

  //STATEMENTS
  printf("Enter the seed value -> ");
  scanf("%d", &seed);
  srand(seed);
  blackjack();

  return(0);
}

/*****+*--*-**--*-*-***-*----*-**---********--******************************
 *
 *  Function Information
 *
 *  Name of Function: blackjack
 *
 *  Function Return Type: void
 *
 *  Function Description: After the rand seed is established, the blackjack function
 *                        is in charge of running the general game of blackjack and calling
 *                        other functions that help complete the print statements
 *
 ******+*--*-**--*-*-***-*----*-**---********--*****************************/

int blackjack(void)
{
  //INITIALIZATION
  int var1; //contains the first rand value
  int var2; //contains the second rand value
  int var3; //contains the third rand value
  int var4; //contains the fourth rand value
  int var5; //contains the fifth rand value
  int card1; //contains the first card's determining value
  int card2; //contains the second card's determining value
  int card3; //contains the third card's determining value
  int card4; //contains the fourth card's determining value 
  int card5; //contains the fifth card's determining value
  char val1; //contains the first card's actual value
  char val2; //contains the second card's actual value
  char val3; //contains the third card's actual value
  char val4; //contains the fourth card's actual value
  char val5; //contains the fifth card's actual value
  int total; // contains a value for the total of the current cards drawn
  int acecount; //counts the number of aces present in the cards drawn

  //STATEMENTS
  acecount = 0;
  var1 = rand();
  var2 = rand();
  var3 = rand();
  var4 = rand();
  var5 = rand();
  card1 = (var1 % 52) + 1;
  card2 = (var2 % 52) + 1;
  card3 = (var3 % 52) + 1;
  card4 = (var4 % 52) + 1;
  card5 = (var5 % 52) + 1;
  val1 = makeval(card1);
  val2 = makeval(card2);
  val3 = makeval(card3);
  val4 = makeval(card4); 
  val5 = makeval(card5);
  
  total = val1; // Begins set for first card
  acecount = acecount + (val1 > 10);
  printf("\nThe first card is #: %d (", card1);
  printcard(card1);
  printf(") Current score: %d\n", total);

  total += val2; // Begins set for second card
  acecount = acecount + (val2 > 10);
  printf("The second card is #: %d (", card2);
  printcard(card2);
  
  if (total > 21)
  {
    total -= 10;
    acecount -= 1;
  }
  printf(") Current score: %d\n", total);

  if (total == 21)
  {
    printf("\nDealer wins!\n");
  }
  else if (total >= 16)
  {
    printf("\nDealer holds.\n");
  }
  else
  {

    total += val3; // Begin set for third card
    acecount = acecount + (val3 > 10);
    printf("The third card is #: %d (", card3);
    printcard(card3);
    if (acecount > 0)
    {
      if (total > 21)
      {
        total -= 10;
        acecount -= 1;
      }
    }
    printf(") Current score: %d\n", total);
    if (total > 21)
    {
      printf("\nDealer busts.\n");      
    }
    else if (total == 21)
    {
      printf("\nDealer wins!\n");
    }
    else if ( total >= 16)
    {
      printf("\nDealer holds.\n");
    }
    else
    {  
      
      total += val4; // Begins set for fourth card
      acecount = acecount + (val4 > 10);
      printf("The fourth card is #: %d (", card4);
      printcard(card4);
      if (acecount > 0)
      {
        if (total > 21)
        {
          total -= 10;
          acecount -= 1;
        }
      }
      printf(") Current score: %d\n", total);
      if (total > 21)
      {
        printf("\nDealer busts.\n");
      }
      else if (total == 21)
      {
        printf("\nDealer wins!\n");
      }
      else if ( total >= 16)
      {
        printf("\nDealer holds.\n");
      }
      else
      {
        
        total += val5; // Begins set for fifth card
        acecount = acecount + (val5 > 10);
        printf("The fifth card is #: %d (", card5);
        printcard(card5);
        if (acecount > 0)
        {
          if (total > 21)
          {
            total -= 10;
            acecount -= 1;
          }
        }
        printf(") Current score: %d\n", total);

        if (total > 21)
        {  
          printf("\nDealer busts.\n");
        }
        else if (total == 21)
        {
          printf("\nDealer wins!\n");
        }
        else
        {
          printf("\nDealer holds.\n");
        }
      }
    }
  }

  return(0);
}

/*****+**---**--*----*--*----*-*--*-**-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: printcard
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int card // contains value for current card
 *
 *  Function Description: This function takes an input card value, then determines the face/number of the card
 *
 ******+**---**--*----*--*----*-*--*-**-*****--*****************************/
void printcard(int card)
{
  //INITIALIZATION
  int cardinsuit; // contains the value of the card 1-13 regardless of suit

  //STATEMENTS
  card -= 1;
  cardinsuit = (card % 13) + 1;

  switch(cardinsuit)
  {
    case 1: printf("Ace");
            break;
    case 2 ... 10: printf("%d", cardinsuit);
                   break;
    case 11: printf("Jack");
             break;
    case 12: printf("Queen");
             break;
    case 13: printf("King");
  }

  printsuit(card);
}

/*****+**----**------*--*----*-*--*-**-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: printsuit
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int card // contains value for current card
 *
 *  Function Description: This function takes an input value for a card and finds the associated suite for the card.
 *
 ******+**----**------*--*----*-*--*-**-*****--*****************************/
void printsuit(int card)
{
  //INITIALIZATION
  card += 1;

  //STATEMENTS
  switch(card)
  {
    case 1 ... 13: printf(" of Clubs");
                   break;
    case 14 ... 26: printf(" of Diamonds");
                    break;
    case 27 ... 39: printf(" of Hearts");
                    break;
    case 40 ... 52: printf(" of Spades");
                    break;
  }
}

/*****+*--*--*--*---***-*----*-**---********--******************************
 *
 *  Function Information
 *
 *  Name of Function: makeval
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int val // this is the input raw value of a card
 *
 *  Function Description: This function takes the identifier value for a card, then
 *  determines the numerical value associated with that card for scoring in blackjack
 *
 ******+*--*--*--*---***-*----*-**---********--****************************/
int makeval(int val)
{
  //INITIALIZATION
  int num; //contains value of associated card in blackjack

  //STATEMENTS
  val -= 1;
  num = (val % 13) + 1;

  if (num >= 11)
  {
    num = 10;
  }
  else if (num == 1)
  {
    num = 11;
  }

  return(num);
}

