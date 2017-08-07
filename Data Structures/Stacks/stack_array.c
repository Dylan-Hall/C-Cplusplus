/*
Dylan Hall
Queue and Stacks
10/31/16
*/

#include <stdio.h>
#define MAXSIZE  15    
int stack[15];     
int top = -1;            

//Prototypes
int pop();
int push(int data);
int isEmpty();
int isFull();

//Main Function
int main(void)
{
   int i, num, size_t = 0;
   int stackarr[size_t];
   printf("Please enter size of stack: ");
   scanf("%d", &size_t);
   for(i = 0; i < size_t; i++){
      printf("Please enter value %d to push: ",i);
      scanf("%d", &num);
      push(num);
   }
  
   printf("Elements: \n");

   // print stack data 
   while(!isEmpty()) {
      int data = pop();
      printf("%d\t0x%x\n",data, &stackarr[i]);
      i++;
   }
}


//isEmpty Function (stacks)
int isEmpty(){
   if(top == -1)
      return 1;
   else
      return 0;
}

//isFull Function
int isFull(){
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

//Pop Function (stacks)
int pop() {
   int data;
	
   if(!isEmpty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   }
   else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

//Push Function (stacks)
int push(int data){
   if(!isFull()) {
      top = top + 1;   
      stack[top] = data;
   }
   else {
      printf("Could not insert data, Stack is full.\n");
   }
}
