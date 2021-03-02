/*
Write a program to convert fully parenthesized infix
expression to postfix expression.
*/


#include <stdio.h>
#include <string.h>
#define max 100
void push (char a);
char pop ();
int priority(char a);
int top=-1;
char stack[max];

int main ()
{
    char str[50],dis[50];
    int i,j=0;
    printf ("Enter you Expression :");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'||str[i]>='0'&&str[i]<='9')
        {
            dis[j]=str[i];
            printf("%c",dis[j]);
            j++;
        }
        else if (str[i] == '(')
        {
            push(str[i]); 
        }
         else if(str[i] == ')')
        {
            while((dis[j] = pop()) != '(')
                printf("%c", dis[j]);
        }
        else
        {
            while(priority(stack[top]) >= priority(str[i]))
                printf("%c",pop());
            push(str[i]);
        }
    }
     while(top != -1)
    {
        printf("%c",pop());
    }
}
int priority(char a)
{
    if(a == '(')
        return 0;
    if(a == '+' || a == '-')
        return 1;
    if(a == '*' || a == '/')
        return 2;
}

void push(char a)
{
    stack[++top] = a;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
Input
Enter you Expression :(a+b)-c*s
Output
ab+cs*-
