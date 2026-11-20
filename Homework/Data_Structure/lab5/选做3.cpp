#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *Tree;

Tree CreateNode(ElemType data) {
    Tree node = (Tree)malloc(sizeof(TreeNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

// 判断是否为完全二叉树
int IsCompleteTree(Tree root) {
    if (root == NULL) return 1;
    Tree queue[1000]; 
    int front = 0, rear = 0;
    queue[rear++] = root;
    int flag = 0;
    
    while (front < rear) {
        Tree node = queue[front++];
        
        if (node == NULL) {
            flag = 1; 
        } else {
            if (flag) {
                return 0; // 之前遇到过空节点，现在又遇到非空节点，说明不是完全二叉树
            }
            // 无论孩子是否为空，都入队
            queue[rear++] = node->lchild;
            queue[rear++] = node->rchild;
        }
    }
    return 1;
}

int main() {
    printf("--- 判断一棵二叉树是否为完全二叉树 ---\n\n");

    Tree root1 = CreateNode('A');
    root1->lchild = CreateNode('B');
    root1->rchild = CreateNode('C');
    root1->lchild->lchild = CreateNode('D');
    root1->lchild->rchild = CreateNode('E');
    root1->rchild->lchild = CreateNode('F');
    root1->rchild->rchild = CreateNode('G');
    
    if (IsCompleteTree(root1)) {
        printf("(满二叉树): 是完全二叉树\n");
    } else {
        printf("(满二叉树): 不是完全二叉树\n");
    }
    Tree root2 = CreateNode('A');
    root2->lchild = CreateNode('B');
    root2->lchild->lchild = CreateNode('D');
    root2->lchild->rchild = CreateNode('E');
    // A 缺失了右孩子 C，但左边还有一堆，所以不是完全二叉树
    
    if (IsCompleteTree(root2)) {
        printf("(缺失右侧节点的树): 是完全二叉树\n");
    } else {
        printf("(缺失右侧节点的树): 不是完全二叉树\n");
    }
    
    return 0;
}
