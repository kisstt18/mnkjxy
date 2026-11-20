#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 哈夫曼树结点：三叉链表
typedef struct{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

// 哈夫曼编码表
typedef char** HuffmanCode;

int m,s1,s2;  // 全局，Select用来存最小、次小结点下标

/*
函数：Select
功能：在 HT[1] ~ HT[n] 范围内，选出两个parent==0（未合并）权最小、次小的结点，存入s1,s2
*/
void Select(HuffmanTree HT,int n){
    int i,j;
    s1=s2=0;
    // 找第一个空闲结点当s1初始
    for(i=1;i<=n;i++){
        if(HT[i].parent==0){
            s1=i;
            break;
        }
    }
    // 在s1后面找第二个空闲结点当s2初始
    for(j=i+1;j<=n;j++){
        if(HT[j].parent==0){
            s2=j;
            break;
        }
    }
    // 保证 s1初始权 < s2
    if(HT[s1].weight>HT[s2].weight){
        int t=s1;
        s1=s2;
        s2=t;
    }
    // 遍历全部结点，筛选全局最小、次小
    for(i=1;i<=n;i++){
        if(HT[i].parent==0 && HT[i].weight<HT[s1].weight){
            s2=s1;
            s1=i;
        }else if(HT[i].parent==0 && HT[i].weight<HT[s2].weight && i!=s1){
            s2=i;
        }
    }
}

/*
函数：HuffmanCoding
功能：构建哈夫曼树 + 无栈非递归遍历生成哈夫曼编码
*/
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n){
    int i,p,cdlen;
    char *cd;
    if(n<=1) return;
    m=2*n-1;
    // 分配结点数组，下标0弃用
    *HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    // 初始化叶子结点 1~n
    for(i=1;i<=n;i++){
        (*HT)[i].weight=w[i-1];
        (*HT)[i].parent=0;
        (*HT)[i].lchild=0;
        (*HT)[i].rchild=0;
    }
    // 初始化内部合并结点 n+1 ~ m
    for(i=n+1;i<=m;i++){
        (*HT)[i].weight=0;
        (*HT)[i].parent=0;
        (*HT)[i].lchild=0;
        (*HT)[i].rchild=0;
    }
    // 构造哈夫曼树
    for(i=n+1;i<=m;i++){
        Select(*HT,i-1);
        (*HT)[s1].parent=i;
        (*HT)[s2].parent=i;
        (*HT)[i].lchild=s1;
        (*HT)[i].rchild=s2;
        (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
    }
    // 分配编码表 HC[1]~HC[n]
    *HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
    cd=(char*)malloc(n*sizeof(char));
    p=m;
    cdlen=0;
    // weight临时充当遍历标记：0未访问，1左走完，2全部走完
    for(i=1;i<=m;i++){
        (*HT)[i].weight=0;
    }
    while(p){
        if((*HT)[p].weight==0){
            (*HT)[p].weight=1;
            if((*HT)[p].lchild!=0){
                p=(*HT)[p].lchild;
                cd[cdlen++]='0';
            }
            else if((*HT)[p].rchild==0){
                // 叶子结点
                cd[cdlen]='\0';
                (*HC)[p]=(char*)malloc((cdlen+1)*sizeof(char));
                strcpy((*HC)[p],cd);
            }
        }
        else if((*HT)[p].weight==1){
            (*HT)[p].weight=2;
            if((*HT)[p].rchild!=0){
                p=(*HT)[p].rchild;
                cd[cdlen++]='1';
            }
        }
        else{
            (*HT)[p].weight=0;
            p=(*HT)[p].parent;
            cdlen--;
        }
    }
    free(cd);
}

int main(){
    HuffmanTree HT;
    HuffmanCode HC;
    int n=6,i,WPL=0;
    int w[6]={5,9,12,13,16,45};
    char ch[6]={'A','B','C','D','E','F'};
    HuffmanCoding(&HT,&HC,w,n);
    printf("字符 权值 哈夫曼编码\n");
    for(i=1;i<=n;i++){
        printf("%c    %2d    %s\n",ch[i-1],w[i-1],HC[i]);
        WPL += w[i-1] * strlen(HC[i]);
    }
    printf("\n带权路径长度 WPL = %d\n",WPL);
    return 0;
}

