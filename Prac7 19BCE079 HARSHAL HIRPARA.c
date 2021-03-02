/*
Write a program to implement phone book dictionary
using Binary Search Tree which provides following
operations: (a) add new entry in phone book, (b)
remove entry from phone book, (c) search phone
number (d) list all entries in ascending order of name
and (e) list all entries in descending order of name.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int max=20;
struct tnode{
int n;//number
char name[20];//name string
struct tnode *left,*right;
};

struct tnode *createnewnode(int num,char s[max])
{
struct tnode *temp = (struct tnode *)malloc(sizeof(struct tnode));
strcpy(temp->name,s);
temp->n = num;
temp->left= temp->right= NULL;
return temp;
}
struct tnode *insert(struct tnode *base,int num, char s[max])
{
if(base==NULL) return createnewnode(num,s);
if(strcmp(s,base->name)<0)
{
base->left=insert(base->left,num,s);
}
else if(strcmp(s,base->name)>0)
{
base->right=insert(base->right,num,s);
}
return base;
}

struct tnode * search(struct tnode* base, char s[max])
{
if(base!=NULL && strcmp(s,base->name)==0)
return base;

else if(strcmp(s,base->name)<0)
{
return search(base->left,s);
}
else if(strcmp(s,base->name)>0)
{
return search(base->right,s);
}
}


void display(struct tnode* base){
printf("Name= %s Number=%d\n",base->name,base->n);
}
void inorder(struct tnode* base)
{
if(base!=NULL)
{
inorder(base->left);
printf("Name= %s Number=%d\n",base->name,base->n);
inorder(base->right);
}
}
struct tnode * min(struct tnode* base)
{
    struct tnode* current = base;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct tnode *delete(struct tnode * base, char s[max])
{
if(base==NULL) return base;
if(strcmp(s,base->name)<0)
{
base->left=delete(base->left,s);
}
else if(strcmp(s,base->name)>0)
{
base->right=delete(base->right,s);
}
else{
if(base->left == NULL)
{
struct tnode* temp= base->right;
free(base);
return temp;
}
else if(base->right == NULL)
{
struct tnode* temp= base->left;
free(base);
return temp;
}
        struct tnode* temp = min(base->right);

       strcpy(base->name,temp->name);
       base->right = delete(base->right, temp->name);
}
return base;
}

void revinorder(struct tnode *root)
{
    if (root != NULL)
    {
        inorder(root->right);
        printf(" %s : %d\n", root->name,root->n);
        inorder(root->left);

    }
}

int main()
{
	int choice;
    char name[max];
    int number;
	struct tnode * root =NULL;
    while(1)
    {
        printf("\n");
        printf("1. Add new name \n");
        printf("2. Remove existing name,  \n");
        printf("3. To search a number for a name  \n");
        printf("4. To list all entries in ascending order \n");
        printf("5. To list all entries in descending order \n");
        printf("6. Exit phone book \n");
        printf("Enter your choice : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter name : ");
            scanf(" %s",&name);
            printf("Enter phone number : ");
            scanf("%d",&number);
            root = insert(root,number,name);
            break;

            case 2:
            printf("Enter name to remove : ");
            scanf(" %s",name);
            root = delete(root,name);
            break;

            case 3:
            printf("Enter name to search : ");
            scanf(" %s",name);
            root = search(root, name);
            printf("Contact of %s : %d\n",name,root->n);
            break;

            case 4:
            inorder(root);
            break;

            case 5:
           	revinorder(root);
            break;

            case 6:
            exit(1);

            default:
            printf("Enter valid choice : ");
        }
    }
}

/*
1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
1
Enter name : harshal
Enter phone number : 7016

1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
1
Enter name : raj
Enter phone number : 8929

1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
1
Enter name : ajay
Enter phone number : 67221

1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
1
Enter name : natukaka
Enter phone number : 77281

1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
2
Enter name to remove :
raj

1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
4
Name= ajay Number=67221
Name= harshal Number=7016
Name= natukaka Number=77281

1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
1
Enter name : hemanshi
Enter phone number : 324444

1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
5

Name= natukaka Number=77281
Name= hemanshi Number=324444
Name= harshal Number=7016
Name= ajay Number=67221

1. Add new name
2. Remove existing name,
3. To search a number for a name
4. To list all entries in ascending order
5. To list all entries in descending order
6. Exit phone book
Enter your choice :
6
*/