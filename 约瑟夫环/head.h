//�����������Ҫ�ĺ�
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LISTINCREMENT 10

//����������õ����������ͱ��
typedef  int Status ;
typedef int ElemType ;

//���嵥�����н��Ľṹ
struct LNode{
	ElemType data;
	struct LNode * next;
};

//�Խ�㼰���ָ�����ͽ����ض��壬Ŀ������ǿ����ɶ���
typedef struct LNode LNode;
typedef LNode* LinkList;

typedef LinkList JoseList;

Status createJoseList(JoseList &L, int n);
Status printJose(JoseList L, int n, int m);

