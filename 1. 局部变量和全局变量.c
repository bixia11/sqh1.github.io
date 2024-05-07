1. 局部变量： 定义在函数内部的变量称为局部变量

	(1)局部变量的作用域只在{}之间有效 
	(2)局部变量的生命周期在函数调用结束后，自动释放，存储位置（栈）
	(3)未初始化的局部变量，默认值是随机数（垃圾值）
	(4)不同函数里面的两个局部变量可以同名
	(5)在同一个函数里，函数体内的局部变量和函数的形参不能同名
	
	(1)证明	
		
	#include <stdio.h>

	int main(int argc, const char *argv[])
	{
		if(3 > 2)
		{
			int a = 10;
		}
		printf("a is %d\n",a);//编译报错，因为int a 定义在if {}内，超出作用域范围
		return 0;
	}

	(3) (4) (5)证明
	#include <stdio.h>

	void fun(int a)//函数形参的变量a和内部的a不能同名，编译会报错
	{
		int a;//局部变量,未初始化，默认值是
		printf("fun():a is %d\n",a);
	}

	int main(int argc, const char *argv[])
	{
		int a = 10;
		fun(5);
		printf("a is %d\n",a);//编译报错，因为int a 定义在if {}内，超出作用域范围
		
		return 0;
	}
	
2. 全局变量:定义在函数外部的变量称为全部变量


	(1)全局变量的作用域在程序的任何位置都可以直接使用 
	(2)全局变量的生命周期直到整个程序的结束，存储位置(全局区或数据段)
	(3)未初始化的全部变量，默认值是 0
	(4)全局变量和局部变量可以同名吗？可以，优先使用的是局部变量
	(5)对于全局变量，一个地方修改了，其他的任何位置都看得见
	


//////extern关键字，外部引用声明 

#include <stdio.h>

//当你把全局变量放在下面的时候，编译器找不到
extern int a;//外部引用声明,这句话不是在定义变量，只是提前告诉编译器,有这么个全局变量名字叫a，定义在其他位置

int main(int argc, const char *argv[])
{
	printf("a is %d\n",a);
	return 0;
}

int a;//未初始化的全局变量，默认值是0

//////////////////////////////////////////////////////////////




//////////////(4) (5)证明//////////

#include <stdio.h>

int a = 100;//未初始化的全局变量

void fun1()
{
	a -= 10;
	printf("fun1(): a is %d\n",a);//a is 90
}
void fun2()
{
	a -= 10;
	printf("fun2(): a is %d\n",a);//a is 80
}
void fun3()
{
	a -= 10;
	printf("fun3(): a is %d\n",a);//a is 70
}
void fun4()
{
	int a = 15;//局部变量a和全局变量ａ可以同名，优先使用的局部变量
	printf("fun4(): a is %d\n",a);//a is 15
}

int main(int argc, const char *argv[])
{
	fun1();
	fun2();
	fun3();
	fun4();//(4)证明，编译不报错
	printf("a is %d\n",a);//a is 70
	return 0;
}
