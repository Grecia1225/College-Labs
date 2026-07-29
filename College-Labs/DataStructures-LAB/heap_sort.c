#include<stdio.h>
int a[100],n;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void makeheap()
{
    int i,j;
    for(i=1;i<n;i++)
    {
        j=i;
        while(j>0&&a[j]>a[(j-1)/2])
        {
            swap(&a[j],&a[(j-1)/2]);
            j=(j-1)/2;
        }
    }
}
void heapsort()
{
    int size=n;
    while(n>1)
    {
        makeheap();
        swap(&a[0],&a[n-1]);
            n--;
    }
    n=size;
}
int main()
{
    int i;
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort();
    {
        printf("after sorting:\n");
        for(i=0;i<n;i++)
        {
            printf("%d",a[i]);
        }
    }
    return 0;
}
