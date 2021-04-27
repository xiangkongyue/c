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
	printf("ѧ��                  ����       ��ѧ�ɼ�       ���ĳɼ�       C���Գɼ�     Ӣ��ɼ��ɼ�     ����ɼ�     ��ѧ�ɼ�     �ܷ�     ƽ����\n");
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
			printf("�ڴ��������\n");
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
	FILE* w = fopen("C:\�û�\DELL\�ĵ�\student.txt", "ab+");
	if (w == NULL)
	{
		printf("���ļ�ʧ��!");
		return;
	}
	while (p)
	{
		fprintf(w, "%s %s %lf %lf %lf %lf %lf %lf %.2lf %.2lf", p->xuehao, p->name, p->shuxue, p->yuwen, p->c, p->yingyu, p->wuli, p->huaxue, p->zongfen, p->pingjunfen);
		p = p->next;
	}
	printf("\n\n");
	fprintf(w, "\n");
	printf("�洢�ɹ�!\n");
	fclose(w);
	return;
}

//չʾѧ���ĳɼ�
void zhanshi(struct student* head)
{
	struct student* p;
	p = head;
	if (head = NULL)
		printf("���ݿ����������ݣ�����������");
	print();
	for (; p != NULL; p = p->next)
	{
		printf("%s%13s%14.2lf%16.2lf%15.2lf%16.2f%15.2lf%12.2lf%13.2lf%9.2lf\n", p->xuehao, p->name, p->shuxue, p->yuwen, p->c, p->yingyu, p->wuli, p->huaxue, p->zongfen, p->pingjunfen);
	}
}

//�������չʾѧ���ĳɼ�
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
	printf("��ѡ������չ�����������.��������������'1',��֮������'0':");
	for (;;)
	{
		scanf("%d", &a);
		if (a == 1 || a == 0)
			break;
		else
			printf("����ѡ��Ƿ�������������\n");
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
//����������ĳ��ѧ���ĳɼ���Ϣ
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
		printf("ϵͳ������ѧ����Ϣ����������ѧ������Ϣ");
		return;
	}
	for (;;)
	{
		p = head;
		printf("����������Ҫ���ҵ�ѧ��������");
		scanf("%s", name);
		for (; p != NULL; p = p->next)
		{
			if (strcmp(name, p->name) == 0)
			{
				print();
				printf("%s%13s%14.2lf%16.2lf%15.2lf%16.2f%15.2lf%12.2lf%13.2lf%9.2lf\n", p->xuehao, p->name, p->shuxue, p->yuwen, p->c, p->yingyu, p->wuli, p->huaxue, p->zongfen, p->pingjunfen);

			}
		}
		printf("�Ƿ�Ҫ��������?��������'1'����֮����'0'\n");
		for (;;)
		{
			scanf("%d", &a);
			if (a == 1 || a == 0)
				break;
			else
			{
				printf("����ѡ����������������\n");
			}
		}
		if (a == 0)
			return;

	}
}
//��ѧ�Ų���ĳ��ѧ���ɼ���Ϣ
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
		printf("ϵͳ������ѧ����Ϣ����������ѧ������Ϣ");
		return;
	}
	for (;;)
	{
		p = head;
		printf("����������Ҫ���ҵ�ѧ����ѧ��:");
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
			printf("��ѧ��������");
			o = 0;
		}
		printf("�Ƿ�Ҫ��������?��������'1'����֮����'0'\n");
		for (;;)
		{
			scanf("%d", &a);
			if (a == 1 || a == 0)
				break;
			else
			{
				printf("����ѡ����������������\n");
			}
		}
		if (a == 0)
			return;
	}
}

//�޸�ѧ����Ϣ
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
		printf("ϵͳ������ѧ����Ϣ����������ѧ������Ϣ");
		return;
	}
	for (k = 0;;)
	{
		p = head;
		printf("��������Ҫ�޸���Ϣ��ѧ����ѧ��(����no�����滻):\n");
		scanf("%s", xuehao);
		for (; p != NULL; p = p->next)
		{
			if (strcmp(xuehao, "no") == 0)return;
			if (strcmp(p->xuehao, xuehao) == 0)
			{
				k = 1;
				printf("                        ѧ������Ϣ�������                    \n");
				printf("1-ѧ�� 2-���� 3-��ѧ�ɼ� 4-���ĳɼ� 5-C���Գɼ� 6-Ӣ��ɼ� 7-����ɼ� 8-��ѧ�ɼ�\n");
				printf("��������Ҫ�޸ĵ���Ϣ�����:\n");
				while (true)
				{
					scanf("%d", &xuhao);
					if (xuhao < 1 || xuhao>8)
					{
						printf("����Ƿ�����������\n");
						printf("��������Ҫ�޸ĵ���Ϣ�����:");
					}
					if (xuhao >= 1 && xuhao <= 8)
						break;
				}
				printf("\n");
				if (xuhao == 1)
				{
					printf("ԭ��ѧ��Ϊ:%s\n", p->xuehao);
					printf("��������ѧ��(�س��������滻):");
					scanf("%s", xuehao);
					if (xuehao[0] == NULL)
						return;
					strcpy(p->xuehao, xuehao);
					printf("\n");
					printf("�滻�ɹ�\n");
				}
				if (xuhao == 2)
				{
					printf("ԭ������Ϊ:%s\n", p->name);
					printf("������������(�س��������滻):");
					scanf("%s", name);
					if (name[0] == NULL)
						return;
					strcpy(p->name, name);
					printf("\n");
					printf("�滻�ɹ�\n");
				}
				if (xuhao == 3)
				{
					printf("ԭ����ѧ�ɼ�Ϊ:%lf\n", p->shuxue);
					printf("����������ѧ�ɼ�(�س�������):");
					scanf("%lf", &shuxue);
					if (shuxue == NULL)
						return;
					p->shuxue = shuxue;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("�滻�ɹ�\n");
				}
				if (xuhao == 4)
				{
					printf("ԭ�����ĳɼ�Ϊ:%lf\n", p->yuwen);
					printf("�����������ĳɼ�(�س�������):");
					scanf("%lf", &yuwen);
					if (yuwen == NULL)
						return;
					p->yuwen = yuwen;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("�滻�ɹ�\n");
				}
				if (xuhao == 5)
				{
					printf("ԭ��C���Գɼ�Ϊ:%lf\n", p->c);
					printf("��������C���Գɼ�(�س�������):");
					scanf("%lf", &c);
					if (c == NULL)
						return;
					p->c = c;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("�滻�ɹ�\n");
				}
				if (xuhao == 6)
				{
					printf("ԭ��Ӣ��ɼ�Ϊ:%lf\n", p->yingyu);
					printf("��������Ӣ��ɼ�(�س�������):");
					scanf("%d", &yingyu);
					if (yingyu == NULL)
						return;
					p->yingyu = yingyu;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("�滻�ɹ�");
				}
				if (xuhao == 7)
				{
					printf("ԭ������ɼ�Ϊ:%lf\n", p->wuli);
					printf("������������ɼ�(�س�������):");
					scanf("%lf", &wuli);
					if (wuli == NULL)
						return;
					p->wuli = wuli;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("�滻�ɹ�");
				}
				if (xuhao == 8)
				{
					printf("ԭ�Ȼ�ѧ�ɼ�Ϊ:%lf\n", p->huaxue);
					printf("������������ɼ�(�س�������):");
					scanf("%lf", &huaxue);
					if (huaxue == NULL)
						return;
					p->huaxue = huaxue;
					p->zongfen = p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue;
					p->pingjunfen = (p->shuxue + p->yuwen + p->c + p->yingyu + p->wuli + p->huaxue) / 6;
					printf("\n");
					printf("�滻�ɹ�");
				}
			}
			if (k == 0)
				printf("�ɼ������޸�ѧ��,����ѧ���Ƿ�������ȷ\n");
			printf("�Ƿ�Ҫ�����޸�ѧ����Ϣ�� �����������1����֮����0\n");
			while (true)
			{
				printf("������(1��0):\n");
				scanf("%d", &t);
				if (t != 0 && t != 1)
					printf("����Ƿ�������������\n");
				if (t == 0)
					return;
			}
		}
	}
}

//ɾ��ѧ����Ϣ
struct student* shanchu(struct student* head)
{
	char cc[100];
	int e = 0;
	struct student* p, * q;
	char xuehao[200];
	if (head == NULL)
	{
		printf("ϵͳ������ѧ����Ϣ,��������ѧ������Ϣ\n");
		return head;
	}
	for (;;)
	{
		p = head->next;
		q = head;
		printf("��������Ҫɾ����ѧ����ѧ��(����no����ɾ��):\n");
		scanf("%s", xuehao);
		if (strcmp(xuehao, "no") == 0)return head;
		printf("%s ��ȷ�ϴ�ѧ��Ϊ��Ҫɾ��ѧ�������������yes,��ִ��ɾ����������noȡ��ɾ��", xuehao);
		while (true)
		{
			scanf("%s", cc);
			if (strcmp(cc, "no") != 0 && strcmp(cc, "yes") != 0)
				printf("����Ƿ�����������");
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
				printf("ɾ���ɹ�\n");

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
						printf("ɾ���ɹ�\n");
						break;
					}
					p = p->next;
					q = q->next;
				}
			}
		}
		printf("�������ɾ��ѧ����Ϣ,������ѧ�ţ���֮����no����ɾ��\n");
	}
}
//��ʼ������
void chushihua(struct student* p)
{
	p = (struct student*)malloc(len);
	p->next = NULL;
}

//��ӭ����
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
	printf("                   ***********************  ��ӭ��¼ѧ���ɼ�����ƽ̨ *************************  \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ------------------------------------------------------------------------------");
}

//���ܲ˵�
void gongnengcaidan()
{
	printf("                                   |������������������������������������������������|\n");
	printf("                                   |                                                |\n");
	printf("                                   |              ѧ���ɼ�����ϵͳ���ܱ�            |\n");
	printf("                                   |                                                |\n");
	printf("                                   |               0.�˳�ϵͳ                       |\n");
	printf("                                   |               1.�����µ�ѧ���ɼ�               |\n");
	printf("                                   |               2.ɾ��ѧ���ɼ���Ϣ               |\n");
	printf("                                   |               3.�޸�ѧ���ɼ�                   |\n");
	printf("                                   |               4.����ĳ��ѧ���ɼ�               |\n");
	printf("                                   |               5.����ѧ���ɼ��������չʾ     |\n");
	printf("                                   |               6.���ȫ��ѧ����Ϣ               |\n");
	printf("                                   |                                                |\n");
	printf("                                   |������������������������������������������������|\n");
}

//����ѧ������
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
	printf("������ѧ���ɼ���Ϣ,������������ѧ��������no���˳��������\n");
	printf("����˳��Ϊ:ѧ�� ���� ��ѧ�ɼ� ���ĳɼ� C���Գɼ� Ӣ��ɼ� ����ɼ� ��ѧ�ɼ�\n");
	for (a = 0;; a++)
	{
		printf("ѧ��:");
		scanf("%s", xuehao);
		if (strcmp(xuehao, "no") == 0)
		{
			return m;
		}
		printf("����:");
		scanf("%s", name);
		printf("��ѧ:");
		for (;;) {
			scanf("%lf", &shuxue);
			if (shuxue<min || shuxue>max)
			{
				printf("�ɼ������������������\n");
				printf("��ѧ:");
				scanf("%lf", &shuxue);

			}
			else
				break;
		}
		printf("����:");
		scanf("%lf", &yuwen);
		for (;;)
		{
			if (yuwen<min || yuwen>max)
			{
				printf("�ɼ������������������\n");
				printf("����");
				scanf("%lf", &yuwen);

			}
			else
				break;
		}
		printf("C����:");
		scanf("%lf", &c);
		for (;;)
		{
			if (c<min || c>max)
			{
				printf("�ɼ������������������\n");
				printf("C����:");
				scanf("%lf", &c);
			}
			else
				break;
		}
		printf("Ӣ��:");
		scanf("%lf", &yingyu);
		for (;;)
		{
			if (yingyu<min || yingyu>max)
			{
				printf("�ɼ������������������\n");
				printf("Ӣ��");
				scanf("%lf", &yingyu);
			}
			else
				break;

		}
		printf("����:");
		scanf("%lf", &wuli);
		for (;;)
		{
			if (wuli<min || wuli>max)
			{
				printf("�ɼ������������������\n");
				printf("����");
				scanf("%lf", &wuli);
			}
			else
				break;
		}
		printf("��ѧ:");
		scanf("%lf", &huaxue);
		for (;;)
		{
			if (yingyu<min || yingyu>max)
			{
				printf("�ɼ������������������\n");
				printf("��ѧ:");
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
//���浽�ļ�
void write(struct student* head) {
	FILE* fp;
	struct student* p;
	if ((fp = fopen("student.txt", "w")) == NULL)
		printf("\a error! Can not open the file!");
	p = head;
	while (p != NULL) {
		if (fwrite(p, len, 1, fp) != 1) {
			printf("д�����ݳ���\n");
			fclose(fp);
			return;
		}
		p = p->next;
	}
	fclose(fp);
}


//�˳�ϵͳ
void tuichu()
{
	system("cls");//����
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
	printf("                         ***********************  ��ӭ�´�ʹ�� *************************  \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ------------------------------------------------------------------------------");
	Sleep(1000);//��ʱ
	exit(0);
}
void fanhui()
{
	char e[100];
	int a;
	printf("\n");
	printf("���Ҫ�������˵�������yes");
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
				printf("����������Ҫ�Ĺ������:");
				scanf("%d", &a);
				if (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7)
					printf("����Ƿ�����������");
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
	printf("��ѡ����Ҫ���ҵķ�ʽ");
	printf("                 1.ѧ�Ų���              ");
	printf("                 2.��������              ");
	printf("\n");
	while (true)
	{
		printf("��������Ҫ���ҵķ�ʽ�����:");
		while (true)
		{
			scanf("%s", a);
			if (strcmp(a, "1") != 0 && strcmp(a, "2") != 0)
			{
				if (strcmp(a, "no") == 0)
					return;
				else
					printf("����Ƿ�����������:");
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
			printf("�Ƿ�Ҫ�������������������yes,��֮����no:");
			scanf("%s", pd);
			if (strcmp(pd, "no") == 0)
				return;
			else
				break;
			if (strcmp(pd, "yes") != 0 && strcmp(pd, "no") != 0)
				printf("����Ƿ�����������");
		}

	}
}
int main()

{
	char e[100];
	int a;
	huanying();
	Sleep(1000);//��ʱ
	system("cls");//����
	struct student* p, * q;
	p = NULL;
	p = read();
	gongnengcaidan();
	while (true)
	{
		for (;;)
		{
			printf("����������Ҫ�Ĺ������:");
			scanf("%d", &a);
			if (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7)
				printf("����Ƿ�����������");
			else
				break;
		}
		if (a == 0)
			tuichu();
		else if (a == 1)
		{
			system("cls");//����
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