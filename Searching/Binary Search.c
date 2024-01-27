//BINARY SEARCH
#include <stdio.h>
int binarySearch(int[],int,int,int);
int main()
{
	int c, n, search, array[100];
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter %d integers\n", n);
	for (c = 0; c < n; c++)
	{
		scanf("%d",&array[c]);
	}
	printf("Enter value to find\n");
	scanf("%d", &search);
	int p=binarySearch(array,0,n,search);
	if(p==-1)
        printf("Element not found\n");
    else
        printf("%d position element found\n",p);
    return 0;
}

//change the array & search type to your liking
int binarySearch(int array[], int first, int last,int search){
	last = last - 1;
	while (first <= last)
	{
		int middle = (first+last)/2;
		if (array[middle] < search)
		{
			first = middle + 1;
		}
		else if (array[middle] > search)
		{
			last = middle - 1;
		}
		else
		{
			return middle;
		}
	}

	return -1; //no match
}

/*
OUTPUT:
Enter number of elements
4
Enter 4 integers
1
5
8
9
Enter value to find
8
2 position element found

Process returned 0 (0x0)   execution time : 8.406 s
Press any key to continue.
*/
