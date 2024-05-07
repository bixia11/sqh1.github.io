重头戏在后面


指针数组：本质是数组，研究角度：数组元素的类型和元素的个数？

整型数组，数组中的元素类型是整型
字符数组，数组中的元素类型是字符
浮点数组，数组中的元素类型是浮点 
指针数组，数组中的元素类型是指针

//int a,b,c,d,e;

int a[5];//元素的类型是int, 元素个数5个

//在定义数组的时候，先写元素的类型，在写数组的名字，在写元素个数


char *p1,*p2,*p3,*p4,*p5;
p1 = "asan";
p2 = "xiaosi";
p3 = "awu";
p4 = "dalang";
p5 = "xixi";

//字符指针数组，有5个元素,类型是char*
char* a[5];// a[0] a[1] a[2] a[3] a[4] 类型是char*
a[0] = "asan";
a[1] = "xiaosi";
a[2] = "awu";
a[3] = "dalang";
a[4] = "xixi";

char* a[5] = {"asan","xiaosi","awu","dalang","jinlian"};
//元素类型是char*
//a是一个字符指针数组，元素个数5个char*


#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i;
	//字符指针数组，有5个元素
	/*
	char* a[5];// a[0] a[1] a[2] a[3] a[4] 类型是char*
	a[0] = "asan";
	a[1] = "xiaosi";
	a[2] = "awu";
	a[3] = "dalang";
	a[4] = "xixi";
	*/
	
	char* a[5] = {"asan","xiaosi","awu","dalang","jinlian"};
	//数组中的元素类型char*  a[0] 类型char*
	//a的类型是什么 a是一个字符指针数组
	printf("sizeof(a[0]) is %d\n",sizeof(a[0]));//求一个元素的大小，因为是char*所以占4个字节
	printf("sizeof(a) is %d\n",sizeof(a));//求整个数组的大小 = 元素的大小*元素个数 4 * 5 == 20
	//将每个字符串打印输出 ,打印字符串用%s
	for(i = 0; i < 5; i++)
	{
		printf("%s\n",a[i]);
	}
	return 0;
}


//练习：定义一个整型指针数组 ,元素个数有3个 

int* a[3]; //整型指针数组

//////////////////////////////////////////

#include <stdio.h>


int main(int argc, const char *argv[])
{
	int b = 3, c = 4, d = 5;
	int i;
	int* a[3] = {&b,&c,&d};
	//请你用循环,将b c d的值打印输出
	for(i = 0; i < 3; i++)
	{
		printf("%d\n",*a[i]);//优先级[]优先级高于*，所以a[i]是在一起的，代表元素也就是指针变量int*
	}
	return 0;
}

数组指针：本质是指针，研究角度：指针的类型是什么，指针指向的类型是什么？

整型指针 int* p: 指针的类型是int* (用手挡住p,剩下的就是指针的类型) , 指针指向的类型 int (用手挡住*p) 
字符指针 char* p: 指针的类型是char*  (用手挡住p,剩下的就是指针的类型) , 指针指向的类型 char (用手挡住*p) 


整型指针，指向的类型是整型
字符指针，指向的类型是字符 
数组指针，指向的类型是数组


#include <stdio.h>

int main(int argc, const char *argv[])
{
	//sizeof求变量或数据类型所占内存空间的大小
	//数组指针
	int a;//a是变量的名字　a的数据类型是int 
	printf("%d %d\n",sizeof(int),sizeof(a));
	int b[5];//b变量的名字 b的数据类型是 int [5] 
	printf("%d %d\n",sizeof(int [5]),sizeof(b));
	return 0;
}

///////////数组指针与二维数组////////////

int b[3][4] = {{1,2,3,4},{5,6,7,8},{2,2,3,4}}; //抽象二维数组看成，由三个一维数组(int [4])组成
    
		
		
		b[0][0] b[0][1] b[0][2] b[0][3]
		
		b[1][0] b[1][1] b[1][2] b[1][3]
		
		b[2][0] b[2][1] b[2][2] b[2][3]
		
		//请问三个一维数组的名字叫什么  b[0]  b[1] b[2]
		b[0][1] == *(b[0] + 1)
		b[1][2] == *(b[1] + 2)
		
		i = 1, j = 2;
		b[i][j] == *(b[i]+j) == b[1][2]

int a[5] = {10,20,30,40,50};
int* p = a;

//元素 
a[i] == p[i] == *(p+i) == *(a+i)

//元素的地址
&a[i] == &p[i] == p+i == a+i
		
		
		0 1 2 3
   0 	1 2 3 4
   1 	5 6 7 8
   2 	2 2 2 4

二维数组由3个一维数组组成 

二维数组的元素类型是 int [4]， 元素个数有 3个 


二维数组： int a[5][8]; // 元素类型 int [8] 元素个数 5


#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[5] = {10,20,30,40,50};
	//数组的名字就是第一个元素的首地址 a == &a[0]
	int* p = a; //int* p = &a[0];//为什么p定义为int类型,因为元素类型是int
	//要求用指针将一维数组全部遍历
	int i,j;
	for(i = 0; i < 5; i++)
	{
		printf("%d ",p[i]);//*(p+i) == p[i]
	}
	printf("\n");
	//抛出问题 定义一个二维数组，用指针遍历二维数组,指针如何定义
	int b[3][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3}};
	//定义指针来保存数组的首地址
	int (*q)[4] = b;//q的类型定义int (*q)[4]，取决于数组b的元素类型 int [4]
	//既然q是一个指针，指针的类型和指针指向的类型
	//int* p 挡住p就是p的类型int* 挡住*p就是p指向的类型int
	//int (*q)[4] q的类型,挡住q,剩下int (*)[4],数组指针类型,　q指向的类型,挡住(*q)  int [4]
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%d ",q[i][j]);
		}
		printf("\n");
	}
	return 0;
}

////////////////////////////////////////////////////////////////
学习数组指针就是为了，将他放在函数参数上，传递二维数组的时候使用
////////////////////////////////////////////////////////////////

#include <stdio.h>

//遍历a数组
void showA(int* p, int n)//函数调用时候实参初始化形参int* p = a; int n = 5;
{//为什么p定义为int*,因为a数组的元素类型是int
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ",*(p+i));//*(p+i) == p[i]
	}
	printf("\n");
}

//遍历b数组 
void showB(int (*p)[4], int row)//int (*p)[4] = b;
{//b数组的元素类型 int [4],所以p的类型 int (*)[4]
	int i,j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}

}

int main(int argc, const char *argv[])
{
	int a[5] = {10,20,30,40,50};
	int b[3][4] = {{1,2,3,4},{5,6,7,8},{2,2,3,4}};
	showA(a,5);
	showB(b,3);//数组指针:在传递二维数组的时候，用数组指针
	return 0;
}


//////////////////////////////////////////////////

i //行指针 
j //列指针 
p[i][j] == *(*(p+i) + j) //类似于一维数的 p[i] == *(p+i)
//////////////////////////////////////////////////

#include <stdio.h>

//遍历a数组
void showA(int* p, int n)//函数调用时候实参初始化形参int* p = a; int n = 5;
{//为什么p定义为int*,因为a数组的元素类型是int
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ",*(p+i));//*(p+i) == p[i]
	}
	printf("\n");
}

//遍历b数组 
void showB(int (*p)[4], int row)//int (*p)[4] = b;
{//b数组的元素类型 int [4],所以p的类型 int (*)[4], p指向的类型的是 int [4]
	int i,j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < 4; j++)
		{
			//printf("%d ",*(p[i]+j));//把p[i]看成每个一维数组的名字 *(p[i] + j)
			printf("%d ",*(*(p+i)+j));//又因为p[i] == *(p+i) 　*(*(p+i) + j)
			//i对应二维数组的行 i称为行指针
			//j对应二维数组的列 j称为列指针
			//p[i][j] == *(*(p+i) + j) 
		}
		printf("\n");
	}

}

int main(int argc, const char *argv[])
{
	int b[3][4] = {{1,2,3,4},{5,6,7,8},{2,2,3,4}};
	int i,j;
	/*
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%d ",*(b[i] + j));//把b[i]看成每行一维数组的名字
		}
		printf("\n");
	}
	*/
	showB(b,3);//数组指针:在传递二维数组的时候，用数组指针
	return 0;
}





///////////////作业//////////////

char* name[5] = {"asan","xixi","haha","hehe","wuwu"};
//用冒泡排序，实现对这个数组的名字进行排序

for(i = 0; i < 5; i++)
{
	printf("%s\n",name[i]);
}
//"asan" "xixi"  "haha" "hehe" "wuwu"

/***
///冒泡排序之后
***/
for(i = 0; i < 5; i++)
{
	printf("%s\n",name[i]);
}

//"asan" "haha" "hehe" "wuwu"  "xixi" 


////要求 打印数组封装成一个函数 

int main()
{
	char* name[5] = {"asan","xixi","haha","hehe","wuwu"};
	showName(name,5);//遍历名字
	bubbleSort(name,5);//冒泡排序
	showName(name,5);//遍历名字
	return 0;
}

////////////作业答案/////////////////////

#include <stdio.h>
#include <string.h>

//遍历名字
void showName(char** p, int n)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("%s ",p[i]);//*(p+i) p[i]的类型是什么??char*
	}
	printf("\n");
}
//请编写一个函数，交换两个变量的值p[j] 和 p[j+1]
void swap(char** p, char** q)
{
	char* t = *p;
	*p = *q;
	*q = t;
}

//对名字排序
void bubbleSort(char** p, int n)
{
	int i,j;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-1-i; j++)
		{
			if(strcmp(p[j],p[j+1]) == 1)
			{
				/*
				//p[j] p[j+1]的类型是char*,所以交换的时候第三个变量类型是char*
				char* t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
				*/
				swap(&p[j],&p[j+1]);
			}
		}
	}
}

int main(int argc, const char *argv[])
{
	char* name[5] = {"asan","xixi","haha","hehe","wuwu"};
	showName(name, 5);
	bubbleSort(name,5);
	showName(name, 5);
	//name是数组的名字，就是数组第一个元素的首地址 name 等价 &name[0]
	//name[0]类型是char*  &name[0] 对一级指针变量&,说明&name[0],是char**
	//又因为name 等价 &name[0],所以name代表类型是char**
	return 0;
}
