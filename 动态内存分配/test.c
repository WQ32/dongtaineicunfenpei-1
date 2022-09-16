#include <stdio.h>

//test 4-27

//动态内存分配   - 在堆上分配

//malloc和free  - 两个函数成对使用
//void* malloc(size_t size)

//void free(void* memblock)


#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	//向内存中申请10个整形的空间
	int* p = (int*)malloc(10 * sizeof(int));
	// int* p = (int*)malloc(INT_MAX); //所占空间太大，p为NULL
	if (p == NULL)
	{
		//打印错误原因的一个方式
		printf("%s\n", strerror(errno));
	}
	else
	{
		//正确使用空间
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//当空间动态申请的空间不再使用的时候
	//将空间还给操作系统
	free(p);
	//这里虽然p的空间被释放了，但我们依旧能通过p找到这个空间，这是很危险的，此处p也能是空指针
	p = NULL;
	//这样空指针不能随便被调用，就会更安全，将其与原空间彻底断掉联系
	return 0;
}