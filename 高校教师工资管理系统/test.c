#include"my_stdio.h"
int _month[12];
int nummonth=0;
tea* creat(tea*Head)//创建链表
{
    tea *newone,*p;
    if(Head==NULL)
    {
        Head=(tea*)malloc(sizeof(tea));
        Head->next=NULL;
        Head->nummonth=0;
        return Head;
    }
    else
    {
        p=Head;
        newone=(tea*)malloc(sizeof(tea));
        while(p->next!=NULL)
            p=p->next;
        p->next=newone;
        newone->next=NULL;
        newone->nummonth=0;
        return Head;
    }
}
void sys()
{
    printf("\n\t");
    system("pause");
    Sleep(500);
    system("cls");
}
int choose()
{
    int n;
    Sleep(500);
    system("cls");
    printf("\n\t------录入菜单------------");
    printf("\n\t------[1]录入教师基本信息--------");
    printf("\n\t------[2]录入教师工资信息------");
    printf("\n\t------[3]返回主菜单------");
    printf("\n\t*****************************");
    printf("\n\t请选择:");
    while(1)
    {
        scanf("%d",&n);
        if(n>=1&&n<=3)
        {
            return n;
        }
        else
        {
            printf("\t提示：请输入1-3之间的数字！");
            while(getchar()!='\n');
        }
    }

}
tea* input1(int *count,tea*Head)//工号、姓名、学院、职称，职称分为：教授、副教授、讲师、助教。教师的工资信息
{
        if(*count==0)
        {
            Head=creat(Head);
            printf("\n\t请输入教师基本信息");
            printf("\n\t请输入工号:");
            scanf("%s",Head->Id);
            printf("\t请输入教师姓名：");
            scanf("%s",Head->Name);
            printf("\t请选择教师学院：");
            int c;
            printf("\t1.工学院  2.信息学院  3.马学院  4.理学院\n\t");
            scanf("%d",&c);
            switch(c)
            {
            case 1:strcpy(Head->xueyuan,"工学院");break;
            case 2:strcpy(Head->xueyuan,"信息学院");break;
            case 3:strcpy(Head->xueyuan,"马学院");break;
            case 4:strcpy(Head->xueyuan,"理学院");break;
            default:printf("录入该信息失败,应输入1-4之间的数字");break;
            }
            printf("\n\t请选择教师职称：");
		    printf("\t1.教授  2.副教授  3.讲师  4.助教\n\t") ;
            scanf("%d",&c);
		    switch(c)
            {
            case 1: strcpy(Head->job,"教授");break;
            case 2:strcpy(Head->job,"副教授");break;
            case 3:strcpy(Head->job,"讲师");break;
            case 4:strcpy(Head->job,"助教");break;
            default:printf("录入该信息失败,应输入1-4之间的数字");break;
            }
            (*count)++;
            printf("\t录入成功\n");
            return Head;
        }
        else
        {
            char tmp[20];
            tea*p;
            int flag=0;
            char temp;
            printf("\n\t请输入教师基本信息");
            while(1)
            {
                p=Head;
                printf("\n\t请输入工号:");
                scanf("%s",tmp);
                while(1)
                {
                    if(strcmp(p->Id,tmp)==0)
                    {
                        printf("\t工号为 %s 的教师信息已录入",tmp);
                        printf("\n\t是否重新输入 Y/N\n\t");
                        while(1)
                        {
                            getchar();
                            if(scanf("%c",&temp)==1)
                            {
                                if(temp=='n'||temp=='N')
                                {
                                    flag=1;
                                    break;
                                }
                                else if(temp=='y'||temp=='Y')
                                {
                                    flag=2;
                                    break;
                                }
                                else
                                {
                                    printf("\t提示：请输入Y/N\n\t");
                                }
                            }
                        }
                        break;
                    }
                    if(p->next==NULL)
                       {
                           flag=3;
                           break;
                       }
                     p=p->next;
                }
                if(flag==1)
                    break;
                if(flag==3)
                    break;
            }
            if(flag==1)
               return Head;
            p=Head;
            p=creat(p);
            while(p->next!=NULL)
                p=p->next;
            strcpy(p->Id,tmp);
            printf("\n\t请输入教师姓名：");
            scanf("%s",p->Name);
            printf("\t请输入教师学院：");
            int c;
            printf("\t1.工学院  2.信息学院  3.马学院  4.理学院\n\t");
            scanf("%d",&c);
            switch(c)
            {
            case 1:strcpy(p->xueyuan,"工学院");break;
            case 2:strcpy(p->xueyuan,"信息学院");break;
            case 3:strcpy(p->xueyuan,"马学院");break;
            case 4:strcpy(p->xueyuan,"理学院");break;
            default:printf("录入该信息失败,应输入1-4之间的数字");break;
            }
            printf("\n\t请选择教师职称：");
		    printf("\t1.教授\t2.副教授\t3.讲师\t4.助教\n\t") ;
	        scanf("%d",&c);
		    switch(c)
            {
            case 1: strcpy(p->job,"教授");break;
            case 2:strcpy(p->job,"副教授");break;
            case 3:strcpy(p->job,"讲师");break;
            case 4:strcpy(p->job,"助教");break;
            default:printf("录入该信息失败,应输入1-4之间的数字");break;
            }
            printf("\t录入成功\n");
            (*count)++;
            return Head;
        }
}
void creatmonth(tea*p,int n)
{
    printf("\t请输入教师的基本工资：");
    scanf("%f",&p->a[n-1].basic);
    printf("\t请输入教师的业绩津贴：");
    scanf("%f",&p->a[n-1].jintie);
    printf("\t请输入教师的扣除费用：");
    scanf("%f",&p->a[n-1].kouchu);
    p->a[n-1].yingfa=p->a[n-1].basic+p->a[n-1].jintie;
    p->a[n-1].shifa=p->a[n-1].yingfa-p->a[n-1].kouchu;
    printf("\t该教师的应发工资为%.2f：",p->a[n-1].yingfa);
    printf("\n\t该教师的实发工资为%.2f：\n",p->a[n-1].shifa);
    Sleep(500);
}
void input2(tea*Head)//工号、月份、基本工资、业绩津贴、扣除费用、应发工资、实发工资
{
    char tmp[20];
    int month;
    printf("\n\t请输入工号:");
    scanf("%s",tmp);
    tea*p=Head;
    int flag2=0;
    int flag=0;
    while(p)
    {
        if(strcmp(p->Id,tmp)==0)
        {
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==1)
    {
        do
        {
            printf("\t请输入月份:");
            scanf("%d",&month);
            int i;
            for(i=0;i<p->nummonth;i++)
            {
                if(p->monthhave[i]+1==month)
                    flag2=1;
            }
            if(flag2!=1)
            {
                switch(month)//月份
                {
                case 1:
                    creatmonth(p,1);
                    p->monthhave[p->nummonth]=0;
                    (p->nummonth)++;
                    break;
                case 2:
                    creatmonth(p,2);
                    p->monthhave[p->nummonth]=1;
                    (p->nummonth)++;
                    break;
                case 3:
                    creatmonth(p,3);
                    p->monthhave[p->nummonth]=2;
                    (p->nummonth)++;
                    break;
                case 4:
                    creatmonth(p,4);
                    p->monthhave[p->nummonth]=3;
                    (p->nummonth)++;
                    break;
                case 5:
                    creatmonth(p,5);
                    p->monthhave[p->nummonth]=4;
                    (p->nummonth)++;
                    break;
                case 6:
                    creatmonth(p,6);
                    p->monthhave[p->nummonth]=5;
                    (p->nummonth)++;
                    break;
                case 7:
                    creatmonth(p,7);
                    p->monthhave[p->nummonth]=6;
                    (p->nummonth)++;
                    break;
                case 8:
                    creatmonth(p,8);
                    p->monthhave[p->nummonth]=7;
                    (p->nummonth)++;
                    break;
                case 9:
                    creatmonth(p,9);
                    p->monthhave[p->nummonth]=8;
                    (p->nummonth)++;
                    break;
                case 10:
                    creatmonth(p,10);
                    p->monthhave[p->nummonth]=9;
                    (p->nummonth)++;
                    break;
                case 11:
                    creatmonth(p,11);
                    p->monthhave[p->nummonth]=10;
                    (p->nummonth)++;
                    break;
                case 12:
                    creatmonth(p,12);
                    p->monthhave[p->nummonth]=11;
                    (p->nummonth)++;
                    break;
                default:
                    printf("\t提示：请输入1-12月份\n");
                    break;
                }
            }
            else
            {
                printf("\n\t该月份已录入");
                break;
            }
        }while(month<1||month>12);
    }
    else
        printf("\t工号为 %s 的教师未录入\n",tmp);
}
int choose2()
{
    int n;
    Sleep(500);
    system("cls");
    printf("\n\t------------------修改菜单---------------------");
    printf("\n\t------[1]按工号修改教师基本信息和工资信息------");
    printf("\n\t------[2]按姓名修改教师基本信息和工资信息------");
    printf("\n\t------[3]删除某一工号的教师的所有信息------");
    printf("\n\t------[4]返回主菜单------");
    printf("\n\t***********************************************");
    printf("\n\t请选择:");
    while(1)
    {
        scanf("%d",&n);
        if(n>=1&&n<=4)
        {
            return n;
        }
        else
        {
            printf("\t提示：请输入1-4之间的数字！");
            while(getchar()!='\n');
        }
    }
}
void shownow(tea*p)
{
    int month;
    printf("\n\t以下为该教师的所有信息:");
    printf("\n\t基本信息");
    printf("\n\t%-20s  %-10s  %-20s  %-10s","工号","姓名","学院","职称");
    printf("\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
    printf("\n");
    printf("\n\t工资信息");
    printf("\n\t%-10s  %-10s  %-10s  %-10s  %-10s  %-10s","月份","基本工资","业绩津贴","扣除费用","应发工资","实发工资");
    for(month=0;month<(p->nummonth);month++)
    {
    printf("\n\t%d%-10s  %-10.2f  %-10.2f  %-10.2f  %-10.2f  %-10.2f",(p->monthhave[month]+1)," 月份:",p->a[p->monthhave[month]].basic,p->a[p->monthhave[month]].jintie,p->a[p->monthhave[month]].kouchu,p->a[p->monthhave[month]].yingfa,p->a[p->monthhave[month]].shifa);
    }
    printf("\n");
}
void changenow(tea*p)
{
    while(1)
    {
        char name[20];
        printf("\n\t请输入要修改的信息是基本信息还是工资信息：");
        scanf("%s",name);
        if(strcmp(name,"基本信息")==0)
        {
            printf("\n\t请输入教师姓名：");
            scanf("%s",p->Name);
            printf("\t请输入教师学院：");
            int c;
            printf("\t1.工学院  2.信息学院  3.马学院  4.理学院");
            scanf("%d",&c);
            switch(c)
            {
            case 1:strcpy(p->xueyuan,"工学院");break;
            case 2:strcpy(p->xueyuan,"信息学院");break;
            case 3:strcpy(p->xueyuan,"马学院");break;
            case 4:strcpy(p->xueyuan,"理学院");break;
            default:printf("录入该信息失败,应输入1-4之间的数字\n\t");break;
            }
            printf("\t请选择教师职称：");
		    printf("\n\t1.教授  2.副教授  3.讲师  4.助教\n\t") ;
	        scanf("%d",&c);
		    switch(c)
            {
            case 1: strcpy(p->job,"教授");break;
            case 2:strcpy(p->job,"副教授");break;
            case 3:strcpy(p->job,"讲师");break;
            case 4:strcpy(p->job,"助教");break;
            default:printf("录入该信息失败,应输入1-4之间的数字");break;
            }
            printf("\n\t修改成功\n");
            break;
        }
        else if(strcmp(name,"工资信息")==0)
        {
            int n;
            int i;
            printf("\t请输入要修改的月份：");
            scanf("%d",&n);
            for(i=0;i<p->nummonth;i++)
            {
                if(p->monthhave[i]==n-1)
                {
                    creatmonth(p,n);
                    printf("\n\t修改成功\n");
                    break;
                }
            }
            if(i==p->nummonth)
            {
                printf("\n\t该月份未录入");
            }
            break;
        }
        else
        {
            printf("\t提示：请输入 基本信息/工资信息");
        }
    }
}
void change1(tea*Head)//工号、姓名、学院、职称，职称分为：教授、副教授、讲师、助教。教师的工资信息包括：工号、月份、基本工资、业绩津贴、扣除费用、应发工资、实发工资，
{
    char tmp[20];
    printf("\n\t请输入修改教师的工号:");
    scanf("%s",tmp);
    tea*p=Head;
    int flag=0;
    while(p)
    {
        if(strcmp(p->Id,tmp)==0)
        {
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==1)
    {
        shownow(p);
        changenow(p);
    }
    else
    {
        printf("\t工号为 %s 的教师未录入",tmp);
    }
}
void change2(tea*Head)
{
    char tmp[20];
    printf("\n\t请输入教师姓名:");
    scanf("%s",tmp);
    tea*p=Head;
    int flag=0;
    while(p)
    {
        if(strcmp(p->Name,tmp)==0)
        {
            shownow(p);
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==1)
    {
        printf("\n\t请输入修改教师的工号:");
        scanf("%s",tmp);
        int tm=0;
        while(p)
        {
            if(strcmp(p->Id,tmp)==0)
            {
                tm=1;
                break;
            }
            p=p->next;
        }
        if(tm==1)
        {
            changenow(p);
        }
        else
        {
            printf("\t工号为 %s 的教师未录入",tmp);
        }
    }
    else
    {
         printf("\t姓名为 %s 的教师未录入",tmp);
    }
}
tea* del(tea*Head)
{
    tea*p,*cur;
    char l;
    p=Head;
    char tmp[20];
    printf("\n\t请输入要删除教师的工号:");
    scanf("%s",tmp);
    int tm=0;
    while(p)
    {
        if(strcmp(p->Id,tmp)==0)
        {
            tm=1;
            break;
        }
        p=p->next;
    }
    if(tm==1)
    {
        printf("\n\t是否确认删除 Y/N");
        while(1)
        {
            while(getchar()!='\n');
            if(scanf("%c",&l)==1)
            {
                if(l=='y'||l=='Y')
                {
                    while(1)
                    {
                        printf("\n\t再次确认是否删除 Y/N");
                        while(getchar()!='\n');
                        if(scanf("%c",&l)==1)
                        {
                            while(getchar()!='\n');
                            if(l=='n'||l=='N')
                            {
                                tm=2;
                                break;
                            }
                            else if(l=='y'||l=='Y')
                            {
                                tm=1;
                                break;
                            }
                            else
                            {
                                printf("\t提示：请输入Y/N\n\t");
                            }
                        }
                    }
                    break;
                }
                else if(l=='n'||l=='N')
                {
                    tm=2;
                    break;
                }
                else
                {
                    printf("\t提示：请输入Y/N\n\t");
                }
            }
        }
    }
    if(tm==1)
    {
        if(p==Head)
        {
            cur=p->next;
            free(p);
            printf("\n\t删除成功");
            return cur;
        }
        else
        {
            cur=Head;
            while(cur->next!=p)
                cur=cur->next;
            p=p->next;
            free(cur->next);
            cur->next=p;
            printf("\n\t删除成功");
            return Head;
        }
    }
    else if(tm==2)
    {
        printf("\n\t已取消删除");
        return Head;
    }
    else
    {
        printf("\t工号为 %s 的教师未录入",tmp);
        return Head;
    }
}
void paixu(tea*Head,int count)
{
    tea*p=Head;
    int flag=0;
    int i;
    tea*tmp1,*tmp2;
    tea tmp3;
    for(i=0;i<count-1;i++)
    {
        while(p)
        {
            flag=1;
            if(p->next==NULL)
                break;
            if(strcmp(p->Id,p->next->Id)>0)
            {
                tmp1=p->next;
                tmp2=p->next->next;
                tmp3=*p;
                *p=*(p->next);
                *tmp1=tmp3;
                p->next=tmp1;
                p->next->next=tmp2;
            }
            p=p->next;
        }
    }
    if(flag==0&&count!=1)
    {
        printf("\n\t未录入任何教师信息");
    }
}
int choose3()
{
    int n;
    Sleep(500);
    system("cls");
    printf("\n\t----------------查询菜单-----------------------");
    printf("\n\t------[1]显示全部教师的基本信息----------------");
    printf("\n\t------[2]根据月份查询--------------------------");
    printf("\n\t------[3]根据工号和月份查询--------------------");
    printf("\n\t------[4]根据姓名和月份查询--------------------");
    printf("\n\t------[5]返回主菜单----------------------------");
    printf("\n\t***********************************************");
    printf("\n\t请选择:");
    while(1)
    {
        scanf("%d",&n);
        if(n>=1&&n<=5)
        {
            return n;
        }
        else
        {
            printf("\t提示：请输入1-5之间的数字！");
            while(getchar()!='\n');
        }
    }
}
void show(tea*Head)
{
    tea*p=Head;
    printf("\n\t以下为所有教师的所有基本信息:");
    while(p)
    {
        printf("\n\t%-20s  %-10s  %-20s  %-10s","工号","姓名","学院","职称");
        printf("\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
        p=p->next;
    }
}
void research1(tea*Head,int count)
{
    paixu(Head,count);
    show(Head);
}
void shownow2(tea*p,int month)
{
    printf("\n\t基本信息");
    printf("\n\t%-20s  %-10s  %-20s  %-10s","工号","姓名","学院","职称");
    printf("\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
    printf("\n\t工资信息");
    printf("\n\t%-10s  %-10s  %-10s  %-10s  %-10s  %-10s","月份","基本工资","业绩津贴","扣除费用","应发工资","实发工资");
    printf("\n\t%d%-10s  %-10.2f  %-10.2f  %-10.2f  %-10.2f  %-10.2f",month," 月份:",p->a[p->monthhave[month-1]].basic,p->a[month-1].jintie,p->a[month-1].kouchu,p->a[month-1].yingfa,p->a[month-1].shifa);
}
void shownow3(tea*p,int month)
{
    printf("\n\t基本信息");
    printf("\n\t%-20s  %-10s  %-20s  %-10s","工号","姓名","学院","职称");
    printf("\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
    printf("\n\t工资信息");
    printf("\n\t%-10s  %-10s  %-10s  %-10s  %-10s  %-10s","月份","基本工资","业绩津贴","扣除费用","应发工资","实发工资");
    printf("\n\t该教师 %d 月工资信息未录入",month);
}
void shownow4(tea*p,int month)
{
    printf("\n\t%d%-10s  %-10s  %-10.2f  %-10.2f  %-10.2f  %-10.2f  %-10.2f",month," 月份:",p->Id,p->a[p->monthhave[month-1]].basic,p->a[month-1].jintie,p->a[month-1].kouchu,p->a[month-1].yingfa,p->a[month-1].shifa);
}
void research3(tea*Head)
{
    char tmp[20];
    int month;
    printf("\n\t请输入工号:");
    scanf("%s",tmp);
    tea*p=Head;
    int flag=0;
    while(p)
    {
        if(strcmp(p->Id,tmp)==0)
        {
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==1)
    {
        printf("\t请输入月份:");
        scanf("%d",&month);
        int i;
        for(i=0;i<p->nummonth;i++)
        {
            flag=0;
            if(month==p->monthhave[i]+1)
            {
                flag=1;
                shownow2(p,month);
                printf("\n");
                break;
            }
        }
        if(flag==0)
            printf("\n\t未录入该月份的信息");
    }
    else
        printf("\t工号为 %s 的教师未录入\n",tmp);
}
void research4(tea*Head)
{
    char tmp[20];
    int month;
    printf("\n\t请输入教师姓名:");
    scanf("%s",tmp);
    printf("\t请输入月份:");
    scanf("%d",&month);
    tea*p=Head;
    int flag=0;
    int flag2=0;
    while(p)
    {
        if(strcmp(p->Name,tmp)==0)
        {
            int i;
            flag=1;
            flag2=0;
            for(i=0;i<p->nummonth;i++)
            {
                if(month==p->monthhave[i]+1)
                {
                    flag2=1;
                    shownow2(p,month);
                    printf("\n");
                    break;
                }
            }
            if(flag2==0)
                shownow3(p,month);
        }
        p=p->next;
    }
    if(flag==0)
         printf("\t姓名为 %s 的教师未录入",tmp);
}
void show1(int flag)
{
    if(flag==0)
    {
        printf("\n\t工资信息");
        printf("\n\t%-10s  %-10s  %-10s  %-10s  %-10s  %-10s  %-10s","月份","工号","基本工资","业绩津贴","扣除费用","应发工资","实发工资");
    }
}
void research2(tea*Head,int count)
{
    paixu(Head,count);
    tea*p=Head;
    int month;
    int i;
    int flag=0;
    printf("\n\t请输入查询的月份");
    scanf("%d",&month);
    while(p)
    {
        for(i=0;i<p->nummonth;i++)
        {
            if(month==p->monthhave[i]+1)
            {
                show1(flag);
                shownow4(p,month);
                flag=1;
            }
        }
        p=p->next;
    }
    if(flag==0)
        printf("\n\t未录入该月份信息");
}
int choose4()
{
    int n;
    Sleep(500);
    system("cls");
    printf("\n\t---------------录入菜单-----------------------");
    printf("\n\t------[1]根据月份分析不同学院的教师信息--------");
    printf("\n\t------[2]根据月份分析不同职称的教师信息--------");
    printf("\n\t------[3]返回主菜单----------------------------");
    printf("\n\t*****************************");
    printf("\n\t请选择:");
    while(1)
    {
        scanf("%d",&n);
        if(n>=1&&n<=3)
        {
            return n;
        }
        else
        {
            printf("\t提示：请输入1-3之间的数字！");
            while(getchar()!='\n');
        }
    }
}
int cmp(const void* a,const void* b)
{
    return (int)(((anl)b)->aver2 -((anl)a)->aver2);
}
void analyse1(tea*Head)
{
    int month;
    tea*p=Head;
    int flag=0;
    int caver[4]={0};//统计学院人数
    anal anal1[4];//0.工学院  1.信息学院  2.马学院  3.理学院"      //aver1为应发  aver2为实发
    int i;
    for(i=0;i<4;i++)//初始化
    {
        anal1[i].aver1=0;
        anal1[i].aver2=0;
    }
    strcpy(anal1[0].namexue,"工学院");
    strcpy(anal1[1].namexue,"信息学院");
    strcpy(anal1[2].namexue,"马学院");
    strcpy(anal1[3].namexue,"理学院");
    printf("\n\t请输入月份");
    scanf("%d",&month);
    while(p)
    {
        for(i=0;i<p->nummonth;i++)
        {
            if(month==p->monthhave[i]+1)
            {
                flag=1;
                if(strcmp(p->xueyuan,"工学院")==0)
                {
                    anal1[0].aver1+=p->a[month-1].yingfa;
                    anal1[0].aver2+=p->a[month-1].shifa;
                    caver[0]++;
                }
                if(strcmp(p->xueyuan,"信息学院")==0)
                {
                    anal1[1].aver1+=p->a[month-1].yingfa;
                    anal1[1].aver2+=p->a[month-1].shifa;
                    caver[1]++;
                }
                if(strcmp(p->xueyuan,"马学院")==0)
                {
                    anal1[2].aver1+=p->a[month-1].yingfa;
                    anal1[2].aver2+=p->a[month-1].shifa;
                    caver[2]++;
                }
                if(strcmp(p->xueyuan,"理学院")==0)
                {
                    anal1[3].aver1+=p->a[month-1].yingfa;
                    anal1[3].aver2+=p->a[month-1].shifa;
                    caver[3]++;
                }
            }

        }
        p=p->next;
    }
    if(flag==0)
        {
            printf("\n\t该月份未录入");
            return;
        }
        for(i=0;i<4;i++)
        {
            if(caver[i]==0)
                caver[i]=1;
        }
    for(i=0;i<4;i++)
    {
        anal1[i].aver1=anal1[i].aver1/caver[i];
        anal1[i].aver2=anal1[i].aver2/caver[i];
    }
    int(*pp)(const void*,const void*)=cmp;
    qsort(anal1,4,sizeof(anal),pp);
    printf("\n\t%-10s  %-20s  %-20s","学院名","平均应发工资","平均实发工资");
    for(i=0;i<4;i++)
    {
        printf("\n\t%-10s  %-20.2f  %-20.2f",anal1[i].namexue,anal1[i].aver1,anal1[i].aver2);
    }
}
int cmp2(const void* a,const void* b)
{
    return (int)(((anl)b)->aver1 -((anl)a)->aver1);
}
void analyse2(tea*Head)
{
    int month;
    tea*p=Head;
    int flag=0;
    int caver[4]={0};//统计职位人数
    anal anal1[4];//0.教授  1.副教授  2.讲师  3.助教      //aver1为应发  aver2为实发
    int i;
    for(i=0;i<4;i++)//初始化
    {
        anal1[i].aver1=0;
        anal1[i].aver2=0;
    }
    strcpy(anal1[0].namexue,"教授");
    strcpy(anal1[1].namexue,"副教授");
    strcpy(anal1[2].namexue,"讲师");
    strcpy(anal1[3].namexue,"助教");
    printf("\n\t请输入月份");
    scanf("%d",&month);
    while(p)
    {
        for(i=0;i<p->nummonth;i++)
        {
            if(month==p->monthhave[i]+1)
            {
                flag=1;
                if(strcmp(p->job,"教授")==0)
                {
                    anal1[0].aver1+=p->a[month-1].yingfa;
                    anal1[0].aver2+=p->a[month-1].shifa;
                    caver[0]++;
                }
                if(strcmp(p->job,"副教授")==0)
                {
                    anal1[1].aver1+=p->a[month-1].yingfa;
                    anal1[1].aver2+=p->a[month-1].shifa;
                    caver[1]++;
                }
                if(strcmp(p->job,"讲师")==0)
                {
                    anal1[2].aver1+=p->a[month-1].yingfa;
                    anal1[2].aver2+=p->a[month-1].shifa;
                    caver[2]++;
                }
                if(strcmp(p->job,"助教")==0)
                {
                    anal1[3].aver1+=p->a[month-1].yingfa;
                    anal1[3].aver2+=p->a[month-1].shifa;
                    caver[3]++;
                }
            }

        }
        p=p->next;
    }
    if(flag==0)
        {
            printf("\n\t该月份未录入");
            return;
        }
        for(i=0;i<4;i++)
        {
            if(caver[i]==0)
                caver[i]=1;
        }
    for(i=0;i<4;i++)
    {
        anal1[i].aver1=anal1[i].aver1/caver[i];
        anal1[i].aver2=anal1[i].aver2/caver[i];
    }
    int(*pp)(const void*,const void*)=cmp2;
    qsort(anal1,4,sizeof(anal),pp);
    printf("\n\t%-10s  %-20s  %-20s","职位名","平均应发工资","平均实发工资");
    for(i=0;i<4;i++)
    {
        printf("\n\t%-10s  %-20.2f  %-20.2f",anal1[i].namexue,anal1[i].aver1,anal1[i].aver2);
    }
}
void freeall(tea*Head)//释放内存
{
    if(Head->next==NULL)
        free(Head);
    else
    {
        freeall(Head->next);
        free(Head);
    }
}
void write(tea*Head)
{
    FILE*pf;
    pf=NULL;
    if((pf=fopen("高校教师工资管理系统-教师基本信息.txt","w"))==NULL)
    {
        printf("\n\t%s",strerror(errno));
    }
    else
    {
        tea*p=Head;
        fprintf(pf,"\t以下为所有教师的所有基本信息:");
        fprintf(pf,"\n\t%-20s %-10s %-20s %-10s","工号","姓名","学院","职称");
        while(p)
        {
            fprintf(pf,"\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
            p=p->next;
        }
        fclose(pf);
    }
    FILE*pf1;
    pf1=NULL;
    if((pf1=fopen("高校教师工资管理系统-教师工资信息.txt","w"))==NULL)
    {
        printf("\n\t%s",strerror(errno));
    }
    else
    {
        int month;
        tea*p1=Head;
        fprintf(pf1,"\t以下为所有教师的所有工资信息:");
        fprintf(pf1,"\n\t%-10s\t%-10s%-10s\t%-10s\t%-10s\t%-10s\t%-10s","  月份：","工号"," 基本工资"," 业绩津贴"," 扣除费用"," 应发工资"," 实发工资");
        while(p1)
        {
            for(month=0;month<(p1->nummonth);month++)
            {
                fprintf(pf1,"\n\t%d%-10s\t%-10s\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f",(p1->monthhave[month]+1)," 月份:",p1->Id,p1->a[p1->monthhave[month]].basic,p1->a[p1->monthhave[month]].jintie,p1->a[p1->monthhave[month]].kouchu,p1->a[p1->monthhave[month]].yingfa,p1->a[p1->monthhave[month]].shifa);
            }
            p1=p1->next;
        }
        fclose(pf1);

    }
    FILE*pf2;
    pf2=NULL;
    if((pf2=fopen("高校教师工资管理系统-录入月份统计.txt","w"))==NULL)
    {
        printf("\n\t%s",strerror(errno));
    }
    else
    {
        int s;
        tea*p2=Head;
        while(p2)
        {
            fprintf(pf2,"\t%-10s %-10s","工号","录入月份统计数量");
            fprintf(pf2,"\n\t%-10s  %-10d  ",p2->Id,p2->nummonth);
            fprintf(pf2,"\n\t已录入月份：");
            for(s=0;s<p2->nummonth;s++)
            {
                fprintf(pf2,"\n\t%d",p2->monthhave[s]+1);
            }
            p2=p2->next;
        }
        fclose(pf2);
    }
}
tea* read(tea*Head,int *count)
{
    char arr[10000];
    FILE*pf;
    pf=NULL;
    tea*p=Head;
    tea*tpp;
    int tmp;
    if((pf=fopen("高校教师工资管理系统-教师基本信息.txt","r"))==NULL)
    {
         if(*count!=0)
         printf("\n\t%s-高校教师工资管理系统-教师基本信息.txt",strerror(errno));
         return Head;
    }
    else
    {
         fgets(arr,10000,pf);
         fgets(arr,10000,pf);
         while(1)
         {
            Head=creat(Head);
            p=Head;
            while(p->next!=NULL)
            {
                tpp=p;
                p=p->next;
            }
            tmp=fscanf(pf,"\t%s  %s  %s  %s",p->Id,p->Name,p->xueyuan,p->job);
            (*count)++;
            if(tmp==-1)
            {
                tpp->next=NULL;
                free(p);
                (*count)--;
                break;
            }
         }
         fclose(pf);
    }
    FILE*pf2;
    pf2=NULL;
    if((pf2=fopen("高校教师工资管理系统-录入月份统计.txt","r"))==NULL)
    {
        printf("\n\t%s-高校教师工资管理系统-录入月份统计.txt",strerror(errno));
    }
    else
    {
        int k;
        tea*p2=Head;
        while(p2)
        {
            fgets(arr,10000,pf2);
            fscanf(pf2,"\t%s  %d\n",p2->Id,&(p2->nummonth));
            fgets(arr,10000,pf2);
            for(k=0;k<p2->nummonth;k++)
            {
                fscanf(pf2,"\t%d\n",&(p2->monthhave[k]));
            }
            p2=p2->next;
        }
        fclose(pf2);
    }
    FILE*pf1;
    pf1=NULL;
    if((pf1=fopen("高校教师工资管理系统-教师工资信息.txt","r"))==NULL)
    {
        printf("\n\t%s-高校教师工资管理系统-教师工资信息.txt",strerror(errno));
    }
    else
    {
        int month;
        int monthtmp;
        char mon[10000];
        tea*p1=Head;
        fgets(arr,10000,pf1);
        fgets(arr,10000,pf1);
        while(p1)
        {
            for(month=0;month<p1->nummonth;month++)
            {
                tmp=fscanf(pf1,"\t%d %s  %s  %f  %f  %f  %f  %f\n",&monthtmp,mon,p1->Id,&((p1->a[p1->monthhave[month]-1]).basic),&((p1->a[p1->monthhave[month]-1]).jintie),&((p1->a[p1->monthhave[month]-1]).kouchu),&((p1->a[p1->monthhave[month]-1]).yingfa),&((p1->a[p1->monthhave[month]-1]).shifa));
                if(tmp==-1)
                    break;
            }
            for(month=0;month<12;month++)
                (p1->monthhave[month])--;
            p1=p1->next;
        }
        fclose(pf1);
    }
    return Head;
}
