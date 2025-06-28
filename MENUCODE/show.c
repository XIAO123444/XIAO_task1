#include "show.h"


void show_page(MENU_pagedef menu_page)
{
    printf("%s\n",menu_page.page_name);
    printf("\n");
    for(int j=0;j<menu_page.v_num;j++)
    {
        printf("%s",menu_page.V[j].name);
        printf("     %.2f,x=%d,y=%d\n",menu_page.V[j].num,menu_page.V[j].x,menu_page.V[j].y);
    }
}