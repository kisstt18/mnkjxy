#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m, s1, s2;
typedef struct {
    unsigned int weight;
    unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char *HuffmanCode;

void Select(HuffmanTree HT, int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        if (!HT[i].parent) {
            s1 = i;
            break;
        }
    }
    for (j = i + 1; j <= n; j++) {
        if (!HT[j].parent) {
            s2 = j;
            break;
        }
    }
    for (i = 1; i <= n; i++) {
        if ((HT[s1].weight > HT[i].weight) && (!HT[i].parent) && (s2 != i))
            s1 = i;
    }
    for (j = 1; j <= n; j++) {
        if ((HT[s2].weight > HT[j].weight) && (!HT[j].parent) && (s1 != j))
            s2 = j;
    }
}

// 构造哈夫曼树并生成编码（已修复叶子结点状态标记bug）
void HuffmanCoding(HuffmanTree *HT, HuffmanCode HC[], int *w, int n) {
    int i, j;
    char *cd;
    int p;
    int cdelen;
    if (n <= 1) return;
    m = 2 * n - 1;
    *HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for (i = 1; i <= n; i++) {
        (*HT)[i].weight = w[i - 1];
        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }
    for (i = n + 1; i <= m; i++) {
        (*HT)[i].weight = 0;
        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }

    for (i = n + 1; i <= m; i++) {
        Select(*HT, i - 1);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }

    cd = (char *)malloc(n * sizeof(char));
    p = m;
    cdelen = 0;
    // weight复用为访问标记：0未访问，1访问过左，2访问完左右
    for (i = 1; i <= m; i++)
        (*HT)[i].weight = 0;

    while (p) {
        if ((*HT)[p].weight == 0) {
            (*HT)[p].weight = 1;
            if ((*HT)[p].lchild != 0) {
                p = (*HT)[p].lchild;
                cd[cdelen++] = '0';
            } else if ((*HT)[p].rchild == 0) {
                // 叶子结点：保存编码，并标记为已访问完成
                HC[p] = (char *)malloc((cdelen + 1) * sizeof(char));
                cd[cdelen] = '\0';
                strcpy(HC[p], cd);
                (*HT)[p].weight = 2; // 修复点：标记叶子已处理完毕
            } else {
                (*HT)[p].weight = 2;
                p = (*HT)[p].rchild;
                cd[cdelen++] = '1';
            }
        } else if ((*HT)[p].weight == 1) {
            (*HT)[p].weight = 2;
            p = (*HT)[p].rchild;
            cd[cdelen++] = '1';
        } else {
            p = (*HT)[p].parent;
            --cdelen;
        }
    }
    free(cd);
}

// 统计文本中每个字符的出现频率
void CountFreq(char *text, char chTab[], int wTab[], int *num) {
    int i, j, flag;
    *num = 0;
    for (i = 0; text[i] != '\0'; i++) {
        flag = 0;
        for (j = 0; j < *num; j++) {
            if (chTab[j] == text[i]) {
                wTab[j]++;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            chTab[*num] = text[i];
            wTab[*num] = 1;
            (*num)++;
        }
    }
}

int main() {
    HuffmanTree HT = NULL;
    HuffmanCode *HC;
    char text[200];
    char chTab[128];
    int wTab[128];
    int n, i;
    int totalBit = 0, originBit;

    printf("输入待编码的英文文本：");
    scanf("%s", text);

    // 1. 统计字符频率
    CountFreq(text, chTab, wTab, &n);
    printf("\n统计结果：共 %d 种不同字符\n", n);

    // 2. 构造哈夫曼树+生成编码
    HC = (HuffmanCode *)malloc((2 * n) * sizeof(HuffmanCode));
    HuffmanCoding(&HT, HC, wTab, n);

    // 3. 输出编码表，计算总比特
    printf("\n字符 频率 哈夫曼编码\n");
    printf("------------------------\n");
    for (i = 1; i <= n; i++) {
        printf(" %c %d %s\n", chTab[i - 1], wTab[i - 1], HC[i]);
        totalBit += strlen(HC[i]) * wTab[i - 1];
    }

    // 4. 计算压缩率
    originBit = strlen(text) * 8;
    printf("\n原始文本总比特（ASCII）：%d bit\n", originBit);
    printf("哈夫曼编码后总比特：%d bit\n", totalBit);
    printf("压缩率：%.2f %%\n", (1.0 * totalBit / originBit) * 100);

    // 释放内存
    for (i = 1; i <= n; i++)
        free(HC[i]);
    free(HC);
    free(HT);

    getchar();
    getchar();
    return 0;
}
