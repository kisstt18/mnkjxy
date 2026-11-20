#include<stdio.h>
#include<malloc.h>
#define N 7
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
	Node *q,*p;
	q=Head;
	while(i++<=N){
		p=(Node*)malloc(sizeof(Node));
		scanf("%d",&p->data);
		p->next=NULL;
		q=p;
	}
	return Head;
}

int CountXNode(Node *head,ElemType x)
{
	Node *p=head->next;
	int count=0;
	while(p!=NULL){
		if(p->data==x)
		{
			count++;
		}
		p=p->next;
	}
	return count;
}

void Print_node(Node* H)
{
	Node* p;
	p=H->next;
	printf("HEAd->");
	while(p)
	{
		printf("%2d->",p->data);
		p=p->next;
	}
	printf("END\n");
}

 int main(){
 	Node * head;
 	ElemType x;
 	int num;
 	printf("请输入%d个链表元素:",N);
 	head=Init_node();
 	create_node(head);
 	Print_node(head);
 	printf("请输入要统计的数值x:");
 	scanf("%d",&x);
 	num=CountXNode(head,x);
 	printf("数据为%d的节点个数:%d\n",x,num);
 	return 0;
 }






