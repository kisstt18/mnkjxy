#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 6
#define N 5
typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE];
	int front,rear;
}SqQueue;

//初始化队列
void InitQueue(SqQueue*Sq){
	Sq->rear=Sq->front=0;
} 
//判断队列是否为困难
int EmptyQueue(SqQueue*Sq){
	return(Sq->rear==Sq->front)?1:0;
} 
//判断队列是否已满（牺牲一个单元）
int FullQueue(SqQueue*Sq){
	return((Sq->rear+1)%MAXSIZE==Sq->front)?1:0;
} 
//入队
int InsertQueue(SqQueue*Sq,ElemType x){
	if(FullQueue(Sq)){
		printf("\n队列已满！");
		return 0;
	}
	else{
		Sq->data[Sq->rear]=x;
		Sq->rear=(Sq->rear+1)%MAXSIZE;
		return 1;
	}
} 
//出队 
int DelseqQueue(SqQueue*Sq,ElemType*y){
	if(EmptyQueue(Sq)){
		printf("队列为空");
		return 0;
	}
	else{
		*y=Sq->data[Sq->front];
		Sq->front=(Sq->front+1)%MAXSIZE;
		return 1;
	}
} 
//取队首元素
ElemType getFront(SqQueue*Sq){
	return Sq->data[Sq->front];
} 
//取队尾元素
ElemType getRear(SqQueue*Sq){
	return Sq->data[(Sq->rear-1+MAXSIZE)%MAXSIZE];
} 
//求队列长度
int length(SqQueue*Sq){
	return(Sq->rear-Sq->front+MAXSIZE)%MAXSIZE;
} 
//输出队列元素（队首->队尾）
void PrintQueue(SqQueue*Sq){
	int i,k;
	if(EmptyQueue(Sq)){
		printf("队列为空！\n");
		return;
	}
	printf("队列元素（队首->队尾）:");
	for(i=Sq->front,k=0;k<length(Sq);k++,i=(i+1)%MAXSIZE)
		printf(" %d",Sq->data[i]);
	printf("\n");
} 
int main(){
	SqQueue*Sq;
	ElemType*y,x;
	int i;
	Sq=(SqQueue*)malloc(sizeof(SqQueue));
	y=(ElemType*)malloc(sizeof(ElemType));
	InitQueue(Sq);
	printf("请输入%d个整数：",N);
	for(i=0;i<N;i++){
		scanf("%d",&x);
		InsertQueue(Sq,x);
	}
	printf("leng=%3d\n",length(Sq));
	printf("队首元素为：%2d\n",getFront(Sq));
	printf("队尾元素为：%2d\n",getRear(Sq));
	PrintQueue(Sq);
	printf("请输入一个元素：\n");
	scanf("%d",&x);
	InsertQueue(Sq,x);
	DelseqQueue(Sq,y);
	printf("出队元素：%2d\n",*y);
	printf("请输入一个元素:\n");
	scanf("%d",&x);
	InsertQueue(Sq,x);
	PrintQueue(Sq);
	putchar('\n');
	return 0; 
}













