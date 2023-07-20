#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

int maximum(int A[],int n)
{   int max=INT_MIN;
    for(int i=0; i<n;i++)
    {
        if(max<A[i])
        {
            max=A[i];
        }
    }
    return max;
}
void countsort(int * A,int n)
{

    int i,j;
   //find the maximum element in A;
   int max= maximum(A,n);
  // create the count array
   int *count =(int *)malloc((max+1)*sizeof(int));
   
   //intialize count array with 0
   for( i=0; i<max+1;i++)
   {
    count[i]=0;
   }
   // increment index with 1
   for( i=0;i<n;i++)
   {
    count[A[i]]=count[A[i]]+1;
   }

   i=0;  //counter for count array
   j=0; //counter for count array

   while(i<=max){
    if(count[i]>0)
    {
        A[j]=i;
        count[i]=count[i]-1;
        j++;
    }
    else{
        i++;
    }
   }

}

int main()
{
    int a[] = {1,4,3,2,5,7,9,8,10,2};
    int n = 10;
   print(a,n);
   countsort(a,n);
   print(a,n);
}