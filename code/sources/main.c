#include<stdio.h>
#include<windows.h>
#include"../headers/error_me.h"
#include"../headers/vector.h"
#include"../headers/data_structure.h"

//程序开始位置

bool copy_int(void* a,void* b)
{
    (*(int *)b)=(*(int*)a);
    return true;
}

bool print_(void* data,FILE* file)
{
    printf("%d ",*((int*)data));
    return 0;
}


int main()
{
    //程序第一句 打开日志文件 此处位置不可更改
    creat_error_log();

    

    //此处为程序测试

    vector vec;
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    vector_init(&vec,1,sizeof(int));
    vector_push_back(&vec,(void*)arr,copy_int);
    vector_print(&vec,NULL,print_);
    

    /*
    for(int i=0;i<vec.current_number_of_elements;i++)
    {
        printf("%d ",*((int*)vector_get_index(&vec,i)));
    }
    printf("\n");
    */

    vector_push_backs(&vec,(void*)(arr+1),9,copy_int);
    vector_print(&vec,NULL,print_);
    
    /*
    for(int i=0;i<vec.current_number_of_elements;i++)
    {
        printf("%d ",*((int*)vector_get_index(&vec,i)));
    }
    */
    printf("\n");



    skill* ski=(skill*)malloc(sizeof(skill));
    skill_init(ski,"chengzhi",1);
    printf("%s\n",ski->describe);


    

    //程序最后关闭日志文件
    close_error_log();
    system("pause");
    return 0;
}


