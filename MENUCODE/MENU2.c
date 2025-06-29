#include "stdio.h"
#include <string.h> 
typedef struct 
{
    unsigned char priority;
    char str[40];
    void (*Operate)();
}MENU;

MENU menu[]={
    {1,"pid查看与修改"},
        {2,"p"},
            {3,"x"},
        {2,"i"}, 
        {2,"d"},
    {1,"车状态"},
        {2,"v"},
        {2,"turn"},
    {1,"end"},
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
void output() 
{
    printf("\n\n");
    int target_priority=current_state-1;
    if (target_priority==0)
    {
        for(int i=0;strcmp(menu[i].str, "end") != 0;i++)
        {
            if(menu[i].priority==1)
            {
                if(i==p)
                {
                    printf("%s<-\n",menu[i].str);
                }
                else
                {
                    printf("%s\n",menu[i].str);
                }
            }
        }
    }
    else if(target_priority!=0)
    {
        for(int i=p_nearby+1;menu[i].priority!=target_priority;i++)
        {
            if(menu[i].priority==current_state)
            {
                if(i==p)
                {
                    printf("%s<-\n",menu[i].str);
                }
                else
                {
                    printf("%s\n",menu[i].str);
                }
            }
        }
    }
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
                while(menu[p].priority!=temp){p++;} 
            }
            else
            {
                printf("无效操作");
            }
                printf("%d,%d\n",p,p_nearby);
             
            break;
        case L:
            if(p!=0&&menu[p-1].priority>=menu[p].priority)
            {
                int temp=menu[p].priority;
                p--;
                while (menu[p].priority!=temp){p--;}
            }
            else
            {
                printf("无效操作");
            }
            
                printf("%d,%d\n",p,p_nearby);

            break;
        case CONFIRM:
            if(menu[p+1].priority==current_state+1&&strcmp(menu[p+1].str,"end")!=0)
            {
                current_state++;
                p_nearby=p;
                p++;
            }
            else
            {
                printf("无效操作");
            }
         
         printf("%d,%d\n",p,p_nearby);

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
        printf("%d,%d\n",p,p_nearby);


        default:
            break;
    }
        
    }
    
    
}