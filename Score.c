#include <stdio.h>
#include <stdlib.h>

#include "Score.h"

void Score()
{
	DataType x; //里面的 _name是指针 所以不能用这个来输入 回收站
	DataType px; //获取元素缓存区
	//x._name = (char*)malloc(sizeof(char) * 15);
	x._name = NULL;
	SeqList List;
	int mainflag = 1;
	while (mainflag)
	{
		int num, n;
		int i, j, y;
		int but;
		int flag;
		int getnum;
		PrintInfo();
		printf("\t\t选择你的操作:");
		scanf("%d", &but);
		switch (but)
		{
		case 0:
			Error(); //系统错误检测

			if ((x._name) != NULL)
			{
				free(x._name); //回收内存 x 是个回收站 要随时清理它
			}
			//free(x._name);
			mainflag = 0; //关闭主开关

			Clean();  //显示屏处理
			but = -1; //初始化次开关
			break;
		case 1:
			Error();
			Clean();

			printf("\n\n\n\n\n\n\t\t输入你输入的最大学生数：");
			scanf("%d", &num);
			ListInitiate(&List, num + 1);
			Clean();
			printf("\n\n\n\n\n\n\t\t测评表创建成功！");

			_sleep(1000);
			Clean();
			but = -1;
			break;
		case 2:
			Clean();
			Error();

			printf("\n\n\n\n\n\t\t本表您申请的学生数为：%d\n\t\t本程序可以检测此类错误\n\t\t但是为了您的效率，请不要输错数据，之后难以更改！\n", List.max - 1);
			printf("\n\n\t\t请输入本次要添加的学生数:");
			scanf("%d", &n);
			printf("操作完成\n");
			_sleep(500);
			Clean();
			while (n--)
			{
				printf("\n\n\n\t\t\t请输入第 %d 个学生的信息：\n", List.size + 1);
				ListInsert(&List, List.size);
			}

			Clean();
			but = -1;
			break;
		case 3:
			Clean();
			Error();

			/*printf("\n\n\n\n\t\t下面，您将创建要添加的学生的信息\n");
			Xget(&List);*/
			printf("\n\n\n\n\t\t目前在表中的学生数为%d\n\t\t注：位置不包含0\n", List.size);
			printf("\n\t\t您想插入的位置是：");
			scanf("%d", &y);
			if (y <= 0 || y > List.size + 1)
			{
				Clean();
				printf("\n\n\n\n\t\tError!\n");
				_sleep(1000);
				but = -1;
				Clean();
				break;
			}
			ListInsert(&List, y-1);
			Clean();

			printf("\n\n\n\n\n\t\t已成功插入！\n");
			_sleep(1000);

			Clean();
			but = -1;
			break;
		case 4:
			Clean();
			Error();

			Print(&List);
			_sleep(1000);

			Clean();
			but = -1;
			break;
		case 5:
			Clean();
			Error();

			printf("\n\n\n\n\t\t目前在表中的学生数为%d\n\t\t注：位置不包含0\n", List.size);
			printf("\n\n\n\n\n\t\t请输入您想删除的位置：");
			scanf("%d", &j);
			if (j <= 0 || j > List.size)
			{
				Clean();
				printf("\n\n\n\n\t\tError!\n");
				_sleep(1000);
				but = -1;
				Clean();
				break;
			}
			ListDelete(&List, j-1, &x);

			Clean();

			printf("\n\n\n\n\n\t\t已成功删除！\n");
			_sleep(1000);

			Clean();
			but = -1;
			break;
		case 6:
			Clean();
			Error();

			printf("\n\n\n\n\t\t目前在表中的学生数为%d\n\t\t注：位置不包含0\n", List.size);
			printf("\n\n\n\t\t请输入您想获取的位置：");
			scanf("%d", &getnum);
			if (getnum <= 0 || getnum > List.size)
			{
				Clean();
				printf("\n\n\n\n\t\tError!\n");
				_sleep(1000);
				but = -1;
				Clean();
				break;
			}
			Clean();
			ListGet(List, getnum - 1, &px);
			getchar();
			getchar();
			Clean();

			printf("\n\n\n\t\t已获取元素\n");
			_sleep(1000);

			Clean();
			but = -1;
			break;
		case 7:
			Clean();
			Error();

			ListFind(List);

			Clean();
			but = -1;
			break;
		case 8:
			Clean();
			Error();

			OutPut(List);
			Clean();
			printf("\n\n\n\t\t导出成功！\n");
			_sleep(1000);

			Clean();
			but = -1;
			break;
		case 9:
			Clean();
			Error();

			InPut(&List);
			Clean();
			printf("\n\n\n\t\t读取成功！\n");
			_sleep(1000);

			Clean();
			but = -1;
			break;
		default:
			Clean();
			Error();
			Clean();
			but = -1;
			break;
		}
	}
}

void PrintInfo()
{
	printf("\t\t+-----------------------------------------------------+\n");
	printf("\t\t|            学   生   评   测   系   统              |\n");
	printf("\t\t|_____________________________________________________|\n");
	printf("\t\t|                                                     |\n");
	printf("\t\t|       1.创建新评测表                                |\n");
	printf("\t\t|       2.连续输入学生信息                            |\n");
	printf("\t\t|       3.插入单个学生的信息                          |\n");
	printf("\t\t|       4.打印学生信息                                |\n");
	printf("\t\t|       5.删除单个学生的信息                          |\n");
	printf("\t\t|       6.获取单个学生的信息                          |\n");
	printf("\t\t|       7.查找学生信息                                |\n");
	printf("\t\t|                                                     |\n");
	printf("\t\t|       8.导出当前的信息表                            |\n");
	printf("\t\t|       9.读取已有的表到当前的信息表                  |\n");
	printf("\t\t|                                                     |\n");
	printf("\t\t|       0.退出系统                                    |\n");
	printf("\t\t|_____________________________________________________|\n");
}

void Clean()
{
	_sleep(100); //减少画面抖动
	system("cls");
	_sleep(100); //减少画面抖动
}

//void Xget(DataType *x)
//{
//	_sleep(1000);
//	Clean();
//	printf("\n\n\n\n\t\t请输入学号：");
//	scanf("%d", &x->_num);
//	Clean();
//	printf("\n\n\n\n\t\t请输入姓名：");
//	scanf("%s", &x->_name);
//	Clean();
//	printf("\n\n\n\n\t\t请输入身高：");
//	scanf("%f", &x->_height);
//	Clean();
//	printf("\n\n\n\n\t\t请输入体重：");
//	scanf("%f", &x->_weight);
//
//	Clean();
//	printf("\n\n\n\n\t\t请输入英语成绩：");
//	scanf("%d", &x->_englishScore);
//	Clean();
//	printf("\n\n\n\n\t\t请输入数学成绩：");
//	scanf("%d", &x->_mathScore);
//	Clean();
//	printf("\n\n\n\n\t\t请输入中文成绩：");
//	scanf("%d", &x->_chineseScore);
//	Clean();
//	printf("\n\n\n\n\t\t请输入理综成绩：");
//	scanf("%d", &x->_integratedScienceScore);
//	Clean();
//}

void Error()
{
	errno = 0;
	if (errno != 0)
	{
		printf("Error num: %d \nDetailed information: %s\n", errno, strerror(errno));
		_sleep(10000);
	}
}