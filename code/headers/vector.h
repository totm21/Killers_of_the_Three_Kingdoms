

#ifndef VECTOR
#define VECTOR



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"error_me.h"
#include"mark.h"

typedef struct VECTOR
{
    void * data;        //元素
    int type_size;      //单个类型长度
    int total_number_of_elements;   //总元素个数
    int current_number_of_elements; //当前元素个数
}vector;

//暂时只完成了类似栈的操作   主要是想做一个可以随机访问的东西    


//初始化vector  其中数量为len   单个数据长度为size  返回总长度
int vector_init(vector* vector_,int len,int size);

//扩容  若总长度不为0 则*2   若为0 则总长度扩为1  返回总长度
int vector_expand(vector* vector_);

//尾部插入新的数据   返回当前元素个数   
int vector_push_back(vector* vector_,void* data,bool (*copy_)(void* scoure,void* goal));

//尾部删除数据  返回删除后的数据数量  失败返回FAIL_CODE
int vector_pop(vector* vector_);

//按照下标访问具体数据 返回具体的数据指针   失败返回NULL
void* vector_get_index(vector* vector_,int index);


#endif
