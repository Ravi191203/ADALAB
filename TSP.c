//TSP
#include<stdio.h>
#define max 100
#define infinity 999
int TSP(int c[][max],int tour[],int start,int n);
int main()
{
    int i,j,n;
    int c[max][max];
    int tour[max];
    int cost;
    printf("How many cities to travel\n");
    scanf("%d",&n);
    printf("Enter the matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&c[i][j]);
        }
    }
        for(i=0;i<n;i++){
            tour[i]=i;
            cost=TSP(c,tour,0,n);
            printf("\n Minimum cost=%d\n",cost);
            for(i=0;i<n;i++){
                printf("%d",tour[i]+1);
                printf("1\n");
            }
        }
    }
int TSP(int c[][max],int tour[],int start,int n)
{
    int i,j,k;
    int temp[max];
    int mintour[max];
    int mincost;
    int cost;
    if(start==n-2)
        return c[tour[n-2]][tour[n-1]]+c[tour[n-1]][0];
    mincost=infinity;
    for(i=start+1;i<n;i++)
    {
        for(j=0;j<n;j++){
            temp[j]=tour[j];
            tour[start+1]=tour[i];
            temp[i]=tour[start+1];
        }
        if(c[tour[start]][tour[i]]+(cost=TSP(c,temp,start+1,n))<mincost)
        {
            mincost=c[tour[start]][tour[i]]+cost;
            for(k=0;k<n;k++)
                mintour[k]=temp[k];
        }
    }
    for(i=0;i<n;i++){
        tour[i]=mintour[i];
        return mincost;
    }
    return 0;
}
