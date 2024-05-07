2 内存管理

	2.1程序内存分配，分为两种方式
	
	(1)静态分配(在编译时确定内存的大小)
	
		int a;           //给a分配4字节空间
		char c[100];     //给c分配100个字节空间


		静态分配，在编译时就确定好内存空间的大小

		
		
		为什么有动态内存分配这个知识点？？
		写一个程序，保存全班的数学成绩？？
		(1) 数组定义小了，灵活性不行 
		(2) 数组定义大了，浪费空间
		
		
		int n;//代表班级的人数 
		printf("请您输入班级人数:\n");
		scanf("%d",&n);//78
		int a[n]; //语法错误的  定义的数组的时候，长度是固定的，必须是一个常量
		
						  int n;
		所以数组 不能这样 char c[n];   //数组元素个数一定是一个常量  n是变量语法错误
		
		
		
		学完动态内存分配，就可以解决上面的问题
		
		
	(2)动态内存分配：在程序运行的时候，才确定分配空间的大小
		
		利用malloc函数，在堆空间申请一块内存
		
		typedef int size_t;
		
		
		#include <stdlib.h>

		void *malloc(size_t size);
		void free(void *ptr);
		
		#功能：在堆空间手动申请一块内存 
		#参数:
			int size;//申请空间的大小，以字节为单位
		#返回值: void* (无类型指针) 返回值是一个指针类型
				返回值就是在堆空间申请内存的首地址
				返回值0x********
				
				成功：返回值是申请连续空间的首地址
				失败：返回值是NULL
		
		
		//举例：想要在堆空间申请4个字节，保存一个整数
		
		void free(void *ptr);

		

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	//静态内存分配
	int a;//4个字节 栈区
	int* p = &a;//4个字节的首地址
	*p = 100;//将100存储，在栈区a的４个字节空间内
	printf("栈区:%d\n",*p);

	//动态内存分配,因为想存整数，所以q的类型是int*
	//int* q = malloc(4);//在堆空间申请４个字节，返回值是４个字节的首地址
	int* q = malloc(sizeof(int));
	//必须做容错判断，判断空间是否申请成功
	if(q == NULL)//申请失败
	{
		printf("malloc failed!!\n");
		return -1;
	}
	*q = 100;//将100存储在堆区的４个字节中
	printf("堆区:%d\n",*q);//将堆区存储的内容打印输出
	//malloc属于手动申请，必须手动释放
	free(q);//在释放的时候，需要的是申请空间的首地址
	return 0;
}




#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	//静态内存分配
	int i;
	int a[5];//20个字节 栈区
	int* p = a;//p保存 栈区 20个字节的首地址,数组的名字就是数组在内存当中的首地址
	//给栈区的5个int赋值,共20个字节
	for(i = 0; i < 5; i++)
	{
		p[i] = i*10;//*(p+i) = i*10;
	}
	//将栈区5个int打印输出,共20个字节
	for(i = 0; i < 5; i++)
	{
		printf("%d\n",p[i]);//printf("%d\n",*(p+i));
	}


	//动态内存分配,因为想存整数，所以q的类型是int*
	int* q = malloc(5*sizeof(int));//q保存 堆区 20个字节的首地址
	//必须做容错判断，判断空间是否申请成功
	if(q == NULL)//申请失败
	{
		printf("malloc failed!!\n");
		return -1;
	}
	//给堆区的5个int赋值,共20个字节
	for(i = 0; i < 5; i++)
	{
		q[i] = i*11;//*(q+i) = i*11;
	}
	//将堆区5个int打印输出,共20个字节
	for(i = 0; i < 5; i++)
	{
		printf("%d\n",q[i]);//printf("%d\n",*(q+i));
	}

	free(q);//在释放的时候，需要的是申请空间的首地址
	return 0;
}	
	
							
	char *p = (char*)malloc(100*sizeof(char));	//malloc是动态分配内存函数, 100是分配的内存大小,   类似于 char a[100];
				//返回值分配的内存的首地址，赋值给p, 使用p可以访问这块内存
	int *p = (int*)malloc(100 * sizeof(int));  //类似于 int a[100];

	struct student *p = (struct student*)malloc(100 * sizeof(struct student)); //类似于 struct studnet a[100];

	定义有n个元素的动态数组，并输出
	
		
	##练习7

	学生人数由输入确定，动态分配内存，保存scanf输入n个学生成绩，
	然后求出学生平均成绩
	
	
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int n,i;//代表班级的人数
	int sum = 0;
	printf("请您输入班级人数:\n");
	scanf("%d",&n);
	int* p = malloc(n*sizeof(int));
	if(p == NULL)
	{
		printf("malloc failed!!\n");
		return -1;//提前结束main函数
	}
	for(i = 0; i < n; i++)
	{
		printf("请输入第%d个学生:\n",i+1);
		scanf("%d",&p[i]);//scanf("%d",p+i);
		sum += p[i];//sum += *(p+i);
	}
	printf("avg is %.2f\n",(float)sum/n);
	//必须手动释放
	free(p);
	return 0;
}	
	
	
	
	注意：
	
	(1)
	malloc申请空间必须手动申请，手动释放
	动态内存分配，不会自动释放，需要在程序里释放
	free(p);    

	通常 malloc 和 free要成对出现
	
	(2)
	
	动态内存分配可能失败

	如果分配失败，malloc返回值为NULL,

	所以，分配后要检查p是不是NULL
	
	使用malloc函数的时候，一定要加上条件判断，对申请是否成功，做出判断


///内存管理//总结 


代码区(代码段): 特点只读，保存程序代码 常量区保存的是字符串常量

全局区(数据段): 存放全局变量和静态变量,生命周期直到整个程序的结束，未初始化默认值是0

				已初始化的全局区    未初始化全局区 
				已初始化全局变量	未初始化的全局变量 
				已初始化的静态变量  未初始化的静态变量
				
堆： malloc动态内存分配，在堆区手动申请的空间，每申请一个空间，就会标记为已用，所以必须要手动释放free(p)
栈： 局部变量，生命周期随着函数的调用结束而结束，自动创建自动释放

///关于字符串 

char* p = "hello";
p[0] = 'H';//报段错误，因为修改的是常量区里面的字符串，常量区是只读的，不可改

char a[] = "hello";
a[0] = 'H';//可以，修改的是栈区的那份字符串


	