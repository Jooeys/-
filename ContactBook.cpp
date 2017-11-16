 /*通讯录管理系统*/
#include<stdio.h>//标准输入输出头文件 
#include<stdlib.h>//包含最常用的系统函数 
#include<string.h>//关于字符数组的函数定义的头文件
struct Contacts {                            /*结构定义*/
	char name[10];
	char address[30];
	char birthday[10];
	char phonenumber[15];
	char mail[20];
	char zipcode[8];
};
void add(struct Contacts recode[]); //添加通讯录函数 
void search(struct Contacts recode[]);//查询通讯录函数 
void show(struct Contacts recode[]);//显示通讯录函数 
void modify(struct Contacts recode[]);//修改通讯录函数 
void remove(struct Contacts recode[]); // 删除通讯录函数 
void logout(struct Contacts recode[]);//退出通讯录函数 
/*main函数，进行主界面设计，调用各函数*/
int main(void)
{
	int choice,i;
	struct Contacts recode[10];//
	FILE *fp;
	printf("           ☆☆☆☆☆通讯录程序设计 ☆☆☆☆☆        \n");
	printf("              0: 按0进行系统初始化\n");
	printf("              1: 按1开始使用系统!\n");
	printf("              请输入您的选择：");
	scanf("%d",&i);
	if(i==0){
		if((fp=fopen("A:\\C-program\\Project.txt","w+"))==NULL){
			printf("File open error!");
			exit(0);//正常退出	
		}
		if(fclose(fp)){
			printf("can not close the file!");
			exit(0);
		}
	}
	else if(i==1);
	system("pause");
	system("cls");//清屏 
	do{
		printf("                                通讯录管理系统     \n");
		printf("                         |-------------------------|\n");
		printf("                         |   选择[1]:添加通讯记录  |\n");
		printf("                         |   选择[2]:修改通讯记录  |\n");
		printf("                         |   选择[3]:删除通讯记录  |\n");
		printf("                         |   选择[4]:查询通讯记录  |\n");
		printf("                         |   选择[5]:显示通讯记录  |\n");
		printf("                         |   选择[0]:退出通讯记录  |\n");
		printf("                         |-------------------------|\n");
		printf("\n");
		printf(" 请输入您的选择: ");              
		scanf("%d",&choice);
		switch(choice){ 
			case 1:add(recode);	
			   	break;
			case 2:modify(recode);
				break;
			case 3:remove(recode);
				break;
			case 4:search(recode);
			    break;
			case 5:show(recode);
				break;
			case 0:
			    break;
			default:
				printf("\n");
				printf(" 您的选择有误!\n");
				printf("\n");
				break;
		}
	}while(choice!=0&&choice<6);
	printf("\n");
	printf("               谢谢使用!\n");
	printf("  ★★★★天津工业大学荣誉出品★★★★\n");
	printf("        ★★★出品人：钟俊毅★★★\n");
	return 0;
}
/*添加通讯录函数*/
void add(struct Contacts recode[])  
{
	int n,count=0,t,i,m; /*变量n作为是否保存判断，t判断是否继续添加，i循环判断，m记还可添加数目*/
	FILE *fp;
	struct Contacts s,p;      /*定义新结构s保存新输入信息,新结构p保存原来已经保存在文件的信息*/
	if((fp=fopen("A:\\C-program\\Project.txt","a+"))==NULL){
		printf("File open error!");
		exit(0);	
	}
	while(!feof(fp)){                       /*计算文件中已有记录数count*/	
		fscanf(fp,"%s%s%s%s%s%s\n",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
	 	count++;
	}
	printf("                  |*****************开始添加****************|\n");
	printf("        |*******************注意:地址不要超过十个字*******************|         \n");
	for(i=0;i<10;i++){
		printf(" 姓名：");
		scanf("%s",&s.name);
		printf(" 电话手机：");
		scanf("%s",&s.phonenumber);
		printf(" 住址：");
		scanf("%s",&s.address);
		printf(" 生日：");
		scanf("%s",&s.birthday);
		printf(" 邮箱：");
		scanf("%s",&s.mail);
		printf(" 邮编：");
		scanf("%s",&s.zipcode); 
		printf(" 保存记录请按1，否则按其他数字!\n");
		printf(" 输入您的选择：");
		scanf("%d",&n);
		if(n==1){
			fprintf(fp,"%-7s%-12s%-22s%-10s%-20s%-3s\n",s.name,s.phonenumber,s.address,s.birthday,s.mail,s.zipcode);
			printf(" 保存成功!\n");
			count++;
			system("pause");
			system("cls");
		}
		else if(n!=1){
			system("cls");
			break;
		}
		if(count<=10){
			system("cls");      /*一次记录保存后清屏*/
			m=10-count;
			printf(" 您已经输入了%d个记录，还可以输入%d个!\n",count,m);
		}
		else{
			printf(" 您的通讯录已满!\n");
			system("cls");
		}
		printf(" 按0退出添加,按其他数字继续添加!\n");
		scanf("%d",&t);
		if(t==0){
			system("cls");
			break;
		}
	}
	if(fclose(fp)){
		printf("can not cloce the file!");
		exit(0);
	}
}
/*查询通讯录函数*/
void search(struct Contacts recode[])
{
	struct Contacts s,p;         /*定义两个新结构变量，s用来保存要查询的某个项目，p用来保存查询到需输出结构各项目*/
	int flag,a,l;                 /*flag作为判断查询开始，a为判断查询方式，l为判断是否退出查询*/
	FILE *fp;
	if((fp=fopen("A:\\C-program\\Project.txt","r+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	printf(" 按0选择姓名查询，按1选择号码查询!\n");
	printf(" 输入您的选择：");
	scanf("%d",&a);
	if(a==0){                                         /*用姓名查询*/
		printf(" 输入要查询的姓名：");
		scanf("%s",&s.name);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			if(strcmp(s.name,p.name)==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| 姓名       号码           地址            生日            邮箱         邮编 |\n");
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*输出新结构中项目*/
			printf("|-----------------------------------------------------------------------------|\n");
			printf(" 按0退出查询!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
		else{
			printf(" 您的通讯录中没有此记录!\n");
			printf(" 按0退出查询!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
	}
	else if(a==1){                                     /*用号码查询*/
		printf(" 输入要查询的号码：");
		scanf("%s",&s.phonenumber);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			if(strcmp(s.phonenumber,p.phonenumber)==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| 姓名       号码           地址            生日            邮箱         关系 |\n");
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);	/*输出新结构中项目*/
			printf("|-----------------------------------------------------------------------------|\n");
			printf(" 按0退出查询!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
		else{
			printf(" 您的通讯录中没有此记录!\n");
			printf(" 按0退出查询!\n");
			scanf("%d",&l);
				if(l==0)
					system("cls");
		}
	}
	if(fclose(fp)){
			printf("can not cloce the file!");
			exit(0);
	}	
}
/*显示通讯录函数*/
void show(struct Contacts recode[])
{
	struct Contacts p;              /*定义新结构变量保存要显示的信息*/
	int l,i,j,n=0,m;
	FILE *fp;
	if((fp=fopen("A:\\C-program\\Project.txt","r+"))==NULL){
		printf("File open error!");
		exit(0);//正常退出 
	}
	for(j=0;j<10;j++){
		if(feof(fp))
			break;
		fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode); /*将数据保存在新结构变量中*/
		n++;
	}
	if(n==1){
		printf(" ###################################\n");
		printf(" ###   您还没有添加任何联系人!   ###\n");
		printf(" ###################################\n");
	}
	else{
		m=ftell(fp);                      /*用while（！feof（fp））直接循环会是最后一条信息显示两次，此处解决此问题*/
		fseek(fp,-m,1);                 /*将文件指针移向开头*/
		printf(" ##################################\n");
		printf(" ###   您总共有以下%d个联系人!   ###\n",n-1);
		printf(" ##################################\n");
		printf("|-----------------------------------------------------------------------------|\n");
		printf("|                 ***************通讯录**************                         |\n");
		printf("|-----------------------------------------------------------------------------|\n");
		printf("| 姓名       号码           地址            生日            邮箱         邮编 |\n");
		printf("|-----------------------------------------------------------------------------|\n");
		for(j=0;j<n-1;j++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*输出新结构中项目*/
			printf("|-----------------------------------------------------------------------------|\n");
		}
	}
		printf(" 按0退出查看!\n");
		scanf("%d",&l);
		if(l==0)
			system("cls");
	if(fclose(fp)){
		printf("can not cloce the file!");
		exit(0);
	}
}
/*修改通讯录函数*/
void modify(struct Contacts recode[])
{
	FILE *fp,*fpz;
	struct Contacts s,p,m,z;         /*定义两个新结构变量，s用来保存要查询的某个项目，p用来保存查询到需输出结构各项目*/
	int flag,a,l,choice,n,d=0,i,x=0; /*flag作为判断查询开始，a为判断查询方式，l为判断是否退出查询,choice作为判断C-program\\项目，d记录原有文件数，i循环判断*/                   
	if((fp=fopen("A:\\C-program\\Project.txt","a+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	if((fpz=fopen("A:\\recode.txt","w+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	printf(" 按0选择姓名查询修改，按1选择号码查询修改!\n");
	printf(" 输入您的选择：");
	scanf("%d",&a);
	if(a==0){                                         /*用姓名查询修改*/
		printf(" 输入要修改记录的姓名：");
		scanf("%s",&s.name);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			x++;
		}
		fseek(fp,0L,0);               /*将文件指针定向开头*/
		for(i=0;i<x-1;i++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			n=ftell(fp);
			if(strcmp(s.name,p.name)!=0)
				fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
			if(strcmp(s.name,p.name)==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*输出新结构中项目*/
			printf("|-----------------------------------------------------------------------------|\n");
			m=p;
			fseek(fp,n,0);
			while(!feof(fp)){
				fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
				d++;
			}                
			fseek(fp,n,0);        /*用while（！feof（fp））直接循环会是最后一条信息保存两次，此处解决此问题*/
			for(i=0;i<d-1;i++){
				fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
				fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
			}
			printf(" 是否要修改这条记录？\n");
			printf(" 确认请按1,退出请按0!\n");
			printf(" 输入您的选择：");
			scanf("%d",&l);
			system("cls");
			if(l==1){
				printf("|--------------------|\n");
				printf("|      修改项目      |\n");
				printf("|--------------------|\n");
				printf("| choice[1]:修改姓名 |\n");
				printf("| choice[2]:修改号码 |\n");
				printf("| choice[3]:修改地址 |\n");
				printf("| choice[4]:修改生日 |\n");
				printf("| choice[5]:修改邮箱 |\n");
				printf("| choice[6]:修改邮编 |\n");
				printf("|--------------------|\n");
				printf("输入您的选择：");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("%s ",m.name);
						printf("改成：");
						scanf("%s",&m.name);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 2:
						printf("%s ",m.phonenumber);
						printf("改成：");
						scanf("%s",&m.phonenumber);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 3:
						printf("%s ",m.address);
						printf("改成：");
						scanf("%s",&m.address);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 4:
						printf("%s ",m.birthday);
						printf("改成：");
						scanf("%s",&m.birthday);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 5:
						printf("%s ",m.mail);
						printf("改成：");
						scanf("%s",&m.mail);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 6:
						printf("%s ",m.zipcode);
						printf("改成：");
						scanf("%s",&m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					default:
						break;
				}
			}
			else if(l==0)
				system("cls");
		}
		else{
			printf(" 您的通讯录中没有此记录!\n");
			printf(" 按0退出修改!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
	}
	else if(a==1){                                     /*用号码查询修改*/
		printf(" 输入要修改记录的号码：");
		scanf("%s",&s.phonenumber);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			x++;
		}
		fseek(fp,0L,0);
		for(i=0;i<x-1;i++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			n=ftell(fp);
			if(strcmp(s.phonenumber,p.phonenumber)!=0)
				fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
			if(strcmp(s.phonenumber,p.phonenumber)==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*输出新结构中项目*/
			printf("|-----------------------------------------------------------------------------|\n");
			m=p;
			fseek(fp,n,0);
			while(!feof(fp)){
				fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
				d++;
			}             
			fseek(fp,n,0);   /*用while（！feof（fp））直接循环会是最后一条信息保存两次，此处解决此问题*/
			for(i=0;i<d-1;i++){
				fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
				fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
			}
			printf(" 是否要修改这条记录？\n");
			printf(" 确认请按1，退出请按0!\n");
			printf(" 输入您的选择：");
			scanf("%d",&l);
			system("cls"); 
			if(l==1){
				printf("|--------------------|\n");
				printf("|      修改项目      |\n");
				printf("|--------------------|\n");
				printf("|  选择[1]:修改姓名  |\n");
				printf("|  选择[2]:修改号码  |\n");
				printf("|  选择[3]:修改地址  |\n");
				printf("|  选择[4]:修改生日  |\n");
				printf("|  选择[5]:修改邮箱  |\n");
				printf("|  选择[6]:修改邮编  |\n");
				printf("|--------------------|\n");
				printf(" 输入您的选择：");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("%s ",m.name);
						printf("改成：");
						scanf("%s",&m.name);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 2:
						printf("%s ",m.phonenumber);
						printf("改成：");
						scanf("%s",&m.phonenumber);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 3:
						printf("%s ",m.address);
						printf("改成：");
						scanf("%s",&m.address);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 4:
						printf("%s ",m.birthday);
						printf("改成：");
						scanf("%s",&m.birthday);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 5:
						printf("%s ",m.mail);
						printf("改成：");
						scanf("%s",&m.mail);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,z.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					case 6:
						printf("%s ",m.zipcode);
						printf("改成：");
						scanf("%s",&m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" 修改成功!\n");
						system("pause");
						system("cls");
						break;
					default:
						break;
				}
			}
			else if(l==0)
				system("cls");
		}
		else{
			printf(" 您的通讯录中没有此记录!\n");
			printf(" 按0退出修改!\n");
			scanf("%d",&l);
				if(l==0)
					system("cls");
		}
	}
	if(fclose(fp)){
		printf("can not cloce the file!");
		exit(0);
	}
	if(fclose(fpz)){
		printf("can not cloce the file!");
		exit(0);
	}
	logout(recode);
}
/*删除通讯录函数*/
void remove(struct Contacts recode[])
{
	struct Contacts s,p;         /*定义两个新结构变量，s用来保存要查询的某个项目，p用来保存查询到需输出结构各项目*/
	int flag,a,l,n,i,m=0,q,x=0;                 /*flag作为判断查询开始，a为判断查询方式，l为判断是否退出查询，n是fteel返回值 */
	FILE *fp,*fpz;
	if((fp=fopen("A:\\C-program\\Project.txt","a+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	if((fpz=fopen("A:\\recode.txt","w+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	printf(" 按0选择姓名查询删除，按1选择号码查询删除!\n");
	printf(" 输入您的选择：");
	scanf("%d",&a);
	if(a==0){                                         /*用姓名查询删除*/
		printf(" 输入要删除的记录姓名：");
		scanf("%s",&s.name);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			x++;
		}
		fseek(fp,0L,0);
		for(i=0;i<x-1;i++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			n=ftell(fp);
			if(strcmp(s.name,p.name)!=0)
				fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
			if(strcmp(s.name,p.name)==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*输出新结构中项目*/
			printf("|-----------------------------------------------------------------------------|\n");
			printf(" 是否要删除这条记录!\n");
			printf(" 确认按1，退出按0\n");
			printf(" 输入您的选择：");
			scanf("%d",&l);
			if(l==1){
				fseek(fp,n,0);
				while(!feof(fp)){
					fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
                    m++;
				}
				fseek(fp,n,0);
				for(i=0;i<m-1;i++){
					fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
					fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
				}
				printf(" 删除成功!\n");
				system("pause");
				system("cls");
			}
			 if(l==0)
				system("cls");
		}
		else{
			printf(" 您的通讯录中没有此记录!\n");
			printf(" 按0退出删除!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
	}
	else if(a==1){                                     /*用号码查询删除*/
		printf(" 输入要删除的记录号码：");
		scanf("%s",&s.phonenumber);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			x++;
		}
		fseek(fp,0L,0);
		for(i=0;i<x-1;i++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*将数据保存在新结构变量中*/
			n=ftell(fp);
			if(strcmp(s.phonenumber,p.phonenumber)!=0)
				fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
			if(strcmp(s.phonenumber,p.phonenumber)==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);	/*输出新结构中项目*/
			printf("|-----------------------------------------------------------------------------|\n");
			printf(" 是否要删除这条记录!\n");
			printf(" 按1确认，按0退出!\n");
			printf(" 输入您的选择：");
			scanf("%d",&l);
			if(l==1){
				fseek(fp,n,0);
				while(!feof(fp)){
					fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
                    m++;
				}
				fseek(fp,n,0);
				for(i=0;i<m-1;i++){
					fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
					fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
				}
				printf(" 删除成功!\n");
				system("pause");
				system("cls");
			}
			if(l==0)
				system("cls");
		}
		else{
			printf(" 您的通讯录中没有此记录!\n");
			printf(" 按0退出删除!\n");
			scanf("%d",&l);
				if(l==0)
					system("cls");
		}
	}
	if(fclose(fp)){
		printf("can not cloce the file!");
		exit(0);
	}
	if(fclose(fpz)){
		printf("can not cloce the file!");
		exit(0);
	}
	
	logout(recode);
}
/*删除源文件后又新建写入源文件*/
void logout(struct Contacts recode[])
{
	int i,n=0;
	struct Contacts p;
	FILE *fp,*fpz;
	if((fp=fopen("A:\\C-program\\Project.txt","w"))==NULL){
		printf("File open error!");
		exit(0);
	}
	if((fpz=fopen("A:\\recode.txt","r"))==NULL){
		printf("File open error!");
		exit(0);
	}
	while(!feof(fpz)){
		fscanf(fpz,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
		n++;
	}
	fseek(fpz,0L,0);
	for(i=0;i<n-1;i++){
		fscanf(fpz,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
		fprintf(fp,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
	}
	if(fclose(fp)){
		printf("can not cloce the file!");
		exit(0);
	}
	if(fclose(fpz)){
		printf("can not cloce the file!");
		exit(0);
	}	
}

