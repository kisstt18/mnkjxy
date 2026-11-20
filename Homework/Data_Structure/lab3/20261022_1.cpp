#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct StackNode{
    int length;
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStackNode;

StackNode* InitStack(StackNode *top){
    top->next=NULL;
    top->length=0;
    return top;
}

int Push(StackNode* top,ElemType x){
    StackNode* p=(StackNode*)malloc(sizeof(StackNode));
    if(p == NULL) exit(0);
    p->data=x;
    p->next = top->next;
    top->next = p;
    top->length++;
    return 1;
}

int StackEmpty(StackNode *top){
    return (top->next==NULL);
}

// 【标准双参数Pop】
int Pop(StackNode* top, ElemType *e)
{
    if(StackEmpty(top))
    {
        return 0;
    }
    StackNode *p = top->next;
    *e = p->data;
    top->next = p->next;
    top->length--;
    free(p);
    return 1;
}

int length(StackNode* top){
    return top->length;
}

ElemType getTop(StackNode* top){
    return top->next->data;
}

int main(){
    StackNode *L;
    L=(StackNode*)malloc(sizeof(StackNode));
    L=InitStack(L);
    Push(L,1);
    Push(L,2);
    Push(L,3);
    Push(L,4);
    ElemType y;
    Pop(L,&y);
    printf("出栈元素是：%d\n",y);
    printf("栈中元素个数：%d\n",length(L));
    printf("栈顶元素的值为：%d\n",getTop(L));
    return 0;
}

