#include"my_stdio.h"
int _month[12];
int nummonth=0;
tea* creat(tea*Head)//��������
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
    printf("\n\t------¼��˵�------------");
    printf("\n\t------[1]¼���ʦ������Ϣ--------");
    printf("\n\t------[2]¼���ʦ������Ϣ------");
    printf("\n\t------[3]�������˵�------");
    printf("\n\t*****************************");
    printf("\n\t��ѡ��:");
    while(1)
    {
        scanf("%d",&n);
        if(n>=1&&n<=3)
        {
            return n;
        }
        else
        {
            printf("\t��ʾ��������1-3֮������֣�");
            while(getchar()!='\n');
        }
    }

}
tea* input1(int *count,tea*Head)//���š�������ѧԺ��ְ�ƣ�ְ�Ʒ�Ϊ�����ڡ������ڡ���ʦ�����̡���ʦ�Ĺ�����Ϣ
{
        if(*count==0)
        {
            Head=creat(Head);
            printf("\n\t�������ʦ������Ϣ");
            printf("\n\t�����빤��:");
            scanf("%s",Head->Id);
            printf("\t�������ʦ������");
            scanf("%s",Head->Name);
            printf("\t��ѡ���ʦѧԺ��");
            int c;
            printf("\t1.��ѧԺ  2.��ϢѧԺ  3.��ѧԺ  4.��ѧԺ\n\t");
            scanf("%d",&c);
            switch(c)
            {
            case 1:strcpy(Head->xueyuan,"��ѧԺ");break;
            case 2:strcpy(Head->xueyuan,"��ϢѧԺ");break;
            case 3:strcpy(Head->xueyuan,"��ѧԺ");break;
            case 4:strcpy(Head->xueyuan,"��ѧԺ");break;
            default:printf("¼�����Ϣʧ��,Ӧ����1-4֮�������");break;
            }
            printf("\n\t��ѡ���ʦְ�ƣ�");
		    printf("\t1.����  2.������  3.��ʦ  4.����\n\t") ;
            scanf("%d",&c);
		    switch(c)
            {
            case 1: strcpy(Head->job,"����");break;
            case 2:strcpy(Head->job,"������");break;
            case 3:strcpy(Head->job,"��ʦ");break;
            case 4:strcpy(Head->job,"����");break;
            default:printf("¼�����Ϣʧ��,Ӧ����1-4֮�������");break;
            }
            (*count)++;
            printf("\t¼��ɹ�\n");
            return Head;
        }
        else
        {
            char tmp[20];
            tea*p;
            int flag=0;
            char temp;
            printf("\n\t�������ʦ������Ϣ");
            while(1)
            {
                p=Head;
                printf("\n\t�����빤��:");
                scanf("%s",tmp);
                while(1)
                {
                    if(strcmp(p->Id,tmp)==0)
                    {
                        printf("\t����Ϊ %s �Ľ�ʦ��Ϣ��¼��",tmp);
                        printf("\n\t�Ƿ��������� Y/N\n\t");
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
                                    printf("\t��ʾ��������Y/N\n\t");
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
            printf("\n\t�������ʦ������");
            scanf("%s",p->Name);
            printf("\t�������ʦѧԺ��");
            int c;
            printf("\t1.��ѧԺ  2.��ϢѧԺ  3.��ѧԺ  4.��ѧԺ\n\t");
            scanf("%d",&c);
            switch(c)
            {
            case 1:strcpy(p->xueyuan,"��ѧԺ");break;
            case 2:strcpy(p->xueyuan,"��ϢѧԺ");break;
            case 3:strcpy(p->xueyuan,"��ѧԺ");break;
            case 4:strcpy(p->xueyuan,"��ѧԺ");break;
            default:printf("¼�����Ϣʧ��,Ӧ����1-4֮�������");break;
            }
            printf("\n\t��ѡ���ʦְ�ƣ�");
		    printf("\t1.����\t2.������\t3.��ʦ\t4.����\n\t") ;
	        scanf("%d",&c);
		    switch(c)
            {
            case 1: strcpy(p->job,"����");break;
            case 2:strcpy(p->job,"������");break;
            case 3:strcpy(p->job,"��ʦ");break;
            case 4:strcpy(p->job,"����");break;
            default:printf("¼�����Ϣʧ��,Ӧ����1-4֮�������");break;
            }
            printf("\t¼��ɹ�\n");
            (*count)++;
            return Head;
        }
}
void creatmonth(tea*p,int n)
{
    printf("\t�������ʦ�Ļ������ʣ�");
    scanf("%f",&p->a[n-1].basic);
    printf("\t�������ʦ��ҵ��������");
    scanf("%f",&p->a[n-1].jintie);
    printf("\t�������ʦ�Ŀ۳����ã�");
    scanf("%f",&p->a[n-1].kouchu);
    p->a[n-1].yingfa=p->a[n-1].basic+p->a[n-1].jintie;
    p->a[n-1].shifa=p->a[n-1].yingfa-p->a[n-1].kouchu;
    printf("\t�ý�ʦ��Ӧ������Ϊ%.2f��",p->a[n-1].yingfa);
    printf("\n\t�ý�ʦ��ʵ������Ϊ%.2f��\n",p->a[n-1].shifa);
    Sleep(500);
}
void input2(tea*Head)//���š��·ݡ��������ʡ�ҵ���������۳����á�Ӧ�����ʡ�ʵ������
{
    char tmp[20];
    int month;
    printf("\n\t�����빤��:");
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
            printf("\t�������·�:");
            scanf("%d",&month);
            int i;
            for(i=0;i<p->nummonth;i++)
            {
                if(p->monthhave[i]+1==month)
                    flag2=1;
            }
            if(flag2!=1)
            {
                switch(month)//�·�
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
                    printf("\t��ʾ��������1-12�·�\n");
                    break;
                }
            }
            else
            {
                printf("\n\t���·���¼��");
                break;
            }
        }while(month<1||month>12);
    }
    else
        printf("\t����Ϊ %s �Ľ�ʦδ¼��\n",tmp);
}
int choose2()
{
    int n;
    Sleep(500);
    system("cls");
    printf("\n\t------------------�޸Ĳ˵�---------------------");
    printf("\n\t------[1]�������޸Ľ�ʦ������Ϣ�͹�����Ϣ------");
    printf("\n\t------[2]�������޸Ľ�ʦ������Ϣ�͹�����Ϣ------");
    printf("\n\t------[3]ɾ��ĳһ���ŵĽ�ʦ��������Ϣ------");
    printf("\n\t------[4]�������˵�------");
    printf("\n\t***********************************************");
    printf("\n\t��ѡ��:");
    while(1)
    {
        scanf("%d",&n);
        if(n>=1&&n<=4)
        {
            return n;
        }
        else
        {
            printf("\t��ʾ��������1-4֮������֣�");
            while(getchar()!='\n');
        }
    }
}
void shownow(tea*p)
{
    int month;
    printf("\n\t����Ϊ�ý�ʦ��������Ϣ:");
    printf("\n\t������Ϣ");
    printf("\n\t%-20s  %-10s  %-20s  %-10s","����","����","ѧԺ","ְ��");
    printf("\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
    printf("\n");
    printf("\n\t������Ϣ");
    printf("\n\t%-10s  %-10s  %-10s  %-10s  %-10s  %-10s","�·�","��������","ҵ������","�۳�����","Ӧ������","ʵ������");
    for(month=0;month<(p->nummonth);month++)
    {
    printf("\n\t%d%-10s  %-10.2f  %-10.2f  %-10.2f  %-10.2f  %-10.2f",(p->monthhave[month]+1)," �·�:",p->a[p->monthhave[month]].basic,p->a[p->monthhave[month]].jintie,p->a[p->monthhave[month]].kouchu,p->a[p->monthhave[month]].yingfa,p->a[p->monthhave[month]].shifa);
    }
    printf("\n");
}
void changenow(tea*p)
{
    while(1)
    {
        char name[20];
        printf("\n\t������Ҫ�޸ĵ���Ϣ�ǻ�����Ϣ���ǹ�����Ϣ��");
        scanf("%s",name);
        if(strcmp(name,"������Ϣ")==0)
        {
            printf("\n\t�������ʦ������");
            scanf("%s",p->Name);
            printf("\t�������ʦѧԺ��");
            int c;
            printf("\t1.��ѧԺ  2.��ϢѧԺ  3.��ѧԺ  4.��ѧԺ");
            scanf("%d",&c);
            switch(c)
            {
            case 1:strcpy(p->xueyuan,"��ѧԺ");break;
            case 2:strcpy(p->xueyuan,"��ϢѧԺ");break;
            case 3:strcpy(p->xueyuan,"��ѧԺ");break;
            case 4:strcpy(p->xueyuan,"��ѧԺ");break;
            default:printf("¼�����Ϣʧ��,Ӧ����1-4֮�������\n\t");break;
            }
            printf("\t��ѡ���ʦְ�ƣ�");
		    printf("\n\t1.����  2.������  3.��ʦ  4.����\n\t") ;
	        scanf("%d",&c);
		    switch(c)
            {
            case 1: strcpy(p->job,"����");break;
            case 2:strcpy(p->job,"������");break;
            case 3:strcpy(p->job,"��ʦ");break;
            case 4:strcpy(p->job,"����");break;
            default:printf("¼�����Ϣʧ��,Ӧ����1-4֮�������");break;
            }
            printf("\n\t�޸ĳɹ�\n");
            break;
        }
        else if(strcmp(name,"������Ϣ")==0)
        {
            int n;
            int i;
            printf("\t������Ҫ�޸ĵ��·ݣ�");
            scanf("%d",&n);
            for(i=0;i<p->nummonth;i++)
            {
                if(p->monthhave[i]==n-1)
                {
                    creatmonth(p,n);
                    printf("\n\t�޸ĳɹ�\n");
                    break;
                }
            }
            if(i==p->nummonth)
            {
                printf("\n\t���·�δ¼��");
            }
            break;
        }
        else
        {
            printf("\t��ʾ�������� ������Ϣ/������Ϣ");
        }
    }
}
void change1(tea*Head)//���š�������ѧԺ��ְ�ƣ�ְ�Ʒ�Ϊ�����ڡ������ڡ���ʦ�����̡���ʦ�Ĺ�����Ϣ���������š��·ݡ��������ʡ�ҵ���������۳����á�Ӧ�����ʡ�ʵ�����ʣ�
{
    char tmp[20];
    printf("\n\t�������޸Ľ�ʦ�Ĺ���:");
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
        printf("\t����Ϊ %s �Ľ�ʦδ¼��",tmp);
    }
}
void change2(tea*Head)
{
    char tmp[20];
    printf("\n\t�������ʦ����:");
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
        printf("\n\t�������޸Ľ�ʦ�Ĺ���:");
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
            printf("\t����Ϊ %s �Ľ�ʦδ¼��",tmp);
        }
    }
    else
    {
         printf("\t����Ϊ %s �Ľ�ʦδ¼��",tmp);
    }
}
tea* del(tea*Head)
{
    tea*p,*cur;
    char l;
    p=Head;
    char tmp[20];
    printf("\n\t������Ҫɾ����ʦ�Ĺ���:");
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
        printf("\n\t�Ƿ�ȷ��ɾ�� Y/N");
        while(1)
        {
            while(getchar()!='\n');
            if(scanf("%c",&l)==1)
            {
                if(l=='y'||l=='Y')
                {
                    while(1)
                    {
                        printf("\n\t�ٴ�ȷ���Ƿ�ɾ�� Y/N");
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
                                printf("\t��ʾ��������Y/N\n\t");
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
                    printf("\t��ʾ��������Y/N\n\t");
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
            printf("\n\tɾ���ɹ�");
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
            printf("\n\tɾ���ɹ�");
            return Head;
        }
    }
    else if(tm==2)
    {
        printf("\n\t��ȡ��ɾ��");
        return Head;
    }
    else
    {
        printf("\t����Ϊ %s �Ľ�ʦδ¼��",tmp);
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
        printf("\n\tδ¼���κν�ʦ��Ϣ");
    }
}
int choose3()
{
    int n;
    Sleep(500);
    system("cls");
    printf("\n\t----------------��ѯ�˵�-----------------------");
    printf("\n\t------[1]��ʾȫ����ʦ�Ļ�����Ϣ----------------");
    printf("\n\t------[2]�����·ݲ�ѯ--------------------------");
    printf("\n\t------[3]���ݹ��ź��·ݲ�ѯ--------------------");
    printf("\n\t------[4]�����������·ݲ�ѯ--------------------");
    printf("\n\t------[5]�������˵�----------------------------");
    printf("\n\t***********************************************");
    printf("\n\t��ѡ��:");
    while(1)
    {
        scanf("%d",&n);
        if(n>=1&&n<=5)
        {
            return n;
        }
        else
        {
            printf("\t��ʾ��������1-5֮������֣�");
            while(getchar()!='\n');
        }
    }
}
void show(tea*Head)
{
    tea*p=Head;
    printf("\n\t����Ϊ���н�ʦ�����л�����Ϣ:");
    while(p)
    {
        printf("\n\t%-20s  %-10s  %-20s  %-10s","����","����","ѧԺ","ְ��");
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
    printf("\n\t������Ϣ");
    printf("\n\t%-20s  %-10s  %-20s  %-10s","����","����","ѧԺ","ְ��");
    printf("\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
    printf("\n\t������Ϣ");
    printf("\n\t%-10s  %-10s  %-10s  %-10s  %-10s  %-10s","�·�","��������","ҵ������","�۳�����","Ӧ������","ʵ������");
    printf("\n\t%d%-10s  %-10.2f  %-10.2f  %-10.2f  %-10.2f  %-10.2f",month," �·�:",p->a[p->monthhave[month-1]].basic,p->a[month-1].jintie,p->a[month-1].kouchu,p->a[month-1].yingfa,p->a[month-1].shifa);
}
void shownow3(tea*p,int month)
{
    printf("\n\t������Ϣ");
    printf("\n\t%-20s  %-10s  %-20s  %-10s","����","����","ѧԺ","ְ��");
    printf("\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
    printf("\n\t������Ϣ");
    printf("\n\t%-10s  %-10s  %-10s  %-10s  %-10s  %-10s","�·�","��������","ҵ������","�۳�����","Ӧ������","ʵ������");
    printf("\n\t�ý�ʦ %d �¹�����Ϣδ¼��",month);
}
void shownow4(tea*p,int month)
{
    printf("\n\t%d%-10s  %-10s  %-10.2f  %-10.2f  %-10.2f  %-10.2f  %-10.2f",month," �·�:",p->Id,p->a[p->monthhave[month-1]].basic,p->a[month-1].jintie,p->a[month-1].kouchu,p->a[month-1].yingfa,p->a[month-1].shifa);
}
void research3(tea*Head)
{
    char tmp[20];
    int month;
    printf("\n\t�����빤��:");
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
        printf("\t�������·�:");
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
            printf("\n\tδ¼����·ݵ���Ϣ");
    }
    else
        printf("\t����Ϊ %s �Ľ�ʦδ¼��\n",tmp);
}
void research4(tea*Head)
{
    char tmp[20];
    int month;
    printf("\n\t�������ʦ����:");
    scanf("%s",tmp);
    printf("\t�������·�:");
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
         printf("\t����Ϊ %s �Ľ�ʦδ¼��",tmp);
}
void show1(int flag)
{
    if(flag==0)
    {
        printf("\n\t������Ϣ");
        printf("\n\t%-10s  %-10s  %-10s  %-10s  %-10s  %-10s  %-10s","�·�","����","��������","ҵ������","�۳�����","Ӧ������","ʵ������");
    }
}
void research2(tea*Head,int count)
{
    paixu(Head,count);
    tea*p=Head;
    int month;
    int i;
    int flag=0;
    printf("\n\t�������ѯ���·�");
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
        printf("\n\tδ¼����·���Ϣ");
}
int choose4()
{
    int n;
    Sleep(500);
    system("cls");
    printf("\n\t---------------¼��˵�-----------------------");
    printf("\n\t------[1]�����·ݷ�����ͬѧԺ�Ľ�ʦ��Ϣ--------");
    printf("\n\t------[2]�����·ݷ�����ְͬ�ƵĽ�ʦ��Ϣ--------");
    printf("\n\t------[3]�������˵�----------------------------");
    printf("\n\t*****************************");
    printf("\n\t��ѡ��:");
    while(1)
    {
        scanf("%d",&n);
        if(n>=1&&n<=3)
        {
            return n;
        }
        else
        {
            printf("\t��ʾ��������1-3֮������֣�");
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
    int caver[4]={0};//ͳ��ѧԺ����
    anal anal1[4];//0.��ѧԺ  1.��ϢѧԺ  2.��ѧԺ  3.��ѧԺ"      //aver1ΪӦ��  aver2Ϊʵ��
    int i;
    for(i=0;i<4;i++)//��ʼ��
    {
        anal1[i].aver1=0;
        anal1[i].aver2=0;
    }
    strcpy(anal1[0].namexue,"��ѧԺ");
    strcpy(anal1[1].namexue,"��ϢѧԺ");
    strcpy(anal1[2].namexue,"��ѧԺ");
    strcpy(anal1[3].namexue,"��ѧԺ");
    printf("\n\t�������·�");
    scanf("%d",&month);
    while(p)
    {
        for(i=0;i<p->nummonth;i++)
        {
            if(month==p->monthhave[i]+1)
            {
                flag=1;
                if(strcmp(p->xueyuan,"��ѧԺ")==0)
                {
                    anal1[0].aver1+=p->a[month-1].yingfa;
                    anal1[0].aver2+=p->a[month-1].shifa;
                    caver[0]++;
                }
                if(strcmp(p->xueyuan,"��ϢѧԺ")==0)
                {
                    anal1[1].aver1+=p->a[month-1].yingfa;
                    anal1[1].aver2+=p->a[month-1].shifa;
                    caver[1]++;
                }
                if(strcmp(p->xueyuan,"��ѧԺ")==0)
                {
                    anal1[2].aver1+=p->a[month-1].yingfa;
                    anal1[2].aver2+=p->a[month-1].shifa;
                    caver[2]++;
                }
                if(strcmp(p->xueyuan,"��ѧԺ")==0)
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
            printf("\n\t���·�δ¼��");
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
    printf("\n\t%-10s  %-20s  %-20s","ѧԺ��","ƽ��Ӧ������","ƽ��ʵ������");
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
    int caver[4]={0};//ͳ��ְλ����
    anal anal1[4];//0.����  1.������  2.��ʦ  3.����      //aver1ΪӦ��  aver2Ϊʵ��
    int i;
    for(i=0;i<4;i++)//��ʼ��
    {
        anal1[i].aver1=0;
        anal1[i].aver2=0;
    }
    strcpy(anal1[0].namexue,"����");
    strcpy(anal1[1].namexue,"������");
    strcpy(anal1[2].namexue,"��ʦ");
    strcpy(anal1[3].namexue,"����");
    printf("\n\t�������·�");
    scanf("%d",&month);
    while(p)
    {
        for(i=0;i<p->nummonth;i++)
        {
            if(month==p->monthhave[i]+1)
            {
                flag=1;
                if(strcmp(p->job,"����")==0)
                {
                    anal1[0].aver1+=p->a[month-1].yingfa;
                    anal1[0].aver2+=p->a[month-1].shifa;
                    caver[0]++;
                }
                if(strcmp(p->job,"������")==0)
                {
                    anal1[1].aver1+=p->a[month-1].yingfa;
                    anal1[1].aver2+=p->a[month-1].shifa;
                    caver[1]++;
                }
                if(strcmp(p->job,"��ʦ")==0)
                {
                    anal1[2].aver1+=p->a[month-1].yingfa;
                    anal1[2].aver2+=p->a[month-1].shifa;
                    caver[2]++;
                }
                if(strcmp(p->job,"����")==0)
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
            printf("\n\t���·�δ¼��");
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
    printf("\n\t%-10s  %-20s  %-20s","ְλ��","ƽ��Ӧ������","ƽ��ʵ������");
    for(i=0;i<4;i++)
    {
        printf("\n\t%-10s  %-20.2f  %-20.2f",anal1[i].namexue,anal1[i].aver1,anal1[i].aver2);
    }
}
void freeall(tea*Head)//�ͷ��ڴ�
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
    if((pf=fopen("��У��ʦ���ʹ���ϵͳ-��ʦ������Ϣ.txt","w"))==NULL)
    {
        printf("\n\t%s",strerror(errno));
    }
    else
    {
        tea*p=Head;
        fprintf(pf,"\t����Ϊ���н�ʦ�����л�����Ϣ:");
        fprintf(pf,"\n\t%-20s %-10s %-20s %-10s","����","����","ѧԺ","ְ��");
        while(p)
        {
            fprintf(pf,"\n\t%-20s  %-10s  %-20s  %-10s",p->Id,p->Name,p->xueyuan,p->job);
            p=p->next;
        }
        fclose(pf);
    }
    FILE*pf1;
    pf1=NULL;
    if((pf1=fopen("��У��ʦ���ʹ���ϵͳ-��ʦ������Ϣ.txt","w"))==NULL)
    {
        printf("\n\t%s",strerror(errno));
    }
    else
    {
        int month;
        tea*p1=Head;
        fprintf(pf1,"\t����Ϊ���н�ʦ�����й�����Ϣ:");
        fprintf(pf1,"\n\t%-10s\t%-10s%-10s\t%-10s\t%-10s\t%-10s\t%-10s","  �·ݣ�","����"," ��������"," ҵ������"," �۳�����"," Ӧ������"," ʵ������");
        while(p1)
        {
            for(month=0;month<(p1->nummonth);month++)
            {
                fprintf(pf1,"\n\t%d%-10s\t%-10s\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f",(p1->monthhave[month]+1)," �·�:",p1->Id,p1->a[p1->monthhave[month]].basic,p1->a[p1->monthhave[month]].jintie,p1->a[p1->monthhave[month]].kouchu,p1->a[p1->monthhave[month]].yingfa,p1->a[p1->monthhave[month]].shifa);
            }
            p1=p1->next;
        }
        fclose(pf1);

    }
    FILE*pf2;
    pf2=NULL;
    if((pf2=fopen("��У��ʦ���ʹ���ϵͳ-¼���·�ͳ��.txt","w"))==NULL)
    {
        printf("\n\t%s",strerror(errno));
    }
    else
    {
        int s;
        tea*p2=Head;
        while(p2)
        {
            fprintf(pf2,"\t%-10s %-10s","����","¼���·�ͳ������");
            fprintf(pf2,"\n\t%-10s  %-10d  ",p2->Id,p2->nummonth);
            fprintf(pf2,"\n\t��¼���·ݣ�");
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
    if((pf=fopen("��У��ʦ���ʹ���ϵͳ-��ʦ������Ϣ.txt","r"))==NULL)
    {
         if(*count!=0)
         printf("\n\t%s-��У��ʦ���ʹ���ϵͳ-��ʦ������Ϣ.txt",strerror(errno));
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
    if((pf2=fopen("��У��ʦ���ʹ���ϵͳ-¼���·�ͳ��.txt","r"))==NULL)
    {
        printf("\n\t%s-��У��ʦ���ʹ���ϵͳ-¼���·�ͳ��.txt",strerror(errno));
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
    if((pf1=fopen("��У��ʦ���ʹ���ϵͳ-��ʦ������Ϣ.txt","r"))==NULL)
    {
        printf("\n\t%s-��У��ʦ���ʹ���ϵͳ-��ʦ������Ϣ.txt",strerror(errno));
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
