
//////////////////////复习/////////////////////////////

//1. 全局变量和局部变量

	全局变量：定义在函数外部的变量

	(1) 作用域，作用于整个文件，在程序的任何位置，都可以直接使用
	(2) 生命周期，直到整个程序的结束
	(3) 未初始化默认值是0，存储位置(全局区或数据段)
	(4) 全局变量和局部比变量可以同名，优先使用的局部变量
	(5) 全局变量一个位置修改了， 其他位置都看得见，在修改之后的基础上，继续使用
	
	局部变量：定义在函数外部的变量
	
	(1) 作用域，只在{ }之间有效
	(2) 生命周期，函数调用结束之后，自动释放
	(3) 未初始化默认值是随机数 
	(4) 不同函数内部的局部变量可以同名
	(5) 函数形参上的变量和函数内部定义的变量不可以同名
	
//2. static 关键 

	extern 关键字：外部引用声明 
	
		extern int a;//对全局变量外部引用声明
		extern void fun(); //对函数进行外部引用声明
	
	static 
	
		(1)修饰局部变量，此时的变量称为静态变量，作用域不变，生命周期直到整个程序的结束，未初始化默认值是0
			，多次调用，只初始化一次，存储位置(全局区或数据段)
		(2)修饰全局变量，这个全局变量只能在本文件中使用，不能被其他外部文件调用
		(3)修饰函数，这个函数只能在本文件中使用，不能被其他外部文件调用
	
//3. const关键字:作用常量化 

		const int a = 10;
		a = 200;//报错 a read-only
		
		const修饰指针 
		
		方法：研究const在谁的前面 
		
		int a = 10;
		int b = 20;
		const int* p = &a;//const在*p前，*p不可变
		p = &b;
		*p = 200;//此行报错
		
		
		int a = 10;
		int b = 20;
		int const* p = &a;//const在*p前，*p不可变
		p = &b;
		*p = 200;//此行报错
		
		
		int a = 10;
		int b = 20;
		int* const p = &a;//const在p前，p不可变
		p = &b;//此行报错
		*p = 200;
		
		
		
		int a = 10;
		int b = 20;
		const int* const p = &a;//const在*p 和 p前，*p 和 p都不可变
		p = &b;//此行报错
		*p = 200;//此行报错
		
		
		int a = 10;
		int b = 20;
		int const * const p = &a;//const在*p 和 p前，*p 和 p都不可变
		p = &b;//此行报错
		*p = 200;//此行报错
		
//4. 动态内存分配：在程序运行的时候，确定分配空间的大小 


	int n;
	scanf("%d",&n);//10
	
	int* p = malloc(n*sizeof(int));//类似于  int a[10]
	
	free(p);
	
	(1)请您你知道动态内存分配吗？？ 知道
	
		动态内存分配，空间是在哪儿分配的？？ 在堆区 
	
	(2)使用的是哪个函数？？
	
		malloc函数 
	
	(3)malloc函数的参数和返回值的意义是什么？？
	
		参数：堆申请空间的大小size，以字节为单位 
		返回值：申请空间的首地址
	
			成功：返回堆空间申请内存的首地址
			失败：返回值是NULL
		
	(4)使用malloc函数的注意事项是什么？？？
	
		(1) 必须对malloc函数的返回值进行判断，判断是否申请成功
		(2) malloc属于手动申请空间，必须手动释放
	
	
	内存管理：
	
	代码区(代码段)：只读，保存程序的代码 常量区 只读，常量 字符串常量 
	全局区(数据段)：存放的是全局变量和静态变量 生命周期直到整个程序结束，未初始化默认值是0 
					分为已初始化的全局区 和 未初始化的全局区 
					
	堆： malloc申请，必须手动申请，手动释放
	栈： 保存函数的局部变量，函数调用结束后，自动释放
	
	
//5. 数组指针和指针数组 

	(1) 指针数组：本质是数组， 元素的类型和元素的个数 
		
		char* a[5] = {"haha","xixi","wuwu","heihei","gaga"};
		//数组中的元素类型char* 
		//sizeof(a) -----> 20 
		//sizeof(a[0]) ----> 4
		
		
		int a1 = 3,a2 = 5, a3 = 6;
		int*  b[3] = {&a1,&a2,&a3};
		
		//sizeof(b) -----> 12 
		//sizeof(a[0]) ----> 4
		
	(2) 数组指针：本质是指针， 指针的类型和指针指向的类型
	
		int a[4];//a的类型是什么？？ int [4]
	


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

新知识： 二级指针 + 指针函数 + 函数指针 + 函数指针数组 

1. 二级指针： 指向指针的指针 

int a = 10;
int* p = &a;//p 一级指针 
int** q = &p//q 二级指针 



#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 10;
	int* p = &a;
	int** q = &p;
	printf("%d %d %d\n",a,*p,**q);
	printf("%p %p %p\n",&a,p,*q);
	printf("%p %p\n",&p, q);
	return 0;
}

//////打印输出结果

10 10 10 // a == *p == **q  --->int 
0xbfa563b4 0xbfa563b4 0xbfa563b4 // &a == p == *q --->int*
0xbfa563b8 0xbfa563b8 //&p == q ----> int**



int a = 10;
int* p = &a;//p 一级指针 
int** q = &p//q 二级指针 

类型

a 	//int
p   //int*
q   //int** 
&a  //int*
*p	//int
&p	//int** 
**q //int 
&q  //int*** 


重要的笔试题：

		请问下面的这段代码有问题吗？如果有，请指出 
		运行程序，段错误，因为p调用getMemory函数后，依然是空指针


#include <stdio.h>
#include <stdlib.h>

//封装一个函数，申请 空间
void getMemory(int* q)
{ //实参初始化形参 int* q = p;
	//调用getMemory可以得到申请空间的首地址
	q = malloc(5*sizeof(int));
	if(q == NULL)
	{
		printf("malloc failed!!\n");
		return;
	}
	
}


int main(int argc, const char *argv[])
{
	int i;
	int* p = NULL;
	getMemory(p); //值传递，将p里面保存的地址，给函数形参变量q
	//装上５个学生成绩
	for(i = 0; i < 5; i++)
	{
		p[i] = i*10;
		printf("%d\n",p[i]);
	}
	
	free(p);
	return 0;
}

/////一个函数想要给他的调用者，传递值有几种方式 
(1) return value;返回值 
(2) 参数上的地址传递

//////////////修正后的代码，要用二级指针,通过参数上地址传递的方式，将malloc申请空间的首地址返回///////////////

#include <stdio.h>
#include <stdlib.h>

//封装一个函数，申请空间
void getMemory(int** q)
{//实参初始化形参 int** q = &p;
	//调用getMemory可以得到申请空间的首地址
	*q = malloc(5*sizeof(int)); //因为q保存的是main函数中p的地址,所以*q代表的是main函数中的p
	if(*q == NULL)
	{
		printf("malloc failed!!\n");
		return;
	}
	
}

int main(int argc, const char *argv[])
{
	int i;
	int* p = NULL;
	getMemory(&p);//调用完函数之后，成功现象，是p里面保存了申请空间的首地址
				  //把p的地址，给函数的形参变量q
				 
	//装上５个学生成绩
	for(i = 0; i < 5; i++)
	{
		p[i] = i*10;
		printf("%d\n",p[i]);
	}
	
	free(p);
	return 0;
}


////////////通过return 返回值的形式，将malloc申请空间的首地址返回/////////////


#include <stdio.h>
#include <stdlib.h>

//通过返回值的形式，将申请空间的首地址返回
int* getMemory()
{
	//调用getMemory可以得到申请空间的首地址
	int* q  = malloc(5*sizeof(int)); //因为q保存的是main函数中p的地址,所以*q代表的是main函数中的p
	if(q == NULL)
	{
		printf("malloc failed!!\n");
		return NULL;
	}
	return q;
}

int main(int argc, const char *argv[])
{
	int i;
	int* p = NULL;
	p = getMemory();//调用完函数之后，成功现象，是p里面保存了申请空间的首地址

	//装上５个学生成绩
	for(i = 0; i < 5; i++)
	{
		p[i] = i*10;
		printf("%d\n",p[i]);
	}
	
	free(p);
	return 0;
}


//////练习题 

查找一个字符串中是否出现某个字符，如果出现了这个字符，请将这个字符的首地址返回，在main函数中将其打印

//char letter //被查找的字符
#include <stdio.h>

//char* s 保存字符串的首地址
//char letter 被查找的字符
char* iswithin(char* s, char letter)
{
	//遍历字符串查找
	/*
	//方法一
	while(*s != '\0')
	{
		if(*s == letter)
			return s;

		s++;//指针向后移动一个位置，指向下一个字符
	}
	//如果程序能够执行到这，说明查找的字符不存在,用空指针来表达不存在
	return NULL;
	*/
	//方法二 
	int i = 0;
	while(s[i] != '\0')
	{
		if(s[i] == letter)
			return &s[i];//return s+i
		i++;
	}
	return NULL;//用空指针来表达不存在
}

int main(int argc, const char *argv[])
{
	char a[] = "hello";
	char* p = iswithin(a, 'e');
	if(p == NULL)
		printf("没有找到!!\n");
	else
		printf("%c找到了!!\n",*p);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
数组指针: int (*p)[8]    p的类型 int (*)[8]   p指向的类型 int [8]
指针数组 

指针函数：本质是函数，研究问题角度  参数个数及类型 + 返回值的类型  
函数指针：本质是指针，研究问题角度  指针的类型 + 指针指向的类型


指针函数：返回值为指针的函数就是指针函数 

	char* iswithin(char* s, char letter)//指针函数  返回值是char* 
	int* getMemory()//指针函数  返回值是int*
	int getmax(int a, int b) //不是指针函数 ,返回值是int 
	void *malloc(size_t size);//指针函数  返回值是void*
	char *strcpy(char *dest, const char *src);//指针函数  返回值是char* 

整型指针：指向整型的指针 
字符指针：指向字符的指针 
数组指针：指向数组的指针

函数指针：指向函数的指针
												
	int add(int a, int b)  //函数add的类型是什么 int (int,int)  
	int sub(int a, int b)  //函数sub的类型是什么 int (int,int)
	int mul(int a, int b)  //函数mul的类型是什么 int (int,int)
	int dev(int a, int b)  //函数dev的类型是什么 int (int,int)
	char* iswithin(char* s, char letter) //函数iswithin的类型是什么 char* (char*,char)
	int* getMemory()//函数getMemory的类型是什么 int* ()
	int getMax(int a, int b) //函数getMax的类型是什么 int (int,int)
	void *malloc(int size);//函数malloc的类型是什么 void* (int)
	char *strcpy(char *dest, const char *src); ////函数strcpy的类型是什么 char* (char*, const char*)

	函数的名字，就是函数在内存当中的首地址

	(1) 如何定义一个函数指针，指向一个函数
		
		//将函数的声明复制过来，将函数的名字，替换成 (*p)就可以了
		int (*p)(int, int);  //先定义一个函数指针变量p
		p = add;//给函数指针变量p，赋值

		int (*p)(int, int) = add; //直接对函数指针变量p初始化
		
		

		//p本质是指针 
		int* p //p的类型，用手挡住p，所以是int*     p指向的类型，用手挡住*p,所以指向的类型是int 
		
		int (*p)[8];
		p的类型是 int (*)[8];// 数组指针类型
		p指向的类型 int [8] //数组类型 元素个数为8个int的一维数组
		
		char* (*p)(char* , char );
		p的类型是什么？？  char* (*)(char*,char)   //这是一个函数指针类型
		p指向的类型是什么？？ char* (char*,char)   //这是一个函数类型, 参数为char* 和 char 返回值为char*类型的函数
		
		
		char* (*p)(char *, const char *) = strcpy;
		p的类型是什么 char* (*) (char*, const char*)
		p指向的类型 char* (char*,const char*)

	(2) 通过函数指针来调用函数


		#include <stdio.h>

		//四个函数属于同一个类型 int (int,int)
		int add(int a, int b)
		{
			return a + b;
		}

		int sub(int a, int b)
		{
			return a - b;
		}

		int mul(int a, int b)
		{
			return a * b;
		}

		int dev(int a, int b)
		{
			return a / b;
		}


		int main(int argc, const char *argv[])
		{
			//定义一个函数指针变量，名字叫p, 指向一个函数
			int (*p)(int,int) = add;//函数的名字就是函数的首地址
			//通过函数指针调用函数
			int ret = p(3,5);//直接用函数指针变量的名字替换函数的名字，进行调用
			printf("ret is %d\n",ret);
			p = sub;
			ret = p(3,5);//直接用函数指针变量的名字替换函数的名字，进行调用　
			printf("ret is %d\n",ret);
			return 0;
		}

	(3) 函数指针的应用，需要将函数指针放在函数的参数上，写成一个回调函数
	
		回调函数：函数的参数上有函数指针的函数，称为回调函数
		
		
		#include <stdio.h>

		//四个函数属于同一个类型 int (int,int)
		int add(int a, int b)
		{
			return a + b;
		}

		int sub(int a, int b)
		{
			return a - b;
		}

		int mul(int a, int b)
		{
			return a * b;
		}

		int dev(int a, int b)
		{
			return a / b;
		}

		//process函数就是回调函数
		//process函数有三个参数
		//int (*p)(int,int)
		//int a
		//int b 
		//后两个参数为第一个参数服务的，因为通过函数指针调用函数的时候，需要两个int
		int process(int (*p)(int,int),int a, int b)//int (*p)(int,int) = add;
		{
			int ret = p(a,b);
			return ret;
		}


		int main(int argc, const char *argv[])
		{
			int ret = process(add,8,10);
			printf("ret is %d\n",ret);
			ret = process(sub,100,20);
			printf("ret is %d\n",ret);
			ret = process(mul,2,5);
			printf("ret is %d\n",ret);
			ret = process(dev,100,2);
			printf("ret is %d\n",ret);

			return 0;
		}


//////函数指针数组//////////

		#include <stdio.h>

		//四个函数属于同一个类型 int (int,int)
		int add(int a, int b)
		{
			return a + b;
		}

		int sub(int a, int b)
		{
			return a - b;
		}

		int mul(int a, int b)
		{
			return a * b;
		}

		int dev(int a, int b)
		{
			return a / b;
		}

		//process函数就是回调函数
		//process函数有三个参数
		//int (*p)(int,int)
		//int a
		//int b 
		//后两个参数为第一个参数服务的，因为通过函数指针调用函数的时候，需要两个int
		int process(int (*p)(int,int),int a, int b)//int (*p)(int,int) = add;
		{
			int ret = p(a,b);
			return ret;
		}


		int main(int argc, const char *argv[])
		{
			//函数指针数组，本质是数组，数组中的元素类型是函数指针
			// int (*)(int,int)
			int (*a[4])(int,int) = {add, sub, mul, dev};
			//sizeof(a) == 16
			//数组的元素类型是 int (*)(int,int) 函数指针类型,用手挡住数组名和元素个数a[4]，剩下的就是元素类型 
			//数组的元素个数 4
			//如何找数组元素的类型
			//int a[5];//用手挡住数组的名字和元素的个数,剩下的就是元素类型 挡住a[5]
			int i;
			for(i = 0; i < 4; i++)
			{
				int ret = a[i](3,5);
				printf("%d\n",ret);
			}
			return 0;
		}				
		
		
/////练习：

p的本质有三种可能 指针  数组  函数 

p是一个数组: 介绍 元素类型和个数
p是一个指针: 介绍 p的类型和指向的类型
p是一个函数: 介绍 函数参数个数及类型 和 返回值的类型

//解题方法：一定要先确定本质，因为确定了本质你就知道了研究问题的角度
//有了研究问题的角度，你就知道用手应该挡住谁
//只要看到(*p)这种写法，本质立刻定义为指针

int *p[3];//数组 [优先级高于*，所以p和[3]先结合在一起，本质是数组 

(1)元素类型  用手挡住数组名字和元素的个数，剩下的就是元素的类型 int*
(2)元素个数  3
(3) 整型指针数组(元素个数3)

int (*p)[3];//指针
(1) p的类型，用手挡住p,剩下的就是类型 int (*)[3]  
(2) p指向的类型，用手挡住(*p),剩下的就是指向的类型 int [3]
(3) 数组指针 p指向的是一个元素个数3个int的一维数组的指针

int *p(int, int);// (优先级高于*,所以p和()结合在一起,本质是函数声明
(1)参数：()内函数的参数列表 2个int  
(2)返回值类型 int*
(3)这个函数的返回值类型是int*,是一个指针，所以这是 指针函数声明

int (*p)(int,int);//指针
(1) p的类型，用手挡住p,剩下的就是类型 int (*)(int,int)  函数指针类型
(2) p指向的类型，用手挡住(*p),剩下的就是指向的类型 int (int,int) 函数类型
(3) 函数指针 p指向的类型是参数为2个int，返回值为int类型的函数

int *(*p)(int,int);//指针
(1) p的类型，用手挡住p,剩下的就是类型 int* (*)(int,int)  函数指针类型
(2) p指向的类型，用手挡住(*p),剩下的就是指向的类型 int* (int,int) 函数类型,p指向的类型是一个指针函数
(3) (指针函数)指针 p指向的类型是参数为2个int，返回值为int*类型的指针函数

int (*p[3])(int,int);//数组 [优先级高于*，所以p和[3]先结合在一起，本质是数组

(1)元素类型  用手挡住数组名字和元素的个数，剩下的就是元素的类型 int (*)(int,int); 函数指针
(2)元素个数  3
(3) (函数指针)数组(元素个数3)

int *(*p[3])(int,int);//数组 [优先级高于*，所以p和[3]先结合在一起，本质是数组

(1)元素类型  用手挡住数组名字和元素的个数，剩下的就是元素的类型 int *(*)(int,int);  指针函数指针
(2)元素个数  3
(3)(指针函数)指针数组(元素个数3)


指针函数指针： int *(*)(int,int) 这个函数指针，指向的函数类型是一个 指针函数