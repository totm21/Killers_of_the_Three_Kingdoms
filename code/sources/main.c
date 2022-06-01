#include<stdio.h>
#include<windows.h>
#include"../headers/error_me.h"


//程序开始位置

int main()
{
    //此处为程序测试

    creat_error_log();


    char str[50];
    for(int i=0;i<5;i++)
    {
        scanf("%s",str);
        write_error_log(str,__LINE__,__FUNCTION__,__FILE__);
    }

    close_error_log();

 
    system("pause");
    return 0;
}


