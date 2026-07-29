#include<stdio.h>
void main()
{
    int size,i,j,temp,list[100];
    printf("enter the size of list:");
    scanf("%d",&size);
    printf("enter %d integer values:",size);
    for(i=0;i<size;i++)
    scanf("%d",&list[i]);
    //insertion sort logic
    for (i=1;i<size;i++)
    {
        temp=list[i];
        j=i-1;
        while(j >=0 && list[j]>temp)
        {
            list[j+1]=list[j];
            j=j-1;
        }
        list[j+1]=temp;
    }
    printf("list after sorting is:");
    for (i=0;i<size;i++)
    {
        printf("%d ",list[i]);
    }
}