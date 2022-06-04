#include<stdio.h>
#include<windows.h>
#include"../headers/error_me.h"
#include"../headers/vector.h"

//程序开始位置

bool co(void* a,void* b)
{
    (*(int *)b)=(*(int*)a);
    return true;
}

int main()
{
    //程序第一句 打开日志文件 此处位置不可更改
    creat_error_log();

    //此处为程序测试
    int arr[50];
    for(int i=0;i<50;i++)
    {
        arr[i]=i;
    }

    vector vec;
    vector_init(&vec,2,sizeof(int));
    for(int i=0;i<50;i++)
    {
        if(i<10)
        {
            vector_pop(&vec);
        }
        else
        {
            vector_push_back(&vec,arr+i,co);
        }
        
        
    }
    for(int i=0;i<vec.current_number_of_elements;i++)
    {
        printf("%d ",*(int*)vector_get_index(&vec,i));
    }
    printf("\n");
    printf("%d %d\n",vec.total_number_of_elements,vec.current_number_of_elements);


    //程序最后关闭日志文件
    close_error_log();
    system("pause");
    return 0;
}


