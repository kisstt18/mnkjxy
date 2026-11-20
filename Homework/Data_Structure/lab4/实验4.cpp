#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}SqQueue;

/* 初始化队列 */
void InitQueue(SqQueue*Sq){ Sq->rear=Sq->front=0; }

/* 判队列空 */
int EmptyQueue(SqQueue*Sq){ return(Sq->rear==Sq->front)?1:0; }

/* 判队列满（牺牲一个单元区分空/满） */
int FullQueue(SqQueue*Sq){ return((Sq->rear+1)%MAXSIZE==Sq->front)?1:0; }

/* 入队 */
int InsertQueue(SqQueue*Sq,ElemType x){
    if(FullQueue(Sq)){ printf("\n队列已满!"); return 0; }
    else{
        Sq->data[Sq->rear]=x;
        Sq->rear=(Sq->rear+1)%MAXSIZE;
        return 1;
    }
}

/* 出队 */
int DelQueue(SqQueue*Sq,ElemType *y){
    if(EmptyQueue(Sq)){ printf("\n队列已空!"); return 0; }
    else{
        *y=Sq->data[Sq->front];
        Sq->front=(Sq->front+1)%MAXSIZE;
        return 1;
    }
}

int main(){
    SqQueue*Sq=(SqQueue*)malloc(sizeof(SqQueue));
    ElemType*y=(ElemType*)malloc(sizeof(ElemType));
    int i,n;
    InitQueue(Sq);
    printf("请输入排队人数:");
    scanf("%d",&n);
    printf("依次取号入队:");
    for(i=1;i<=n;i++){ printf(" %d",i); InsertQueue(Sq,i); }
    printf("\n叫号出队顺序(FIFO):");
    while(!EmptyQueue(Sq)){ DelQueue(Sq,y); printf(" %d",*y); }
    printf("\n");
    return 0;
}

