#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
int i = 0;
char str[100];

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreatBitree(BiTree *T)
{
    (*T) = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = str[i++];
    if((*T)->data != '#'){
        CreatBitree(&(*T)->lchild);
        CreatBitree(&(*T)->rchild);
    } 
}

void InOrderTraverse(BiTree T)
{
    if (T != NULL) {
        InOrderTraverse(T->lchild);
        if(T->data != '#') printf("%c ", T->data);
        InOrderTraverse(T->rchild);
    }
}

int main()
{
    int n, tmp;

    while (scanf("%s", str) != EOF)
    {
        BiTree T = NULL;
        CreatBitree(&T);       

        InOrderTraverse(T);
        printf("\n");
        i = 0;
    }

    return 0;
}