
#include "../headers/data_structure.h"

skill* skill_init(skill* skill_,char* describe,int effect)
{
    skill_->describe=(char*)malloc(sizeof(char)*(strlen(describe)+1));
    strcpy(skill_->describe,describe);
    skill_->effect=effect;
    return skill_;
}





hero* hero_init(hero* hero_,char* name,char HP,char nation,skill* skills,int number)
{
    hero_->name=(char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(hero_->name,name);
    hero_->HP=HP;
    hero_->nation=nation;
}
