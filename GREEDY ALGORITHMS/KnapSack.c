//PRIM'S
#include<stdio.h>
#include<stdlib.h>
int mat[20][20];
int n,e,i,j,u,v,weight,de=0,visit[20]={0},src,min,tc=0;
void print();
int main()
{
    printf("Enter the no.of vertice\n");
    scanf("%d",&n);
    printf("Enter the number of edges\n");
    scanf("%d",&e);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            mat[i][j]=9999;//Assigning Values of Whole matrix to 9999.
        }
    }
    print();
    for(i=1;i<=e;i++)
    {
        printf("Enter the connections %d\n",i);
        scanf("%d%d",&u,&v);
        printf("Enter the weight %d\n",i);
        scanf("%d",&weight);
        mat[u][v]=mat[v][u]=weight; //here instead of giving 16 times i/p reduced to 8 because u,v & v,u weight is same.
    }
    print();
    printf("enter the source\n");
    scanf("%d",&src);
    visit[src]=1; //firstly  v[1] as marked as 1 because to start the search in matrix.
    while(de<n-1) //How many times it have to draw the spanning like A to B.
    {
        min=9999;
        for(i=1;i<=n;i++)
        {
            if(visit[i]!=0) //if visited != 0 then it will search in matrix find the minimum and marked as 9999
            {
                for(j=1;j<=n;j++)
                {
                    if(mat[i][j]<min) //comparing from starting matrix value and minimum value
                    {
                        min=mat[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(visit[v]!=1) //checking visited or not
        {
            printf("%d TO %d = %d\n",u,v,min);
            de++;
            visit[v]=1; //if one time completed minimum value index V will marked as 1.
            tc=tc+min;
        }
        mat[u][v]=mat[v][u]=9999; //After finding the minimum both u,v and v,u value marked as 9999.
    }
    printf("Total Cost is %d\n",tc); //Total Cost of spanning tree
}
void print() //To Avoid Repeating the code of to print matrix, when function called it will print.
{
    printf("MATRIX IS \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}


/*Enter the no.of vertices
6
Enter the number of edges
8
MATRIX IS
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
9999    9999    9999    9999    9999    9999
Enter the connections 1
1 2
Enter the weight 1
70
Enter the connections 2
2 4
Enter the weight 2
90
Enter the connections 3
4 6
Enter the weight 3
400
Enter the connections 4
6 5
Enter the weight 4
170
Enter the connections 5
5 3
Enter the weight 5
190
Enter the connections 6
3 1
Enter the weight 6
50
Enter the connections 7
3 2
Enter the weight 7
150
Enter the connections 8
3 4
Enter the weight 8
70
MATRIX IS
9999    70      50      9999    9999    9999
70      9999    150     90      9999    9999
50      150     9999    70      190     9999
9999    90      70      9999    9999    400
9999    9999    190     9999    9999    170
9999    9999    9999    400     170     9999
enter the source
1
1 TO 3 = 50
1 TO 2 = 70
3 TO 4 = 70
3 TO 5 = 190
5 TO 6 = 170
Total Cost is 550

Process returned 0 (0x0)   execution time : 74.680 s
Press any key to continue.*/
