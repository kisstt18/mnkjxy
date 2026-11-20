#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
    int len;
} LQueue;

// 初始化队列（带头结点）
void InitQueue(LQueue *Lq) {
    QNode *p;
    p = (QNode*)malloc(sizeof(QNode));
    p->next = NULL;
    Lq->front = Lq->rear = p;
    Lq->len = 0;
}

// 判断队列是否为空
int QueueEmpty(LQueue *Lq) {
    return (Lq->front == Lq->rear) ? 1 : 0;
}

// 入队（队尾插入）
void EnQueue_L(LQueue *Lq, ElemType x) {
    QNode *p;
    p = (QNode*)malloc(sizeof(QNode));
    p->data = x;
    p->next = NULL;
    Lq->rear->next = p;
    Lq->rear = p;
    Lq->len++;
}

// 出队（队头删除）
int DelQueue_L(LQueue *Lq, ElemType *y) {
    QNode *p;
    if (Lq->front == Lq->rear) { 
        printf("队列为空，无法出队!\n"); 
        return 0; 
    }
    p = Lq->front->next;
    *y = p->data;
    Lq->front->next = p->next;
    if (Lq->rear == p) Lq->rear = Lq->front;
    free(p);
    Lq->len--;
    return 1;
}

// 取队首元素
ElemType getFront(LQueue *Lq) {
    return Lq->front->next->data;
}

// 求队列长度
int length(LQueue *Lq) {
    return(Lq->len);
}

// 输出队列元素
void PrintQueue(LQueue *Lq) {
    QNode *p = Lq->front->next;
    printf("队列元素(队首->队尾):");
    while(p) { 
        printf(" %d", p->data); 
        p = p->next; 
    }
    printf("\n");
}

// 销毁链队列
void DestroyQueue(LQueue *Lq) {
    ElemType y;
    while(!QueueEmpty(Lq)) DelQueue_L(Lq, &y);
    free(Lq->front);
    Lq->front = Lq->rear = NULL;
}

int main() {
    LQueue *Lq;
    ElemType *y, x;
    int i;
    
    Lq = (LQueue*)malloc(sizeof(LQueue));
    y = (ElemType*)malloc(sizeof(ElemType));
    InitQueue(Lq);
    
    printf("请输入%d个整数:", 5);
    for(i=0; i<5; i++) { 
        scanf("%d", &x); 
        EnQueue_L(Lq, x); 
    }
    
    printf("队首元素为:%2d\n", getFront(Lq));
    printf("队列中元素个数:%2d\n", length(Lq));
    PrintQueue(Lq);
    
    DelQueue_L(Lq, y);
    printf("出队元素:%2d\n", *y);
    PrintQueue(Lq);
    
    DestroyQueue(Lq);
    DelQueue_L(Lq, y); // 空队列出队异常处理测试
    
    return 0;
}
