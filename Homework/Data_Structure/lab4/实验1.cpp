#include <stdio.h>
#include <stdlib.h>   

#define MAXSIZE 5
#define N 5

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int front, rear;   
} SqQueue;

// 初始化队列
void InitQueue(SqQueue *Sq)
{
    Sq->rear = Sq->front = 0;
}

// 判断队列是否为空
int EmptyQueue(SqQueue *Sq)
{
    return (Sq->rear == Sq->front) ? 1 : 0;
}

// 判断队列是否满（非循环：rear 走到数组上限就算满）
int FullQueue(SqQueue *Sq)
{
    return (Sq->rear == MAXSIZE) ? 1 : 0;
}

// 入队
int InsertQueue(SqQueue *Sq, ElemType x)
{
    if (FullQueue(Sq))
    {
        printf("\n队列已满！");
        return 0;
    }
    else
    {
        Sq->data[Sq->rear] = x;
        Sq->rear++;
        return 1;
    }
}

// 出队
int DelseQueue(SqQueue *Sq, ElemType *y)
{
    if (EmptyQueue(Sq))
    {
        printf("队列为空");
        return 0;
    }
    else
    {
        *y = Sq->data[Sq->front];
        Sq->front++;
        return 1;
    }
}

// 获取队首元素
ElemType getFront(SqQueue *Sq)
{
    return Sq->data[Sq->front];
}

// 获取队尾元素
ElemType getRear(SqQueue *Sq)
{
    return Sq->data[Sq->rear - 1];
}

int main()
{
    SqQueue *Sq;
    ElemType *y, x;
    int i;

    Sq = (SqQueue *)malloc(sizeof(SqQueue));
    y  = (ElemType *)malloc(sizeof(ElemType));
    InitQueue(Sq);

    printf("请输入%d个整数：", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &x);
        InsertQueue(Sq, x);
    }

    printf("队首元素为：%2d\n", getFront(Sq));
    printf("队尾元素为：%2d\n", getRear(Sq));

    printf("出队的结果为：");
    while (!EmptyQueue(Sq))
    {
        DelseQueue(Sq, y);
        printf("%2d", *y);
    }
    putchar('\n');

    InitQueue(Sq);
    for (i = 0; i < N; i++)
        InsertQueue(Sq, i + 1);

    for (i = 0; i < 3; i++)
        DelseQueue(Sq, y);

    printf("出队3个后 front=%d rear=%d 队中元素：", Sq->front, Sq->rear);
    for (i = Sq->front; i < Sq->rear; i++)
        printf(" %d", Sq->data[i]);

    printf("\n此时再入队6：");
    if (!InsertQueue(Sq, 6))
        printf(" —— 假溢出：实际只剩2个元素，却不能再入队");
    printf("\n");


    free(Sq);
    free(y);
    return 0;
}

