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

    


    //程序最后关闭日志文件
    close_error_log();
    system("pause");
    return 0;
}


