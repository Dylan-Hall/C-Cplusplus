/*
Dylan Hall
Encrpytion and Decryption program
9/11/16
Prog. for Engineers

Use two functions;
encryption_func 
main

enmcryption func just preforms simple calculations and linear exchanges of data within arrays,
from strings (arrays of characters) to ints, and vice versa.
*/

#include <stdio.h>

//Encryption function
int encryption_func(char word[6], char new_word[6], int key)
{
   int i;
   
   //Displays and saves, then modifies the word from user input.
   printf("This is the un-modified ascii values of %s.\n", word);
   for(i = 0; i < 6; i++)
   {
      printf("%d ", word[i]);
      new_word[i] = word[i] - key; //Subtracts the key form the ascii values of each letter.
   }                               // Saves it into new char array (string)
   printf("\n");
   
   //Displays the new modified word. (Each ascii value minus the key)
   printf("This is the modified ascii values of %s.\n", word);
   for(i = 0; i < 6; i++)
   {
      printf("%d ", new_word[i]);
   }
   printf("\nYour new word: %s", new_word);
}
   
//Main Function
int main()
{
   //Variables
   char word[6],
        new_word[6];
   int key;
   
   //Prompt/Save/Display user input
   printf("Enter a word, 6 letters long & all uppercase: ");
   scanf("%s", word);
   printf("Now enter a cypher key as an integer, between 2 and 8: ");
   scanf("%d", &key);
   printf("Your word: %s   Your key: %d\n", word, key); 
   
   //function call to display changes
   encryption_func(word,new_word,key);
}
