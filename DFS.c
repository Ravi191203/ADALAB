//DEPTH FIRST SEARCH
#include<stdio.h>
int dfs(int n,int cost[10][10],int u,int s[])
{
    int v;
    s[u]=1;
    for(v=0;v<n;v++){
        if((cost[u][v]==1) && (s[v]==0))
            dfs(n,cost,v,s);
    }
}

int main()
{
    int n,cost[10][10],s[10],i,j,connected,flag;
    printf("Enter the number of vertices");
    scanf("%d",&n);
    printf("Enter the Adjacency matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    connected=0;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++)
            s[i]=0;
        dfs(n,cost,j,s);
        flag=0;
        for(i=0;i<n;i++){
            if(s[i]==0)
               flag=1;
        }
            if(flag==0)
                connected=1;
        }
    if(connected==1)
        printf("Graph is Connected");
    else
        printf("Graph is not Connected");
    return 0;
}

/*
The program you provided checks whether a graph is connected or not.
To get output, you need to provide the following input:

1. Number of vertice (n):This is the total number of nodes in the graph.
Enter an integer value for this.
2. Adjacency matrix: This is a square matrix of size n x n, where each element (i, j) represents the presence of an edge between nodes i and j.
Enter 1 if there is an edge, and 0 if there is no edge.

Here's an example of how to provide input:

Enter the number of vertice: 4

Enter the Adjacency matrix :

1 0 1 0
0 1 1 1
1 1 0 1
0 1 1 0

This will result in the program checking if the graph with 4 vertice and the given adjacency matrix is connected.

------------------------------------------------------------------------------------------------------

Enter the number of vertice: 4

Enter the Adjacency matrix :

1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1

This code will output the following

Graph is not

As you can see, this graph is not connected because there is no path between node 0 and nodes 2 and 3.
*/

