/*
Dylan Hall
Program 6
Prog. for Engineers
10/24/16


Calculator
by: Sam Russel
*/

#include<stdio.h>
#include<math.h>
#define PI 3.14159    // defining a constant PI

//Prototypes
char menu_display();
double to_radius(double x);
double circle_area(double x);
double circle_parameter(double x);
double rec_area(double x, double y);
double rec_para(double x, double y);
double sqr_area(double x);
double sqr_para(double x);
double tri_area(double x, double y);
double hypotenuse(double x, double y);
double vol_cylinder(double x, double y);
void factorial(int z);

//Main Function
int main(void)
{
   char ch;
   double x = 0, y = 0;
   int z = 0, fact = 1;

   do
   {   
      ch = menu_display();
      switch(ch)
      {     
         case 'c': case 'C':
            printf("please enter diameter of circle:  ");
            scanf("%lf", &x);
            x = to_radius(x);    // changing diameter to radius
            printf("The area of the circle is: %.2lf\n", circle_area(x));           
            printf("The parameter of the circle is: %.2lf\n", circle_parameter(x));
            break;
      
         case 'r': case 'R':
            printf("please enter one side of the rectangle:  ");
            scanf("%lf", &x);
            printf("please enter the second side of the rectangle:  ");
            scanf("%lf", &y);
            printf("The area of the triangle is: %.2lf\n", rec_area(x, y));
            printf("The parameter of the triangle is: %.2lf\n", rec_para(x, y));
            break;
      
         case 's': case 'S':
            printf("please enter the side of the square:  ");
            scanf("%lf", &x);
            printf("The area of the square is: %.2lf\n", sqr_area(x));
            printf("The parameter of the square is: %.2lf\n", sqr_para(x));
            break;
      
         case 't': case 'T':
            printf("please enter one side of the triangle:  ");
            scanf("%lf", &x);
            printf("please enter the second side of the triangle:  ");
            scanf("%lf", &y);
            printf("The area of the triangle is: %.2lf\n",tri_area(x, y));
            break;
      
         case 'h': case 'H':
            printf("please enter one side of the triangle:  ");
            scanf("%lf", &x);
            printf("please enter the second side of the triangle:  ");
            scanf("%lf", &y);
            printf("The hypotenuse of the triangle is: %.2lf\n", hypotenuse(x, y));
            break;
      
         case 'd': case 'D':
            printf("please enter diameter of the cylinder base:  ");
            scanf("%lf", &x);
            x = to_radius(x);  
            printf("please enter height of the cylinder:  ");
            scanf("%lf", &y);
            printf("The volume of the cylinder is: %.2lf\n", vol_cylinder(x, y));
            break;
      
         case 'f': case 'F':
            printf("please enter number to get the factorial of:  ");
            scanf("%d", &z);
            factorial(z);          
            break;
      
         case 'x': case 'X':
            return 0;
      
         default:
            printf("Invalid input");
      }
   
   }while(1);
   return 0;
}

//Menu Display Function
char menu_display(){
   char ch;
   printf("\n\nplease choose from the following menu\n\n");
   printf("Choose              to                \n");
   printf("-----------------------------------------\n");
   printf("  c or C          circle calculations    \n");
   printf("  r or R          rectangle calculations \n");
   printf("  s or S          square calculations    \n");
   printf("  t or T          right triangle calculations       \n");
   printf("  h or H          hypotenuse of right triangle       \n");
   printf("  d or D          cylinder volume        \n");
   printf("  f or F          factorial              \n");
   printf("  x or X                 exit            \n");

   printf("Please enter menu choice: ");
   scanf(" %c", &ch);
   
   return ch;
}

//Conver to Radius Function
double to_radius(double x){
   x = x / 2;
   return x;
}

//Area of a Circle Function
double circle_area(double x){
   double y = 0;
   y = PI * x * x;
   return y;
}

//Parameter of a Circle Function
double circle_parameter(double x){
   double y = 0;
   y = 2 * PI * fabs(x);
   return y;
}

//Area of a Rectangle Function
double rec_area(double x, double y){
   double area = 0;
   area = fabs(x) * fabs(y);
   return area;
}

//Parameter of a Rectangle Function
double rec_para(double x, double y){
   double para = 2 * (fabs(x) + fabs(y));
   return para;
}

//Area of a Square Function
double sqr_area(double x){
   double area = x * x;
   return area;
}

//Parameter of a Square Function
double sqr_para(double x){
   double para = 4 * fabs(x);
   return para;
}

//Area of a Triangle Function
double tri_area(double x, double y){
   double area = 0.5 * fabs(x) * fabs(y);
   return area;
}

//Hypotenuse of a Triangle Function
double hypotenuse(double x, double y){
   double hypo = sqrt(x * x + y * y);
   return hypo;
}

//Volume of a Cylinder Function
double vol_cylinder(double x, double y){
   double volume = PI * x * x * fabs(y);
   return volume;
}

//Factorial Function
void factorial(int z){
   int fact = 1;
   if(z < 0)
      printf("cannot get factorial of negative number");
   else if(z == 0)
      printf("The factorial of 0 is 1");
   else
   {
      for( ;z > 1; z--)
         fact = fact * z;
            
      printf("The factorial is: %d", fact);
   }
}