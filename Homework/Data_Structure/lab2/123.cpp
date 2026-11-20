#include<stdio.h>
#include<malloc.h>
#define N 10
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}Node;
Node*Init_node(){
	Node*Head=(Node*)malloc(sizeof(Node));
	Head->next=NULL;
	return Head;
}
Node*create_node(Node*Head){
	int i=1;
	Node*q,*p;
	q=Head;
	while(i++<=N){
		p = (Node*)malloc(sizeof(Node));
		scanf("%d",&p->data);
		p->next=NULL;
		q->next=p;
		q=p;
	}
	return Head;
}
Node*Search(Node*H,int i){
	Node*q=H;
	int j=1;
	while(q&&j<1){
		q=q->next;
		++j;
	}
	if(!q||j>i) return NULL;
	return q;
}
Node*insert_node_i(Node*H,int i,ElemType x){
	Node*q,*p;
	q=Search(H,i);
	if(q){
		p=(Node*)malloc(sizeof(Node));
		p->data=x;
		p->next=q->next;
		q->next=p;
	}
	return H;
}
Node*delete_node(Node*H,int i){
	Node*q,*p;
	int j =1;
	q=Search(H,i);
	if(q){
		p=q->next;
		q->next=p->next;
		free(p);
	}
	return H;
}
void Print_node(Node*H){
	Node*p;
	p=H->next;
	printf("HEAD->");
	while(p){
		printf("%2d->",p->data);
		p=p->next;
	}
	printf("END\n");
}
// 修改点1：void main() → int main()
int main() {
    Node*Head;
    int i,j;
    ElemType x;
    printf("请建立有%d节车厢的火车\n",N);
    // 修改点2：Init_node(Head) → Init_node()，不要传参
    Head=Init_node();
    create_node(Head);
    Print_node(Head);
    printf("\n\n");
    printf("将不足的1节车厢连到第 i (0<i<10)节车厢后 i=");
    scanf("%d",&i);                    //输入i
    printf("请输入元素 x 的值:");
    scanf("%d",&x);
    insert_node_i(Head,i,x);
    Print_node(Head);
    printf("\n\n");
    printf("将第 j (0<j<15)节车厢的煤留在湖北,j=");
    scanf("%d",&j);                    //输入j
    delete_node(Head,j);
    Print_node(Head);
    // 修改点3：main函数返回0
    return 0;
}
