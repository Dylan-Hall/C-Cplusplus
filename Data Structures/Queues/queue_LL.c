/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
   int data;
   struct NODE *next;
}node_t;

// Two glboal variables to store address of front and rear nodes. 
typedef node_t *NodePtr;
node_t *front = NULL, *rear = NULL;

// To Enqueue an integer
void Enqueue(int x) {
   NodePtr temp = (node_t*)malloc(sizeof(node_t));
   temp->data = x; 
   temp->next = NULL;
   if(front == NULL && rear == NULL){
      front = rear = temp;
      return;
   }
   rear->next = temp;
   rear = temp;
}

// To Dequeue an integer.
void Dequeue() {
   NodePtr temp = front;
   if(front == NULL) {
      printf("Queue is Empty\n");
      return;
   }
   if(front == rear) 
      front = rear = NULL;	
   else 
      front = front->next;
	
   free(temp);
}

int Front() {
   if(front == NULL) {
      printf("Queue is empty\n");
      return;
   }
   return front->data;
}

void Print() {
   NodePtr temp = front;
   while(temp != NULL) {
      printf("%d ",temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
   Enqueue(2); Print(); 
   Enqueue(4); Print();
   Enqueue(6); Print();
   Dequeue();  Print();
   Enqueue(8); Print();
   printf("Front Data: %d\tRear Data: %d", Front(), *rear);
}