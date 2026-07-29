#include<stdio.h>
int main()
{
    int a[30],i,n,x,low,high,mid,xloc=1;
    printf("enter number of elements in array\n");
    scanf("%d",&n);
    printf("enter %d elements:\n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the number u want to search:\n");
    scanf("%d",&x);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
        {
            xloc=mid;
            break;
        }
        else if(x<a[mid])
        high=mid-1;
        else 
        low=mid+1;
    }
    if(xloc==-1)
    printf("%d is not present in array",x);
    else
    printf("%d is present in location %d",x,xloc);
    return 0;
}