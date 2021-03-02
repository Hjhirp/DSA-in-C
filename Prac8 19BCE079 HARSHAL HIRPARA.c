//practical 8
//MST using prims algorithm


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int vertices;
int max=999;

void display(int parent[],int graph[vertices][vertices]);
int minimum(int key[], bool mstset[]);
void mst(int graph[vertices][vertices]);


void mst(int graph[vertices][vertices])
{
    int key[vertices];
    int parent[vertices];
    bool mstflag[vertices];

     for(int i=0;i<vertices;i++)
    {
        mstflag[i] = false;
        key[i] = max;
    }
    // mstflag as a flag for min path 
    // mstflag = false as default;
    key[0] = 0;
    parent[0] = -1;//setting root node of mst as first vertex
    //now check for min key
    for (int i = 0; i < vertices; i++)
    {
     int min= minimum(key,mstflag);
     mstflag[min]=true;   // sets position to true to avoid repeataion of same key in mst

     for (int j = 0; j < vertices; j++)
     {
         if (graph[i][j]< key[j] && graph[i][j]&& mstflag[j]==false)/*checks if graph position is non zero*/
         {
            key[j]=graph[i][j];
            parent[j]=i; // j's parent is set to be i
         }
     }
    }
    display(parent,graph);
}

int minimum(int key[vertices], bool mstflag[vertices])
{
    int min, m;
    min=max;
    for (int i = 0; i < vertices; i++)
    {
        if (key[i]<min && mstflag[i]==false)
        {
            min=key[vertices];// keeps min maximum and searchs for minimum key lesser than min
            m=i;
        }
    }
    return m;//finally returns position of min key between 2 vertices
}

void display(int parent[vertices],int graph[vertices][vertices])
{
    printf("\nEdges \t Wieght\n");
    for(int i=1;i<vertices;i++)       //i = 1 because 0 has no parent
    {
        printf("%d - %d \t %d\n",i,parent[i],graph[i][parent[i]]);
    }
}

void main()
{
    int edge;
    printf("Enter number of vertices: ");
    scanf("%d",&vertices);
    printf("Enter number of Edges: ");
    scanf("%d",&edge);

    int graph[vertices][vertices];

    int x,y,w,i,j;

    for(i=0;i<edge;i++)
        for (j = 0; j < vertices; j++)
        {
            graph[i][j]=0; // intiallizing all vertices to 0 for later sorting
        }

        for(i=0;i<edge;i++)
        {
            printf("Enter vertice 1: ");
            scanf("%d",&x);
            printf("Enter vertice 2: ");
            scanf("%d",&y);
            printf("Enter wieght of this edge: ");
            scanf("%d",&w);
            // linking two vertices with its wieght
            graph[x][y]=w;
            graph[y][x]=w;
        }

        mst(graph);
}

/*
Enter number of vertices: 5
Enter number of Edges: 8
Enter vertice 1: 0
Enter vertice 2: 1
Enter wieght of this edge: 2
Enter vertice 1: 1
Enter vertice 2: 2
Enter wieght of this edge: 3
Enter vertice 1: 0
Enter vertice 2: 2
Enter wieght of this edge: 3
Enter vertice 1: 0
Enter vertice 2: 4
Enter wieght of this edge: 5
Enter vertice 1: 1
Enter vertice 2: 3
Enter wieght of this edge: 2
Enter vertice 1: 1
Enter vertice 2: 4
Enter wieght of this edge: 3
Enter vertice 1: 2
Enter vertice 2: 3
Enter wieght of this edge: 3
Enter vertice 1: 4
Enter vertice 2: 2
Enter wieght of this edge: 1

Edges    Wieght
1 - 0    2
2 - 0    3
3 - 1    2
4 - 2    1
*/