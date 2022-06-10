

#ifndef ERROR_H
#define ERROR_H

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"mark.h"



FILE* file_name_error_log;


//初始化log文件
bool creat_error_log();


//将str 以及对应数据 写入log
bool write_error_log(char* str,char rank,int line,const char* function,char* file);

//将int写入log————安全版
bool write_log_only_int_safety(int data);

//将char*写入log————安全版
bool write_log_only_char__safety(char* str);

//将char写入————安全版
bool write_log_only_char_safety(char char_);


//文件打开检测  不存在则打开
bool open_error_log();



//将int写入log
bool write_log_only_int(int data);

//将char*写入log
bool write_log_only_char_(char* str);

//将char写入
bool write_log_only_char(char char_);

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