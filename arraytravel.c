#include<stdio.h>
void display(int arr[],int n)
{
	int i;
    for(i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\n");
}
int insert(int arr[],int size,int elment,int index,int capacity)
{
    //insertion
    int i;
    if(size>=capacity)
    {
        return -1;
    }
    for(i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=elment;
    return 1;
}
void delete(int arr[],int size,int index)
{int i;
    for( i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
}
void main()
{
    int arr[100]={7,8,12,27,88};
    int size=5,element=45,index=3;
    display(arr,size);
    insert(arr,size,element,index,100);
    size+=1;
    display(arr,size);
    delete(arr,size,index);
    size-=1;
    display(arr,size);

}
