#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<windows.h>
//���š�������ѧԺ��ְ�ƣ�ְ�Ʒ�Ϊ�����ڡ������ڡ���ʦ�����̡���ʦ�Ĺ�����Ϣ���������š��·ݡ��������ʡ�ҵ���������۳����á�Ӧ�����ʡ�ʵ�����ʣ�
typedef struct teachermoney
{
    float basic;
    float jintie;
    float kouchu;
    float yingfa;
    float shifa;
}money;
typedef struct teacher
{
    char Id[20];
    char Name[10];
    char xueyuan[20];
    char job[10];
    money a[12];
    int monthhave[12];//�����������·�
    int nummonth;//�洢�����·ݵ�����
    struct teacher*next;
}tea;
typedef struct analyse
{
    char namexue[10];
    float aver1;
    float aver2;
}anal,*anl;
void sys();
int choose();
tea* input1(int*,tea*);
void input2(tea*);
int choose2();
void change1(tea*);
void change2(tea*);
tea* del(tea*);
void research1(tea*,int );
int choose3();
void research2(tea*,int );
void research3(tea*);
void research4(tea*);
int choose4();
void analyse1(tea*);
void analyse2(tea*);
void freeall(tea*);
void write(tea*);
tea* read(tea*,int*);
