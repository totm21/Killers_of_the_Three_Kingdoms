
#include "../headers/data_structure.h"

skill* skill_init(skill* skill_,char* describe,int effect)
{
    skill_->describe=(char*)malloc(sizeof(char)*(strlen(describe)+1));
    strcpy(skill_->describe,describe);
    skill_->effect=effect;
    return skill_;
}

bool skill_free_skill(skill* skill_)
{
    if(skill_==NULL)
    {
        write_error_log("skill_free_skill is skill_ NULL ",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        return false;
    }


    if(skill_->describe==NULL)
    {
        write_error_log("skill_free_skill is skill_ NULL ",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
    }
    else
    {
        free(skill_->describe);
        skill_->describe=NULL;
    }

    return true;

}

bool skill_free_void(void* skill_)
{
    return skill_free_skill((skill*)skill_);
}









hero* hero_init(hero* hero_,char* name,char HP,char nation,skill* skills,int number)
{
    hero_->name=(char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(hero_->name,name);
    hero_->HP=HP;
    hero_->nation=nation;
}


bool hero_free(hero* hero_)
{
    if(hero_==NULL)
    {
        write_error_log("hero_free hero is NULL \n",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
        return false;
    }


    if(hero_->name==NULL)
    {
        write_error_log("hero_free hero_->name is NULL \n",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
    }
    else
    {
        free(hero_->name);
        hero_->name=NULL;
    }


    if(hero_->vector_skill==NULL)
    {
        write_error_log("hero_free hero_->vector_skill is NULL \n",WARN_ERROR_ME,__LINE__,__FUNCTION__,__FILE__);
    }
    else
    {
        vector_free(hero_->vector_skill,skill_free_void);
        free(hero_->vector_skill);
        hero_->vector_skill=NULL;
    }


    return true;

}