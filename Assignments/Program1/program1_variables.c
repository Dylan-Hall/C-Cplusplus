/*
Dylan Hall
Program 1
Encryption and Decryption 
in C
Using variables

This section is the way you asked to do it origionally,
just wanted to make sure I had it done both 
my way and the way you origionally asked for.

In my personal time im going to perfect this code to my own knowledge using arrays, such as the other code I sent you.
*/

#include <stdio.h>

//Main Function
int main(void)
{ 
   //Prompt header, and variables
   printf("This is a C program to encrypt and decrypt a password using variables.\n");
   char val1,val2,val3,val4,val5,val6; //reg-values of word
   int nval1,nval2,nval3,nval4,nval5,nval6, key, //modified values
   ctext1,ctext2,ctext3,ctext4,ctext5,ctext6,//cypher text words:modified
   rtext1,rtext2,rtext3,rtext4,rtext5,rtext6,
   salty1,salty2,salty3,salty4,salty5; //cypher text words: regular
   
   //User input for word and key, converts to ASCII
   printf("Please enter a six letter long word:");
   scanf("%c%c%c%c%c%c",&val1,&val2,&val3,&val4,&val5,&val6);
   printf("Your word is: %c%c%c%c%c%c\n",val1,val2,val3,val4,val5,val6);
   printf("ASCII values: %d %d %d %d %d %d\nNow enter a value for your key: ",val1,val2,val3,val4,val5,val6);
   scanf("%d", &key);
   
   //Saving modified values in new variables
   nval1 = val1 - key;
   nval2 = val2 - key;
   nval3 = val3 - key;
   nval4 = val4 - key;
   nval5 = val5 - key;
   nval6 = val6 - key;
   
   //Display new variables as ASCII and letters to show modifcations
   printf("Your new word is: %c%c%c%c%c%c\n",nval1,nval2,nval3,nval4,nval5,nval6);
   printf("Your new ASCII values are: %d %d %d %d %d %d\n",nval1,nval2,nval3,nval4,nval5,nval6);
   
   //Prompt for cypher text
   printf("Please enter your cypher text **Enter values as one digit then space.. ex: 62 63 64 65 etc(12 digits): "); //I couldn't figure out how to do it any other way.
   scanf("%d %d %d %d %d %d",&ctext1,&ctext2,&ctext3,&ctext4,&ctext5,&ctext6);
   printf("Cypher Text: %d%d%d%d%d%d\n",ctext1,ctext2,ctext3,ctext4,ctext5,ctext6);
   
   //Saving modified values in new variables
   rtext1 = ctext1 + key;
   rtext2 = ctext2 + key;
   rtext3 = ctext3 + key;
   rtext4 = ctext4 + key;
   rtext5 = ctext5 + key;
   rtext6 = ctext6 + key;
   
  //Display new variables as ASCII and letters to show modifcations
   printf("Your new word is: %c%c%c%c%c%c\n",rtext1,rtext2,rtext3,rtext4,rtext5,rtext6);
   printf("Your new ASCII values are: %d %d %d %d %d %d\n",rtext1,rtext2,rtext3,rtext4,rtext5,rtext6);
   
   salty1 = (rtext1 + ctext1) % 100;
   salty2 = (rtext2 + ctext2) % 100;
   salty3 = (rtext3 + ctext3) % 100;
   salty4 = (rtext4 + ctext4) % 100;
   salty5 = (rtext5 + ctext5) % 100;
   
    printf("Your new SALTED word is: %c%c%c%c%c%c%c%c%c%c%c\n",rtext1,salty1,rtext2,salty2,rtext3,salty3,rtext4,salty4,rtext5,salty5,rtext6);
   printf("Your new ASCII values are: %d%d%d%d%d%d%d%d%d%d%d\n",rtext1,salty1,rtext2,salty2,rtext3,salty3,rtext4,salty4,rtext5,salty5,rtext6);
   
   
   
   
   

   
   
   
   }
