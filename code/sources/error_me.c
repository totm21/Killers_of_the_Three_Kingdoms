

#include"../headers/error_me.h"


bool creat_error_log()
{
    file_name_error_log=fopen("log.txt","w");
    if(file_name_error_log==NULL)
    {
        perror("creat_error_log");
        return false;
    }
    return true;
}

bool write_error_log(char* str,char rank,int line,const char * function,char* file)
{
    //文件打开检测
    if(file_name_error_log==NULL)
    {
        creat_error_log();
    }
    
    char ranks[20];
    if(rank==ERROR_ERROR_ME)
    {
        strcpy(ranks,"error ");
    }
    else if(rank==WARN_ERROR_ME)
    {
        strcpy(ranks,"warn ");
    }


    if(fprintf(file_name_error_log,"%s  %s %s %d : %s\n",ranks,file,function,line,str)<0)
    {
        return false;
    }
    fflush(file_name_error_log);
    return true;
}

bool write_log_only_int_safety(int data)
{
    //文件打开检测
    if(file_name_error_log==NULL)
    {
        creat_error_log();
    }

    if(fprintf(file_name_error_log,"%d",data)<0)
    {
        return false;
    }
    fflush(file_name_error_log);
    return true;
}

bool write_log_only_char__safety(char* str)
{
    //文件打开检测
    if(file_name_error_log==NULL)
    {
        creat_error_log();
    }
    if(fprintf(file_name_error_log,"%s",str)<0)
    {
        return false;
    }
    fflush(file_name_error_log);
    return true;
}

bool write_log_only_char_safety(char char_)
{
    //文件打开检测
    if(file_name_error_log==NULL)
    {
        creat_error_log();
    }
    if(fprintf(file_name_error_log,"%c",char_)<0)
    {
        return false;
    }
    fflush(file_name_error_log);
    return true;
}


bool open_error_log()
{
    //文件打开检测
    if(file_name_error_log==NULL)
    {
        creat_error_log();
        return false;
    }
    return true;
}




bool write_log_only_int(int data)
{
    if(fprintf(file_name_error_log,"%d",data)<0)
    {
        return false;
    }
    fflush(file_name_error_log);
    return true;
}


bool write_log_only_char_(char* str)
{
    if(fprintf(file_name_error_log,"%s",str)<0)
    {
        return false;
    }
    fflush(file_name_error_log);
    return true;
}


bool write_log_only_char(char char_)
{
    if(fprintf(file_name_error_log,"%c",char_)<0)
    {
        return false;
    }
    fflush(file_name_error_log);
    return true;
}


bool close_error_log()
{
    if(fclose(file_name_error_log)==0)
    {
        return true;
    }
    return false;
}
