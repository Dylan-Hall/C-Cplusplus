#include<stdio.h>

int main()
{
 int arr[30];
 int i,j,k,tmp,num;
 printf("Enter total no. of elements : ");
 scanf("%d", &num);
 for(k=0; k<num; k++)
 {
   printf("\nEnter %d number : ",k+1);
   scanf("%d",&arr[k]);
 }
 for(i=num/2; i>0; i=i/2)
 {
   for(j=i; j<num; j++)
   {
     for(k=j-i; k>=0; k=k-i)
     {
        if(arr[k+i]>=arr[k])
            break;
        else
        {
            tmp=arr[k];
            arr[k]=arr[k+i];
            arr[k+i]=tmp;
        }
     }
   }
 }
 printf("\t**** Shell Sorting ****\n");
 for(k=0; k<num; k++)
     printf("%d\t",arr[k]);
 
 return 0;
}
