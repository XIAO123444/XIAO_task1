#include "stdio.h"
#include "stdlib.h"
int condition;
int up_down;//页面前移后移
int add;//加减
typedef struct v
{
    char name[16];  //变量名字
    float num;      //变量值
    int x;          //在X轴上显示起点
    int y;          //在Y轴上显示起点
};
typedef struct MENU_page
{
    char page_name[12];
    int v_num;
    struct v V[10];
};

void key()
{
    switch (condition)
    {
    case 1:
        up_down=1;//页面前移
        break;
    case 2:
        up_down=-1;//页面后移
        break;
    case 3:
        add=1;//数据+1
        break;
    case 4:
        add=-1;//数据-1
        break;
    default:
        break;
    }
}

void show_pid(int i)
{

}
int main()
{

    return 0;
}
