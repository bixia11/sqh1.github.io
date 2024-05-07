typedef //类型重定义 
static  //修饰局部变量 静态变量 修饰全局变量和函数 保护作用
extern  //外部引用声明 可以对全局变量和函数进行声明
const   //常量化的意思


#include <stdio.h>

int main(int argc, const char *argv[])
{
	const int a = 10;//此时a被const修饰，是一个常量，不可改
	a = 200; //此行代码编译报错，因为a定义的时候，有const修饰
	printf("a is %d\n",a); 
	return 0;
}


///////(1)const 在*p前面，*p是常量,不可改有两种写法，是等价的//////////
const int* p = &a; == int const* p = &a; 二者等价
*p = 200;//报错

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 10;
	int b = 20;
//	const int* p = &a;//const在*p的前面，*p是一个常量,p指向的内存空间里面存储的值不可改
	int const* p = &a;//上下两种写法，表达的是同一个意思
	*p = 200; //会报错
	p = &b; //不会报错，因为*p是常量，指向可改
	printf("a is %d\n",a);
	return 0;
}

///////(2)const 在p的前面，p是常量，p里面保存的地址不可变///////
int* const p  = &a;
p = &b;//报错

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 10;
	int b = 20;
	int* const p = &a;//const在p的前面，所以p是一个常量，p里面保存的地址不可变
	*p = 200;//不会报错，因为p是常量 
	p = &b;//此行代码报错，因为p是常量
	printf("a is %d\n",a);
	return 0;
}

//////////(3) 在p和*p的前面各有一个const，p和*p都不可变,两种写法 
const int* const p = &a; == int const* const p = &a;

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 10;
	int b = 20;
	//const int* const p = &a;//在p和*p前都有const修饰，p和*p都不可变
	int const* const p = &a;
	*p = 200;//此行代码也报错，因为*p是常量
	p = &b;//此行代码报错，因为p是常量
	printf("a is %d\n",a);
	return 0;
}




/////////////字符串拷贝函数 


char* strcpy( char* dest, const char* src)
{
	
}

//////字符串比较 
int strcmp(const char* s1, const char* s2)
{
	
}

//"abc" < "b"  strcmp("abc","b"); -----> -1
//"aab" < "abcd"  -1
//"bb" > "a" 1
//"aaa" "aaa" 0


//求字符串长度 
int strlen(const char* s1)
{
	
}
//字符串连接函数
int strcat(char* dest, const char* src)
{
	
}