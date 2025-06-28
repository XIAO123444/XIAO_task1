#include "stdio.h"
#include "string.h"
#include "show.h"
int condition;
int up_down;//页面前移后移
int add;//加减


MENU_pagedef pidmenu;
void pidMenu_init()
{

}
int main()
{
    pidmenu.v_num=3;
    strcpy(pidmenu.V[0].name,"p");
    strcpy(pidmenu.V[1].name,"i");
    strcpy(pidmenu.V[2].name,"d");
    pidmenu.V[0].num=1;
    pidmenu.V[1].num=1;
    pidmenu.V[2].num=1;
    pidmenu.V[0].x=0;
    pidmenu.V[1].x=1;
    pidmenu.V[2].x=1;
    pidmenu.V[0].y=0;
    pidmenu.V[1].y=1;
    pidmenu.V[2].y=1;

    strcpy(pidmenu.page_name, "pid");
    show_page(pidmenu);    
    return 0;
}
