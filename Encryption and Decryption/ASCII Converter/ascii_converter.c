#include <stdio.h>
int main() {
    char c;
    int x;
    printf("Enter a character: ");
    scanf("%c", &c);  
    printf("ASCII value of %c = %d\n", c, c);
    
    printf("Enter a integer: ");
    scanf("%d", &x);  
    printf("ASCII value of %d = %c", x, x);
   
   
    return 0;
}
