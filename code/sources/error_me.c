

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

bool write_error_log(char* str,int line,const char * function,char* file)
{
    if(fprintf(file_name_error_log,"%s %s %d : %s\n",file,function,line,str)<0)
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
