#include<stdio.h>
#include<string.h>
#define N 5
char stu_name[10][100],stu_sex[100];
double stu_num[100];
int stu_c[100],stu_math[100],stu_english[100];
void fun()  //����ѧ���Ļ�����Ϣ
{ int i;
{printf("���������֣�\n");
for(i=0;i<N;i++)
        scanf("%s",stu_name[i]);
		printf("������ѧ�ţ�\n");
		for(i=0;i<N;i++)
     scanf("%ld",&stu_num[i]);
	 printf("�������Ա�\n");
for(i=0;i<10;i++)
          scanf("%c",&stu_sex[i]);
        printf("������c�̳ɼ���\n");
for(i=0;i<N;i++)
               scanf("%d",&stu_c[i]);
printf("����������ɼ���\n");
for(i=0;i<N;i++)
                   scanf("%d",&stu_math[i]);
printf("������Ӣ��ɼ���\n");
for(i=0;i<N;i++)
             scanf("%d",&stu_english[i]);
}
}
void fun1()
{int i=N+1;

printf("���������֣�\n");
        scanf("%s",stu_name[i]);
		printf("������ѧ�ţ�\n");
     scanf("%ld",&stu_num[i]);
	 printf("�������Ա�\n");
    scanf("%c",&stu_sex[i]);
printf("������c�̳ɼ���\n");
               scanf("%d",&stu_c[i]);
printf("����������ɼ���\n");
                   scanf("%d",&stu_math[i]);
printf("������Ӣ��ɼ���\n");
             scanf("%d",&stu_english[i]);
}

void fun2()//���ѧ���Ļ�����Ϣ
{ int i;
for(i=0;i<N;i++)
{
printf("%ld\t%s\t%c\n",stu_num[i],stu_name[i],stu_sex[i]);
printf("%d\t%d\t%d\n",stu_c[i],stu_math[i],stu_english[i]);
}
}

void fun3()//����ѧ��
{char name[100];
int k,f=0;
printf("����������Ҫ���ҵ�����: ");
gets(name);
for(k=0;k<N;k++)
if(strcmp(name,stu_name[k])==0)
{ printf("%ld,%s,%c,%d,%d,%d",stu_num[k],stu_name[k],stu_sex[k],stu_c[k],stu_math[k],stu_english[k]);
f=1;
}
 else if(f=0)
printf("ľ�������~~~TOT");
}
void fun4()//ɾ��ѧ��
{

 int k;
char newname[100];
printf("�������ѧ�������֣�\n");
gets(newname);
for(k=0;k<N;k++)
if(strcmp(newname,stu_name[k])==0)
{
stu_num[k]=stu_num[k+1];
strcpy(stu_name[k],stu_name[k+1]);
stu_sex[k]=stu_sex[k+1];
stu_c[k]=stu_c[k+1];
stu_math[k]=stu_math[k+1];
stu_english[k]=stu_english[k+1];
fun2();
}
printf("ѧ����¼ɾ����ϣ�");
}

int main()
{fun();
	int choose;
printf("*********************************************\n");
printf("*************ѧ���ɼ��������****************\n");
printf("*********************************************\n");
printf("***********************************��ӭʹ�ã�\n");
printf("1..............................���\n");
printf("2..............................��ʾ\n");
printf("3..............................��ѯ\n");
printf("4..............................ɾ��\n");

printf("��������Ҫ���еĲ�����\n");
scanf("%d",&choose);
while(choose!=1&&choose!=2&&choose!=3&&choose!=4)
{ printf("���ֶ�Ҳ����߹~~~~�ٰ���� ~ ������� ^_^");
scanf("%d",&choose);
}
while(choose==1||choose==2||choose==3||choose==4)
{switch(choose)
{
case 1:fun1(); break;
case 2:fun2(); break;
case 3:fun3(); break;
case 4:fun4(); break;
}
printf("��������Ҫ���еĲ�����\n");
scanf("%d",&choose);
}
  return 0;
}
