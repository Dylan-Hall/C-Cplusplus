/*
Dylan Hall
Program 4
Intrest Calculator 
10/9/16
*/

#include<stdio.h>

//Main Function
int main(void)
{
   //Variables
   int quarter, i;
   char choice;
   double prin_bal, ann_rate, rate, new_bal;
   
   do{ //Repeats the whole program if user wants another calculation
      do{ //Repeats if user wishes to change input
         do{ //Principal Balance
            printf("\nPlease enter your Principal Balance greater than zero: ");
            scanf("%lf", &prin_bal);
            if(prin_bal <= 0)
               printf("\nPrincipal Balance must be greater than zero. Try again.\n");
         }while(prin_bal <= 0); //repeats if beginning balance is > 0
      
         do{ //Annual Intrest
            printf("Please enter your Annual Intrest rate than zero and less than 20%: ");
            scanf("%lf", &ann_rate);
            rate = (ann_rate/4)/100;
            if(ann_rate <= 0 || ann_rate > 20)
               printf("\nAnnual Intrest must be greater than zero and less than 20%. Try again.\n");
         }while(ann_rate <= 0 || ann_rate > 20); //repeats if the annual rate is smaller than 0 or larger than 20
      
         do{ //Quarters
            printf("Please enter number of Quarters to calculate for greater than zero and no more than 40: ");
            scanf("%d", &quarter);
            if(quarter <= 0 || quarter > 40)
               printf("\nQuarters must be greater than zero and less than 40. Try again.\n");
         }while(quarter <= 0 || quarter > 40);
         printf("You entered a Principal Balance of $%.2lf for %d Quarters at %%%.2lf intrest (%.2f quarterly).\nIs this corret? (y/n): ", prin_bal, quarter, ann_rate, (ann_rate/4));
         scanf(" %c", &choice);
         
      }while(choice == 'n' || choice == 'N'); //if user inputs n or N repeats prompts if user wants to change input
   
      printf("Quarter\t\t\tBeginning\t\t\tIntrest\t\t\tEnding\nNumber\t\t\tBalance\t\t\t\tEarned\t\t\tBalance\n");
      for(i = 1; i < quarter+1; i++){  //For loop itteration for number of quarters
         new_bal = (prin_bal * rate) + prin_bal;
         printf("%-15d%-18.2lf%-15.2lf%-18.2lf\n", i, prin_bal, (prin_bal*rate), new_bal);
         prin_bal = new_bal;
      }
      printf("\nDo you have another intrest calculation to perform? (y/n): ");
      scanf(" %c", &choice);
   }while(choice == 'y' || choice == 'Y'); //if user inputs y or Y program repeats for another calculation
}

