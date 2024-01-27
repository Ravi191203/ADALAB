#include<stdio.h>

int a[10][10], n, m, cost, i, j, d[10], p[10], x, y;
int src, u, vis[10] = {0}, temp, ne = 0, mini, key;

void dij();
void print();
int main()
{
    do{
        printf("Enter number of nodes\n");
        scanf("%d", &n);
        printf("Enter number of edges\n");
        scanf("%d", &m);
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                a[i][j] = 9999;
            }
        }
        print();
        for (i = 1; i <= m; i++)
        {
            printf("Enter the connection\n");
            scanf("%d %d", &x, &y);
            printf("Enter the cost\n");
            scanf("%d", &cost);
            a[x][y] = cost;
        }
        print();
        printf("Enter the source\n");
        scanf("%d", &src);
        dij();
        printf("Press 1 to retry\n");
        scanf("%d",&key);
    }while(key==1);
    return 0;
}

void dij()
{
    for (i = 0; i <= n; i++)
    {
        d[i] = a[src][i];
        p[i] = src;
    }
    p[src] = -1;
    vis[src] = 1;
    while (ne < n - 1)
    {
        mini = 9999;
        for (i = 0; i <= n; i++)
        {
            if (d[i] < mini && vis[i] == 0)
            {
                mini = d[i];
                u = i;
            }
        }
        vis[u] = 1;
        for (i = 0; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                temp = (d[i] < d[u] + a[u][i]) ? d[i] : d[u] + a[u][i];
                if (temp<d[i])
                {
                    p[i] = u;
                }
                d[i] = temp;
            }
        }
        i = u;
        ne++;
        while (p[i] != -1)
        {
            printf("%d<----", i);
            i = p[i];
        }
        printf("%d=%d\n", src, mini);
    }
}
void print()
//To Avoid Repeating the code of to print matrix, when function called it will print.
{
    printf("MATRIX IS \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

/*
Enter number of nodes
6
Enter number of edges
11
MATRIX IS
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
Enter the connection
0 1
Enter the cost
15
Enter the connection
0 2
Enter the cost
10
Enter the connection
0 4
Enter the cost
45
Enter the connection
1 2
Enter the cost
15
Enter the connection
1 4
Enter the cost
20
Enter the connection
2 0
Enter the cost
20
Enter the connection
2 3
Enter the cost
20
Enter the connection
3 1
Enter the cost
10
Enter the connection
3 4
Enter the cost
35
Enter the connection
4 3
Enter the cost
30
Enter the connection
5 3
Enter the cost
4
MATRIX IS
9999    15      9999    20      9999    9999
9999    9999    20      9999    9999    9999
10      9999    9999    35      9999    9999
9999    9999    30      9999    9999    9999
9999    9999    4       9999    9999    9999
9999    9999    9999    9999    9999    9999
Enter the source
5
3<----5=4
1<----3<----5=14
2<----1<----3<----5=29
4<----1<----3<----5=34
0<----2<----1<----3<----5=49

*/
