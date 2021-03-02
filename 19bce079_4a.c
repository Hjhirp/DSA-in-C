/*
Consider a linked list with N integers. Each node of
the list is numbered from ‘1’ to ‘N’. Write a program
to split the list into 4 lists, so that:
i) First list contains nodes numbered 1, 5, 9, 13,
_, _, _
ii) Second list contains nodes numbered 2, 6, 10,
14, _, _, _
iii) Third list contains nodes numbered 3, 7, 11, 15,
_, _, _
iv) And fourth list contains nodes numbered 4, 8,
12, 16, _, _, _
*/


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*node;
struct node *l1 = NULL;//4 list... tried for array but getting some error
struct node *l2 = NULL;
struct node *l3 = NULL;
struct node *l4 = NULL;

void createNodeList(int n)
{
    struct node *last, *tmp;
    int num, i;
    node = (struct node *)malloc(sizeof(struct node));
        num=1;
        node->data = num;
        node->next = NULL;
        tmp = node;
        // Creating n nodes and adding to linked list easy by using for loop direct in function..
        for(i=2; i<=n; i++)
        {
            last = (struct node *)malloc(sizeof(struct node));
            if(last == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                num=i;

                last->data = num;
                last->next = NULL;
                 tmp->next = last;
                tmp = tmp->next;
            }
        }
}

void display(struct node *head) {
   struct node *tmp = head;

   if(head == NULL)
    {
        printf(" List is empty.");
    }
   else
   while(tmp != NULL) {
      printf(" %d ->",tmp->data);
      tmp = tmp->next;
   }
}
void split_list() {
   // function to split into 4 parts
   struct node *link;//helps in linking
   struct node *current;//Acts as temporary node

   while(node != NULL) {
      link = (struct node*) malloc(sizeof(struct node));

      link->data = node->data;
      link->next = NULL;

      if(node->data % 4 == 0) {
         if(l1 == NULL) {
            l1 = link;
            node = node->next;
         } else {
            current = l1;
            while(current->next != NULL)
            current = current->next;
            current->next = link;
            node = node->next;

         }

      } else if(node->data%4 == 1){
         if(l2 == NULL) {
            l2 = link;
            node = node->next;
         } else {
            current = l2;
            while(current->next!=NULL)
            current = current->next;
            current->next = link;
            node = node->next;

         }
      }

      else if(node->data%4 == 2){
         if(l3 == NULL) {

            l3 = link;
            node = node->next;
         } else {
            current = l3;
            while(current->next!=NULL)
            current = current->next;
            current->next = link;
            node = node->next;

         }

      }

      else if(node->data%4 == 3){
         if(l4 == NULL) {
            l4 = link;
            node = node->next;
         } else {
            current = l4;
            while(current->next!=NULL)
            current = current->next;
            current->next = link;
            node = node->next;

         }


      }
   }
}
int main()
{
    int n;
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    split_list();
    printf("\n Data entered in the list : \n");
    display(node);
    printf("\n Data in the list 1: \n");
    display(l1);
        printf("\n Data in the list 2: \n");
    display(l2);
        printf("\n Data in the list 3: \n");
    display(l3);
        printf("\n Data in the list 4: \n");
    display(l4);
    return 0;
}

 //Input the number of nodes : 16

 /*Data entered in the list :
 List is empty.
 Data in the list 1:
 4 -> 8 -> 12 -> 16 ->
 Data in the list 2:
 1 -> 5 -> 9 -> 13 ->
 Data in the list 3:
 2 -> 6 -> 10 -> 14 ->
 Data in the list 4:
 3 -> 7 -> 11 -> 15 ->
*/


