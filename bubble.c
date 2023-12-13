//BUBBLE SORT
#include <stdio.h>
void bubble_sort(int a[], int n) {
   int i = 0, j = 0, tmp;
   for (i = 0; i < n; i++) {   // loop n times - 1 per element
       for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (a[j] > a[j + 1]) {  //swap if order is broken
               tmp = a[j];
               a[j] = a[j + 1];
               a[j + 1] = tmp;
           }
       }
   }
}
int main() {
 int a[100], n, i;
 printf("Enter number of elements in the array:\n");
 scanf("%d", &n);
 printf("Enter %d integers\n", n);
 for (i = 0; i < n; i++)
   scanf("%d", &a[i]);
 bubble_sort(a, n);
 printf("Printing the sorted array:\n");
 for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
 return 0;

 /*
 Enter number of elements in the array:
5
Enter 5 integers
4
8
2
9
1
Printing the sorted array:
1
2
4
8
9

Process returned 0 (0x0)   execution time : 10.524 s
Press any key to continue.
*/
