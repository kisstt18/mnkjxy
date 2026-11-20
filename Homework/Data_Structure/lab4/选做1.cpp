#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define N 5
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}SqQueue;
void InitQueue(SqQueue*q){ q->front=q->rear=0; }
int EmptyQueue(SqQueue*q){ return q->front==q->rear; }
int FullQueue(SqQueue*q){ return (q->rear+1)%MAXSIZE==q->front; }
void EnQueue(SqQueue*q,ElemType x){
    if(!FullQueue(q)){ q->data[q->rear]=x; q->rear=(q->rear+1)%MAXSIZE; }
}
ElemType DeQueue(SqQueue*q){
    ElemType x=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return x;
}
int main(){
    SqQueue q;
    InitQueue(&q);
    int i,j,temp,prev;
    EnQueue(&q,1);                
    for(i=1;i<=N;i++){             
        for(j=1;j<=N-i;j++) printf("   ");  
        EnQueue(&q,0);             
        prev=0;                    
        for(j=1;j<=i;j++){         
            temp=DeQueue(&q);
            printf("%6d",temp);
            EnQueue(&q,temp+prev); 
            prev=temp;
        }
        DeQueue(&q);               
        EnQueue(&q,prev);         
        printf("\n");
    }
    return 0;
}
