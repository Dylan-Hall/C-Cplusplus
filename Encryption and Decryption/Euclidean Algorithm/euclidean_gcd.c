#include <stdio.h>
#include <stdlib.h>

int greatestCommonDivisor(int m, int n) {
    if(m == 0 && n == 0)
        return -1;

    if(m < 0) m = -m;
    if(n < 0) n = -n;

    int r;
    while(n) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main(void)
{
    srand(time(NULL));
    int num1 =  rand() % 500,
        num2 =  rand() % 1250;
    int gcd = greatestCommonDivisor(num1, num2); 

    printf("The GCD of %d and %d is %d\n", num1, num2, gcd);

    
    return 0;
}