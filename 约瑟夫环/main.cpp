#include "head.h"
#include<malloc.h>
#include<stdio.h>
main()
{
	int n,m;
	JoseList L;
	printf("������Լɪ�򻷴�С�ͼ�����λ��n,m��");
	scanf("%d,%d", &n, &m);
	createJoseList(L,n);
	printJose(L,n, m);
}