#include<stdio.h>
#include<string.h>
#define N 5
char stu_name[10][100],stu_sex[100];
double stu_num[100];
int stu_c[100],stu_math[100],stu_english[100];
void fun()  //输入学生的基本信息
{ int i;
{printf("请输入名字：\n");
for(i=0;i<N;i++)
        scanf("%s",stu_name[i]);
		printf("请输入学号：\n");
		for(i=0;i<N;i++)
     scanf("%ld",&stu_num[i]);
	 printf("请输入性别\n");
for(i=0;i<10;i++)
          scanf("%c",&stu_sex[i]);
        printf("请输入c程成绩：\n");
for(i=0;i<N;i++)
               scanf("%d",&stu_c[i]);
printf("请输入高数成绩：\n");
for(i=0;i<N;i++)
                   scanf("%d",&stu_math[i]);
printf("请输入英语成绩：\n");
for(i=0;i<N;i++)
             scanf("%d",&stu_english[i]);
}
}
void fun1()
{int i=N+1;

printf("请输入名字：\n");
        scanf("%s",stu_name[i]);
		printf("请输入学号：\n");
     scanf("%ld",&stu_num[i]);
	 printf("请输入性别\n");
    scanf("%c",&stu_sex[i]);
printf("请输入c程成绩：\n");
               scanf("%d",&stu_c[i]);
printf("请输入高数成绩：\n");
                   scanf("%d",&stu_math[i]);
printf("请输入英语成绩：\n");
             scanf("%d",&stu_english[i]);
}

void fun2()//输出学生的基本信息
{ int i;
for(i=0;i<N;i++)
{
printf("%ld\t%s\t%c\n",stu_num[i],stu_name[i],stu_sex[i]);
printf("%d\t%d\t%d\n",stu_c[i],stu_math[i],stu_english[i]);
}
}

void fun3()//查找学生
{char name[100];
int k,f=0;
printf("请输入您所要查找的姓名: ");
gets(name);
for(k=0;k<N;k++)
if(strcmp(name,stu_name[k])==0)
{ printf("%ld,%s,%c,%d,%d,%d",stu_num[k],stu_name[k],stu_sex[k],stu_c[k],stu_math[k],stu_english[k]);
f=1;
}
 else if(f=0)
printf("木有这个人~~~TOT");
}
void fun4()//删除学生
{

 int k;
char newname[100];
printf("请输入该学生的名字！\n");
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
printf("学生记录删除完毕！");
}

int main()
{fun();
	int choose;
printf("*********************************************\n");
printf("*************学生成绩管理程序****************\n");
printf("*********************************************\n");
printf("***********************************欢迎使用！\n");
printf("1..............................添加\n");
printf("2..............................显示\n");
printf("3..............................查询\n");
printf("4..............................删除\n");

printf("请输入您要进行的操作：\n");
scanf("%d",&choose);
while(choose!=1&&choose!=2&&choose!=3&&choose!=4)
{ printf("数字多也表按错吖~~~~再按遍吧 ~ 看清楚咯 ^_^");
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
printf("请输入您要进行的操作：\n");
scanf("%d",&choose);
}
  return 0;
}
