// #include "stdio.h"
// #include "string.h"
// #include "show.h"

// //这里可以链接其他的头文件，获取如pid参数，pwm参数，陀螺仪参数

// int up_down;//页面前移后移
// int add;//加减
// MENU_pagedef pidmenu;
// /*
// @brief初始化菜单显示pid参数
// @param p参数p
// @param i参数i
// @param d参数d

// */
// int pidMenu_init(float p,float i,float d)
// {
//     strcpy(pidmenu.page_name, "pid");
//     pidmenu.v_num=3;
//     strcpy(pidmenu.V[0].name,"p");
//     strcpy(pidmenu.V[1].name,"i");
//     strcpy(pidmenu.V[2].name,"d");
//     pidmenu.V[0].num=p;
//     pidmenu.V[1].num=i;
//     pidmenu.V[2].num=d;
//     pidmenu.V[0].x=0;
//     pidmenu.V[1].x=1;
//     pidmenu.V[2].x=2;
//     pidmenu.V[0].y=0;
//     pidmenu.V[1].y=1;
//     pidmenu.V[2].y=2;
//     return pidmenu.v_num;
// }
// enum 
// {
//     PIDMENU=1,
//     MPU6050=2,
//     PWMMENU=3
// }condition;
// int main()
// {
//     pidMenu_init(1.0,2.0,3.0);
//     //当然这里可以在pid函数中设计一个get函数获取
//     switch (condition)
//     {
//     case PIDMENU:
//         show_page(pidmenu);
        
//         break;
    
//     default:
//         break;
//     }
//     return 0;
// }
