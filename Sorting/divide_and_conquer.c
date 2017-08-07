/**
  * Divide  : Divide the n-element array into two n/2-element
  *           sub-arrays
  * Conquer : Sort the two sub-arrays recursively using
  *           merge sort
  * Combine : Merge the two sorted subsequences to form the
  *           sorted array
  **/

#include<stdio.h>

int main()
{
   int n, i, array[20];

   printf("Enter the size of array\n");  // input the elements
   scanf("%d", &n);
   printf("Enter the elements:");
   for(i = 0; i < n; i++)
      scanf("%d", &array[i]);

   sort(array, 0, n-1);  // sort the array

   printf("Sorted array:");  // print sorted array
   for(i = 0; i < n; i++)
      printf("%d", array[i]);

   return 0;
}

int sort(int array[], int low, int high)
{
   int mid;
   if(low < high)
   {
      mid=(low+high)/2;
      // Divide and Conquer
      sort(array, low, mid);
      sort(array, mid+1, high);
      // Combine
      merge(array, low, mid, high);
   }

   return 0;
}

int merge(int array[], int l, int m, int h)
{
   int array1[10], array2[10];  // Two temporary arrays to
   //hold the two arrays to be merged
   int n1, n2, i, j, k;
   n1 = m-l+1;
   n2 = h-m;

   for(i = 0; i < n1; i++)
      array1[i] = array[l+i];
   for(j = 0; j < n2; j++)
      array2[j]=array[m+j+1];

   array1[i]=9999;  // To mark the end of each temporary array
   array2[j]=9999;

   i=0;
   j=0;
   for(k = l; k <= h; k++) 
   { //process of combining two sorted arrays
      if(array1[i] <= array2[j])
         array[k] = array1[i++];
      else
         array[k] = array2[j++];
   }

   return 0;
}