#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadTree pre = NULL; 
ThreadTree CreateTestTree() {
    ThreadTree A = (ThreadTree)malloc(sizeof(ThreadNode)); A->data = 'A'; A->ltag = 0; A->rtag = 0;
    ThreadTree B = (ThreadTree)malloc(sizeof(ThreadNode)); B->data = 'B'; B->ltag = 0; B->rtag = 0;
    ThreadTree C = (ThreadTree)malloc(sizeof(ThreadNode)); C->data = 'C'; C->ltag = 0; C->rtag = 0;
    ThreadTree D = (ThreadTree)malloc(sizeof(ThreadNode)); D->data = 'D'; D->ltag = 0; D->rtag = 0;
    ThreadTree E = (ThreadTree)malloc(sizeof(ThreadNode)); E->data = 'E'; E->ltag = 0; E->rtag = 0;
    ThreadTree F = (ThreadTree)malloc(sizeof(ThreadNode)); F->data = 'F'; F->ltag = 0; F->rtag = 0;
    ThreadTree G = (ThreadTree)malloc(sizeof(ThreadNode)); G->data = 'G'; G->ltag = 0; G->rtag = 0;
    
    A->lchild = B; A->rchild = C;
    B->lchild = D; B->rchild = E;
    C->lchild = F; C->rchild = G;
    
    D->lchild = NULL; D->rchild = NULL;
    E->lchild = NULL; E->rchild = NULL;
    F->lchild = NULL; F->rchild = NULL;
    G->lchild = NULL; G->rchild = NULL;
    
    return A;
}

void InThread(ThreadTree p) {
    if (p != NULL) {
        InThread(p->lchild); 
        
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p; 
        
        InThread(p->rchild); 
    }
}

void CreateInThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {
        InThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1; 
        }
    }
}

void InOrderTraverse_Thread(ThreadTree T) {
    ThreadTree p = T;
    if (p == NULL) return;
    
    while (p->ltag == 0) {
        p = p->lchild;
    }
    
    while (p != NULL) {
        printf("%c ", p->data);
        
        if (p->rtag == 1) {
            p = p->rchild;
        } else {
            p = p->rchild;
            while (p != NULL && p->ltag == 0) {
                p = p->lchild;
            }
        }
    }
    printf("\n");
}

int main() {
    printf("--- 线索二叉树中序非递归遍历 ---\n\n");
    ThreadTree root = CreateTestTree();
    printf("构建的二叉树前序为: A B D E C F G\n\n");
    
    CreateInThread(root);
    
    printf("线索化后的中序非递归遍历结果: ");
    InOrderTraverse_Thread(root);
    
    return 0;
}
