/*
Dylan Hall
Program 5
10/23/16
Prog. for Engineers

I know there are some funcitons, I just kept coming back and adding and changing everything.
So I had everything seperated perfectly with tabs, but when I transfer my code to different platforms, from my home computer to my laptop, and to the school computers,
the numbers of spaces a tab increments increased around 1 or reduced around 1 and just messed up my whole display. So, he told me just to use spaces.

Also, I have function and pointer implementation in this code mostly because I really enjoy programming and I don't like to stop when I finish. I had an extra day or two
to put more work in after the fact. So, I thought it would be fun and a good learning experiance. 
*/

//Includes and global constant values of column and row, array cant be larger than array[20][5]
#include <stdio.h>
#include <stdlib.h>
#define MAX_COL 5
#define MAX_ROW 20
const char name[MAX_COL][20] = {"Student Number", "Midterm 1 grade", "Midterm 2 grade", "Homework grade", "Final Exam grade"}; //Saves the names of each grade type

//Prototypes
void total_students(int addrow);
void display_menu(void);
void display_all(double arr[MAX_ROW][MAX_COL], int addrow);
void search(double arr[][5], int addrow, int *found, int *num, int ch);

//Main Function
int main(void)
{
   //Variables
   int i, j, n, temp, found = 0, num = 0, ch = 0, addrow = 0, addcol = 0;
   double arr[MAX_ROW][MAX_COL] = {0}, fingrade[MAX_ROW] = {0}, sum = 0, average = 0;   
   display_menu(); //display menu function call
   
   do{ //Do while 1 (true), exit when user inputs number 9 or a character (letter).
      printf("\nPlease enter option you wish to perform: ");
      if(scanf("%d", &ch) != 1){
         printf("You need to enter a number, not a letter or character.\n");
         return 0;
      }      
      switch(ch){
         case 1://Main part, adds students to the record
            if(addrow >= MAX_ROW){ // Can't have more than 20 students
               printf("Cannot go past a maximum of 20 total records. Please delete a record if you wish to add new ones.\n");
               break;
            }
            printf("You chose to add student information.\n\n");
            for(i = 0; i < MAX_COL; i++){
               printf("Please enter %s for the %d student: ", name[addcol], addrow+1 );
               scanf("%lf", &arr[addrow][addcol]);                      
               addcol++;           
            }  
            if(addcol = MAX_COL){
               addcol = 0;
               addrow++;
            }   
            for (i = 0; i < addrow; ++i){
               for (j = 1; j < MAX_COL; ++j){
                  sum = sum + arr[i][j];
               }
               fingrade[i] = (sum/4);
               sum = 0;
            }
            break;
                     
         case 2: //Displays a single students information.
            num = 0;
            printf("You chose to display a single student's information.\nPlease enter the %s you are wishing to display: ", name[0]);
            scanf("%d", &ch);
            search(arr, addrow, &found, &num, ch); //Searching for student info based on user input. Changes found and num 
                   
            if(found != 0){
               printf("\n%s: %d\n",name[0], (int)arr[num][0]);            
               for(j = 1; j < MAX_COL; j++)
                  printf("\n\n%s: %.2lf\n",name[j], arr[num][j]);
               printf("\n\nFinal Grade: %.2lf\n\n", fingrade[num]);       
               printf("\n\n");               
            } 
            else 
               printf("\nStudent Record not found.\n");                         
            break;
            
         case 3: //Displays the class average
            average = 0; sum = 0;
            printf("You chose to display the class average.\n");
            for(i = 0; i < addrow; i++){
               sum += fingrade[i];
            }
            if(sum == 0)
               printf("Student records are empty.");
            else{
               average = sum/addrow;
               printf("\nAverage: %.2lf\n", average);
            }
            break;
            
         case 4: //Display all the student information
            printf("\nYou chose to display all student information.\n\n\nClass Information:\nStudent:      Midterm 1:    Midterm 2:    Homework:     Final Exam:\n");
            display_all(arr, addrow);
            break;
            
         case 5: //A Quick addition to the menu, re-display the menu.
            printf("\nYou chose to display the menu again.\n\n");
            display_menu();
            break;
            
         case 7: //Remove a student
            printf("You chose to remove a student from the records.\n\nPlease enter the student information you wish to remove: ");
            scanf("%d", &ch);            
            search(arr, addrow, &found, &num, ch);
                                                
            if(found != 0){
               for(i = num; i < addrow; i++){
                  for(j = 0; j < 5; j++)
                     arr[i][j] = arr[i+1][j];
               }
               addrow--;                
               if(addrow == 0)
                  printf("\nRecords are empty.\n\n");
               else{
                  printf("\nStudent record was removed.\n");
                  printf("\n----------------------Updated Records----------------------\nClass Information:\nStudent:      Midterm 1:    Midterm 2:    Homework:     Final Exam:\n");
                  display_all(arr, addrow); 
               }
            }   
            else
               printf("\nStudent Record was not found.\n\n");     
                                            
            break;
            
         case 8: //Display total student count
            total_students(addrow);
            break;
            
         case 9: //Exit program
            printf("You chose to exit the program.");
            return 0;
      
         default: //Invalid menu option
            printf("Invalid option.\n");
            break;
      }
   }while(1);
}

//Display Menu Function
void display_menu(void){
   printf("------Student Record Modification Menu------\n____________________________________________\n|Method:                      |Input:      |\n--------------------------------------------\n");
   printf("|Add Student:                 |       1    |\n|Display Student:             |       2    |\n|Class Avergage:              |       3    |\n|Display All Student:         |       4    |\n");
   printf("|Display Menu:                |       5    |\n|Remove Record:               |       7    |\n|Record Total:                |       8    |\n|Exit Program:                |       9    |\n--------------------------------------------\n");
}

//Display All Students Function
void display_all(double arr[MAX_ROW][MAX_COL], int addrow){
   int i, j;
   for(i = 0; i < addrow; i++){
      printf("%-13d ", (int)arr[i][0]);            
      for(j = 1; j < 5; j++)
         printf("%-13.2lf ", arr[i][j]);        
      printf("\n\n");
   }
}

//Total Students Functions
void total_students(int addrow){
   int i, num = 0;
   for(i = 0; i < addrow; i++)
      num++;  
   if(num == 0)
      printf("Student record is empty.");
   else{
      printf("The student record count is: ");
      printf("%d\n", num);
   }
}

//Search for Student Function
void search(double arr[][5], int addrow, int *found, int *num, int ch){
   int n;
   for(n = 0; n < addrow; n++){
      if(ch == (int)arr[n][0]){
         *found = 1;
         *num = n;
         break; 
      }          
      else
         *found = 0;                          
   }  
}
