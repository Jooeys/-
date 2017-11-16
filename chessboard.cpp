#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10000
int board[N][N];//���̵Ĳ���
int team;//�÷��鸲�ǣ��൱�ڷ���
int loc;//key(x,y)�ķ�λ������ֵΪ1��2��3��4�ֱ�ָ1��2��3��4���ޣ�
int witk(int m,int x,int y,int a,int b){//where is the key(x,y)?  mΪ���̵ı߳���x��yΪ�ڵ�����꣬a��bΪ�������Ͻǵ����꣬
    int n;
    n=m/2;
    if(x<n+a&&y>=n+b)
        return 1;
    else if(x<n+a&&y<n+b)
        return 2;
    else if(x>=n+a&&y<n+b)
        return 3;
    else if(x>=n+a&&y>=n+b)
        return 4;
}
void cover(int m,int a,int b){
    int i;
    int j;
    int x,y;
    int n;
    if(m==2){//��m==2��ֱ�Ӹ���
        for(i=a;i<m+a;i++)
            for(j=b;j<m+b;j++)
                if(board[i][j]==-1)
                    board[i][j]=team;
        team++;
    }
    else{//m>2
        for(i=a;i<m+a;i++){//�ҳ��ڵ��λ��x��y
            for(j=b;j<m+b;j++)
                if(board[i][j]!=-1){
                    x=i;
                    y=j;
                }
        }
        n=m/2;
        loc=witk(m,x,y,a,b);//where is the key(x,y)?
        for(i=a+n-1;i<=a+n;i++)//���������в��ĸ����ж��䷽λ�������ͺڵ���ͬһ����λ���串�ǣ�
            for(j=b+n-1;j<=b+n;j++)
                if(witk(m,i,j,a,b)!=loc)
                    board[i][j]=team;
        team++;
        cover(n,a,b);//�����ĸ������򣬵ݹ����
        cover(n,a,b+n);
        cover(n,a+n,b);
        cover(n,a+n,b+n);
    }
}
int main(){
    int i,j,k;
    int n,m;
    int x,y;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        team=1;
        memset(board,-1,sizeof(board));//������ȫ����Ϊ-1
        scanf("%d%d%d",&m,&x,&y);
        board[x+1][y+1]=0;
        cover(m,1,1);
        printf("CASE:%d\n",i+1);
        for(j=1;j<=m;j++){
            for(k=1;k<=m;k++)
                printf("%-3d",board[j][k]);
            printf("\n");
        }
    }
    return 0;
}
