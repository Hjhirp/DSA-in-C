/*
Write a program to obtain a spanning tree of a
connected undirected graph using appropriate data
structure.
*/



#include<stdio.h>

int main()
{

float x;
int a[10],i,j;
printf("enter data in array");
for(j=0;j<10;j++)
{
 
  scanf("%d",&a[j]);


}
printf("enter data which u want to search");
scanf("%d",&i);



int l,h,m;

l=0;
h=9;

 while(l<=h)
{

   m=(l+h)/2;

   
  
    if(i<a[m])  
    { 
    h=m-1;
    }
   
    else if(i>a[m])
     {
           l=m+1;
      }
    else
    {
      
        printf("successful search");
        if(i==a[h])
        {
                printf("\npossision of element is  %d ",&a[l]);
         }
 
         else if(i==a[l])
        {
                 printf("\npossision of element is  %d ",&a[l]);
        }
   
        else
        {

        printf("\npossision of element is  %d  ",&a[l]);
        } 
        return 0;
    }

}

printf("unsuccessful search");
return 0;

}
