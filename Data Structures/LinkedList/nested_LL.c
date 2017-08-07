#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structures
typedef struct TOY{ //Toy Structure
   char name[50];
   struct TOY *next;
} Toy;
typedef Toy *ToyPtr; //Pointer Alias of type Toy

typedef struct CHILD{ //Child Structure
   char name[50];
   ToyPtr firsToy;
   struct CHILD *next;
} Child;
typedef Child *ChildPtr; //Pointer Alias of type Child

//Prototypes
void *chkMemory(size_t sz);
void addChild(ChildPtr *first);
void addToy(Child *first);
void display(ChildPtr currChild);

//Main Function
int main (void) 
{ 
   ChildPtr firsChild = NULL;

   addChild (&firsChild);
   addToy (firsChild);
   addChild (&firsChild);
   addChild (&firsChild);
   addToy (firsChild);
   addToy (firsChild);

   display (firsChild);
   printf("Finish.");
}

//Check Memory Function
void *chkMemory(size_t sz){
   void *node = malloc(sz);
   
   if (node == NULL) {
      printf ("Out of memory! Exiting.\n");
      exit (1);
   }
}

//Add Child Function
void addChild(ChildPtr *first){
   // Insert new item at start.
   
   ChildPtr new = chkMemory(sizeof(*new));
   printf("Please enter a child name: ");
   scanf("%s", &new->name);
   
   new->next = *first;
   *first = new;
}

//Add Toy to Child Function
void addToy(Child *first) {
   // Insert at start of list.
   ToyPtr new = chkMemory (sizeof (*new));
   printf("Please enter a toy for the first child: ");
   scanf("%s", &new->name);

   new->next = first->firsToy;
   first->firsToy = new;
}

//Display Info Function
void display(ChildPtr currChild){
   // For every child.

   while (currChild != NULL) {
      printf ("%s has:\n", currChild->name);
   
      // For every toy that child has.
   
      ToyPtr currToy = currChild->firsToy;
      if (currToy == NULL) {
         printf ("   <<nothing>>\n");
      } 
      else {
         while (currToy != NULL) {
            printf ("   %s\n", currToy->name);
            currToy = currToy->next;
         }
      }         
      currChild = currChild->next;
   }
}