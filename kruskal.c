#include<stdio.h>
void print();
int c[40][40],i,j,u,v,a,b,n,m,w;
int main()
{
    int min;
    int de=0,tc=0,parent[100]={0};
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the number of edges\n");
    scanf("%d",&m);
    for(i=0;i<=n;i++)
    {
        parent[i]=i;
        for(j=0;j<=n;j++)
        {
            c[i][j]=9999;
        }
    }
    print();
    for(i=1;i<=m;i++)
    {
        printf("Enter the connection\n");
        scanf("%d%d",&u,&v);
        printf("Enter the cost\n");
        scanf("%d",&w);
        c[u][v]=c[v][u]=w;
    }
    print();
    while(de<n-1)
    {
        min=9999;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(c[i][j]<min)
                {
                    min=c[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        while(parent[u]!=u)
        {
            u=parent[u];
        }
        while(parent[v]!=v)
        {
            v=parent[v];
        }
        if(u!=v)
        {
            printf("%d TO %d=%d\n",a,b,min);
            parent[v]=u;
            tc=tc+min;
            de++;
        }
        c[a][b]=c[b][a]=9999;
    }
    printf("MINIMUM COST=%d\n",tc);
    return 0;
}

void print() //To Avoid Repeating the code of to print matrix, when function called it will print.
{
    printf("MATRIX IS \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}

/*
1)
Enter the number of nodes
9
Enter the number of edges
14
MATRIX IS
9999    9999    9999    9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
Enter the connection
0 1
Enter the cost
8
Enter the connection
0 7
Enter the cost
16
Enter the connection
1 2
Enter the cost
16
Enter the connection
1 7
Enter the cost
22
Enter the connection
2 8
Enter the cost
4
Enter the connection
2 5
Enter the cost
8
Enter the connection
2 3
Enter the cost
14
Enter the connection
3 4
Enter the cost
18
Enter the connection
3 5
Enter the cost
28
Enter the connection
4 5
Enter the cost
20
Enter the connection
5 6
Enter the cost
4
Enter the connection
6 8
Enter the cost
12
Enter the connection
6 7
Enter the cost
2
Enter the connection
7 8
Enter the cost
14
MATRIX IS
9999    16      9999    9999    9999    9999    22      9999    9999
16      9999    14      9999    8       9999    9999    4       9999
9999    14      9999    18      28      9999    9999    9999    9999
9999    9999    18      9999    20      9999    9999    9999    9999
9999    8       28      20      9999    4       9999    9999    9999
9999    9999    9999    9999    4       9999    2       12      9999
22      9999    9999    9999    9999    2       9999    14      9999
9999    4       9999    9999    9999    12      14      9999    9999
9999    9999    9999    9999    9999    9999    9999    9999    9999
6 TO 7=2
2 TO 8=4
5 TO 6=4
0 TO 1=8
2 TO 5=8
2 TO 3=14
0 TO 7=16
3 TO 4=18
MINIMUM COST=74

Process returned 0 (0x0)   execution time : 107.211 s
Press any key to continue.



2)
Enter the number of nodes
4
Enter the number of edges
5
MATRIX IS
9999    9999    9999    9999
9999    9999    9999    9999
9999    9999    9999    9999
9999    9999    9999    9999
Enter the connection
1 2
Enter the cost
2
Enter the connection
2 4
Enter the cost
4
Enter the connection
4 3
Enter the cost
8
Enter the connection
4 1
Enter the cost
10
Enter the connection
3 1
Enter the cost
6
MATRIX IS
9999    2       6       10
2       9999    9999    4
6       9999    9999    8
10      4       8       9999
1 TO 2=2
2 TO 4=4
1 TO 3=6
MINIMUM COST=12

Process returned 0 (0x0)   execution time : 28.188 s
Press any key to continue.
*/
