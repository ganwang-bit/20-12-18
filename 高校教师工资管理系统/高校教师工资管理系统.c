#include"my_stdio.h"
void menu()
{
    printf("\n\t--------------------WELCOME--------------------\n");
    printf("\n\t***************教师工资管理系统***************\n\n");
    printf("\n\t---------------[1]输入教师信息并保存---------------");
    printf("\n\t---------------[2]修改教师信息并保存---------------");
    printf("\n\t---------------[3]查询并显示---------------");
    printf("\n\t---------------[4]统计分析---------------");
    printf("\n\t---------------[5]退出-----------------");
    printf("\n\t**********************************************");
    printf("\n\t请选择:");
}
enum Choose
{
    Input=1,
    Change,
    Search,
    Analyse,
    Exit

};
int main()
{
    int n,m,count=0;
    int*num=&count;
    tea* Head=NULL;//头结点
    Head=read(Head,num);
    while(1)
    {
        menu();
        if(scanf("%d",&n)==1)
        {
            switch(n)
            {
            case Input://输入
                m=choose();//基本信息/工资信息
                if(m==1)
                    Head=input1(num,Head);//基本信息
                else if(m==2)
                    input2(Head);//工资信息
                else;

                write(Head);
                sys();
                break;
            case Change://修改
                m=choose2();//工号/姓名
                if(m==1)
                    change1(Head);//按工号修改
                else if(m==2)
                    change2(Head);//按姓名修改
                else if(m==3)
                    Head=del(Head);//删除
                else;
                write(Head);
                sys();
                break;
            case Search://查询并显示
                m=choose3();
                if(m==1)
                    research1(Head,count);
                else if(m==2)
                    research2(Head,count);
                else if(m==3)
                    research3(Head);
                else if(m==4)
                    research4(Head);
                else;
                sys();
                break;
            case Analyse://统计分析
                m=choose4();
                if(m==1)
                    analyse1(Head);
                else if(m==2)
                    analyse2(Head);
                else;
                sys();
                break;
            case Exit://退出
                printf("\n\t程序即将退出");
                printf("\n\t是否确认退出 Y/N");
                char temp;
                while(1)
                {
                    while(getchar()!='\n');
                    if(scanf("%c",&temp)==1)
                    {
                        if(temp=='n'||temp=='N')
                        {
                            n=0;
                            break;
                        }
                        else if(temp=='y'||temp=='Y')
                        {
                            break;
                        }
                        else
                        {
                            printf("\t提示：请输入Y/N");
                        }
                    }
                }
                sys();
                break;
            default:
                printf("\n\t请正确输入1-5之间的数字：");
            }
        }
        else
        {
             printf("\n\t提示：请正确输入1-5之间的数字！");
             sys();
             while(getchar()!='\n');
        }
        if(n==5)
            {
                if(count==0);
                else
                {
                      write(Head);
                    freeall(Head);
                }
                break;
            }
    }
    return 0;
}
