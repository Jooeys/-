 /*ͨѶ¼����ϵͳ*/
#include<stdio.h>//��׼�������ͷ�ļ� 
#include<stdlib.h>//������õ�ϵͳ���� 
#include<string.h>//�����ַ�����ĺ��������ͷ�ļ�
struct Contacts {                            /*�ṹ����*/
	char name[10];
	char address[30];
	char birthday[10];
	char phonenumber[15];
	char mail[20];
	char zipcode[8];
};
void add(struct Contacts recode[]); //���ͨѶ¼���� 
void search(struct Contacts recode[]);//��ѯͨѶ¼���� 
void show(struct Contacts recode[]);//��ʾͨѶ¼���� 
void modify(struct Contacts recode[]);//�޸�ͨѶ¼���� 
void remove(struct Contacts recode[]); // ɾ��ͨѶ¼���� 
void logout(struct Contacts recode[]);//�˳�ͨѶ¼���� 
/*main������������������ƣ����ø�����*/
int main(void)
{
	int choice,i;
	struct Contacts recode[10];//
	FILE *fp;
	printf("           ������ͨѶ¼������� ������        \n");
	printf("              0: ��0����ϵͳ��ʼ��\n");
	printf("              1: ��1��ʼʹ��ϵͳ!\n");
	printf("              ����������ѡ��");
	scanf("%d",&i);
	if(i==0){
		if((fp=fopen("A:\\C-program\\Project.txt","w+"))==NULL){
			printf("File open error!");
			exit(0);//�����˳�	
		}
		if(fclose(fp)){
			printf("can not close the file!");
			exit(0);
		}
	}
	else if(i==1);
	system("pause");
	system("cls");//���� 
	do{
		printf("                                ͨѶ¼����ϵͳ     \n");
		printf("                         |-------------------------|\n");
		printf("                         |   ѡ��[1]:���ͨѶ��¼  |\n");
		printf("                         |   ѡ��[2]:�޸�ͨѶ��¼  |\n");
		printf("                         |   ѡ��[3]:ɾ��ͨѶ��¼  |\n");
		printf("                         |   ѡ��[4]:��ѯͨѶ��¼  |\n");
		printf("                         |   ѡ��[5]:��ʾͨѶ��¼  |\n");
		printf("                         |   ѡ��[0]:�˳�ͨѶ��¼  |\n");
		printf("                         |-------------------------|\n");
		printf("\n");
		printf(" ����������ѡ��: ");              
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
				printf(" ����ѡ������!\n");
				printf("\n");
				break;
		}
	}while(choice!=0&&choice<6);
	printf("\n");
	printf("               ллʹ��!\n");
	printf("  ��������ҵ��ѧ������Ʒ�����\n");
	printf("        �����Ʒ�ˣ��ӿ������\n");
	return 0;
}
/*���ͨѶ¼����*/
void add(struct Contacts recode[])  
{
	int n,count=0,t,i,m; /*����n��Ϊ�Ƿ񱣴��жϣ�t�ж��Ƿ������ӣ�iѭ���жϣ�m�ǻ��������Ŀ*/
	FILE *fp;
	struct Contacts s,p;      /*�����½ṹs������������Ϣ,�½ṹp����ԭ���Ѿ��������ļ�����Ϣ*/
	if((fp=fopen("A:\\C-program\\Project.txt","a+"))==NULL){
		printf("File open error!");
		exit(0);	
	}
	while(!feof(fp)){                       /*�����ļ������м�¼��count*/	
		fscanf(fp,"%s%s%s%s%s%s\n",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
	 	count++;
	}
	printf("                  |*****************��ʼ���****************|\n");
	printf("        |*******************ע��:��ַ��Ҫ����ʮ����*******************|         \n");
	for(i=0;i<10;i++){
		printf(" ������");
		scanf("%s",&s.name);
		printf(" �绰�ֻ���");
		scanf("%s",&s.phonenumber);
		printf(" סַ��");
		scanf("%s",&s.address);
		printf(" ���գ�");
		scanf("%s",&s.birthday);
		printf(" ���䣺");
		scanf("%s",&s.mail);
		printf(" �ʱࣺ");
		scanf("%s",&s.zipcode); 
		printf(" �����¼�밴1��������������!\n");
		printf(" ��������ѡ��");
		scanf("%d",&n);
		if(n==1){
			fprintf(fp,"%-7s%-12s%-22s%-10s%-20s%-3s\n",s.name,s.phonenumber,s.address,s.birthday,s.mail,s.zipcode);
			printf(" ����ɹ�!\n");
			count++;
			system("pause");
			system("cls");
		}
		else if(n!=1){
			system("cls");
			break;
		}
		if(count<=10){
			system("cls");      /*һ�μ�¼���������*/
			m=10-count;
			printf(" ���Ѿ�������%d����¼������������%d��!\n",count,m);
		}
		else{
			printf(" ����ͨѶ¼����!\n");
			system("cls");
		}
		printf(" ��0�˳����,���������ּ������!\n");
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
/*��ѯͨѶ¼����*/
void search(struct Contacts recode[])
{
	struct Contacts s,p;         /*���������½ṹ������s��������Ҫ��ѯ��ĳ����Ŀ��p���������ѯ��������ṹ����Ŀ*/
	int flag,a,l;                 /*flag��Ϊ�жϲ�ѯ��ʼ��aΪ�жϲ�ѯ��ʽ��lΪ�ж��Ƿ��˳���ѯ*/
	FILE *fp;
	if((fp=fopen("A:\\C-program\\Project.txt","r+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	printf(" ��0ѡ��������ѯ����1ѡ������ѯ!\n");
	printf(" ��������ѡ��");
	scanf("%d",&a);
	if(a==0){                                         /*��������ѯ*/
		printf(" ����Ҫ��ѯ��������");
		scanf("%s",&s.name);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
			if(strcmp(s.name,p.name)==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| ����       ����           ��ַ            ����            ����         �ʱ� |\n");
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*����½ṹ����Ŀ*/
			printf("|-----------------------------------------------------------------------------|\n");
			printf(" ��0�˳���ѯ!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
		else{
			printf(" ����ͨѶ¼��û�д˼�¼!\n");
			printf(" ��0�˳���ѯ!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
	}
	else if(a==1){                                     /*�ú����ѯ*/
		printf(" ����Ҫ��ѯ�ĺ��룺");
		scanf("%s",&s.phonenumber);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
			if(strcmp(s.phonenumber,p.phonenumber)==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| ����       ����           ��ַ            ����            ����         ��ϵ |\n");
			printf("|-----------------------------------------------------------------------------|\n");
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);	/*����½ṹ����Ŀ*/
			printf("|-----------------------------------------------------------------------------|\n");
			printf(" ��0�˳���ѯ!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
		else{
			printf(" ����ͨѶ¼��û�д˼�¼!\n");
			printf(" ��0�˳���ѯ!\n");
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
/*��ʾͨѶ¼����*/
void show(struct Contacts recode[])
{
	struct Contacts p;              /*�����½ṹ��������Ҫ��ʾ����Ϣ*/
	int l,i,j,n=0,m;
	FILE *fp;
	if((fp=fopen("A:\\C-program\\Project.txt","r+"))==NULL){
		printf("File open error!");
		exit(0);//�����˳� 
	}
	for(j=0;j<10;j++){
		if(feof(fp))
			break;
		fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode); /*�����ݱ������½ṹ������*/
		n++;
	}
	if(n==1){
		printf(" ###################################\n");
		printf(" ###   ����û������κ���ϵ��!   ###\n");
		printf(" ###################################\n");
	}
	else{
		m=ftell(fp);                      /*��while����feof��fp����ֱ��ѭ���������һ����Ϣ��ʾ���Σ��˴����������*/
		fseek(fp,-m,1);                 /*���ļ�ָ������ͷ*/
		printf(" ##################################\n");
		printf(" ###   ���ܹ�������%d����ϵ��!   ###\n",n-1);
		printf(" ##################################\n");
		printf("|-----------------------------------------------------------------------------|\n");
		printf("|                 ***************ͨѶ¼**************                         |\n");
		printf("|-----------------------------------------------------------------------------|\n");
		printf("| ����       ����           ��ַ            ����            ����         �ʱ� |\n");
		printf("|-----------------------------------------------------------------------------|\n");
		for(j=0;j<n-1;j++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*����½ṹ����Ŀ*/
			printf("|-----------------------------------------------------------------------------|\n");
		}
	}
		printf(" ��0�˳��鿴!\n");
		scanf("%d",&l);
		if(l==0)
			system("cls");
	if(fclose(fp)){
		printf("can not cloce the file!");
		exit(0);
	}
}
/*�޸�ͨѶ¼����*/
void modify(struct Contacts recode[])
{
	FILE *fp,*fpz;
	struct Contacts s,p,m,z;         /*���������½ṹ������s��������Ҫ��ѯ��ĳ����Ŀ��p���������ѯ��������ṹ����Ŀ*/
	int flag,a,l,choice,n,d=0,i,x=0; /*flag��Ϊ�жϲ�ѯ��ʼ��aΪ�жϲ�ѯ��ʽ��lΪ�ж��Ƿ��˳���ѯ,choice��Ϊ�ж�C-program\\��Ŀ��d��¼ԭ���ļ�����iѭ���ж�*/                   
	if((fp=fopen("A:\\C-program\\Project.txt","a+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	if((fpz=fopen("A:\\recode.txt","w+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	printf(" ��0ѡ��������ѯ�޸ģ���1ѡ������ѯ�޸�!\n");
	printf(" ��������ѡ��");
	scanf("%d",&a);
	if(a==0){                                         /*��������ѯ�޸�*/
		printf(" ����Ҫ�޸ļ�¼��������");
		scanf("%s",&s.name);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
			x++;
		}
		fseek(fp,0L,0);               /*���ļ�ָ�붨��ͷ*/
		for(i=0;i<x-1;i++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
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
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*����½ṹ����Ŀ*/
			printf("|-----------------------------------------------------------------------------|\n");
			m=p;
			fseek(fp,n,0);
			while(!feof(fp)){
				fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
				d++;
			}                
			fseek(fp,n,0);        /*��while����feof��fp����ֱ��ѭ���������һ����Ϣ�������Σ��˴����������*/
			for(i=0;i<d-1;i++){
				fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
				fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
			}
			printf(" �Ƿ�Ҫ�޸�������¼��\n");
			printf(" ȷ���밴1,�˳��밴0!\n");
			printf(" ��������ѡ��");
			scanf("%d",&l);
			system("cls");
			if(l==1){
				printf("|--------------------|\n");
				printf("|      �޸���Ŀ      |\n");
				printf("|--------------------|\n");
				printf("| choice[1]:�޸����� |\n");
				printf("| choice[2]:�޸ĺ��� |\n");
				printf("| choice[3]:�޸ĵ�ַ |\n");
				printf("| choice[4]:�޸����� |\n");
				printf("| choice[5]:�޸����� |\n");
				printf("| choice[6]:�޸��ʱ� |\n");
				printf("|--------------------|\n");
				printf("��������ѡ��");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("%s ",m.name);
						printf("�ĳɣ�");
						scanf("%s",&m.name);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 2:
						printf("%s ",m.phonenumber);
						printf("�ĳɣ�");
						scanf("%s",&m.phonenumber);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 3:
						printf("%s ",m.address);
						printf("�ĳɣ�");
						scanf("%s",&m.address);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 4:
						printf("%s ",m.birthday);
						printf("�ĳɣ�");
						scanf("%s",&m.birthday);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 5:
						printf("%s ",m.mail);
						printf("�ĳɣ�");
						scanf("%s",&m.mail);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 6:
						printf("%s ",m.zipcode);
						printf("�ĳɣ�");
						scanf("%s",&m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
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
			printf(" ����ͨѶ¼��û�д˼�¼!\n");
			printf(" ��0�˳��޸�!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
	}
	else if(a==1){                                     /*�ú����ѯ�޸�*/
		printf(" ����Ҫ�޸ļ�¼�ĺ��룺");
		scanf("%s",&s.phonenumber);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
			x++;
		}
		fseek(fp,0L,0);
		for(i=0;i<x-1;i++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
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
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*����½ṹ����Ŀ*/
			printf("|-----------------------------------------------------------------------------|\n");
			m=p;
			fseek(fp,n,0);
			while(!feof(fp)){
				fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
				d++;
			}             
			fseek(fp,n,0);   /*��while����feof��fp����ֱ��ѭ���������һ����Ϣ�������Σ��˴����������*/
			for(i=0;i<d-1;i++){
				fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);
				fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);
			}
			printf(" �Ƿ�Ҫ�޸�������¼��\n");
			printf(" ȷ���밴1���˳��밴0!\n");
			printf(" ��������ѡ��");
			scanf("%d",&l);
			system("cls"); 
			if(l==1){
				printf("|--------------------|\n");
				printf("|      �޸���Ŀ      |\n");
				printf("|--------------------|\n");
				printf("|  ѡ��[1]:�޸�����  |\n");
				printf("|  ѡ��[2]:�޸ĺ���  |\n");
				printf("|  ѡ��[3]:�޸ĵ�ַ  |\n");
				printf("|  ѡ��[4]:�޸�����  |\n");
				printf("|  ѡ��[5]:�޸�����  |\n");
				printf("|  ѡ��[6]:�޸��ʱ�  |\n");
				printf("|--------------------|\n");
				printf(" ��������ѡ��");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("%s ",m.name);
						printf("�ĳɣ�");
						scanf("%s",&m.name);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 2:
						printf("%s ",m.phonenumber);
						printf("�ĳɣ�");
						scanf("%s",&m.phonenumber);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 3:
						printf("%s ",m.address);
						printf("�ĳɣ�");
						scanf("%s",&m.address);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 4:
						printf("%s ",m.birthday);
						printf("�ĳɣ�");
						scanf("%s",&m.birthday);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 5:
						printf("%s ",m.mail);
						printf("�ĳɣ�");
						scanf("%s",&m.mail);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,z.zipcode);
						printf(" �޸ĳɹ�!\n");
						system("pause");
						system("cls");
						break;
					case 6:
						printf("%s ",m.zipcode);
						printf("�ĳɣ�");
						scanf("%s",&m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf("|-----------------------------------------------------------------------------|\n");
						fprintf(fpz,"%-7s%-12s%-22s%-10s%-20s%-3s\n",m.name,m.phonenumber,m.address,m.birthday,m.mail,m.zipcode);
						printf(" �޸ĳɹ�!\n");
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
			printf(" ����ͨѶ¼��û�д˼�¼!\n");
			printf(" ��0�˳��޸�!\n");
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
/*ɾ��ͨѶ¼����*/
void remove(struct Contacts recode[])
{
	struct Contacts s,p;         /*���������½ṹ������s��������Ҫ��ѯ��ĳ����Ŀ��p���������ѯ��������ṹ����Ŀ*/
	int flag,a,l,n,i,m=0,q,x=0;                 /*flag��Ϊ�жϲ�ѯ��ʼ��aΪ�жϲ�ѯ��ʽ��lΪ�ж��Ƿ��˳���ѯ��n��fteel����ֵ */
	FILE *fp,*fpz;
	if((fp=fopen("A:\\C-program\\Project.txt","a+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	if((fpz=fopen("A:\\recode.txt","w+"))==NULL){
		printf("File open error!");
		exit(0);
	}
	printf(" ��0ѡ��������ѯɾ������1ѡ������ѯɾ��!\n");
	printf(" ��������ѡ��");
	scanf("%d",&a);
	if(a==0){                                         /*��������ѯɾ��*/
		printf(" ����Ҫɾ���ļ�¼������");
		scanf("%s",&s.name);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
			x++;
		}
		fseek(fp,0L,0);
		for(i=0;i<x-1;i++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
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
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);/*����½ṹ����Ŀ*/
			printf("|-----------------------------------------------------------------------------|\n");
			printf(" �Ƿ�Ҫɾ��������¼!\n");
			printf(" ȷ�ϰ�1���˳���0\n");
			printf(" ��������ѡ��");
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
				printf(" ɾ���ɹ�!\n");
				system("pause");
				system("cls");
			}
			 if(l==0)
				system("cls");
		}
		else{
			printf(" ����ͨѶ¼��û�д˼�¼!\n");
			printf(" ��0�˳�ɾ��!\n");
			scanf("%d",&l);
			if(l==0)
				system("cls");
		}
	}
	else if(a==1){                                     /*�ú����ѯɾ��*/
		printf(" ����Ҫɾ���ļ�¼���룺");
		scanf("%s",&s.phonenumber);
		while(!feof(fp)){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
			x++;
		}
		fseek(fp,0L,0);
		for(i=0;i<x-1;i++){
			fscanf(fp,"%s%s%s%s%s%s",&p.name,&p.phonenumber,&p.address,&p.birthday,&p.mail,&p.zipcode);/*�����ݱ������½ṹ������*/
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
			printf("| %-7s%-12s%-22s%-10s%-20s%-3s |\n",p.name,p.phonenumber,p.address,p.birthday,p.mail,p.zipcode);	/*����½ṹ����Ŀ*/
			printf("|-----------------------------------------------------------------------------|\n");
			printf(" �Ƿ�Ҫɾ��������¼!\n");
			printf(" ��1ȷ�ϣ���0�˳�!\n");
			printf(" ��������ѡ��");
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
				printf(" ɾ���ɹ�!\n");
				system("pause");
				system("cls");
			}
			if(l==0)
				system("cls");
		}
		else{
			printf(" ����ͨѶ¼��û�д˼�¼!\n");
			printf(" ��0�˳�ɾ��!\n");
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
/*ɾ��Դ�ļ������½�д��Դ�ļ�*/
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

