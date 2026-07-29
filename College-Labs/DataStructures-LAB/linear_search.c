#include<stdio.h>
int main()
{
    int a[100],i,n,x;
    printf("enter the number of elements:");
    scanf("%d",&n);
    printf("enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    pritf("enter the element u want to search:");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            printf("%d element is in array at %d position",x,i+1);
            break;
        }
        if(i==n)
        {
            printf("%d element is not in element");
        }
    }
    return 0;
}
