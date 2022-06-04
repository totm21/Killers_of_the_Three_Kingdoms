#include<stdio.h>
#include<windows.h>
#include"../headers/error_me.h"
#include"../headers/vector.h"

//程序开始位置


int main()
{
    //程序第一句 打开日志文件 此处位置不可更改
    creat_error_log();

    //此处为程序测试

    

    char str[50];
    for(int i=0;i<5;i++)
    {
        scanf("%s",str);
        write_error_log(str,__LINE__,__FUNCTION__,__FILE__);
    }


    //程序最后关闭日志文件
    close_error_log();
    system("pause");
    return 0;
}


