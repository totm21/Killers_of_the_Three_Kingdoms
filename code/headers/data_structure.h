
#ifndef DATA_STRUCTURE
#define DATA_STRUCTURE
#include"vector.h"


//技能类型 
typedef struct SKILL
{
    char* describe;     //武将技能描述
    int effect;         //技能实际效果_标号    技能表  对应查找
}skill;





//武将类型
typedef struct HERO
{
    char name[12];          //名称
    char HP:4;              //血量
    char nation:4;          //国家
    vector* vector_skill;   //技能组
}hero;




#endif  
