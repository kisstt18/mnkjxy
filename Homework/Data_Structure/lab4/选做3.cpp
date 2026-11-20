#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}DeQueue;
void InitDeQueue(DeQueue*q){ q->front=q->rear=0; }
/* 队尾入队 */
int PushBack(DeQueue*q,ElemType x){
    if((q->rear+1)%MAXSIZE==q->front){ printf("队满!\n"); return 0; }
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}
/* 队头入队 */
int PushFront(DeQueue*q,ElemType x){
    if((q->rear+1)%MAXSIZE==q->front){ printf("队满!\n"); return 0; }
    q->front=(q->front-1+MAXSIZE)%MAXSIZE;   
    q->data[q->front]=x;
    return 1;
}
/* 队头出队 */
int PopFront(DeQueue*q,ElemType*x){
    if(q->front==q->rear){ printf("队空!\n"); return 0; }
    *x=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}
/* 队尾出队 */
int PopBack(DeQueue*q,ElemType*x){
    if(q->front==q->rear){ printf("队空!\n"); return 0; }
    q->rear=(q->rear-1+MAXSIZE)%MAXSIZE;      
    *x=q->data[q->rear];
    return 1;
}
int main(){
    DeQueue q;
    InitDeQueue(&q);
    ElemType x;
    PushBack(&q,1);    
    PushBack(&q,2);    
    PushFront(&q,3);   
    PushFront(&q,4);   
    printf("依次出队(队头→队尾):");
    while(q.front!=q.rear){ PopFront(&q,&x); printf(" %d",x); }
    printf("\n");
    PushBack(&q,10);   
    PushBack(&q,20);   
    printf("从队尾出队:");
    while(q.front!=q.rear){ PopBack(&q,&x); printf(" %d",x); }
    printf("\n");
    return 0;
}
