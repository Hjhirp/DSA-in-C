/*
Write a program to perform addition of two
polynomial equations using linked list.
*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node* next;
};
struct node* startA=NULL,* startB=NULL,* sum=NULL;


struct node* createNodelist(struct node* head,int c,int e);
struct node* append(struct node* head,int c,int e);
struct node* add(struct node* startA1,struct node* startB1);
void display(struct node* head);

void main()
{
    int a,b,n,i;
    

    // Inputing the first polynomial..

    printf("Enter the no of terms of polynomial 1 = ");
    scanf("%d",&n);
    printf("\nEnter the polynomial");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient of the term = ");
        scanf("%d",&a);
        printf("\nEnter the exponent of the term = ");
        scanf("%d",&b);
        startA=createNodelist(startA,a,b);
    }

    // Inputing the second polynomial..

    printf("\nEnter the no of terms of polynomial 2 = ");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient of the term = ");
        scanf("%d",&a);
        printf("\nEnter the exponent of the term = ");
        scanf("%d",&b);
        startB=createNodelist(startB,a,b);
    }

    //Performing Addition..

    sum=add(startA,startB);

    //Displaying the polynomial..

    printf("\nThe polynomial 1 is..");
    display(startA);
    printf("\nThe polynomial 2 is..");
    display(startB);
    printf("\nThe sum of the two polynomials is..");
    display(sum);
}

struct node* append(struct node* head,int c,int e)/*it makes addition easier and 
                                                    also used this because was having sum list is empty
                                                    although code is same as inserting in new singly lisnked
                                                    list.*/
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(head==NULL){
    newnode->next=NULL;
    return newnode;
    }
    struct node* trav=head;
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=newnode;
    newnode->next=NULL;
    return head;
}

struct node* createNodelist(struct node* head,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(head==NULL){            // for inserting the first node..
        newnode->next=NULL;
        return newnode;
    }
    struct node* prev,* curr;
    prev=curr=head;
    while(curr!=NULL && curr->expo>e){//solves problem of sorting but add at beggining or end..
        prev=curr;
        curr=curr->next;
    }
    if(curr==head){            // for inserting before the first node...
        newnode->next=curr;
        return newnode;
    }
    else if(curr==NULL){        //for inserting after the last node....
        prev->next=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=curr;
        prev->next=newnode;
    }
    return head;
}

struct node* add(struct node* startA1,struct node* startB1)
{
    struct node* ans=NULL;
    struct node* t1,* t2;//term 1 term 2
    t1=startA1;
    t2=startB1;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo > t2->expo){
            ans=append(ans,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo){
            ans=append(ans,t2->coef,t2->expo);
            t2=t2->next;
        }
        else{
            ans=append(ans,(t1->coef)+(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
        }
    }

    while(t1!=NULL){            //coping the remaining terms of polynomial 1...
        ans=append(ans,t1->coef,t1->expo);
        t1=t1->next;
    }

    while(t2!=NULL){            //coping the remaining terms of polynomial 2...
        ans=append(ans,t2->coef,t2->expo);
        t2=t2->next;
    }
    return ans;
}

void display(struct node* head)
{
    struct node* temp=head;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
            printf(" %dx^%d +",temp->coef,temp->expo);
            temp=temp->next;
        }
       printf(" %dx^%d ",temp->coef,temp->expo);
    }
}

