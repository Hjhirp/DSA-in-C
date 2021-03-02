/*
Write a program to reverse a given string using
Stack.
*/


#include <stdio.h>
#include <string.h>
#define max 100

void push(char a);
void pop();
int top=0;
char stack[max];
int main()
{
    int i;
    char String[50];
    printf("Enter you String (Max Limit =50 characters):");
    gets(String);
    for(i=0;i<strlen(String);i++)
    {
        push(String[i]);
    }
    
        for(i=0;i<strlen(String);i++)
    {
        pop();
    }
    
    
    return 0;
}
void push(char a)
{
if(top<max)
{
 stack[top]=a;   
}
++top;
}
void pop()
{
    printf("%c",stack[--top]);
}
Input:- Enter you String (Max Limit =50 characters):Hello World

Output:- dlroW olleH
