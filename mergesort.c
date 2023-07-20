#include<stdio.h>
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid,int high)
{
  int i,j,k,B[high+1];
  i=low;
  j=mid+1;
  k=low;
  while(i<=mid && j<=high)
  {
    if(A[i]<A[j]){
        B[k]=A[i];
        i++;
        k++;
    }
    else{
        B[k]=A[j];
        j++;
        k++;
    }
  }
  while(i<=mid)
  {
    B[k]=A[i];
    k++;i++;
  }
  while(j<=high){
    B[k]=A[j];
    j++;k++;
  }
  for(i=low; i<=high;i++)
  {
    A[i]=B[i];
  }
}
void mergesort(int x[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(x,low,mid);
        mergesort(x,mid+1,high);
        merge(x,low,mid,high);

    }
}
void main()
{
    int a[] = {1,4,3,2,5,7,9,8,10,2};
    int n = 10;
   print(a,n);
   mergesort(a,0,n-1);
   print(a,n);
}