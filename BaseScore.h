#pragma once

#include <stdio.h>    

#define MaxSize 1000  //最大学生信息存数

typedef struct {
	int _num; //学号
	char *_name; //名字
	float _height; //身高
	float _weight; //体重
	int _englishScore; //英语成绩
	int _mathScore; //数学成绩
	int _chineseScore; //中文成绩
	int _integratedScienceScore; //理综成绩
	int _size[8]; //判断。。
	int _usesize[8];
}DataType; //自己定义的数据类型

typedef struct
{
	DataType list[MaxSize]; 
	int size; //当前已用的空间
	int max; //顺序表的最大空间
	int control[8]; //字符控制开关
} SeqList; //存学生的数据表

void ListInitiate(SeqList *L, int x); //初始化操作
void Print(SeqList *L); //打印
void Sort(SeqList *L); //排序
// ListInsert(SeqList *L, int i, DataType x); //插入
ListInsert(SeqList *L, int i); //插入

void Xget(DataType *x); //另一个插入函数

int ListDelete(SeqList *L, int i, DataType *x); //删除
int ListGet(SeqList L,int i, DataType *x); //获取
int ListFind(SeqList L); //查找
int OutPut(SeqList L); //输出（到文本）
int InPut(SeqList *L); //输入（从文本）
int PrintWordI(SeqList L); //字符输出程序1
int PrintWordII(SeqList L, int i); //字符输出程序2
int PrintWordIII(SeqList L, int i); //字符输出程序3
int PrintWordIV(SeqList L); //字符输出程序4