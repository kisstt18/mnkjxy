#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define ERROR -1
#define OK 1
typedef int ElemType; 
typedef struct{
	ElemType elem[LIST_INIT_SIZE];
	int length;
}SqList;

//线性表的初始化
SqList*init(){
	SqList*L;
	L=(SqList*)malloc(sizeof(SqList));	//分配内存空间
	L->length=0;
	return L; 
} 

//创建线性表
void create(SqList*L){
	int i=0;
	ElemType x;
	do{scanf("%d",&x);
	L->elem[i++]=x;
	L->length++;
	}while(x!=0);
}; 

//求线性表中元素的个数
int length(SqList*L){
	return L->length;
} 

//判断线性表是否为空
int isEmpty(SqList*L){
	return L->length==0; 
} 

//判断线性表是否为满
int isFull(SqList*L){
	return L->length==LIST_INIT_SIZE; 
} 

//在线性表的第i个位置插入一个元素
int ListInsert_Sq(SqList*L,int i,ElemType e){
	int k;
	if(i<1||i>L->length+1)return ERROR;
	if(L->length>=LIST_INIT_SIZE)return ERROR;
	for(k=L->length-1;k>=i-1;--k)
		L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;
	++L->length;
	return OK;
}

//在线性表的第i个位置删除一个元素
int ListDelete_Sq(SqList*L,int i,ElemType*e){
	int k;
	if(i<1||i>L->length)return ERROR;
	*e=L->elem[i-1];
	for(k=i-1;k<L->length;k++)
		L->elem[k]=L->elem[k+1];
	--L->length;
	return OK;
}

//打印输出
void ListPrint_Sq(SqList*L){
	int i;
	for(i=0;i<L->length;i++)
	printf("%4d",L->elem[i]);
	printf("\n");
} 

//查找指定元素的位置
int Locate(SqList*L,ElemType e){
int i=0;
	while((i<=L->length-1)&&(L->elem[i]!=e))i++;
	if(i<=L->length-1)
		return (i+1);
	else
		return(-1); 
} 

/* 主程序：验证顺序表的基本操作 */
int main(){
    SqList *sq;
    ElemType e;
    ElemType *el = (ElemType *)malloc(sizeof(ElemType));
    int k = 0;
    sq = init();
    printf("%d\n", isEmpty(sq));                 /* 初始为空，输出1 */
    printf("请输入若干个元素,以0结束输入:\n");
    create(sq);
    printf("输出结果:");
    ListPrint_Sq(sq);
    printf("\n");
    printf("请输入待插入元素位置k的值:");
    scanf("%d", &k);
    printf("请输入元素e的值:");
    scanf("%d", &e);
    ListInsert_Sq(sq, k,e);
    printf("输出结果:");
    ListPrint_Sq(sq);
    printf("\n请输入删除的元素:");
    scanf("%d", &e);
    k = Locate(sq, e);                           /* 先按值查找位置 */
    if(k == -1)
        printf("\n未找到要删除的元素!\n");
    else
        ListDelete_Sq(sq, k, el);
    printf("输出结果1:\n");
    ListPrint_Sq(sq);
    printf("\n请输入要删除的第k个元素:");
    scanf("%d", &k);
    ListDelete_Sq(sq, k, el);
    printf("当前删除元素el=%d\n", *el);
    printf("输出结果2:\n");
    ListPrint_Sq(sq);
    printf("当前元素的个数为%d个\n", length(sq));
    return 0;
}













