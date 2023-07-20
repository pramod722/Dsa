#include <stdio.h>

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

void insertionsort(int *a, int n)
{
    int key,j;

    for (int i = 1; i <= n - 1; i++) // for number of passes
    {
        printf("passes=%d\n",i);
        print(a,n);
        
        key=a[i];
        j=i-1;
        while (j>=0 && a[j]>key)
        {
           a[j+1]=a[j];
           j--;
        }
        a[j+1]=key;
        
    }
        
}

void selectionsort(int *a,int n)
{
    int indexMin,temp;
    for(int i=0; i<n-1;i++)
    {  
        printf("pass=%d\n",i+1);
        print(a,n);

        indexMin=i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<a[indexMin])
            {
                indexMin=j;
            }
        }
        //swap a[i ] and a[indexmin]

        temp=a[i];
        a[i]=a[indexMin];
        a[indexMin]=temp;
    }
}


void main()
{
    int a[] = {1, 4, 3, 5, 2, 6};
    int n = 6;
   print(a,n);
  // insertionsort(a,n);
  selectionsort(a,n);
   
}