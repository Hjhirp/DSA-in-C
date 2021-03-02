/*
Write a program to simulate music playlist
application using appropriate data structure.
There is no estimation about number of music files
to be managed by this application. It is expected
that user may add new music files or may remove
music files frequently. Your Program should
support following functionalities: (a) play next file
(b) play previous file, (c) play first file and (d) play
next file and (e) play specific file.
*/


#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
    struct node *prev;
}*newnode;
struct node *current;//for display only
struct node *head=NULL;
struct node *end=NULL;
void createNodeList()//creates list
{
    newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Music File:\n");
        scanf("%c",&newnode->data);
        scanf("%c",&newnode->data);
        if (head == NULL)
        {
        	head=newnode;
        	end=newnode;
        }
        else
        {
        	end->next=newnode;
        	newnode->prev=end;
        	end=newnode;
        }
}
void inbeg()//insert in beggining
{
		newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Music File\n");
        scanf("%c",&newnode->data);
        scanf("%c",&newnode->data);
        if (head == NULL)
        {
        	head=newnode;
        	end=newnode;
        }
        else
        {
        	head->prev=newnode;
        	newnode->next=head;
        	newnode->prev=NULL;
        	head=newnode;
        }
}
void inend()//insert in end
{
		newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Music File\n");
        scanf("%c",&newnode->data);
        scanf("%c",&newnode->data);
        if (end == NULL)
        {
        	head=newnode;
        	end=newnode;
        }
        else
        {
        	end->next=newnode;
        	newnode->prev=end;
        	newnode->next=NULL;
        	end=newnode;
        }
}
void inbet()//insert in between
{
		int n,i=1; 
		printf("Enter position\n");
        scanf("%d",&n);
    if(n<1)
        	printf("Invalid position\n");
    else if(n==1)
        	inbeg();
    else
    {
    	struct node *tmp;
    	tmp=head;
		newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Music File\n");
        scanf("%c",&newnode->data);
        scanf("%c",&newnode->data);
        while(i<n-1)
        {
        	tmp=tmp->next;
        	i++;
        }
        	newnode->prev=tmp;
        	newnode->next=tmp->next;
        	tmp->next=newnode;
        	newnode->next->prev=newnode;
    }
}

void outbeg()//detele from beggining
{
	struct node *tmp;
	tmp=head;
	if (head == NULL)
        {
        	printf("List empty\n");
        }
        else
        {
        	head=head->next;
        	head->prev=NULL;
           	tmp->next=NULL;
        	
        }
}
void outend()//detele from end
{
	struct node *tmp;
	tmp=end;
	if (end == NULL)
        {
        	printf("List empty\n");
        }
        else
        {
        	end=end->prev;
        	end->next=NULL;
           	tmp->prev=NULL;
        	
        }
}
void outbet()//detele from between
{
	int n; 
		printf("Enter position\n");
        scanf("%d",&n);
	struct node *tmp;
	tmp=head;
	int i=0;
		if (head == NULL)
        {
        	printf("List empty\n");
        }
        else
        {
        while(i<n-1)
        {
        	tmp=tmp->next;
        	i++;
        }
        	tmp->prev->next=tmp->next;
        	tmp->next->prev=tmp->prev;
        	
    }
        }

// play first file or last file
void display1(struct node *ptr) {
   struct node *tmp = ptr;
   current=ptr;
   if(ptr == NULL)
    {
        printf(" List is empty.");
    }
   else
      printf("%c\n",tmp->data);
}
//play next file or previous file 1 for next 0 for prev
void display2(int n) {
   struct node *tmp = current;
   if(current == NULL)
    {
        printf(" List is empty.");
    }
   else{

   	if(n==1)
    {  printf("%c\n",tmp->data);
	current=current->next;
}
else 
{  printf("%c\n",tmp->data);
	current=current->prev;
}
}
}
//print specific
void display3() {
	int n,i=0;
	printf("Enter the position from start\n");
    scanf("%d",&n);
   struct node *tmp = head;
   if(head == NULL)
    {
        printf(" List is empty.");
    }
   else{
  	while(i<n-1){
     tmp=tmp->next;
     i++;
   	}
   	printf("%c\n",tmp->data);
   }
}
void display()
{
	struct node *tmp = head;
   if(head == NULL)
    {
        printf(" List is empty.");
    }
   else{
   	while(tmp != NULL)
{
    printf("%c\n",tmp->data);
    tmp = tmp->next;
}
   }
}

int main()
{
    int n=1,m=1,p;
    printf("\t Welcome to Spotifi :: Your virtual playlist manager : \t\n");
    printf("\n");

    while(n!=0)
    {
   	printf("What would you like to do:\n\t1).Create a playlist.\n\t2).Add a song to your playlist.\n\t3).Play a song.\n\t4).Delete a song.\n\t5).exit and rate the app\n");
    scanf("%d",&n);
    	switch(n)
    	{
    		case 1:
    		createNodeList();
    		break;
    		case 2:
    		printf("Where do you want to insert the song:\n");
    		printf("\n\t1).Beginning\n\t2).Specific number\n\t3).End\n");
    		scanf("%d",&m);
    		if(m==1)
    			inbeg();
    		else if(m==2)
				inbet();
			else 
				inend();
			break;
			case 3:
			while(m!=0){
			printf("Which song you would like to listen:\n");
    		printf("\n\t1).From Start\n\t2).Specific song\n\t3).From End\n\t4).Play Next\n\t5).Play previous\n\t0).exit\n");
    		scanf("%d",&m);
    		if(m==1)
    			display1(head);
    		else if(m==2)
    			display3();
  
    		else if(m==3)
    			display1(end);
			else if(m==4)
				display2(1);
			else if(m==5)
				display2(0);
			else 
				m=0;
		}
			break;
			case 4:
			while(m!=0){
			printf("Which song you would like to remove:\n");
    		printf("\n\t1).From Start\n\t2).Specific song\n\t3).From End\n\t0).exit\n");
    		scanf("%d",&m);
    		if(m==1)
    			outbeg();
    		else if(m==2)
    			outbeg();
      		else if(m==3)
    			outend();
			else 
				m=0;
		}
			break;
			case 5:
			n=0;
			case 6:
			display();
			break;
			default :
			printf("Enter Valid Option\n");
    	}

    }

    return 0;
}
