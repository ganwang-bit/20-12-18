#include"my_stdio.h"
void menu()
{
    printf("\n\t--------------------WELCOME--------------------\n");
    printf("\n\t***************��ʦ���ʹ���ϵͳ***************\n\n");
    printf("\n\t---------------[1]�����ʦ��Ϣ������---------------");
    printf("\n\t---------------[2]�޸Ľ�ʦ��Ϣ������---------------");
    printf("\n\t---------------[3]��ѯ����ʾ---------------");
    printf("\n\t---------------[4]ͳ�Ʒ���---------------");
    printf("\n\t---------------[5]�˳�-----------------");
    printf("\n\t**********************************************");
    printf("\n\t��ѡ��:");
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
    tea* Head=NULL;//ͷ���
    Head=read(Head,num);
    while(1)
    {
        menu();
        if(scanf("%d",&n)==1)
        {
            switch(n)
            {
            case Input://����
                m=choose();//������Ϣ/������Ϣ
                if(m==1)
                    Head=input1(num,Head);//������Ϣ
                else if(m==2)
                    input2(Head);//������Ϣ
                else;

                write(Head);
                sys();
                break;
            case Change://�޸�
                m=choose2();//����/����
                if(m==1)
                    change1(Head);//�������޸�
                else if(m==2)
                    change2(Head);//�������޸�
                else if(m==3)
                    Head=del(Head);//ɾ��
                else;
                write(Head);
                sys();
                break;
            case Search://��ѯ����ʾ
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
            case Analyse://ͳ�Ʒ���
                m=choose4();
                if(m==1)
                    analyse1(Head);
                else if(m==2)
                    analyse2(Head);
                else;
                sys();
                break;
            case Exit://�˳�
                printf("\n\t���򼴽��˳�");
                printf("\n\t�Ƿ�ȷ���˳� Y/N");
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
                            printf("\t��ʾ��������Y/N");
                        }
                    }
                }
                sys();
                break;
            default:
                printf("\n\t����ȷ����1-5֮������֣�");
            }
        }
        else
        {
             printf("\n\t��ʾ������ȷ����1-5֮������֣�");
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
