#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    memcpy(arr,arr+1,sizeof(int)*9);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;

}