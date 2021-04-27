#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "windows.h"
#define len sizeof(struct student)
#define min 0
#define max 100

struct student
{
	char xuehao[200];
	char name[50];
	double shuxue;
	double yuwen;
	double c;
	double yingyu;
	double wuli;
	double huaxue;
	double zongfen;
	double pingjunfen;
	struct student* next;
};
void print()
{
	printf("学号                  姓名       数学成绩       语文成绩       C语言成绩     英语成绩成绩     物理成绩     化学成绩     总分     平均分\n");
}

struct student* read(void)
{
	struct student* head = NULL;
	struct student* p1, * p2=NULL;

	FILE* fp, * FP;
	if ((fp = fopen("student.txt", "rb+")) == NULL)
	{
		FP = fopen("student.txt", "w+");
		fclose(FP);
		fp = fopen("student.txt", "rb+");

	}
	while (!feof(fp))
	{
		if ((p1 = (struct student*)malloc(len)) == NULL)
		{
			printf("内存申请出错\n");
			fclose(fp);
			exit(0);
		}
		if (fread(p1, len, 1, fp) != 1)
		{
			free(p1);
			break;
		}
		if (head == NULL)
			head = p2 = p1;
		else {
			p2->next = p1;
			p2 = p1;
		}
	}
	fclose(fp);
	return head;
}


void store(struct student* head)
{
	struct student* p = head;
	FILE* w = fopen("C:\用户\DELL\文档\student.txt", "ab+");
	if (w == NULL)
	{
		printf("打开文件失败!");
		return;
	}
	while (p)
	{
		fprintf(w, "%s %s %lf %lf %lf %lf %lf %lf %.2lf %.2lf", p->xuehao, p->name, p->shuxue, p->yuwen, p->c, p->yingyu, p->wuli, p->huaxue, p->zongfen, p->pingjunfen);
		p = p->next;
	}
	printf("\n\n");
	fprintf(w, "\n");
	printf("存储成功!\n");
	fclose(w);
	return;
}

//展示学生的成绩
void zhanshi(struct student* head)
{
	struct student* p;
	p = head;
	if (head = NULL)
		printf("数据库中暂无数据，请输入数据");
	print();
	for (; p != NULL; p = p->next)
	{
		printf("%s%13s%14.2lf%16.2lf%15.2lf%16.2f%15.2lf%12.2lf%13.2lf%9.2lf\n", p->xuehao, p->name, p->shuxue, p->yuwen, p->c, p->yingyu, p->wuli, p->huaxue, p->zongfen, p->pingjunfen);
	}
}

//升序或降序展示学生的成绩
void paixu(struct student* head)
{
	struct student* p, * q, * p2, * q2, * k, * m;
	m = head;
	k = NULL;
	p2 = q2 = p = q = head;
	int a;
	int b, e;
	char xuehao[200];
	char name[50];
	double shuxue;
	double yuwen;
	double c;
	double yingyu;
	double wuli;
	double huaxue;
	double zongfen;
	double pingjunfen;
	printf("请选择升序展排序或降序排序.升序排序请输入'1',反之请输入'0':");
	for (;;)
	{
		scanf("%d", &a);
		if (a == 1 || a == 0)
			break;
		else
			printf("输入选项非法，请重新输入\n");
	}

	if (a == 1)
	{
		for (b = 0; p->next != NULL; b++, p = p->next)
		{
			for (q = p->next; q != NULL; q = q->next)
			{
				if (p->zongfen > q->zongfen)
				{
					if (b != 0)
					{
						if (p->next != q)
						{
							if (q->next != NULL)
							{
								k = p->next;
								p2->next = q;
								q2->next = p;
								p->next = q->next;
								q->next = k;
								k = p;
								p = q;
								q = k;
							}
							else
							{
								q->next = q2;
								q2->next = p;
								p->next = NULL;
								p2->next = q;
								k = q;
								q = p;
								p = k;
							}
						}
						else
						{
							p->next = q->next;
							q->next = p;
							p2->next = q;
							k = p;
							p = q;
							q2 = p;
							q = k;
						}

					}
					else
					{
						if (head->next != q)
						{
							if (q->next != NULL)
							{
								k = head->next;
								head->next = q->next;
								q->next = k;
								q2->next = head;
								head = q;
								q = q2->next;
								p = head;
								p2 = head;
							}
							if (q->next == NULL)
							{
								q->next = head->next;
								q2->next = head;
								head->next = NULL;
								k = head;
								head = q;
								q = q2->next;
								p = head;
								p2 = head;
							}
						}
						if (head->next == q)
						{
							head->next = q->next;
							q->next = head;
							k = head;
							head = q;
							q = k;
							p = head;
							p2 = head;
							q2 = head;
						}
					}
				}
				q2 = q2->next;
			}
			if (b != 0)
				p2 = p2->next;
			q2 = p->next;
		}
	}
	else
	{
		for (b = 0; p->next != NULL; b++, p = p->next)
		{
			for (q = p->next; q != NULL; q = q->next)
			{
				if (p->zongfen < q->zongfen)
				{
					if (b != 0)
					{
						if (p->next != q)
						{
							if (q->next != NULL)
							{
								k = p->next;
								p2->next = q;
								q2->next = p;
								p->next = q->next;
								q->next = k;
								k = p;
								p = q;
								q = k;
							}
							else
							{
								q->next = q2;
								q2->next = p;
								p->next = NULL;
								p2->next = q;
								k = q;
								q = p;
								p = k;
							}
						}
						else
						{
							p->next = q->next;
							q->next = p;
							p2->next = q;
							k = p;
							p = q;
							q2 = p;
							q = k;
						}
					}
					else
					{
						if (head->next != q)
						{
							if (q->next != NULL)
							{
								k = head->next;
								head->next = q->next;
								q->next = k;
								q2->next = head;
								head = q;
								q = q2->next;
								p = head;
								p2 = head;
							}
							if (q->next == NULL)
							{
								q->next = head->next;
								q2->next = head;
								head->next = NULL;
								k = head;
								head = q;
								q = k;
								p = head;
								p2 = head;
							}
						}
						if (head->next == q)
						{
							head->next = q->next;
							q->next = head;
							k = head;
							head = q;
							q = k;
							p = head;
							p2 = head;
							q2 = head;
						}
					}
				}
				q2 = q2->next;
			}
			if (b != 0)
				p2 = p2->next;
			q2 = p->next;
		}
	}

	print();
	for (p = head; p != NULL; p = p->next)
	{
		printf("%s%13s%14.2lf%16.2lf%15.2lf%16.2f%15.2lf%12.2lf%13.2lf%9.2lf\n", p->xuehao, p->name, p->shuxue, p->yuwen, p->c, p->yingyu, p->wuli, p->huaxue, p->zongfen, p->pingjunfen);
	}

}
//按姓名查找某个学生的成绩信息
void chazhao2(struct student* head)
{
	int a;
	char xuehao[200];
	char name[50];
	double shuxue;
	double yuwen;
	double c;
	double yingyu;
	double wuli;
	double huaxue;
	double zongfen;
	double pingjunfen;
	struct student* p;
	p = head;
	if (head == NULL)
	{
		printf("系统中暂无学生信息，请先输入学生的信息");
		return;
	}
	for (;;)
	{
		p = head;
		printf("请输入你想要查找的学生的姓名");
		scanf("%s", name);
		for (; p != NULL; p = p->next)
		{
			if (strcmp(name, p->name) == 0)
			{
				print();
				printf("%s%13s%14.2lf%16.2lf%15.2lf%16.2f%15.2lf%12.2lf%13.2lf%9.2lf\n", p->xuehao, p->name, p->shuxue, p->yuwen, p->c, p->yingyu, p->wuli, p->huaxue, p->zongfen, p->pingjunfen);

			}
		}
		printf("是否要继续查找?是请输入'1'，反之输入'0'\n");
		for (;;)
		{
			scanf("%d", &a);
			if (a == 1 || a == 0)
				break;
			else
			{
				printf("输入选项有误，请重新输入\n");
			}
		}
		if (a == 0)
			return;

	}
}
//按学号查找某个学生成绩信息
void chazhao(struct student* head)
{
	int a, o = 0;
	char xuehao[200];
	char name[50];
	double shuxue;
	double yuwen;
	double c;
	double yingyu;
	double wuli;
	double huaxue;
	double zongfen;
	double pingjunfen;
	struct student* p;
	p = head;
	if (head == NULL)
	{
		printf("系统中暂无学生信息，请先输入学生的信息");
		return;
	}
	for (;;)
	{
		p = head;
		printf("请输入你想要查找的学生的学号:");
		scanf("%s", xuehao);
		for (; p != NULL; p = p->next)
		{
			if (strcmp(xuehao, p->xuehao) == 0)
			{
				print();
				printf("%s%13s%14.2lf%16.2lf%15.2lf%16.2f%15.2lf%12.2lf%13.2lf%9.2lf\n", p->xuehao, p->name, p->shuxue, p->yuwen, p->c, p->yingyu, p->wuli, p->huaxue, p->zongfen, p->pingjunfen);
				o = 1;
			}
		}
		if (o == 0)
		{
			printf("该学生不存在");
			o = 0;
		}
		printf("是否要继续查找?是请输入'1'，反之输入'0'\n");
		for (;;)
		{
			scanf("%d", &a);
			if (a == 1 || a == 0)
				break;
			else
			{
				printf("输入选项有误，请重新输入\n");
			}
		}
		if (a == 0)
			return;
	}
}

//修改学生信息
void xiugaixinxi(struct student* head)
{
	char xuehao[200], name[100];
	double shuxue;
	double yuwen;
	double c;
	double yingyu;
	double wuli;
	double huaxue;
	double zongfen;
	double pingjunfen;
	int chengji, xuhao, k = 0, t;
	struct student* p, * q;
	p = head;
	if (head == NULL)
	{
		printf("系统中暂无学生信息，请先输入学生的信息");
		return;
	}
	for (k = 0;;)
	{
		p = head;
		printf("请输入你要修改信息的学生的学号(输入no结束替换):\n");
		scanf("%s", xuehao);
		for (; p != NULL; p = p->next)
		{
			if (strcmp(xuehao, "no") == 0)return;
			if (strcmp(p->xuehao, xuehao) == 0)
			{
				k = 1;
				printf("                        学生各信息序号如下                    \n");
				printf("1-学号 2-姓名 3-数学成绩 4-语文成绩 5-C语言成绩 6-英语成绩 7-物理成绩 8-化学成绩\n");
				printf("请输入你要修改的信息的序号:\n");
				while (true)
				{
					scanf("%d", &xuhao);
					if (xuhao < 1 || xuhao>8)
					{
						printf("输入非法请重新输入\n");
						printf("请输入你要修改的信息的序号:");
					}
					if (xuhao >= 1 && xuhao <= 8)
						break;
				}
				printf("\n");
				if (xuhao == 1)
				{
					printf("原先学号为:%s\n", p->xuehao);
					printf("请输入新学号(回车键结束替换):");
					scanf("%s", xuehao);
					if (xuehao[0] == NULL)
						return;
					strcpy(p->xuehao, xuehao);
					printf("\n");
					printf("替换成功\n");
				}
				if (xuhao == 2)
				{
					printf("原先姓名为:%s\n", p->name);
					printf("请输入新姓名(回车键结束替换):");
					scanf("%s", name);
					if (name[0] == NULL)
						return;
					strcpy(p->name, name);
					printf("\n");
					printf("替换成功\n");
				}
				if (xuhao == 3)
				{
					printf("原先数学成绩为:%lf\n", p->shuxue);
					printf("请输入新数学成绩(回车键结束):");
					scanf("%lf", &shuxue);
					if (shuxue == NULL)
						return;
					p->shuxue = shuxue;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("替换成功\n");
				}
				if (xuhao == 4)
				{
					printf("原先语文成绩为:%lf\n", p->yuwen);
					printf("请输入新语文成绩(回车键结束):");
					scanf("%lf", &yuwen);
					if (yuwen == NULL)
						return;
					p->yuwen = yuwen;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("替换成功\n");
				}
				if (xuhao == 5)
				{
					printf("原先C语言成绩为:%lf\n", p->c);
					printf("请输入新C语言成绩(回车键结束):");
					scanf("%lf", &c);
					if (c == NULL)
						return;
					p->c = c;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("替换成功\n");
				}
				if (xuhao == 6)
				{
					printf("原先英语成绩为:%lf\n", p->yingyu);
					printf("请输入新英语成绩(回车键结束):");
					scanf("%d", &yingyu);
					if (yingyu == NULL)
						return;
					p->yingyu = yingyu;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("替换成功");
				}
				if (xuhao == 7)
				{
					printf("原先物理成绩为:%lf\n", p->wuli);
					printf("请输入新物理成绩(回车键结束):");
					scanf("%lf", &wuli);
					if (wuli == NULL)
						return;
					p->wuli = wuli;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("替换成功");
				}
				if (xuhao == 8)
				{
					printf("原先化学成绩为:%lf\n", p->huaxue);
					printf("请输入新物理成绩(回车键结束):");
					scanf("%lf", &huaxue);
					if (huaxue == NULL)
						return;
					p->huaxue = huaxue;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("替换成功");
				}
			}
			if (k == 0)
				printf("成绩库中无该学生,请检查学号是否输入正确\n");
			printf("是否要继续修改学生信息？ 如果是请输入1，反之输入0\n");
			while (true)
			{
				printf("请输入(1或0):\n");
				scanf("%d", &t);
				if (t != 0 && t != 1)
					printf("输入非法，请重新输入\n");
				if (t == 0)
					return;
			}
		}
	}
}

//删除学生信息
struct student* shanchu(struct student* head)
{
	char cc[100];
	int e = 0;
	struct student* p, * q;
	char xuehao[200];
	if (head == NULL)
	{
		printf("系统中暂无学生信息,请先输入学生的信息\n");
		return head;
	}
	for (;;)
	{
		p = head->next;
		q = head;
		printf("请输入你要删除的学生的学号(输入no结束删除):\n");
		scanf("%s", xuehao);
		if (strcmp(xuehao, "no") == 0)return head;
		printf("%s 请确认此学号为你要删除学号如果是请输入yes,并执行删除程序，输入no取消删除", xuehao);
		while (true)
		{
			scanf("%s", cc);
			if (strcmp(cc, "no") != 0 && strcmp(cc, "yes") != 0)
				printf("输入非法请重新输入");
			else
				break;
		}
		if (strcmp(cc, "yes") == 0)
		{
			if (strcmp(head->xuehao, xuehao) == 0)
			{
				head->next = NULL;
				free(head);
				head = p;
				q = p;
				printf("删除成功\n");

			}
			else
			{
				for (e = 0; p != NULL; e++)
				{
					if (strcmp(p->xuehao, xuehao) == 0)
					{
						q->next = p->next;
						p->next = NULL;
						free(p);
						p = q;
						printf("删除成功\n");
						break;
					}
					p = p->next;
					q = q->next;
				}
			}
		}
		printf("如果仍需删除学生信息,请输入学号，反之输入no结束删除\n");
	}
}
//初始化链表
void chushihua(struct student* p)
{
	p = (struct student*)malloc(len);
	p->next = NULL;
}

//欢迎界面
void huanying()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                    ------------------------------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ***********************  欢迎登录学生成绩管理平台 *************************  \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ------------------------------------------------------------------------------");
}

//功能菜单
void gongnengcaidan()
{
	printf("                                   |————————————————————————|\n");
	printf("                                   |                                                |\n");
	printf("                                   |              学生成绩管理系统功能表            |\n");
	printf("                                   |                                                |\n");
	printf("                                   |               0.退出系统                       |\n");
	printf("                                   |               1.增添新的学生成绩               |\n");
	printf("                                   |               2.删除学生成绩信息               |\n");
	printf("                                   |               3.修改学生成绩                   |\n");
	printf("                                   |               4.查找某个学生成绩               |\n");
	printf("                                   |               5.按照学生成绩升序或降序展示     |\n");
	printf("                                   |               6.浏览全部学生信息               |\n");
	printf("                                   |                                                |\n");
	printf("                                   |————————————————————————|\n");
}

//输入学生数据
struct student* shuru(struct student* p)
{
	struct student* q;
	int a, b;
	char xuehao[200];
	char name[50];
	double shuxue;
	double yuwen;
	double c;
	double yingyu;
	double wuli;
	double huaxue;
	double zongfen;
	double pingjunfen;
	struct student* m;
	m = p;
	printf("请输入学生成绩信息,如果输入完毕在学号中输入no即退出输入程序\n");
	printf("输入顺序为:学号 姓名 数学成绩 语文成绩 C语言成绩 英语成绩 物理成绩 化学成绩\n");
	for (a = 0;; a++)
	{
		printf("学号:");
		scanf("%s", xuehao);
		if (strcmp(xuehao, "no") == 0)
		{
			return m;
		}
		printf("姓名:");
		scanf("%s", name);
		printf("数学:");
		for (;;) {
			scanf("%lf", &shuxue);
			if (shuxue<min || shuxue>max)
			{
				printf("成绩输入错误请重新输入\n");
				printf("数学:");
				scanf("%lf", &shuxue);

			}
			else
				break;
		}
		printf("语文:");
		scanf("%lf", &yuwen);
		for (;;)
		{
			if (yuwen<min || yuwen>max)
			{
				printf("成绩输入错误请重新输入\n");
				printf("语文");
				scanf("%lf", &yuwen);

			}
			else
				break;
		}
		printf("C语言:");
		scanf("%lf", &c);
		for (;;)
		{
			if (c<min || c>max)
			{
				printf("成绩输入错误请重新输入\n");
				printf("C语言:");
				scanf("%lf", &c);
			}
			else
				break;
		}
		printf("英语:");
		scanf("%lf", &yingyu);
		for (;;)
		{
			if (yingyu<min || yingyu>max)
			{
				printf("成绩输入错误请重新输入\n");
				printf("英语");
				scanf("%lf", &yingyu);
			}
			else
				break;

		}
		printf("物理:");
		scanf("%lf", &wuli);
		for (;;)
		{
			if (wuli<min || wuli>max)
			{
				printf("成绩输入错误请重新输入\n");
				printf("物理");
				scanf("%lf", &wuli);
			}
			else
				break;
		}
		printf("化学:");
		scanf("%lf", &huaxue);
		for (;;)
		{
			if (yingyu<min || yingyu>max)
			{
				printf("成绩输入错误请重新输入\n");
				printf("化学:");
				scanf("%lf", &huaxue);
			}
			else
				break;
		}
		if (a == 0)
		{

			q = (struct student*)malloc(len);
			q->next = NULL;
			strcpy(q->xuehao, xuehao);
			strcpy(q->name, name);
			q->shuxue = shuxue;
			q->yuwen = yuwen;
			q->c = c;
			q->yingyu = yingyu;
			q->wuli = wuli;
			q->huaxue = huaxue;
			q->zongfen = shuxue + yuwen + c + yingyu + wuli + huaxue;
			q->pingjunfen = (shuxue + yuwen + c + yingyu + wuli + huaxue) / 6;
			if (p == NULL)
				m = p = q;
			else
			{
				q->next = m;
				m = q;
			}
		}
		else
		{
			q = (struct student*)malloc(len);
			q->next = m;
			m = q;
			strcpy(q->xuehao, xuehao);
			strcpy(q->name, name);
			q->shuxue = shuxue;
			q->yuwen = yuwen;
			q->c = c;
			q->yingyu = yingyu;
			q->wuli = wuli;
			q->huaxue = huaxue;
			q->zongfen = shuxue + yuwen + c + yingyu + wuli + huaxue;
			q->pingjunfen = p->zongfen / 6;
		}
		printf("\n");
	}
	return m;
}
//保存到文件
void write(struct student* head) {
	FILE* fp;
	struct student* p;
	if ((fp = fopen("student.txt", "w")) == NULL)
		printf("\a error! Can not open the file!");
	p = head;
	while (p != NULL) {
		if (fwrite(p, len, 1, fp) != 1) {
			printf("写入数据出错\n");
			fclose(fp);
			return;
		}
		p = p->next;
	}
	fclose(fp);
}


//退出系统
void tuichu()
{
	system("cls");//清屏
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                    ------------------------------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                         ***********************  欢迎下次使用 *************************  \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ------------------------------------------------------------------------------");
	Sleep(1000);//延时
	exit(0);
}
void fanhui()
{
	char e[100];
	int a;
	printf("\n");
	printf("如果要返回主菜单请输入yes");
	printf("\n");
	while (true)
	{
		scanf("%s", e);
		if (strcmp(e, "yse") == 0)
		{
			system("cls");
			gongnengcaidan();
			for (;;)
			{
				printf("请输入你需要的功能序号:");
				scanf("%d", &a);
				if (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7)
					printf("输入非法请重新输入");
				else
					break;
			}
		}
		break;
	}
}
void cha(struct student* m)
{
	char a[10];
	char pd[10];
	printf("请选择你要查找的方式");
	printf("                 1.学号查找              ");
	printf("                 2.姓名查找              ");
	printf("\n");
	while (true)
	{
		printf("请输入你要查找的方式的序号:");
		while (true)
		{
			scanf("%s", a);
			if (strcmp(a, "1") != 0 && strcmp(a, "2") != 0)
			{
				if (strcmp(a, "no") == 0)
					return;
				else
					printf("输入非法请重新输入:");
			}
			else
				break;
		}
		if (strcmp(a, "1") == 0)
			chazhao(m);
		else
			chazhao2(m);
		while (true)
		{
			printf("是否要继续查找如果是请输入yes,反之输入no:");
			scanf("%s", pd);
			if (strcmp(pd, "no") == 0)
				return;
			else
				break;
			if (strcmp(pd, "yes") != 0 && strcmp(pd, "no") != 0)
				printf("输入非法请重新输入");
		}

	}
}
int main()

{
	char e[100];
	int a;
	huanying();
	Sleep(1000);//延时
	system("cls");//清屏
	struct student* p, * q;
	p = NULL;
	p = read();
	gongnengcaidan();
	while (true)
	{
		for (;;)
		{
			printf("请输入你需要的功能序号:");
			scanf("%d", &a);
			if (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7)
				printf("输入非法请重新输入");
			else
				break;
		}
		if (a == 0)
			tuichu();
		else if (a == 1)
		{
			system("cls");//清屏
			p = read();
			p = shuru(p);
			write(p);
			fanhui();
			system("cls");
			gongnengcaidan();
		}
		else if (a == 2)
		{
			p = read();
			system("cls");
			p = shanchu(p);
			write(p);
			fanhui();
			system("cls");
			gongnengcaidan();
		}
		else if (a == 3)
		{
			p = read();
			system("cls");
			xiugaixinxi(p);
			write(p);
			fanhui();
			system("cls");
			gongnengcaidan();
		}
		else if (a == 4)
		{
			p = read();
			system("cls");
			cha(p);
			fanhui();
			system("cls");
			gongnengcaidan();
		}
		else if (a == 5)
		{
			p = read();
			system("cls");
			paixu(p);
			fanhui();
			system("cls");
			gongnengcaidan();
		}
		else if (a == 6)
		{
			p = read();
			system("cls");
			zhanshi(p);
			fanhui();
			system("cls");
			gongnengcaidan();
		}
	}
	return 0;
}