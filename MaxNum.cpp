/*����һ��4λ��Ȼ�������ú����������Ȼ��������ɵ������*/
#include"stdio.h" 
void fun(int a)
{
	int i,j,buf,x[4];
	for (i=0;i<4;i++)
{
	x[i]=a%10;
	a/=10;//�����ڵ�ʮλ 
}
	for (i=0;i<4;i++)// �ⲿѭ�� 
{
	for (j=0;j<3;j++)
{
	if (x[j]>x[j+1])// 
{
	buf = x[j+1];
	x[j+1] = x[j];
	x[j] = buf;
}
}
	printf("%d",x[3]);
	x[3] = -1;
}
	printf("\n");
}
	int main() 
{ 
	int a;
	scanf("%d",&a); 
	fun(a);
}
