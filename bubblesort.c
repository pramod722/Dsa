#include <stdio.h>

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

void bubblesort(int *a, int n) //non-adaptive
{
    int temp;

    for (int i = 0; i < n - 1; i++) // for number of passes
    {
         printf("pass=%d\n",i+1);
        print(a,n);
        for (int j = 0; j < n - 1 - i; j++) // for number of comparison
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void bubblesortadaptive(int *a, int n) //non-adaptive
{
    int temp;
    int issort=0;
    for (int i = 0; i <=n - 1; i++) // for number of passes
    {
        
         issort=1;
        printf("number of passes = %d\n",i);
        print(a,n);
        for (int j = 0; j <= n - 1 - i; j++) // for number of comparison
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issort=0;
            }
        }
        if(issort)
        {
            return;
        }
    }
}

void main()
{
    int a[] = {6, 4, 3, 5, 2, 1};
    int n = 6;
   
 //  bubblesort(a, n);
   
  bubblesortadaptive(a,n);
   
}