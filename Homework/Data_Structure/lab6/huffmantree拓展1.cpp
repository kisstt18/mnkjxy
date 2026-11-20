#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100
#define MAXCODE 50

typedef struct{
    char ch;
    int weight;
    int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char *HuffmanCode[MAXN];

void Select(HuffmanTree HT, int n, int *s1, int *s2)
{
    int i, min1=0x3f3f3f3f, min2=0x3f3f3f3f;
    *s1 = *s2 = -1;
    for(i=1; i<=n; i++)
    {
        if(HT[i].parent == 0)
        {
            if(HT[i].weight < min1)
            {
                min2 = min1; *s2 = *s1;
                min1 = HT[i].weight; *s1 = i;
            }
            else if(HT[i].weight < min2)
            {
                min2 = HT[i].weight; *s2 = i;
            }
        }
    }
}

void CreateHuffmanTree(HuffmanTree *HT, char ch[], int w[], int n)
{
    int m = 2*n -1;
    *HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
    int i, s1, s2;
    for(i=1; i<=n; i++)
    {
        (*HT)[i].ch = ch[i];
        (*HT)[i].weight = w[i];
        (*HT)[i].parent = (*HT)[i].lchild = (*HT)[i].rchild = 0;
    }
    for(i=n+1; i<=m; i++)
    {
        (*HT)[i].ch = '#';
        (*HT)[i].weight = 0;
        (*HT)[i].parent = (*HT)[i].lchild = (*HT)[i].rchild = 0;
    }
    for(i=n+1; i<=m; i++)
    {
        Select(*HT, i-1, &s1, &s2);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode HC, int n)
{
    char *cd = (char*)malloc(n*sizeof(char));
    cd[n-1] = '\0';
    int i, c, f, start;
    for(i=1; i<=n; i++)
    {
        start = n-1;
        c = i;
        f = HT[i].parent;
        while(f != 0)
        {
            if(HT[f].lchild == c) cd[--start] = '0';
            else cd[--start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = (char*)malloc((n-start)*sizeof(char));
        strcpy(HC[i], cd+start);
    }
    free(cd);
}

//¹þ·òÂü½âÂë
void HuffmanDecode(HuffmanTree HT, int n, char *codeStr)
{
    printf("½âÂë½á¹û£º");
    int p = 2*n-1;
    for(int i=0; codeStr[i]!='\0'; i++)
    {
        if(codeStr[i] == '0') p = HT[p].lchild;
        else p = HT[p].rchild;
        if(HT[p].lchild == 0 && HT[p].rchild == 0)
        {
            printf("%c", HT[p].ch);
            p = 2*n -1;
        }
    }
    printf("\n");
}

int main()
{
    char ch[] = {' ','A','B','C','D','E','F'};
    int w[] = {0,5,9,12,13,16,45};
    int n = 6;
    HuffmanTree HT;
    HuffmanCode HC;
    CreateHuffmanTree(&HT, ch, w, n);
    CreateHuffmanCode(HT, HC, n);

    char testCode[] = "111110110110";
    printf("´ý½âÂë01´®£º%s\n", testCode);
    HuffmanDecode(HT, n, testCode);

    system("pause");
    return 0;
}

