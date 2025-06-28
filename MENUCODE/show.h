#ifndef SHOW_H__
#define SHOW_H__
#include"stdio.h"

typedef struct v
{
    char name[16];  //变量名字
    float num;      //变量值
    int x;          //在X轴上显示起点
    int y;          //在Y轴上显示起点
}v_def;
typedef struct MENU_page
{
    char page_name[12];
    int v_num;
    v_def V[10];
}MENU_pagedef;

void show_page(MENU_pagedef menu_page);

#endif