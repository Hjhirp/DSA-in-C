/*
Design anagram game using array. Allow a user to
enter N primary words and store it in an array.
Generate a random number from the range 1 to N.
Based on the random number generated display
the string stored at that index of array and allow
user to enter its anagram. Compare whether an
anagram entered is correct or not and display
appropriate message.
[Given a word A and word B. B is said to be an
anagram of A if and only If the characters present
is B is same as characters present in A, irrespective
of sequence. For ex: “EARTH” == “HEART”]
*/
 
#include <stdio.h> 
#include <time.h> 
#include <string.h> 
int 
main () 
{ 
int i, x, num, num2, flag, count[26]={0}, count2[26]={0}; 
printf ("Enter number of words you wish to input:"); 
scanf ("%d", &num); 
char word[num][20]; 
char temp[20]; 
//to prevent skipping of first element in word[num] after enter. 
gets (word[0]); 
//loop to take word input. 
for (i = 0; i < num; i++) 
{ 
printf ("\nEnter word= "); 
gets (word[i]); 
} 
//to generate random number. 
srand (time (0)); 
num2 = rand () % num; 
puts (word[num2]); 
//to take anagram word input. 
printf ("Enter anagram of displayed word:-"); 
gets (temp); 
//loops to count each letter. 
for (i = 0;word[num2][i] != '\0'; i++) 
{ 
x = word[num2][i] - 'a'; 
count[x]++; 
} 
for (i = 0;temp[i] != '\0'; i++) 
{ 
x = temp[i] - 'a'; 
count2[x]++; 
} 
// comparing the frequency of characters 
for (i = 0; i < 26; i++) 
{ 
if (count[i] != count2[i]) 
{
    flag = 1; 
    break;
}
else 
flag=0; 
} 
//final output. 
if (flag == 0) 
printf ("its a anagram"); 
else 
printf ("it not a anagram"); 
return 0; 
}
/*
Enter number of words you wish to input:3

Enter word= Harshal

Enter word= hello

Enter word= world
world
Enter anagram of displayed word:-rowld
OUTPUT:-
its a anagram
*/
