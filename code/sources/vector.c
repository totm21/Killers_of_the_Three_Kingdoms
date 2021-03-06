#include"../headers/vector.h"



int vector_init(vector* vector_,int len,int size)
{
    vector_->data=malloc(len*size);
    vector_->current_number_of_elements=0;
    vector_->type_size=size;
    if(vector_->data==NULL)
    {
        //分配空间出现错误
        write_error_log("vector init malloc fail",ERROR_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        vector_->total_number_of_elements=0;
    }
    else
    {
        vector_->total_number_of_elements=len;
    }

    return vector_->total_number_of_elements;
}


int vector_expand(vector* vector_)
{
    if(vector_->total_number_of_elements==0)
    {
        //第一种   原内存分配失败   
        
        vector_->data=malloc(vector_->type_size);
        
        if(vector_->data!=NULL)
        {
            vector_->total_number_of_elements=1;
        }
        else
        {
            write_error_log("vector expand malloc fail ",ERROR_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        }
    }
    else
    {
        //第二种   原内存分配成功

        void* temporary=realloc(vector_->data,vector_->total_number_of_elements*vector_->type_size*2);
        
        if(temporary==NULL)
        {
            write_error_log("vector expand realloc fail ",ERROR_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        }
        else
        {
            if(vector_->data!=temporary)
            {
                vector_->data=temporary;
            }
            vector_->total_number_of_elements=vector_->total_number_of_elements*2;
        }
    }
    return vector_->total_number_of_elements;
}



int vector_expand_len(vector* vector_,int len)
{
    if(len<=vector_->total_number_of_elements)
    {
        write_error_log("vector expand_len malloc fail : Space is enough ",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
    }
    else
    {
        void* temporary=realloc(vector_->data,len*vector_->type_size);
        
        if(temporary==NULL)
        {
            write_error_log("vector expand_len realloc fail ",ERROR_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        }
        else
        {
            if(vector_->data!=temporary)
            {
                vector_->data=temporary;
            }
            vector_->total_number_of_elements=len;
        }
    }
}


int vector_push_back(vector* vector_,void* data,bool (*copy_)(void* scoure,void* goal))
{
    //内部空间不够  空间扩容
    if(vector_->total_number_of_elements==vector_->current_number_of_elements)
    {
        vector_expand(vector_);
        if(vector_->total_number_of_elements==vector_->current_number_of_elements)
        {
            write_error_log("vector push_back to expend fail ",ERROR_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
            return FAIL_CODE;
        }
    }


    //尝试压入容器
    if(copy_(data,vector_->data+(vector_->type_size*vector_->current_number_of_elements)))
    {
        vector_->current_number_of_elements++;
    }
    else
    {
        write_error_log("vector push_back to expend fail : copy_ mistake ",ERROR_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
    }
    
    return vector_->current_number_of_elements;
}


int vector_push_backs(vector*  vector_,void* data,int number,bool (*copy_)(void*score,void* goal))
{
     //内部空间不够  空间扩容
    if(vector_->total_number_of_elements<vector_->current_number_of_elements+number)
    {
        vector_expand_len(vector_,vector_->current_number_of_elements+number);
        if(vector_->total_number_of_elements==vector_->current_number_of_elements)
        {
            write_error_log("vector push_backs to expend fail ",ERROR_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
            return FAIL_CODE;
        }
    }
    for(int i=0;i<number;i++)
    {
        if(copy_(data+(vector_->type_size*i),vector_->data+(vector_->type_size*vector_->current_number_of_elements)))
        {
            vector_->current_number_of_elements++;
        }
        else
        {
            write_error_log("vector push_backs to expend fail : copy_ mistake ",ERROR_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        }

    }   

    return vector_->current_number_of_elements;
}


int vector_pop(vector* vector_)
{
    if(vector_->current_number_of_elements<1)
    {
        write_error_log("vector pop fail ",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        return FAIL_CODE;
    }

    return --vector_->current_number_of_elements;
}


void* vector_get_index(vector* vector_,int index)
{
    if(index>=vector_->current_number_of_elements)
    {
        write_error_log("vector get_index fail ",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        return NULL;
    }
    return vector_->data+(vector_->type_size*index);
}

void vector_print(vector* vector_,FILE* file,bool (*print_)(void* data,FILE* file))
{
    if(file==NULL)
    {
        printf("The type size of the vector is : %d \n",vector_->type_size);
        printf("The total space of the vector is : %d \n",vector_->total_number_of_elements);
        printf("The used space of the vector is : %d \n",vector_->current_number_of_elements);
    }
    else
    {
        fprintf(file,"The type size of the vector is : %d \n",vector_->type_size);
        fprintf(file,"The total space of the vector is : %d \n",vector_->total_number_of_elements);
        fprintf(file,"The used space of the vector is : %d \n",vector_->current_number_of_elements);
    }

    for(int i=0;i<vector_->current_number_of_elements;i++)
    {
        print_(vector_->data+(vector_->type_size*i),file);
    }
    
    if(file==NULL)
    {
        printf("\n");
    }
    else
    {
        fprintf(file,"\n");
    }

    return ;
}





void vector_free(vector* vector_,bool (*delete_)(void* data))
{
    if(vector_==NULL)
    {
        write_error_log("vector_free vector_ is NULL ",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        return ;
    }
    
    //data 释放策略
    if(vector_->data==NULL)
    {
        write_error_log("vector_free vector_->data is NULL ",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
    }
    else
    {
        if(delete_!=NULL)
        {
            for(int i=0;i<vector_->current_number_of_elements;i++)
            {
                delete_(vector_->data+(vector_->type_size*i));
            }
        }
        free(vector_->data);
        vector_->data=NULL;
    }
    return ;
}