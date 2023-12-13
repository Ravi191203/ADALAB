//SELECTION SORT
#include<stdio.h>
int main()
{
    int n,i,j,a[20],min,temp=0;
    printf("Enter the Size\n");
    scanf("%d",&n);
    printf("Enter the Elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min])
            {
                min=j;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\n Sorted\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    printf("\n");
    return 0;
}

/*
OUTPUT :
Enter the Size
4
Enter the Elements
1
5
2
9

Sorted
1
2
5
9

*/
