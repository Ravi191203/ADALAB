#include<stdio.h>
        int a[10][10], n, m, cost, i, j, d[10], p[10], x, y;
        int src, u, vis[10] = {0}, temp, counting = 0, mini;
        
        void dij();
        
        int main()
        {
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
            for (i = 1; i <= m; i++)
            {
                printf("Enter the connection\n");
                scanf("%d %d", &x, &y);
                printf("Enter the cost\n");
                scanf("%d", &cost);
                a[x][y] = a[y][x] = cost;
            }
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf("%d\t", a[i][j]);
                }
                printf("\n");
            }
            printf("Enter the source\n");
            scanf("%d", &src);
            dij();
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
            while (counting < n - 1)
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
                        if (d[i] != temp)
                        {
                            p[i] = u;
                        }
                        d[i] = temp;
                    }
                }
                i = u;
                counting++;
                while (p[i] != -1)
                {
                    printf("%d<----", i);
                    i = p[i];
                }
                printf("%d=%d\n", src, mini);
            }
        }
