//MERGE SORT
#include<stdio.h>
void divide(int arr[], int l1, int r1, int l2, int r2)
{
    int temp[10], i, j, k=0;

    i = l1;

    j = l2;



    while((i <= r1) && (j <= r2))

    {

        if (arr[i] < arr[j])

        {

            temp[k++] = arr[i++];

        }

        else

        {

            temp[k++] = arr[j++];

        }

    }

    while(i <= r1)

    {

        temp[k++] = arr[i++];

    }

    while(j <= r2)

    {

        temp[k++] = arr[j++];

    }





    for (i=l1, j=0; i<=r2; i++,j++)

    {

        arr[i] = temp[j];

    }

}



void conquer(int arr[], int left, int right)

{

    int mid;



    if (left < right)

    {

        mid = (left + right)/2;

        conquer(arr, left, mid);

        conquer(arr, mid+1, right);

        divide(arr, left, mid, mid+1, right);

    }

}



int main()

{

    int arr[10], i, size;



    printf("\n Enter the size of array : ");

    scanf("%d", &size);



    printf("\n Enter the array elements : ");

    for (i = 0; i<size; ++i)

    {

        scanf("%d", &arr[i]);

    }



    conquer(arr, 0, size-1);



    printf("\n After sorting...");

    for (i=0; i<size; ++i)

    {

        printf(" %d ", arr[i]);

    }

    printf("\n");

}



/*

OUTPUT :

 Enter the size of array : 5



 Enter the array elements : 1 5 2 8 3



 After sorting... 1  2  3  5  8
