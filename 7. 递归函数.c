//复习：

1.指针数组：本质是数组，找元素类型和元素个数

	char* a[5]; //字符指针数组的元素char*  一次性定义5个char*类型的指针变量

	int* a[5]; //整型指针数组的元素int*一次性定义5个int*类型的指针变量
	
2.数组指针：本质是指针，指针的类型和指针指向的类型

	int (*p)[5]; //p的类型 int (*)[5]  指向的类型 int [5]
	
	//用途：传递二维数组 
	
	void showArray(int (*p)[9], int row)
	{
		
	}
	int main()
	{
		int a[3][9];
		showArray(a,3);
		return 0;
	}
	
	p[i][j] == *(p[i]+j) == *(*(p+i)+j)
	
	//i 行指针 
	//j 列指针
	*(*(p+i)+j) ----> p[i][j]
	
3.二级指针 ：指向指针的指针

	int a = 10;
	int* p = &a;
	int** q = &p;//对一级指针变量&，就是二级指针

	a == *p == **q //int 
	&a == p == *q  //int*
	&p == q		   //int**
	&q             //int***

4.指针函数：本质是函数，返回值是指针类型的函数称为指针函数

	char* iswithin(char* s, char letter);
	char* strcpy(char* dest, const char* src);

5.函数指针：本质是指针，指向函数的指针

	如何定义一个函数指针，指向一个函数
	
	char* (*p)(char*, char ) = iswithin; //函数的名字就是函数的首地址\
	
	
	char* (*p)(char*, char*) = strcpy;
	p的类型：char* (*) (char*,char*)
	p指向的类型: char* (char*,char*)
	p是 指针函数指针 
	
	//如何通过函数指针来调用函数 
	
	//调用iswithin
	char a[] = "hello";
	char* ret = p(a,'e')
	
	//调用strcpy函数
	char a[100];
	char b[] = "hello";
	p(a,b);
	
	回调函数：将函数指针，当做函数的参数，称为回调函数 
	
	
	char* process(char* (*p)(char*,char*), char* dest, char* src)
	{
		return p(dest,src);
	}
	
	//调用 strcpy
	char a[100];
	char b[] = "hello";	
	char* ret = process(strcpy, a, b);
	
6.函数指针数组 

	int (*a[4])(int ,int) = {add, sub, mul, dev};
	//数组的元素类型 int (*)(int,int) 函数指针类型 
	//元素个数4 
	//函数指针数组
	
////////////////新知识//////////////////////

递归函数：一个函数可以直接或间接的方式调用自己 


(1) 直接自己调用自己 

	#include <stdio.h>

	void fun2();
	//函数直接自己调用字节
	void fun1()
	{
		int a[400000];//添加一个数组，是为了加速程序栈空间不足，因为递归调用时没有释放
		printf("hello world!!\n");
		fun1();
		printf("111111111\n");//不会被打印
	}


	int main(int argc, const char *argv[])
	{
		fun1();	
		return 0;
	}

(2) 间接调用自己 

	#include <stdio.h>

	void fun2();
	//间接调用自己 
	void fun1()
	{
		int a[400000];//添加一个数组，是为了加速程序栈空间不足，因为递归调用时没有释放
		printf("hello world!!\n");
		fun2();
		printf("111111111\n");//不会被打印
	}

	void fun2()
	{
		fun1();
	}


	int main(int argc, const char *argv[])
	{
		fun1();	
		return 0;
	}

(3) 递归函数的一个应用
	

	#include <stdio.h>

	//用递归函数来写
	//这个递归函数，缺少一个递归的结束条件,不能让他无限的递归下去
	int getSum(int num)
	{
		int result;
		//递归的结束条件
		if(num == 1)
			return 1;
		result = num + getSum(num-1);
		return result;
	}


	int main(int argc, const char *argv[])
	{
		printf("result is %d\n",getSum(4));
		//getSum(4) == 4 + getSum(3) // getSum(4) == 10
		//getSum(3) == 3 + getSum(2) // getSum(3) == 6
		//getSum(2) == 2 + getSum(1) // getSum(2) == 3
		//getSum(1) == 1
		return 0;
	}

(4) 笔试题：

	斐波那契数列 
	
	0 1 1 2 3 5 8 13 ..... 
	
	前两项的和等于第三项 
	
	
	请你写一个递归函数，打印满足这样序列
	
	F(0) == 0
	F(1) == 1
	F(2) == 1
	F(3) == 2
	F(4) == 3
	F(5) == 5
	..
	..
	..
	F(19) == 
	
	
#include <stdio.h>

int F(int n)
{
	
	if(n == 0 || n == 1)
		return n;

	int result = F(n-1) + F(n-2);
	return result;
	//return F(n-1) + F(n-2);
}

int main(int argc, const char *argv[])
{
	int i;
	for(i = 0; i < 20; i++)
	{
		printf("%d ",F(i));
	}
	printf("\n");
	return 0;
}
