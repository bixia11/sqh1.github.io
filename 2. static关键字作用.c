*****重点******面试问题 

请你说出static关键字的作用？？

(1) static 修饰局部变量，此时的变量称为静态变量，作用域不变，生命周期直到整个程序的结束

	未初始化的静态变量默认值是0, 多次调用，只初始化一次,存储位置在全局区(或数据段)。

(2) static 修饰全局变量，此时的全局变量只能在本文件中使用，不能被其他文件外部调用
 
(3) static 修饰函数，此时的函数只能在本文件中使用，不能被其他文件外部调用 


///证明(1)
#include <stdio.h>

void fun()
{
	static int x = 2;//此时的ｘ称为静态变量
	x--;
	printf("x is %d\n",x);
}

int main(int argc, const char *argv[])
{
	//printf("x is %d\n",x);//编译会报错，因为静态变量作用域不变
	fun();//1
	fun();//0
	fun();//-1
	return 0;
}

(2)(3)证明 

///test.c///
#include <stdio.h>

extern int a;//外部引用声明，告诉编译器，变量定义在其他位置
extern void fun();//提前告诉编译器，函数定义在其他位置

int main(int argc, const char *argv[])
{
	fun();
	printf("a is %d\n",a);
	return 0;
}

///b.c/// 
#include <stdio.h>

//static修饰全局变量，只能在当前b.c文件中使用，不能被外部其他的.c文件调用
static int a = 10;//全局变量
//static修饰函数，函数只能在当前b.c文件中使用，不能被外部调用
static void fun()
{
	printf("fun(): a is %d\n",a);
}


gcc test.c b.c //编译会报错，因为全局变量a和fun函数前面有static修饰，所以报错，不能被外部文件test.c调用
