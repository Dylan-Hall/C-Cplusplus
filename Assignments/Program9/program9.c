/*
Dylan Hall
Program 9

*/

#include <stdio.h>

typedef struct STRUCT{
   char name[20];
   int population;
   float area;
}new;

int main(void){

   char ch[50];
   int num_cities, sum_pop;
   double sum_area, avg_pop;
   size_t i, j = 0;
   FILE *in = NULL, *out = NULL;
   new city[20];
   
   printf("Please enter an input file: ");
   scanf("%s", ch);
   in = fopen(ch, "r");
      
   while(in == NULL){
      printf("Error opening file: %s.\n\n", ch);
      printf("Please enter an input file: ");
      scanf("%s", ch);
      in = fopen(ch, "r");
   }
   
   printf("\n\nFile: %s, was opened for reading.\n\n", ch);
   printf("|-----------File Validation-----------|\n");
   printf("|Name:           Pop:       Area:     |\n");
   printf("|-------------------------------------|\n");
   while(fscanf(in, "%s %d %f", city[j].name, &city[j].population, &city[j].area) == 3){ //or != EOF, checks if there is missing data
      printf("|%-15s %-10d %-10.2f|\n", city[j].name, city[j].population, city[j].area);
      num_cities++;
      j++;
   }
   fclose(in);
   printf("|-------------------------------------|\n");
   
   for(i = 0; i < num_cities; i++){
      sum_pop += city[i].population;
      sum_area += city[i].area;
   }
   avg_pop = sum_pop / sum_area;
   
   printf("|Total cities: %-15d        |\n|Total area: %-15.2lf          |\n|Total population: %-15d    |\n|Average Pop: %-15.0lf         |\n", num_cities, sum_area, sum_pop, avg_pop);
   printf("|-------------------------------------|\n\n\n");
   printf("Writing calulated values to a new text file.\n");
   
   printf("Enter the name of the output file: ");
   scanf("%s", ch);
   out = fopen(ch, "w");
   fprintf(out, "Total Cities: %d\nTotal Area: %.2lf\nTotal Population: %d\nAverage Population: %.0f\n", num_cities, sum_area, sum_pop, avg_pop);
   fclose(out);
}