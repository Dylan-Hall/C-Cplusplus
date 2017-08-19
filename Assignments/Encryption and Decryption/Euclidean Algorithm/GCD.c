//write a recursive function that returns the suum of the squares of the first n positive integers.
#include <stdio.h>
int main(void)
{
long sumsq (int n)
{
 if (n ==1)
   return 1;
 return sumsqr (n - 1) + n*N;
   
}
}

    
    
    
    
    /*
    Self attempt at Euclidean GCD
    int n = 23,
        m = 100,
        diff = 0;
      
     while( n != m)
     {
       if(n < m)
       {
         n = n - m;
       }
       else
       {
         m = m - n;
       }
   }
    
    Using mod in the case of subtraction, speeds the algorithm up.
    
    long gcd (lang a, long b)
       {
          if (a ==b)
             return b;             //basis
          
          else if (a , b)
             return gcd(a, b % a);   //recursion
             
          else
             return gcd(a % b, a); //recursion
    */
    
