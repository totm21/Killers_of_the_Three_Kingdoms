#include<stdio.h>
#include<windows.h>
#include"../headers/error_me.h"
#include"../headers/vector.h"
#include"../headers/data_structure.h"

//程序开始位置

bool copy_skill(void* a,void* b)
{
    skill* aa=(skill*)a;
    skill* bb=(skill*)b;
    bb->describe=aa->describe;
    bb->effect=aa->effect;
    
    return true;
}

bool print_(void* data,FILE* file)
{
    //printf("%d ",*((int*)data));
    skill* skill_=(skill*)data;
    printf("de : %s \neff : %d\n",skill_->describe,skill_->effect);
    return 0;
}
 


int main()
{
    //程序第一句 打开日志文件 此处位置不可更改
    creat_error_log();

    

    //此处为程序测试

    vector vec;
    vector_init(&vec,1,sizeof(skill));



    skill* ski=(skill*)malloc(sizeof(skill));
    skill_init(ski,"chengzhi",1);
    printf("%s\n",ski->describe);


    vector_push_back(&vec,(void*)ski,copy_skill);

    vector_print(&vec,NULL,print_);

    vector_free(&vec,skill_free_void);
    

    //程序最后关闭日志文件
    close_error_log();
    system("pause");
    return 0;
}


