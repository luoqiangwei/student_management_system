#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BaseScore.h"
//#include "MergeSort.h" //这个排序有大问题。。 //不用删掉注释也能直接使用里面的文件 注释只是说明一下

void ListInitiate(SeqList *L, int x)
{
	for (int i = 0; i < x; i++)
	{
		//L->list[i]._name = (char*)malloc(sizeof(char) * 15);
		L->list[i]._height = 0;
		L->list[i]._chineseScore = 0;
		L->list[i]._englishScore = 0;
		L->list[i]._integratedScienceScore = 0;
		L->list[i]._mathScore = 0;
		L->list[i]._num = 0;
		L->list[i]._weight = 0;
		L->list[i]._name = 0;
		for (int r = 0; r < 8; r++)
		{
			L->list[i]._size[r] = 0;
		}
		for (int u = 0; u < 8; u++)
		{
			L->list[i]._usesize[u] = 0;
		}
	}
	L->max = x;
	L->size = 0;
	for (int i = 0; i < 8; i++)
	{
		L->control[i] = 0;
	}
}
void Print(SeqList *L)
{
	int o = 0;
	printf("选择打印模式：\n1.升序打印\n2.降序打印\n\n");
	printf("请选择：");
	scanf_s("%d", &o);
	int j = 1; //开关
	int i = L->size;
	system("cls");
	if (i <= 0)
		printf("无数据可打印");
	else
	{
		switch (o)
		{
		case 1:

		 //多重选择嵌套出现致命冲突 故关闭选择套件
			for (int y = 0; y < i; y++)
			{
				if (j) //如果有元素并输出的话，设置下列内容只打印一次
				{
					PrintWordIV(*L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\n\n\n");
					printf("\n\n");
					j = 0;
				}
				PrintWordIII(*L, y);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\n", L->list[y]._num, L->list[y]._name, L->list[y]._height, L->list[y]._weight, L->list[y]._englishScore, L->list[y]._mathScore, L->list[y]._chineseScore, L->list[y]._integratedScienceScore);
				printf("\n\n");
			}
			j = 1; //重新初始化开关
			getchar();
			getchar();
			o = -1; //初始化选择器
			break;
		case 2 :
			while (i--)
			{
				if (j) //如果有元素并输出的话，设置下列内容只打印一次
				{
					PrintWordIV(*L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\n\n\n");
					printf("\n\n");
					j = 0;
				}
				PrintWordIII(*L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\n", L->list[i]._num, L->list[i]._name, L->list[i]._height, L->list[i]._weight, L->list[i]._englishScore, L->list[i]._mathScore, L->list[i]._chineseScore, L->list[i]._integratedScienceScore);
				printf("\n\n");
			}
			getchar();
			getchar();
			j = 1; //重新初始化开关
			o = -1;
			break;
		default:
			printf("错误！\n");
			break;
		}
	}
}
void Sort(SeqList *L)
{
	MergeSort(L->list, L->size);
	//InsertSort(L->list, L->size);
}
int ListInsert(SeqList *L, int i) //i 为插入位置  超过七个会导致错位 先添加额外修补函数
{
	char* ie;
	char iq[32];
	int iw;
	char *p;
	if (L->size >= L->max)
	{
		printf("顺序表已经满了无法插入！\n");
		return 0;
	}
	else if (i < 0 || i > L->size)
	{
		printf("参数有误 \n");
		return 0;
	}
	else
	{
		int j;
		for (j = L->size; j>i; j--) //防止某些莫名错误
		{
			L->list[j] = L->list[j - 1]; 
			//经测试后发现可以这样简化 为了防止其他编译器不允许这么简写 故保留下列代码

			/*L->list[j]._chineseScore = L->list[j - 1]._chineseScore;
			L->list[j]._englishScore = L->list[j - 1]._englishScore;
			L->list[j]._height = L->list[j - 1]._height;
			L->list[j]._integratedScienceScore = L->list[j - 1]._integratedScienceScore;
			L->list[j]._mathScore = L->list[j - 1]._mathScore;
			L->list[j]._name = L->list[j - 1]._name;
			L->list[j]._num = L->list[j - 1]._num;
			L->list[j]._weight = L->list[j - 1]._weight;*/
		}
		
		L->list[i]._name = (char*)malloc(sizeof(char) * 15);
		Xget(&L->list[i]);
		L->size++;

		//下面开始审查数据
		/*iq = 0;
		iw = 0;
		iq = L->list[i]._num;
		while (iq / 10)
		{
			iw++;
		}
		iq = (iw - 1) / 7;
		if (iq > L->control[0])
		{
			L->control[0] = iq;
		}
		iq = 0;
		iw = 0;*/
		sprintf(iq, " %d", L->list[i]._num);
		iw = strlen(iq); //居然计算了\0..
		iw = (iw - 2) / 7;
		L->list[i]._size[0] = iw;
		if (iw > L->control[0])
		{
			L->control[0] = iw;
		}
		for (int f = 0; f < L->size; f++)
		{
			L->list[f]._usesize[0] = L->control[0] - (L->list[f]._size[0]);
		}

		iw = strlen(L->list[i]._name);
		iw = (iw - 1) / 7;
		L->list[i]._size[1] = iw;
		if (iw > L->control[1])
		{
			L->control[1] = iw;
		}
		for (int f = 0; f < L->size; f++)
		{
			L->list[f]._usesize[1] = L->control[1] - (L->list[f]._size[1]);
		}

		ie = fcvt(L->list[i]._height, 2, &iw, &iw);
		iw = strlen(ie) + 1;
		iw = (iw - 1) / 7;
		L->list[i]._size[2] = iw;
		if (iw > L->control[2])
		{
			L->control[2] = iw;
		}
		for (int f = 0; f < L->size; f++)
		{
			L->list[f]._usesize[2] = L->control[2] - (L->list[f]._size[2]);
		}

		ie = fcvt(L->list[i]._weight, 2, &iw, &iw);
		iw = strlen(ie) + 1;
		iw = (iw - 1) / 7;
		L->list[i]._size[3] = iw;
		if (iw > L->control[3])
		{
			L->control[3] = iw;
		}
		for (int f = 0; f < L->size; f++)
		{
			L->list[f]._usesize[3] = L->control[3] - (L->list[f]._size[3]);
		}

		sprintf(iq, " %d", L->list[i]._englishScore); //讲道理 到此为止就不用做了 但是万一有人输入8位的成绩呢
		iw = strlen(iq);
		iw = (iw - 2) / 7;
		L->list[i]._size[4] = iw;
		if (iw > L->control[4])
		{
			L->control[4] = iw;
		}
		for (int f = 0; f < L->size; f++)
		{
			L->list[f]._usesize[4] = L->control[4] - (L->list[f]._size[4]);
		}

		sprintf(iq, " %d", L->list[i]._mathScore); 
		iw = strlen(iq);
		iw = (iw - 2) / 7;
		L->list[i]._size[5] = iw;
		if (iw > L->control[5])
		{
			L->control[5] = iw;
		}
		for (int f = 0; f < L->size; f++)
		{
			L->list[f]._usesize[5] = L->control[5] - (L->list[f]._size[5]);
		}

		sprintf(iq, " %d", L->list[i]._chineseScore); 
		iw = strlen(iq);
		iw = (iw - 2) / 7;
		L->list[i]._size[6] = iw;
		if (iw > L->control[6])
		{
			L->control[6] = iw;
		}
		for (int f = 0; f < L->size; f++)
		{
			L->list[f]._usesize[6] = L->control[6] - (L->list[f]._size[6]);
		}

		sprintf(iq, " %d", L->list[i]._englishScore); 
		iw = strlen(iq);
		iw = (iw - 2) / 7;
		L->list[i]._size[7] = iw;
		if (iw > L->control[7])
		{
			L->control[7] = iw;
		}
		for (int f = 0; f < L->size; f++)
		{
			L->list[f]._usesize[7] = L->control[7] - (L->list[f]._size[7]);
		}


		//经测试后发现可以这样简化 为了防止其他编译器不允许这么简写 故保留下列代码

		/*L->list[j]._chineseScore = x._chineseScore;
		L->list[j]._englishScore = x._englishScore;
		L->list[j]._height = x._height;
		L->list[j]._integratedScienceScore = x._integratedScienceScore;
		L->list[j]._mathScore = x._mathScore;
		L->list[j]._name = x._name;
		L->list[j]._num = x._num;
		L->list[j]._weight = x._weight;*/

		//注：在编写到此时测试了简写代码 在VC编译器上可行， 之后都使用这种简写，如果出现编译错误 请自行更改

		Sort(L); //排序
		return 1;
	}
}
int ListDelete(SeqList *L, int i, DataType *x)
{
	int j;
	if (L->size <= 0)
	{
		printf("顺序表已经空！\n");
		return 0;
	}
	else if (i < 0 || i >= L->size)
	{
		printf("参数有误！\n");
		return 0;
	}
	else
	{
		if ((x->_name) != NULL)
		{
			free(x->_name); //回收内存 哈
		}
		*x = L->list[i]; //删除的数据放到 x 里
		for (j = i; j < L->size - 1; j++)
		{
			L->list[j] = L->list[j + 1];
		}
		L->size--;

		return 1;
	}
}
int ListGet(SeqList L, int i, DataType *x)
{
	if (i < 0 || i>L.size)
	{
		printf("参数错误！\n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		PrintWordIV(L);
		//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\n");
		PrintWordIII(L, i);
		//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore);
		return 1;
	}
}
int ListFind(SeqList L)
{
	int flag1 = 1, flag2 = 1;
	int i = 0;
	int j = 0;
	int y;
	int num;
	char *name;
	float hight;
	float weight;
	int englishScore;
	int mathScore; 
	int chineseScore; 
	int integratedScienceScore; 
	int fot; //旋钮
	printf("\t\t+---------------------------------+\n");
	printf("\t\t|         查  找  向  导          |\n");
	printf("\t\t|_________________________________|\n");
	printf("\t\t|                                 |\n");
	printf("\t\t|         1. 学号查找             |\n");
	printf("\t\t|         2. 名字查找             |\n");
	printf("\t\t|         3. 身高查找             |\n");
	printf("\t\t|         4. 体重查找             |\n");
	printf("\t\t|         5. 英语成绩查找         |\n");
	printf("\t\t|         6. 数学成绩查找         |\n");
	printf("\t\t|         7. 中文成绩查找         |\n");
	printf("\t\t|         8. 理综成绩查找         |\n");
	printf("\t\t|                                 |\n");
	printf("\t\t|_________________________________|\n");
	printf("\t\t请输入你的选择：");
	scanf("%d", &fot);
	switch (fot)
	{
	case 1:
		_sleep(100);
		system("cls");
		_sleep(100);
		printf("\n\n\n\n\t\t请输入您要查找的学号：");
		scanf("%d", &num);
		_sleep(100);
		system("cls");
		_sleep(100);
		while (i < L.size)
		{
			if (L.list[i]._num == num)
			{
				flag1 = 0;
				j = 1;
			}
			if (j)
			{
				if (flag2)
				{
					PrintWordI(L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\t所在位置\n");
					flag2 = 0;
				}
				PrintWordII(L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore, i + 1);
				j = 0;
			}
			i++;
		}
		if (flag1)
		{
			printf("\n\n\n\n\t\t未找到此元素");
			flag1 = 1;
		}
		flag2 = 1; //各种初始化~
		i = 0;
		getchar();
		getchar();

		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	case 2:
		_sleep(100);
		system("cls");
		_sleep(100);

		name = (char*)malloc(sizeof(char) * 15);
		printf("\n\n\n\n\t\t请输入您要查找的名字：");
		scanf("%s", name);
		_sleep(100);
		system("cls");
		_sleep(100);
		while (i < L.size)
		{
			if (!strcmp(L.list[i]._name, name));
			{
				flag1 = 0;
				j = 1;
			}
			if (j)
			{
				if (flag2)
				{
					PrintWordI(L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\t所在位置\n");
					flag2 = 0;
				}
				PrintWordII(L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore, i + 1);
				j = 0;
			}
			i++;
		}
		if (flag1)
		{
			printf("\n\n\n\n\t\t未找到此元素");
			flag1 = 1;
		}
		flag2 = 1; //各种初始化~
		i = 0;
		free(name);
		getchar();
		getchar();

		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	case 3:
		_sleep(100);
		system("cls");
		_sleep(100);

		printf("\n\n\n\n\t\t请输入您要查找的身高：");
		scanf("%f", &hight);
		_sleep(100);
		system("cls");
		_sleep(100);
		while (i < L.size)
		{
			if (L.list[i]._height == hight)
			{
				flag1 = 0;
				j = 1;
			}
			if (j)
			{
				if (flag2)
				{
					PrintWordI(L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\t所在位置\n");
					flag2 = 0;
				}
				PrintWordII(L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore, i + 1);
				j = 0;
			}
			i++;
		}
		if (flag1)
		{
			printf("\n\n\n\n\t\t未找到此元素");
			flag1 = 1;
		}
		flag2 = 1; //各种初始化~
		i = 0;
		getchar();
		getchar();

		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	case 4:
		_sleep(100);
		system("cls");
		_sleep(100);

		printf("\n\n\n\n\t\t请输入您要查找的体重：");
		scanf("%f", &weight);
		_sleep(100);
		system("cls");
		_sleep(100);
		while (i < L.size)
		{
			if (L.list[i]._weight == weight)
			{
				flag1 = 0;
				j = 1;
			}
			if (j)
			{
				if (flag2)
				{
					PrintWordI(L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\t所在位置\n");
					flag2 = 0;
				}
				PrintWordII(L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore, i + 1);
				j = 0;
			}
			i++;
		}
		if (flag1)
		{
			printf("\n\n\n\n\t\t未找到此元素");
			flag1 = 1;
		}
		flag2 = 1; //各种初始化~
		i = 0;
		getchar();
		getchar();

		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	case 5:
		_sleep(100);
		system("cls");
		_sleep(100);

		printf("\n\n\n\n\t\t请输入您要查找的英语成绩：");
		scanf("%d", &englishScore);
		_sleep(100);
		system("cls");
		_sleep(100);
		while (i < L.size)
		{
			if (L.list[i]._englishScore == englishScore)
			{
				flag1 = 0;
				j = 1;
			}
			if (j)
			{
				if (flag2)
				{
					PrintWordI(L);
					//("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\t所在位置\n");
					flag2 = 0;
				}
				PrintWordII(L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore, i + 1);
				j = 0;
			}
			i++;
		}
		if (flag1)
		{
			printf("\n\n\n\n\t\t未找到此元素");
			flag1 = 1;
		}
		flag2 = 1; //各种初始化~
		i = 0;
		getchar();
		getchar();

		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	case 6:
		_sleep(100);
		system("cls");
		_sleep(100);

		printf("\n\n\n\n\t\t请输入您要查找的数学成绩：");
		scanf("%d", &mathScore);
		_sleep(100);
		system("cls");
		_sleep(100);
		while (i < L.size)
		{
			if (L.list[i]._mathScore == mathScore)
			{
				flag1 = 0;
				j = 1;
			}
			if (j)
			{
				if (flag2)
				{
					PrintWordI(L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\t所在位置\n");
					flag2 = 0;
				}
				PrintWordII(L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore, i + 1);
				j = 0;
			}
			i++;
		}
		if (flag1)
		{
			printf("\n\n\n\n\t\t未找到此元素");
			flag1 = 1;
		}
		flag2 = 1; //各种初始化~
		i = 0;
		getchar();
		getchar();

		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	case 7:
		_sleep(100);
		system("cls");
		_sleep(100);

		printf("\n\n\n\n\t\t请输入您要查找的中文成绩：");
		scanf("%d", &chineseScore);
		_sleep(100);
		system("cls");
		_sleep(100);
		while (i < L.size)
		{
			if (L.list[i]._chineseScore == chineseScore)
			{
				flag1 = 0;
				j = 1;
			}
			if (j)
			{
				if (flag2)
				{
					PrintWordI(L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\t所在位置\n");
					flag2 = 0;
				}
				PrintWordII(L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore, i + 1);
				j = 0;
			}
			i++;
		}
		if (flag1)
		{
			printf("\n\n\n\n\t\t未找到此元素");
			flag1 = 1;
		}
		flag2 = 1; //各种初始化~
		i = 0;
		getchar();
		getchar();

		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	case 8:
		_sleep(100);
		system("cls");
		_sleep(100);

		printf("\n\n\n\n\t\t请输入您要查找的理综成绩：");
		scanf("%d", &integratedScienceScore);
		_sleep(100);
		system("cls");
		_sleep(100);
		while (i < L.size)
		{
			if (L.list[i]._integratedScienceScore == integratedScienceScore)
			{
				flag1 = 0;
				j = 1;
			}
			if (j)
			{
				if (flag2)
				{
					PrintWordI(L);
					//printf("学号\t姓名\t身高\t体重\t英语\t数学\t中文\t理综\t所在位置\n");
					flag2 = 0;
				}
				PrintWordII(L, i);
				//printf("%d\t%s\t%5.2f\t%5.2f\t%d\t%d\t%d\t%d\t%d\n", L.list[i]._num, L.list[i]._name, L.list[i]._height, L.list[i]._weight, L.list[i]._englishScore, L.list[i]._mathScore, L.list[i]._chineseScore, L.list[i]._integratedScienceScore, i + 1);
				j = 0;
			}
			i++;
		}
		if (flag1)
		{
			printf("\n\n\n\n\t\t未找到此元素");
			flag1 = 1;
		}
		flag2 = 1; //各种初始化~
		i = 0;
		getchar();
		getchar();


		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	default:
		_sleep(100);
		system("cls");
		_sleep(100);
		fot = -1; //初始化
		break;
	}
}

int OutPut(SeqList L) 
{
	FILE *fp = fopen("Data.txt", "w");
	int o = 0;
	int po;
	int pi;
	printf("选择导出模式：\n1.升序导出\n2.降序导出\n\n");
	printf("请选择：");
	scanf_s("%d", &o);
	int j = 1; //开关
	int i = L.size;
	system("cls");
	if (i <= 0)
		printf("无数据可导出");
	else
	{
		switch (o)
		{
		case 1:

			//多重选择嵌套出现致命冲突 故关闭选择套件
			for (int y = 0; y < i; y++)
			{
				if (j) //如果有元素并输出的话，设置下列内容只打印一次
				{
					fprintf(fp, "学号\t");
					po = L.control[0];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "姓名\t");
					po = L.control[1];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "身高\t");
					po = L.control[2];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "体重\t");
					po = L.control[3];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "英语\t");
					po = L.control[4];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "数学\t");
					po = L.control[5];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "中文\t");
					po = L.control[6];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "理综");
					fprintf(fp, "\t\t\t\t\t\t\t\t");
					fprintf(fp, "%d", L.size);

					fprintf(fp, "\n\n\n");

					j = 0;
				}
				fprintf(fp, "%d\t", L.list[y]._num);
				po = L.list[y]._usesize[0];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%s\t", L.list[y]._name);
				po = L.list[y]._usesize[1];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%5.2f\t", L.list[y]._height);
				po = L.list[y]._usesize[2];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%5.2f\t", L.list[y]._weight);
				po = L.list[y]._usesize[3];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%d\t", L.list[y]._englishScore);
				po = L.list[y]._usesize[4];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%d\t", L.list[y]._mathScore);
				po = L.list[y]._usesize[5];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%d\t", L.list[y]._chineseScore);
				po = L.list[y]._usesize[6];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%d\n", L.list[y]._integratedScienceScore);

				fprintf(fp, "\n\n");
			}
			fprintf(fp, "\n\n\n\n\n\n\n\n\n\n");
			for (pi = 0; pi < 8; pi++)
			{
				fprintf(fp, "%d ", L.control[pi]);
			}
			fprintf(fp, "\n");
			for (pi = 0; pi < L.size; pi++)
			{
				for (int q = 0; q < 8; q++)
				{
					fprintf(fp, "%d ", L.list[pi]._size[q]);
					fprintf(fp, "%d ", L.list[pi]._usesize[q]);
				}
				fprintf(fp, "\n");
			}

			j = 1; //重新初始化开关
			
			o = -1; //初始化选择器
			break;
		case 2:
			while (i--)
			{
				if (j) //如果有元素并输出的话，设置下列内容只打印一次
				{
					fprintf(fp,"学号\t");
					po = L.control[0];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "姓名\t");
					po = L.control[1];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "身高\t");
					po = L.control[2];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "体重\t");
					po = L.control[3];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "英语\t");
					po = L.control[4];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "数学\t");
					po = L.control[5];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "中文\t");
					po = L.control[6];
					while (po--)
					{
						fprintf(fp, "\t");
					}

					fprintf(fp, "理综");
					fprintf(fp, "\t\t\t\t\t\t\t\t");
					fprintf(fp, "%d", L.size);

					fprintf(fp, "\n\n\n");

					j = 0;
				}
				fprintf(fp,"%d\t", L.list[i]._num);
				po = L.list[i]._usesize[0];
				while (po--)
				{
					fprintf(fp, "\t");
				}
				
				fprintf(fp, "%s\t", L.list[i]._name);
				po = L.list[i]._usesize[1];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%5.2f\t", L.list[i]._height);
				po = L.list[i]._usesize[2];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%5.2f\t", L.list[i]._weight);
				po = L.list[i]._usesize[3];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%d\t", L.list[i]._englishScore);
				po = L.list[i]._usesize[4];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%d\t", L.list[i]._mathScore);
				po = L.list[i]._usesize[5];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%d\t", L.list[i]._chineseScore);
				po = L.list[i]._usesize[6];
				while (po--)
				{
					fprintf(fp, "\t");
				}

				fprintf(fp, "%d\n", L.list[i]._integratedScienceScore);

				fprintf(fp,"\n\n");
			}
			fprintf(fp, "\n\n\n\n\n\n\n\n\n\n");
			for (pi = 0; pi < 8; pi++)
			{
				fprintf(fp, "%d ", L.control[pi]);
			}
			fprintf(fp, "\n");
			for (pi = 0; pi < L.size; pi++)
			{
				for (int q = 0; q < 8; q++)
				{
					fprintf(fp, "%d ", L.list[pi]._size[q]);
					fprintf(fp, "%d ", L.list[pi]._usesize[q]);
				}
				fprintf(fp, "\n");
			}

			j = 1; //重新初始化开关
			o = -1;
			break;
		default:
			printf("导出错误！\n");
			break;
		}
	}
	fclose(fp);
	return 1;
}
int InPut(SeqList *L) 
{
	int i = 0;
	int fflag = 1;
	char a[10];
	char Text[99999];
	FILE *fp = fopen("Data.txt", "r");
	while (fgets(Text, 99999, fp) != NULL)//逐行读取fp所指向文件中的内容到text中
	{
		puts(Text);//输出到屏幕
	}
	fclose(fp);
	fopen("Data.txt", "r");
	while (!feof(fp))
	{
		if (fflag)
		{
			fscanf(fp, "%s%s%s%s%s%s%s%s", a, a, a, a, a, a, a, a);
			fscanf(fp, "%d", &L->size);
			fflag = 0;
		}
		for (int y = 0; y < L->size; y++)
		{
			L->list[i]._name = (char*)malloc(sizeof(char) * 15);
			fscanf(fp, "%d%s%f%f%d%d%d%d", &L->list[i]._num, L->list[i]._name, &L->list[i]._height, &L->list[i]._weight, &L->list[i]._englishScore, &L->list[i]._mathScore, &L->list[i]._chineseScore, &L->list[i]._integratedScienceScore);
			i++;
		}
		fscanf(fp, "%d%d%d%d%d%d%d%d", &L->control[0], &L->control[1], &L->control[2], &L->control[3], &L->control[4], &L->control[5], &L->control[6], &L->control[7]);
		
		for (int pi = 0; pi < L->size; pi++)
		{
			for (int q = 0; q < 8; q++)
			{
				fscanf(fp, "%d", &L->list[pi]._size[q]);
				fscanf(fp, "%d", &L->list[pi]._usesize[q]);
			}
		}
	}
	fclose(fp);
	fflag = 1;
	getchar();
	getchar();
	return 1;
}

void Xget(DataType *x)
{
	_sleep(1000);
	Clean();
	printf("\n\n\n\n\t\t请输入学号：");
	scanf("%d", &x->_num);
	Clean();
	printf("\n\n\n\n\t\t请输入姓名：");
	scanf("%s", x->_name);
	Clean();
	printf("\n\n\n\n\t\t请输入身高：");
	scanf("%f", &x->_height);
	Clean();
	printf("\n\n\n\n\t\t请输入体重：");
	scanf("%f", &x->_weight);

	Clean();
	printf("\n\n\n\n\t\t请输入英语成绩：");
	scanf("%d", &x->_englishScore);
	Clean();
	printf("\n\n\n\n\t\t请输入数学成绩：");
	scanf("%d", &x->_mathScore);
	Clean();
	printf("\n\n\n\n\t\t请输入中文成绩：");
	scanf("%d", &x->_chineseScore);
	Clean();
	printf("\n\n\n\n\t\t请输入理综成绩：");
	scanf("%d", &x->_integratedScienceScore);
	Clean();
}

int PrintWordI(SeqList L)
{
	int i;
	printf("学号\t");
	i = L.control[0];
	while (i--)
	{
		printf("\t");
	}
	printf("姓名\t");
	i = L.control[1];
	while (i--)
	{
		printf("\t");
	}
	printf("身高\t");
	i = L.control[2];
	while (i--)
	{
		printf("\t");
	}
	printf("体重\t");
	i = L.control[3];
	while (i--)
	{
		printf("\t");
	}
	printf("英语\t");
	i = L.control[4];
	while (i--)
	{
		printf("\t");
	}
	printf("数学\t");
	i = L.control[5];
	while (i--)
	{
		printf("\t");
	}
	printf("中文\t");
	i = L.control[6];
	while (i--)
	{
		printf("\t");
	}
	printf("理综\t");
	i = L.control[7];
	while (i--)
	{
		printf("\t");
	}
	printf("所在位置\n");
}

int PrintWordII(SeqList L, int i)  //我写了不该写的 T T   才怪
{
	int x;
	printf("%d\t", L.list[i]._num);
	x = L.list[i]._usesize[0];
	while (x--)
	{
		printf("\t");
	}
	printf("%s\t", L.list[i]._name);
	x = L.list[i]._usesize[1];
	while (x--)
	{
		printf("\t");
	}
	printf("%5.2f\t", L.list[i]._height);
	x = L.list[i]._usesize[2];
	while (x--)
	{
		printf("\t");
	}
	printf("%5.2f\t", L.list[i]._weight);
	x = L.list[i]._usesize[3];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\t", L.list[i]._englishScore);
	x = L.list[i]._usesize[4];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\t", L.list[i]._mathScore);
	x = L.list[i]._usesize[5];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\t", L.list[i]._chineseScore);
	x = L.list[i]._usesize[6];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\t", L.list[i]._integratedScienceScore);
	x = L.list[i]._usesize[7];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\n", i + 1);
}

int PrintWordIII(SeqList L, int i) //我写了不该写的 T T
{
	int x;
	printf("%d\t", L.list[i]._num);
	x = L.list[i]._usesize[0];
	while (x--)
	{
		printf("\t");
	}
	printf("%s\t", L.list[i]._name);
	x = L.list[i]._usesize[1];
	while (x--)
	{
		printf("\t");
	}
	printf("%5.2f\t", L.list[i]._height);
	x = L.list[i]._usesize[2];
	while (x--)
	{
		printf("\t");
	}
	printf("%5.2f\t", L.list[i]._weight);
	x = L.list[i]._usesize[3];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\t", L.list[i]._englishScore);
	x = L.list[i]._usesize[4];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\t", L.list[i]._mathScore);
	x = L.list[i]._usesize[5];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\t", L.list[i]._chineseScore);
	x = L.list[i]._usesize[6];
	while (x--)
	{
		printf("\t");
	}
	printf("%d\n", L.list[i]._integratedScienceScore);
}

int PrintWordIV(SeqList L)
{
	int i;
	printf("学号\t");
	i = L.control[0];
	while (i--)
	{
		printf("\t");
	}
	printf("姓名\t");
	i = L.control[1];
	while (i--)
	{
		printf("\t");
	}
	printf("身高\t");
	i = L.control[2];
	while (i--)
	{
		printf("\t");
	}
	printf("体重\t");
	i = L.control[3];
	while (i--)
	{
		printf("\t");
	}
	printf("英语\t");
	i = L.control[4];
	while (i--)
	{
		printf("\t");
	}
	printf("数学\t");
	i = L.control[5];
	while (i--)
	{
		printf("\t");
	}
	printf("中文\t");
	i = L.control[6];
	while (i--)
	{
		printf("\t");
	}
	printf("理综\n");
}