#include "stdio.h"
#include <string.h> 
typedef struct 
{
    unsigned char priority;
    char str[40];
    void (*Operate)();
}MENU;

MENU menu[]={
    {1,"pid查看与修改",NULL},
        {2,"p",NULL},
            {3,"x",NULL},
        {2,"i",NULL},
        {2,"d",NULL},
    {1,"车状态",NULL},
        {2,"v",NULL},
        {2,"turn",NULL},
    {1,"end",NULL},
};
enum condition{
    L,
    R,
    UP,
    DOWN,
    CONFIRM,
    BACK

}condition;
    
int current_state=1;
int p=0;//记录当前指针
int p_nearby=0;//记录所属的指针
int input;


void output() {
    // 获取当前选项的优先级
    unsigned char current_priority = menu[p].priority;
    
    // 找到所属上级的索引
    int parent_index = p;
    while(parent_index >= 0 && menu[parent_index].priority >= current_priority) {
        parent_index--;
    }
    parent_index++;  // 回到上级菜单项
    
    // 找到同级别且同上级的所有选项
    printf("\n当前菜单\n(%s):\n", menu[parent_index].str);
    
    // 查找同级的起始索引
    int start = parent_index + 1;
    while(start > 0 && menu[start-1].priority > current_priority) {
        start--;
    }
    
    // 查找同级的结束索引
    int end = parent_index + 1;
    while(strcmp(menu[p].str, "end") != 0 && menu[end+1].priority >= current_priority) {
        end++;
    }
    
    // 输出同级选项
    for(int i = start; i <= end; i++) {
        if(menu[i].priority == current_priority) {  // 确保是同级别
            if(i == p) {
                printf("-> %s\n", menu[i].str);  // 当前选中项
            } else {
                printf("   %s\n", menu[i].str);  // 同级其他项
            }
        }
    }
    printf("操作: 0-左 1-右 4-确认 5-返回\n");
}

int main()
{

    while (1)
    {
        output();
        scanf("%d", &input);
        condition = (enum condition)input; 
        switch (condition)
        {
        case R:
            if (strcmp(menu[p].str, "end") != 0&&menu[p+1].priority>=menu[p].priority)
            {
                int temp=menu[p].priority;
                p++;
                while(menu[p+1].priority!=temp){p++;}
            }
            else
            {
                printf("无效操作");
            }
            break;
        case L:
            if(p!=0&&menu[p-1].priority>=menu[p].priority)
            {
                int temp=menu[p].priority;
                p--;
                while (menu[p-1].priority!=temp){p--;}
            }
            else
            {
                printf("无效操作");
            }
            break;
        case CONFIRM:
            if(menu[p+1].priority==current_state+1)
            {
                current_state++;
                p_nearby=p;
                p++;
            }
            else
            {
                printf("无效操作");
            }
            break;
        case BACK:
        if(menu[p].priority!=1)
        {
            current_state--;
            p=p_nearby;
            while (menu[p_nearby].priority!=current_state-1)
            {
                p_nearby--;
            }
        }
        else
        {
            printf("无效操作");
        }
        default:
            break;
    }
        
    }
    
    
}