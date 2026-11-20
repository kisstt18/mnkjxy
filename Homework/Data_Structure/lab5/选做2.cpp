#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *Tree;

Tree BuildTree(char* preorder, int preLeft, int preRight, char* inorder, int inLeft, int inRight) {
    if (preLeft > preRight || inLeft > inRight) return NULL;
    
    Tree root = (Tree)malloc(sizeof(TreeNode));
    root->data = preorder[preLeft];
    
    int rootIndex = inLeft;
    while (inorder[rootIndex] != root->data) {
        rootIndex++;
    }
    
    int leftLen = rootIndex - inLeft;
    
    root->lchild = BuildTree(preorder, preLeft + 1, preLeft + leftLen, inorder, inLeft, rootIndex - 1);
    root->rchild = BuildTree(preorder, preLeft + leftLen + 1, preRight, inorder, rootIndex + 1, inRight);
    
    return root;
}

void PreOrder(Tree T) {
    if (T != NULL) {
        printf("%c ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(Tree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%c ", T->data);
        InOrder(T->rchild);
    }
}

int main() {
    printf("--- 由前序序列和中序序列重建二叉树 ---\n\n");
    
    char preorder[] = "ABDECFG";
    char inorder[] = "DBEAFCG";
    int len = 7;
    
    printf("输入的前序序列: %s\n", preorder);
    printf("输入的中序序列: %s\n", inorder);
    
    Tree root = BuildTree(preorder, 0, len - 1, inorder, 0, len - 1);
    
    printf("\n重建成功！验证如下：\n\n");
    printf("重建后的前序遍历: ");
    PreOrder(root);
    printf("\n");
    
    printf("重建后的中序遍历: ");
    InOrder(root);
    printf("\n");
    return 0;
}
