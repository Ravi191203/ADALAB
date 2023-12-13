//BREADTH FIRST SEARCH
#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f=0, r=-1;
void BFS(int v)
{
    for(i = 0; i < n; i++)
    {
        if(a[v][i] && !visited[i])
        {
            q[++r] = i;
            visited[q[f]]=1,BFS(q[f++]);
        }
    }
}
int main()
{
    int v;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        q[i]=0,visited[i]=0;
    }
    printf("enter the graph da  ta in matrix : \n");
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Starting Vertex : ");
    scanf("%d",&v);
    BFS(v);
    printf("The nodes which are reachable are \n");
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
            printf("%d is not visited\n",i);
        else
            printf("%d is visited\n",i);
    }
}
