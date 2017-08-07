/*
Dylan Hall
Encrpytion and Decryption program
9/11/16
Prog. for Engineers
Program 1b

Use two functions;
encryption_func 
decryption_func ****Make sure when entering cypher text to type in one value then press enter.*****
main

enmcryption/decryption func just preforms simple calculations and linear exchanges of data within arrays,
from strings (arrays of characters) to ints, and vice versa.

*/

#include <stdio.h>

//Encryption function
//===================================================================================
int encryption_func(char word[6], char new_word[6], int key)
{
   int i;
   
   //Prompt/Save/Display user input
   printf("ENCRYPTION SECTION\n");
   printf("Enter a word, 6 letters long & all uppercase: ");
   scanf("%s", word);
   printf("Now enter a cypher key as an integer, between 2 and 8: ");
   scanf("%d", &key);
   printf("Your word: %s   Your key: %d\n", word, key); 
   
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

//Decrypt Function
//=================================================================================
int decryption_func(int cyptext[6], int new_text[6], int key)
{
   int i;
   
   printf("\n\n\nDECRPYTION SECTION");
   printf("\nPlease enter cypher-text (12 digits): \n"); //Type one, then press enter. Such as, 62 *enter* 63 *enter* so on.
   for(i = 0; i < 6; i++)
   {
      scanf("%d", &cyptext[i]);
   }
   
   printf("Now enter a cypher key as an integer, between 2 and 8: "); //Re-prompts for key (didnt want to go to far into pointers)
   scanf("%d", &key);
   
   printf("Cypher text: "); //Displays the cypher text input by the use
   for(i = 0; i < 6; i++)
   {
      printf("%d ", cyptext[i]);
      new_text[i] = cyptext[i] + key; //Adds the key to each int in cypher and saves to new_text array
   }
   
   printf("\nDecrypted cypher text: ");  //Display decrypted cypher text. (Cypher text + key)
   for(i = 0; i < 6; i++)
   {      
      printf("%d ", new_text[i]);
   }
   
   printf("\nDecrypted word from cypher text: "); //Displays the word based off the cypher text
   for(i = 0; i < 6; i++)
   {      
      printf("%c", new_text[i]);
   }
}

//Main Function
//======================================================================================================
int main(void)
{
   //Variables
   char word[6], new_word[6];
   int key, i, cyptext[6], new_text[6];
            
   //function call to encryption function  
    encryption_func(word,new_word,key);
      
   //function call to decryption funcion
   decryption_func(cyptext,new_text,key);   
}
