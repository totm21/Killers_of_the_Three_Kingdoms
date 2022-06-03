

#ifndef VECTOR
#define VECTOR

typedef struct VECTOR
{
    void * data;        //元素
    int type_size;      //单个类型长度
    int total_number_of_elements;   //总元素个数
    int current_number_of_elements; //当前元素个数
    
}vector;





#endif
