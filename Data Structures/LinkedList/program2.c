/*
Dylan Hall
Linked Lists:
Insertion, Deletion
Program 2
10/13/16

I've only been able to figure out how to insert the values into the first slot. So the list is in reverse order from input.
*/

#include<stdio.h>
#include<malloc.h>

struct node  
{
   int key, data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//Function to delete a node
struct node* delete(int key)
{
   struct node* current = head; // assign current to first node
   struct node* previous = NULL; // first nodes previous is null

   //navigate through list
   while(current->key != key){
	
      //if it is last node
      if(current->next == NULL){
         return NULL;
      }else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;             
      }
		
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   }else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}



//Function to print list
void printList()
{
   struct node *current = head;
	
   while(current != NULL)//start of list
   {        
      printf("%d ",current->data);
      current = current->next;
   }
   printf("\n");
}

void insert(int data)
{
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
   link->next = head;
   head = link;
}

int main(void)
{
   int value, num, n, i = 0, j =0;
   char ch, choice = 'y';
   printf("Please enter number of values to store: ");
   scanf("%d", &num);
   printf("Please enter %d numbers to fill the list.\n", num);
   j = num;
   while (i != num)
   {
      printf("Please enter value to insert to the first position in the list at node %d: ", j);
      scanf("%d", &value);
      insert(value);
      i++;
      j--;
   }
   printf("The list is as follows: ");
   printList();
   
   while(choice == 'Y' || choice == 'y')
   { 
      printf("\n\n");
      printf("Method:\t\tInsertion\t\tDeletion\t\tExit\n");
      printf("Input:\t\tI\t\t\tD\t\t\tX\n");
      printf("\nPlease enter selection for next step to take: ");
      scanf(" %c", &ch);
      
      switch(ch)
      {
         case 'I' : case 'i' : //Insert a node
            printf("You chose insertion.\n");
            break;
            
         case 'D' : case 'd' : //Delete a node
            printf("You chose deletion.\n");
            printf("Enter value to delete from list: ");
            scanf("%d", &n);
            delete(5);
            printList();
            break;
      
         case 'X' : case 'x' : //Exit program
            printf("You chose to exit the program... \n");
            return(0);
         
         default :
            printf("Invalid input.\n");
      }
      printf("Do you wish to perform another action? Enter an y, lower or upper case.");
      scanf(" %c", &choice);
   }   
   getchar();
}
