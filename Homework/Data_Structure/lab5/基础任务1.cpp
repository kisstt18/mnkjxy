#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef int ElemType;
/* 二叉链表结点定义 */
typedef struct TreeNode{
    ElemType data;
    struct TreeNode *lchild,*rchild;
}TreeNode,*BiTree;

/* 循环队列（存结点指针，层序遍历） */
typedef struct{
    BiTree data[MAXSIZE];
    int front,rear;
}SqQueue;

//队列操作
void InitQueue(SqQueue *Sq){ Sq->front=Sq->rear=0; }
int EmptyQueue(SqQueue *Sq){ return (Sq->rear==Sq->front)?1:0; }
int FullQueue(SqQueue *Sq){ return ((Sq->rear+1)%MAXSIZE==Sq->front)?1:0; }
int InsertQueue(SqQueue *Sq,BiTree x){
    if(FullQueue(Sq)){ printf("队列已满!"); return 0; }
    Sq->data[Sq->rear]=x;
    Sq->rear=(Sq->rear+1)%MAXSIZE;
    return 1;
}
int DelseqQueue(SqQueue *Sq,BiTree *y){
    if(EmptyQueue(Sq)) return 0;
    *y=Sq->data[Sq->front];
    Sq->front=(Sq->front+1)%MAXSIZE;
    return 1;
}

/* 申请新结点 */
TreeNode *NewNode(ElemType x){
    TreeNode *s;
    s=(TreeNode *)malloc(sizeof(TreeNode));
    s->data=x;
    s->lchild=s->rchild=NULL;
    return s;
}

/* 手动构建测试二叉树 */
BiTree CreateTree(){
    BiTree t1,t2,t3,t4,t5,t6;
    t1=NewNode(1); t2=NewNode(2); t3=NewNode(3);
    t4=NewNode(4); t5=NewNode(5); t6=NewNode(6);
    t1->lchild=t2; t1->rchild=t3;
    t2->lchild=t4; t2->rchild=t5;
    t3->lchild=NULL; t3->rchild=t6;
    return t1;
}

/* 前序遍历：根 -> 左 -> 右 */
void printTreePreOrder(BiTree t){
    if(t){
        printf("%3d",t->data);
        printTreePreOrder(t->lchild);
        printTreePreOrder(t->rchild);
    }
}

/* 中序遍历：左 -> 根 -> 右 */
void printTreeInOrder(BiTree t){
    if(t){
        printTreeInOrder(t->lchild);
        printf("%3d",t->data);
        printTreeInOrder(t->rchild);
    }
}

/* 后序遍历：左 -> 右 -> 根 */
void printTreePostOrder(BiTree t){
    if(t){
        printTreePostOrder(t->lchild);
        printTreePostOrder(t->rchild);
        printf("%3d",t->data);
    }
}

/* 层序遍历 */
void printTreeLevel(BiTree t){
    SqQueue Sq;
    BiTree p;
    if(t==NULL) return;
    InitQueue(&Sq);
    InsertQueue(&Sq,t);
    while(!EmptyQueue(&Sq)){
        DelseqQueue(&Sq,&p);
        printf("%3d",p->data);
        if(p->lchild) InsertQueue(&Sq,p->lchild);
        if(p->rchild) InsertQueue(&Sq,p->rchild);
    }
}

/* 求树高 */
int countDeep(BiTree t){
    int nl,nr;
    if(t==NULL) return 0;
    nl=countDeep(t->lchild);
    nr=countDeep(t->rchild);
    return (nl>nr?nl:nr)+1;
}

/* 统计叶子结点个数 */
int countLeaf(BiTree t){
    if(t==NULL) return 0;
    if(t->lchild==NULL && t->rchild==NULL)
        return 1;
    return countLeaf(t->lchild)+countLeaf(t->rchild);
}

/* 统计总结点数 */
int countTotal(BiTree t){
    if(t==NULL) return 0;
    return countTotal(t->lchild)+countTotal(t->rchild)+1;
}

/* 输出所有叶子结点 */
void printLeaf(BiTree t){
    if(t){
        if(t->lchild==NULL && t->rchild==NULL) printf("%3d",t->data);
        printLeaf(t->lchild);
        printLeaf(t->rchild);
    }
}

/* 销毁二叉树，后序释放 */
void DestroyTree(BiTree t){
    if(t){
        DestroyTree(t->lchild);
        DestroyTree(t->rchild);
        free(t);
    }
}

int main(){
    BiTree t;
    t=CreateTree();
    printf("前序遍历结果:");
    printTreePreOrder(t);
    printf("\n中序遍历结果:");
    printTreeInOrder(t);
    printf("\n后序遍历结果:");
    printTreePostOrder(t);
    printf("\n层序遍历结果:");
    printTreeLevel(t);
    printf("\n二叉树的树高为:%d",countDeep(t));
    printf("\n二叉树的叶子结点数为:%d",countLeaf(t));
    printf("\n二叉树的结点总数为:%d",countTotal(t));
    printf("\n叶子结点依次为:");
    printLeaf(t);
    printf("\n");
    DestroyTree(t);
    t=NULL;
    return 0;
}
