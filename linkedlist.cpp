#include<stdio.h>
#include"malloc.h"
#include"string.h"
struct worker{
char name[20];
int age;
int salary;
};
struct link{
worker *aworker;
link *next;
};
link *input()//�������� 
{
link *head=(link *)malloc(sizeof(link));
head->aworker=NULL;
head->next=NULL;
link *tail=head;
worker *temp;
while(true)
{
temp=(worker *)malloc(sizeof(worker));
printf("�����빤��������������0����:");
scanf("%s",temp->name);
if(strcmp(temp->name,"0")==0)break;
printf("�����빤������:");
scanf("%d",&(temp->age));
printf("�����빤�˹���:");
scanf("%d",&(temp->salary));
tail->next=(link *)malloc(sizeof(link));
tail=tail->next;
tail->aworker=temp;
tail->next=NULL;
}
return head;
}
void print(link *head)
{
link *temp=head;
printf("����\t����\t����\n");
while(temp->next!=NULL)
{
temp=temp->next;
printf("%s\t%d\t%d\n",temp->aworker->name,temp->aworker->age,temp->aworker->salary);
}
}
int main()
{
print(input());
}
