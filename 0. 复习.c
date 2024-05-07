//复习：
(1)指针 

	指针：内存单元地址称为指针 
	1G == 1024M
	1M == 1024kb
	1kb == 1024字节 byte 
	1 byte == 8 bit
	内存 4G  //4*1024*1024*1024字节  4*1024*1024*1024-1
	内存单元  //基本单位 占 1个字节 
	内存单元地址 //一共有4*1024*1024*1024个字节
	
	//对这个字节，进行编号 内存单元编号
	0 1 2 3 4 .......4*1024*1024*1024-1	
	0x00000000 0x00000001 ... 0x0000000F .....0xFFFFFFFF
	
(2)如何定义一个指针变量，在使用指针

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 10;
	int* p;//定义一个整型的指针变量
	p = &a;//将变量ａ的首地址保存到p里面
	printf("p is %p  &a is %p\n",p,&a); 
	//*p *代表取值的意思，通过ｐ里面保存的地址，找到那块内存，取出值
	printf("*p is %d a is %d\n",*p,a);
	*p = 200;//*p代表的是谁？？ 因为p里面保存是的变量ａ的地址，所以*p代表的就是a
	printf("a is %d\n",a); //a is 200
	return 0;
}

//值传递和地址传递 
void swap(//参数自己定义)
{
	
}

int main()
{
	int a = 3;
	int b = 5;
	swap(//参数自己思考);//交换变量a和b里面的值
	printf("a is %d b is %d\n"a,b);//a is 5  b is 3
}	


///////值传递，不可以修改实参变量的值

#include <stdio.h>

//值传递
void swap(int a, int b)//函数调用的时候实参初始化形参 int a = a(main函数)　int b = b(main函数)
{
	int t = a;
	a = b;
	b = t;
}


int main(int argc, const char *argv[])
{
	int a = 3, b = 5;
	swap(a,b);
	printf("a is %d b is %d\n",a,b);
	return 0;
}

#include <stdio.h>

//地址传递 ，可以修改实参变量的值 
void swap(int* p, int* q)//int* p = &a  int* q = &b;
{
	int t = *p;
	*p = *q;
	*q = t;
}


int main(int argc, const char *argv[])
{
	int a = 3, b = 5;
	swap(&a,&b);
	printf("a is %d b is %d\n",a,b);
	return 0;
}

int fun()
{
	return 1;
	return 2;
	return 3;
}

//学习完指针有啥用

调用一个函数，可以求出长方形的面积和周长

int main()
{
	int L,S;//保存周长和面积
	//调用函数
	printf("L is %d S is %d\n",S,L);
}

#include <stdio.h>
//通过地址传递的方式，给main函数传递了两个值周长和面积
void getSL(int length, int width, int* p, int* q)//实参初始化形参int* p = &L; int* q = &S
{
	*p = (length + width) * 2;//因为p里面保存的是main函数中L的地址，所以*p代表的是main函数的L
	*q = length * width;
}

int main(int argc, const char *argv[])
{
	int S,L;//用来保存面积和周长
	getSL(10,5,&L,&S);
	printf("S is %d L is %d\n",S,L);
	return 0;
}

#include <stdio.h>
//通过return返回值，将面积返回值 ，参数上的地址传递，将周长返回
int getSL(int length, int width, int* p)//实参初始化形参int* p = &L; int* q = &S
{
	*p = (length + width) * 2;//因为p里面保存的是main函数中L的地址，所以*p代表的是main函数的L
	return  length * width;
}

int main(int argc, const char *argv[])
{
	int S,L;//用来保存面积和周长
	S = getSL(10,5,&L);
	printf("S is %d L is %d\n",S,L);
	return 0;
}

#总结：
	
	一个函数想要给他的调用传递值有几种方法
	
	(1) 返回值的形式return value;
	(2) 参数上的地址传递 


(1) 低于平均分的人数 
(2) 求出平均分

编写函数fun：从n个学生的成绩中统计出低于平均分的学生人数，由函数返回值返回，
平均分存放在形参*ptr_aver所指的存储单元中(即平均分由参数上的地址传返回),调用fun函数，可以得到两个值 

低于平均分的人数  return count;
平均分            参数上的地址传递
//float *s ---> 保存数组的首地址
//int n --->数组元素的个数 
//float *ptr_aver ---> 参数上的地址传递，将平均分返回
函数原型为：int fun( float *s, int n, float *ptr_aver );
例如：若输入8名学生的成绩如下
 float a[8] = {80.5 , 60 , 72 , 90.5 , 98 , 51.5 , 88 , 64};
则低于平均分的学生人数为：4(平均分:75.5625)。
#include <stdio.h>

int fun(float* s, int n, float* ptr_aver)
{
	int count = 0;//用来计数
	float sum = 0;
	int i;
	//求平均分
	for(i = 0; i < n; i++)
		sum += s[i];
	*ptr_aver = sum / n;//由于ptr_aver保存的是main函数中avg的地址,所以*ptr_aver代表的是main函数中的avg
	//执行之后,修改了 main函数中avg的值
	//统计低于平均分的人数
	for(i = 0; i < n; i++)
	{
		if(s[i] < *ptr_aver)
		{
			count++;
		}
	}
	return count;
}


int main()
{
	float a[8] = {80.5, 60, 72, 90.5, 98, 51.5, 88, 64};
	int count;//用来保存低于平均分的人数
	float avg;//用来保存平均,参数上的地址传递 
	count = fun(a, 8, &avg);
	printf("平均值是%f\n",avg);
	printf("低于平均分的人数是%d\n",count);
	return 0;
}

//////////////////char* a 和 char a[]的区别////////
#include <stdio.h>

int main(int argc, const char *argv[])
{
	//将一个字符串中的小写转为大写
//	char a[] = "hello";
	char* a = "hello"; //程序会报段错误，因为修改的是常量区的"hello"
	printf("%s\n",a);
	int i = 0;
	while(a[i] != '\0')
	{
		if(a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;//a[i] = a[i] - 32;
		i++;
	}
	printf("%s\n",a);
	return 0;
}