

#ifndef ERROR_H
#define ERROR_H

#include<stdio.h>
#include<stdbool.h>



FILE* file_name_error_log;


//初始化log文件
bool creat_error_log();


//将str写入log
bool write_error_log(char* str,int line,const char* function,char* file);

/*
    __LINE__         当前语句所在的行号, 以10进制整数标注.
    __FUNCTION__     当前语句所在的函数名
    __FILE__         当前源文件的文件名, 以字符串常量标注.
    __DATE__         程序被编译的日期, 以"Mmm dd yyyy"格式的字符串标注.
    __TIME__         程序被编译的时间, 以"hh:mm:ss"格式的字符串标注, 该时间由asctime返回.
*/

//关闭log文件
bool close_error_log();




#endif