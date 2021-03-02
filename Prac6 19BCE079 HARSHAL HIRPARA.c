/*
Write a program to construct binary tree from a given
preorder and postorder traversal sequence.
*/


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* leftchild;
    struct node* rightchild;
};
struct node* head=NULL;//points to root
struct node* temp=NULL;
struct node * createnewnode(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->leftchild=newnode->rightchild=NULL;
    return newnode;
}

struct node * createtree(int pre[], int post[], int* i,int start, int end, int size){//start , end required to make it recursive
    struct node* root = createnewnode(pre[*i]);
    ++*i;
    int j;
    
    if (start == end) 
    return root; 
    
    for(j=start;j<=end;j++)
    {
        if(pre[*i]==post[j])
            break;
    }
    
    if(j<=end)
    {
        root->leftchild = createtree (pre, post, i, start, j, size); 
        root->rightchild = createtree (pre, post, i, j + 1, end, size); 
    }

    return root;
}

 void display (struct node* node) 
{ 
    if (node == NULL) 
        return; 
    display(node->leftchild); 
    printf("%d ", node->data); 
    display(node->rightchild); 
} 

struct node *Tree (int pre[], int post[], int size) 
{ 
    int preIndex = 0; 
    return createtree (pre, post, &preIndex, 0, size - 1, size); 
} 

int main () 
{ 
    int i,size;
    printf("enter size of tree/No of elements in tree==> ");
    scanf("%d",&size);
    int pre[size],post[size];
    for(i=0;i<size;i++)
    {
        printf("Enter preorder elements ");
        scanf("%d",&pre[i]);
    } 
    for(i=0;i<size;i++)
    {
        printf("Enter postorder elements ");
        scanf("%d",&post[i]);
    }  
    struct node *root = Tree(pre, post ,size); 
    printf("Inorder traversal of the constructed tree: \n"); 
    display(root); 
  
    return 0; 
} 
 
/*

enter size of tree/No of elements in tree==> 5
Enter preorder elements 1
Enter preorder elements 2
Enter preorder elements 4
Enter preorder elements 5
Enter preorder elements 3
Enter postorder elements 4
Enter postorder elements 5
Enter postorder elements 2
Enter postorder elements 3
Enter postorder elements 1
Inorder traversal of the constructed tree: 
4 2 5 1 3 

*/
