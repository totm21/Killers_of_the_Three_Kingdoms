
#ifndef DATA_STRUCTURE
#define DATA_STRUCTURE
#include"vector.h"
#include<string.h>


//技能类型 
typedef struct SKILL
{
    char* describe;     //武将技能描述
    int effect;         //技能实际效果_标号    技能表  对应查找
}skill;


//武将类型
typedef struct HERO
{
    char *name;             //名称
    char HP:5;              //血量
    char nation:3;          //国家
    vector* vector_skill;   //技能组
}hero;





//以下为skill 操作 函数


//skill初始化   
skill* skill_init(skill* skill_,char* describe,int effect);







//以下为hero 操作 函数


//hero初始化
hero* hero_init(hero* hero_,char* name,char HP,char nation,skill* skills,int number);





#endif  
