//ALTER TSP
#include<stdio.h>
int a[10][10],completed[10],n,cost=0;

void takeInput()
{
	int i,j;
	printf("Enter the number of cities: ");
	scanf("%d",&n);
	printf("Enter the Cost Matrix\n");
	for(i=0;i < n;i++)
	{
		printf("Enter Elements of Row: %d\n",i);
		for( j=0;j < n;j++)
			scanf("%d",&a[i][j]);
		completed[i]=0;
	}
	printf("The cost matrix is:\n");
	for( i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
			printf("\t%d",a[i][j]);
		printf("\n");
	}
}

void tsp(int city)
{
	int i,c,nc=999,min=999,kmin;
	completed[city]=1;
	printf("%d--->",city);
	c=city;
	for(i=0;i < n;i++)
	{
		if((a[c][i]!=0)&&(completed[i]==0))
			if(a[c][i]+a[i][c] < min)
			{
				min=a[i][0]+a[c][i];
				kmin=a[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=kmin;
	if(nc==999)
	{
		nc=0;
		printf("%d",nc);
		cost+=a[city][nc];
	return;
	}
	tsp(nc);
}

int main()
{
	takeInput();
	printf("The Path is:\n");
	tsp(0);
	printf("\nMinimum cost is %d\n ",cost);
	return 0;
}

/*
OUTPUT :
Enter the number of cities: 4
Enter the Cost Matrix
Enter Elements of Row: 0
0 16 11 6
Enter Elements of Row: 1
8 0 13 16
Enter Elements of Row: 2
4 7 0 9
Enter Elements of Row: 3
5 12 2 0
The cost matrix is:
        0       16      11      6
        8       0       13      16
        4       7       0       9
        5       12      2       0
The Path is:
0--->3--->2--->1--->0
Minimum cost is 23

Process returned 0 (0x0)   execution time : 67.077 s
Press any key to continue.
*/
