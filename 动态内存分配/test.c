#include <stdio.h>

//test 4-27

//��̬�ڴ����   - �ڶ��Ϸ���

//malloc��free  - ���������ɶ�ʹ��
//void* malloc(size_t size)

//void free(void* memblock)


#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	//���ڴ�������10�����εĿռ�
	int* p = (int*)malloc(10 * sizeof(int));
	// int* p = (int*)malloc(INT_MAX); //��ռ�ռ�̫��pΪNULL
	if (p == NULL)
	{
		//��ӡ����ԭ���һ����ʽ
		printf("%s\n", strerror(errno));
	}
	else
	{
		//��ȷʹ�ÿռ�
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
	//���ռ䶯̬����Ŀռ䲻��ʹ�õ�ʱ��
	//���ռ仹������ϵͳ
	free(p);
	//������Ȼp�Ŀռ䱻�ͷ��ˣ�������������ͨ��p�ҵ�����ռ䣬���Ǻ�Σ�յģ��˴�pҲ���ǿ�ָ��
	p = NULL;
	//������ָ�벻����㱻���ã��ͻ����ȫ��������ԭ�ռ䳹�׶ϵ���ϵ
	return 0;
}