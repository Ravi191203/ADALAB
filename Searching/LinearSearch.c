//LINEAR SEARCH
#include <stdio.h>
int main()
{
	int array[100], search, c, n;
	printf("Enter number of elements in array\n");
	scanf("%d", &n);
	printf("Enter %d integer(s)\n", n);
	for (c = 0; c < n; c++)
	{
        	scanf("%d", &array[c]);
	}
	printf("Enter a number to search\n");
	scanf("%d", &search);
	for (c = 0; c < n; c++)
	{
		if (array[c] == search)
		{
			printf("%d is present at location %d.\n", search, c+1);//optional c+1 for getting started from [1] in array.
			break;
		}
	}
	if (c == n){
		printf("%d is n't present in the array.\n", search);
		return 0;
	}
}

/*
OUTPUT :
Enter number of elements in array
4
Enter 4 integer(s)
3
6
1
8
Enter a number to search
3
3 is present at location 1.

Process returned 0 (0x0)   execution time : 14.468 s
Press any key to continue.
*/
