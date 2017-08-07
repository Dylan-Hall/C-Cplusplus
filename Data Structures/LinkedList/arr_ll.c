/*
Dylan Hall
Array of Linked Lists




   Node **array=(Node**)malloc(5*sizeof(Node*));

   for(i = 0; i < 5; i++)
      array[i]=(Node*)malloc(5*sizeof(Node));

   for(i = 0; i < 5; i++)
   {   
      for(j = 0;j < 5; j++)
      {
        array[i][j]= 0;
      }
   }
  
   
   
   
   
*/
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct NODE{
   int key;
   char data[5];
   struct NODE *next;
}Node;
typedef Node *NodePtr;

NodePtr NodesArr[5], temp, temp2, head;

void addNode(NodePtr *head, char *d);
void sDPrint();
void mDPrint();

int main(void)
{
   int i, j;
   char *word = "hello";
   temp = NodesArr[i];
   for(i = 0; i < 5; i++){
      addNode(&NodesArr[i],word);      
   }
   sDPrint();
 
   Node **arr = (Node **)malloc(2*sizeof(Node*));
   for (i = 0; i < 5; i++)
      arr[i] = (Node*)malloc(2*sizeof(Node));
 
   for (i = 0; i <  2; i++)
      for (j = 0; j < 2; j++)
         addNode(&arr[i][j], word);
}

void addNode(NodePtr *head, char *d){
   if((*head) == NULL)
      *head = malloc(sizeof(Node));
   else{
      while((*head)->next != NULL)
         *head = (*head)->next;
   
      (*head)->next = malloc(sizeof(Node));
      *head = (*head)->next;
   }
   
   strcpy((*head)->data,d);
   (*head)->next = NULL; 
}

void sDPrint(){
   int i;
   for(i=0 ; i < 5; i++){
      temp = NodesArr[i];
      while(temp != NULL){
         printf("%s\n",temp->data);
         temp = temp->next;
      }
   }
}
