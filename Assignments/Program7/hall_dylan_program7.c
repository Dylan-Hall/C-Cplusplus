/*
Dylan Hall
Program 7
11/10/16
*/

#include <stdio.h>
#define max_smokers 8 //Assignment said max smokers per hotel at a time is 8

//Prototypes
void wipe(int rows, int cols, double array[][cols]);
void display_hotel(int rows, int cols, double hotel[][cols]);
void room(int rows, int cols,  double hotel[][cols]);
char menu();
void addReservations(int rows, int cols, double hotel[][cols],  int *num_reserves, int max_reserves, int *num_smokers, int *days_reserved);
int search(int rows, int cols, int id, double arr[][cols]);
int search2(int rows, int cols, int id, double arr[][6]);
void cancelReservation(int rows, int cols, double hotel[][cols]);
void retrieveReservation(int rows, int cols, double hotel[][cols]);

//Main Function
int main(void)
{
   //Variables
   int num_adults, num_reserves = 0, max_reserves = 0, rows, cols = 6, num_smokers = 0, days_reserved = 0;
   char ch;
   
   printf("Please enter number of rooms in the hotel: ");
   scanf("%d", &rows);     
   while(rows != 50 && rows != 100 && rows != 150 && rows != 200){ //Make sure user only enters a 50, 100, 150 or 200
      printf("\nInvalid hotel size. Please enter, 50, 100, 150 or 200.\nPlease enter number of rooms in the hotel: ");
      scanf("%d", &rows);           
   }
   max_reserves = rows;
       
   double hotel[rows][cols]; //Declare hotel 2d array   
   wipe(rows, cols, hotel); //wipe hotel array
   room(rows, cols, hotel); //assign room numbers
   
   while(1){
      ch = menu();
      switch(ch)
      {
         case 'a': case 'A': //Add Reservation
            addReservations(rows, cols, hotel, &num_reserves, max_reserves, &num_smokers, &days_reserved);           
            break;
            
         case 'c': case 'C': //Cancel Reservation
            cancelReservation(rows, cols, hotel);
            break;      
      
         case 'r': case 'R': //Retrieve Reservation Info
            retrieveReservation(rows, cols, hotel);
            break;
            
         case 't': case 'T': //Display All Reservations
            display_hotel(rows, cols, hotel);
            break;
      
         case 'x': case 'X': //Exit Program
            printf("\nYou chose to exit the program.\n");
            return 0;
            
         default:            //Default
            printf("\nInvalid input.\n");
            break;
      }
   }
}

//Wipe Array Function (double)
void wipe(int rows, int cols, double array[][cols]){
   int i, j;

   for(i = 0; i < rows; i++){
      for(j = 0; j < cols; j++){
         array[i][j] = 0;//Fills given array with 0's
      }
   }
}

//Display Hotel Layout Function (programmer usage)
void display_hotel(int rows, int cols, double hotel[][cols]){
   int i, j;
   printf("You chose to display the hotel layout and all reservations.\n\n");
   printf(" |--------------------------Hotel Information------------------------------|\n");
   printf(" |Room       |Customer   | Smoking   |  Days     | Adult     |  Room       |\n");
   printf(" |Number     |   Id      |yes(1)no(0)| Reserved  |Occupants  |  Price      |\n");
   printf(" |___________|___________|___________|___________|___________|_____________|\n");
   
   for(i = 0; i < rows; i++){
      for(j = 0; j < cols; j++){
         if(j < 5)
            printf(" |   %5.0lf  ", hotel[i][j]);
         else
            printf(" |   %8.2lf  ", hotel[i][j]);    
      }
      printf("|\n");
   }
   printf(" |___________|___________|___________|___________|___________|_____________|\n");
}

//Room Function (gives rooms their numbers)
void room(int rows, int cols,  double hotel[][cols]){
   int i,j;
   for(i = 0; i < rows; i++){
      hotel[i][0] = (i/50 +1) * 100 + (i % 50) + 1;     
   }
}

//Menu Return Function
char menu(){
   char ch;
   printf("\n\nMenu:\n\nA or a - Add Reservation\nC or c - Cancel Reservation\nR or r - Retrieve Reservation\nT or t - Display All Reservations\nX or x - to Exit Program\n");
   printf("\nPlease enter a option to perform: ");
   scanf(" %c", &ch);
   return ch;
}

//Add Reservation Function
void addReservations(int rows, int cols, double hotel[][cols], int *num_reserves, int max_reserves, int *num_smokers, int *days_reserved){
   int input, choice, found, i, j, id, inc = 0, n, num_adults;
   double tax = 0.1, rate;
   printf("\nYou chose to add a reservation.\n");
   if(*num_reserves < max_reserves){ //If current number of reserved rooms is less than the max number of reserves (max reserves = number of rooms)
      printf("Are you planning on smoking in your room? (1 for yes or 0 for no): ");
      scanf("%d", &input);
      while(input != 1 && input != 0){ //1 for smoker 0 for non-smoker
         printf("Are you planning on smoking in your room? (1 for yes or 0 for no): ");
         scanf("%d", &input);     
      }
      if(input == 1){ // if smoker
         while(1){
            if(*num_smokers == max_smokers){ //Check to see if the hotel has the max number of smokers
               printf("\n\nSorry, we have the total number of smokers allowed. Would you mind a non-smoking room? (1 yes/ 0 no)\n");
               scanf("%d", &choice);
               if(choice == 1){
                  input = 0;
                  break; 
               }             
               else{
                  printf("Well, we cannot accomidate your needs. It is hotel policy.\n");
                  continue;
               }
            }
            else{        
               *num_smokers = *num_smokers + 1; //increment number of smokers
               if(*num_smokers > 0)              //Just a quick display for number of smoking rooms left
                  printf("Total number of smoking rooms left: %d\n", (max_smokers - *num_smokers));  
                  
               break;   
            }   
         }
      }
      
      printf("Please enter the Customers Id: ");
      scanf("%d", &id);  
      printf("Please enter a rate for the rooms of your hotel: ");
      scanf("%lf", &rate);   
      printf("How many days are being reserved for this room? : ");
      scanf("%d", &*days_reserved);
      while(*days_reserved <=  0){ //Make sure the number entered is greater than zero. Assuming they dont want to book for less than a day
         printf("Sorry, you cannot book a room for zero days or a negative number of days. Obviously...");
         printf("How many days are being reserved for this room? : ");
         scanf("%d", &*days_reserved);
      }
      
      printf("How many adult occupants will be staying in the room? :");
      scanf("%d", &num_adults);
   
      for(i = *num_reserves; i < *num_reserves+1; i++){
         hotel[i][2] = input;
         hotel[i][3] = *days_reserved;
         hotel[i][4] = num_adults;
         hotel[i][5] = rate + (rate * tax);
      }  
      found = search(rows, cols, id, hotel);
   
      for(i = found; i < rows; i++){
      
         if(hotel[i][1] != 0){
            hotel[i+1][1] = id;
            break;
         }
         else{
            hotel[i][1] = id;
            break;
         }
      }
      inc = inc++;
      *num_reserves = *num_reserves + 1;
   }
   else // if number of reserves = max reserves, tell the customer we are fully booked
      printf("\n\nThe hotel is fully booked!\n");
      
   printf("\nTotal numbers of smoking rooms: %d\n", *num_smokers);

}

//Retreieve Reservation Function
void retrieveReservation(int rows, int cols, double hotel[][cols]){
   int id, found, i, j, inc = 0, numrooms = 0, daystotal = 0, roomnumbers[100] = {0};
   double roomtotal = 0;
   
   printf("You chose to retrieve the information of a reservation.\nPlease enter the Customer Id: ");
   scanf("%d", &id);
   found = search2(rows, cols, id, hotel);
   for(j = 0; j < rows ;j++){
      if(hotel[j][1] == id){
         roomtotal += hotel[j][5];
         daystotal += hotel[j][3];
         roomnumbers[j] = hotel[j][0];
         numrooms++;
         if(hotel[j][2] == 1)
            inc++;
      }      
   }
   printf("Reservations info for Customer id: %d, was retrieved.\n|--------------------Details--------------------|\n", id);
   printf("|Total Rooms Reserved: %-15d          |\n|Smoking Rooms Reserveed: %-15d       |\n|Total Days Reserved: %-15d           |\n|Total Price: %-15.2lf                   |\n", numrooms, inc, daystotal,  roomtotal);
   printf("|-----------------------------------------------|");
}

//Function to Cancel Reservation
void cancelReservation(int rows, int cols, double hotel[][cols]){
   int id, found, i, j;
   
   printf("You chose to cancel a reservation.\nPlease enter the Customer Id: ");
   scanf("%d", &id);
   for(i = 0; i < rows; i++){
      found = search2(rows, cols, id, hotel);
      for(j = found; j < found + 1 ;j++){
         hotel[j][1] = 0;
         hotel[j][2] = 0;
         hotel[j][3] = 0;
         hotel[j][4] = 0;
         hotel[j][5] = 0;
      }
   }
   printf("Reservations for Customer: %d, were canceled. Have a nice day.", id);
}

//Search for Zero
int search(int rows, int cols, int id, double arr[][6]){
   int i, j, found;
   for(i = 0; i < rows; i++){
      if(arr[i][1] == 0){
         found = i;
         break; 
      }                                            
   }
   return found;
}

//Search for Id not zero Function
int search2(int rows, int cols, int id, double arr[][6]){
   int i, j, found;
   for(i = 0; i < rows; i++){
      if(arr[i][1] == id){
         found = i;
         break; 
      }                                            
   }
   return found;
}
