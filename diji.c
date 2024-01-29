#include <stdio.h>
#include <stdlib.h>
void print();
int n,m,i,j,u,v,cost,a[10][10],p[10],d[10],vis[10]={0},ne=0,src,minimum;
int main()
{
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    printf("Enter number of edges\n");
    scanf("%d",&m);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            a[i][j]=9999;
        }
    }
     for(i=0;i<m;i++)
     {
         printf("Enter the connection\n");
         scanf("%d%d",&u,&v);
         printf("Enter the cost\n");
         scanf("%d",&cost);
         a[u][v]=a[v][u]=cost;
     }
     print();
     dij();
}
void print()
{
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

   void dij()
   {
       printf("Enter the source\n");
       scanf("%d",&src);
        for(i=0;i<=n;i++)
        {
            p[i]=src;
            d[i]=a[src][i];
        }
        p[src]=-1;
        vis[src]=1;

        while(ne<n-1)
         {
           minimum=9999;
           for(i=0;i<=n;i++)
           {
               if(d[i]<minimum && vis[i]==0)
               {
                   minimum=d[i];
                   u=i;
               }
           }
           vis[u]=1;
           for(i=0;i<=n;i++)
           {
               if(vis[i]==0)
               {
                   if(d[i]>(d[u]+a[u][i]))
                   {
                       d[i]=d[u]+a[u][i];
                       p[i]=u;
                   }
               }

           }
           i=u;
           ne++;
           while(p[i]!=-1)
           {
               printf("%d<----",i);
               i=p[i];
           }
           printf("----%d=%d\n",src,minimum);

        }

}