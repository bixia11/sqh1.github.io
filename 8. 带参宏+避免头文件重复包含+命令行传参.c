1. 标准main函数，命令行传递参数 

	//系统预设变量

	bash test.sh aa bb cc 

	echo "0 is $0"  //0 is test.sh
	echo "1 is $1"  //1 is aa
	echo "2 is $2"  //2 is bb 
	echo "# is $#"  //# is 3

	bash test.sh cccc c.txt 

	mkdir $1
	cd $1
	touch $2



	./a.out aa bb cc

	"./a.out" "aa" "bb" "cc"

	char* argv[] = {"./a.out","aa","bb","cc"};
	//argv[0]类型 ---> char*
	//argv[1]类型 ---> char*
	//argv[2]类型 ---> char*
	//argv[3]类型 ---> char*

	int main(int argc, char* argv[])
	{
		
	}

	#include <stdio.h>

	//标准main函数的参数就是为了实现命令行传递参数的
	//arg -- arguments 参数
	//c count 计数　
	//int argc 命令行上的参数个数
	//argv v value 值 命令行参数值
	// .a.out aa bb cc
	//将命令行上的所有参数打印输出
	int main(int argc, char* argv[])
	{
		int i;
		printf("argc is %d\n",argc); //argc is 4  个数包含 ./a.out  
		//argc代表命令行的参数个数包含 ./a.out　
		//要将命令行上的所有参数打印输出
		for(i = 0; i < argc; i++)
		{
			printf("%s\n",argv[i]);//argv[i]的类型是char*，是一个字符指针变量，保存的是命令行上字符串的首地址
		}
		return 0;
	}



	

2. 宏定义 
	
	优点： 见名知意，一改统改
	
	宏定义的本质: 无脑替换
	
	(1) 无脑替换
	
		#include <stdio.h>

		#define N ;}

		int main(int argc, const char *argv[])
		{
			printf("hello world!!\n");
			return 0
		N
		
	(2) N被替换为5，是常量
	
		#include <stdio.h>

		#define N 5

		int main(int argc, const char *argv[])
		{
			//N = 3;//保存，因为N被替换为5,是一个常量，报错
			printf("N is %d\n",N);
			printf("hello world!!\n");
			return 0;
		}
		
	(3) 对无脑替换的再次理解
	
		#include <stdio.h>

		#define N 5
		#define M N+1

		int main(int argc, const char *argv[])
		{
			printf("M*M is %d\n",M*M);//M*M N+1*N+1 5+1*5+1 = 11
			return 0;
		}
		
	(4)带参宏(本质还是无脑替换)
	
	
		#include <stdio.h>

		#define N 5
		#define M N+1
		#define seq(x) x*x

		int main(int argc, const char *argv[])
		{
			printf("result is %d\n",seq(3));//seq(3) ---> 3*3
			printf("result is %d\n",seq(M));//seq(M) ---> M*M ---> N+1*N+1 --> 5+1*5+1 --> 11
			printf("result is %d\n",seq(1+2));//seq(1+2) --> 1+2*1+2 -- 5
			return 0;
		}

		//练习 
		请写一个带参宏，实现求两个数的最大值 
		
		#define getMax(a,b)  (a) > (b) ? ）(a) : (b)
		
		int main()
		{
			int max = getMax(3,5);
			printf("max is %d\n",max);
		}
		
	 (5) 如果宏定义有多行，需要用\连接
	 
		#include <stdio.h>

		#define showStar printf("  *\n");\
			printf(" ***\n");\
			printf("*****\n");

		int main(int argc, const char *argv[])
		{
			showStar
			showStar
			showStar
			return 0;
		}
		
3. 条件编译 

	(1) 条件编译案例1 

		#include <stdio.h>

		#define DEBUG

		int main(int argc, const char *argv[])
		{
		#ifdef DEBUG //如果定义了DEBUG这个宏,条件句里面的代码就参加编译
			printf("hello world!!\n");
			printf("hello world!!\n");
		#endif
			printf("hello world!!\n");
			printf("hello world!!\n");
			
			return 0;
		}
		
		
	(2) #if 0 或 #if 1   //1 真  0 假
	
		#include <stdio.h>

		int main(int argc, const char *argv[])
		{
		#if 0 //0代表假 1代表真
			printf("hello world!!\n");
			printf("hello world!!\n");
			printf("hello world!!\n");
		#endif
			printf("hello world!!\n");
			
			return 0;
		}
		
	(3) 面试问题: 请问如何避免头文件的重复包含 ??

/////my.h/////		
#ifndef _MY_H //#ifndef 如果没有定义_MY_H这个宏，进入条件判断 
#define _MY_H
int max = 10;  //工作中，我们不会把全局变量放在.h文件中，会放在.c文件中
#endif		
		

//////test.c/////
#include <stdio.h>
#include "my.h"
#include "my.h"

/*
#ifndef _MY_H //真
#define _MY_H
int max = 10;
#endif

#ifndef _MY_H //假,因为上一次的条件判断是真，进入后，定义了_MY_H这个宏
#define _MY_H
int max = 10;
#endif
*/


int main(int argc, const char *argv[])
{
	printf("max is %d\n",max);
	return 0;
}	


##如何避免头文件的重复包含

#ifndef ****(宏)
#define ****(宏)

//头文件内容 

#endif 


///////////////////////////////////////////////////////////////////////////////////////////////////


//////作业： 用标准main函数，命令行传递参数，实现一个计算器  

	./a.out 35 + 78 
	// 113 
	 
	./a.out 35 - 20
	// 15 


	"./a.out" "35" "-" "20"

	"35" - "10"

	"35" ---> 35 
	"10" ---> 10

	#include <stdlib.h>

	char * p = "35"
	int num = atoi(p); //atoi函数功能：将纯数字字符串，转换为对应的整数
	printf("nun is %d\n",num);//num is 35
	
	
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	//容错判断
	if(argc != 4)
	{
		printf("忘记传递参数了!! ./a.out 34 + 5\n");
		return -1;
	}
	// argv[0]   argv[1] argv[2] argv[3]
	// "./a.out" "34"    "+" 	"67"
	//得到命令行上的两个数字
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[3]);
	//argv[2] char* 类型，保存的是字符串的首地址"+"
	// "+" 由 '+' '\0'
//	char* p = "+";
//	printf("ch is %c\n",*p);
	char oper = *argv[2];//用来保存运算符,argv[2]保存的是字符串的首地址,所以*argv[2]取出的就是第一个字符
	switch(oper)
	{
	case '+':
		printf("result is %d\n",num1+num2);
		break;
	case '-':
		printf("result is %d\n",num1-num2);
		break;
	case '*':
		printf("result is %d\n",num1*num2);
		break;
	case '/':
		printf("result is %d\n",num1/num2);
		break;

	}

	return 0;
}	
	
	