#include<stdio.h>
void main()
{
    int i,j,size,temp,list[20];
    printf("enter the size of the list:");
    scanf("%d",&size);
    printf("enter the values:");
    for(i=0;i<size;i++)
    scanf("%d",&list[i]);
    //selection sort logic
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(list[i]>list[j])
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }
    }
    printf("\nafter sorting:");
    for(i=0;i<size;i++)
        printf("%d",list[i]);
}
