/*
Write a program to simulate printer spooler
application. Assume maximum 5 users are using
this printer. Use appropriate data structure to
implement the system.
*/


#include <stdio.h>
#define MAX 5
void printreq();
void currentjobprocessing();
void spool();
int queue[MAX];
int rear = - 1;
int front = - 1;

//main
int main()
{
int i=0,n;
while (i==0)
{
printf("\n1.Insert element to queue ");
printf("\n2.Display first element from queue ");
printf("\n3.Spool elements of queue ");
printf("\n4.Exit ");
printf("\nEnter your choice : ");
scanf("%d", &n);
switch(n)
{
case 1:
printreq();
break;
case 2:
currentjobprocessing();
break;
case 3:
spool();
break;
case 4:
i=1;
break;
default:
printf("Wrong choice ");
}
}
}

//enqueue
void printreq()
{
int i;
if(rear == MAX - 1)
printf("Queue Overflow \n");
else
{
if(front== - 1)
front = 0;
printf("\nInsert the element in queue : ");
scanf("%d", &i);
rear = rear + 1;
queue[rear] = i;
}
}

//dequeue
void currentjobprocessing()
{
if(front == - 1 || front > rear)
{
printf("Queue Underflow \n");
return;
}
else
{
printf("1st Element from queue is : %d\n", queue[front]);//deletion
for(int i = 0; i <= rear; i++)
{
    queue[i]=queue[i+1];
}
rear--;
}
}

//spooling or complete dequeue
void spool()
{
int i;
if(front == - 1)
printf("Queue is empty \n");
else
{
printf("Queue is : \n");
for(i = 0; i <= rear; i++)
printf("%d ", queue[i]);
printf("\n");
}
}