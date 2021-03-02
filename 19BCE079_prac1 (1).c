/*
An organization has to maintain it employee’s
details. There is need of accessing details of
employees frequently. Taking this information into
consideration, use appropriate data structure to
implement system for providing functionality of
adding details of new employee, removing
employee’s detail from the system, listing all
employees’ details.
*/

#include <stdio.h> 
#include<string.h> 
struct employee 
{ 
char name[40]; 
char designation[60]; 
int id; 
int salary; 
}s[4]; 
int main() 
{ 
int i,j; 
int n,m,l=4; 
char temp[100]; 
//input 
for(i=0;i<4;i++) 
{ 
printf("\nEnter Name=\n"); 
scanf("%s",&s[i].name); 
printf("Enter designation=\n"); 
scanf("%s",&s[i].designation);
printf("Enter id=\n");
scanf("%d",&s[i].id); 
printf("Enter salary=\n");
scanf("%d",&s[i].salary); 
} 
//listing or output 
for(i=0;i<4;i++) 
{ 
printf("\nName=%s\n",s[i].name); 
printf("designation=%s\n",s[i].designation); 
printf("id=%d\n",s[i].id); 
printf("salary=%d\n",s[i].salary); 
} 
printf("enter user index no. to remove="); 
scanf("%d",&n); 
//removing 
if(n>=0&&n<=l) 
{ 
for(i=n;i<l;i++) 
{s[i]=s[i+1]; 
} 
l--; 
} 
//sorting with id 
for(i=0;i<l;i++) 
{ 
for(m=i+1;m<l;m++) 
{ 
if(s[i].id>s[m].id) 
{j=s[i].id; 
s[i].id=s[m].id; 
s[m].id=j; 
strcpy(temp,s[i].name); 
strcpy(s[i].name,s[m].name); 
strcpy(s[m].name,temp); 
strcpy(temp,s[i].designation); 
strcpy(s[i].designation,s[m].designation); 
strcpy(s[m].designation,temp);  
j=s[i].salary; 
s[i].salary=s[m].salary; 
s[m].salary=j; 
} 
} 
} 
printf("id in order:-\n"); 
for(i=0;i<l;i++) 
{ 
printf("Name=%s\n",s[i].name); 
printf("designation=%s\n",s[i].designation); 
printf("id=%d\n",s[i].id); 
printf("salary=%d\n",s[i].salary); 
} 
return 0; 
}

/*
INPUT:-
Enter Name=
a
Enter designation=
a
Enter id=
1
Enter salary=
1

Enter Name=
b
Enter designation=
b
Enter id=
2
Enter salary=
3

Enter Name=
c
Enter designation=
c
Enter id=
7
Enter salary=
7

Enter Name=
d
Enter designation=
d
Enter id=
4
Enter salary=
4
enter user index no. to remove=1
OUTPUT:-

Name=a
designation=a
id=1
salary=1

Name=b
designation=b
id=2
salary=3

Name=c
designation=c
id=7
salary=7

Name=d
designation=d
id=4
salary=4
id in order:-
Name=a
designation=a
id=1
salary=1
Name=d
designation=d
id=4
salary=4
Name=c
designation=c
id=7
salary=7
*/

