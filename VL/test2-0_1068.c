#include<stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void CreatBitree(BiTree *T, int tmp)
{
    if ((*T) == NULL) {
        (*T) = (BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data = tmp;
    }
    else
    {
        if (tmp < (*T)->data) CreatBitree(&(*T)->lchild, tmp);
        if (tmp > (*T)->data) CreatBitree(&(*T)->rchild, tmp);
    }

}

void PreOrderTraverse(BiTree t)
{
    if (t != NULL) {
        printf("%d ", t->data);
        PreOrderTraverse(t->lchild);
        PreOrderTraverse(t->rchild);
    }
}
void InOrderTraverse(BiTree T)
{
    if (T != NULL) {
        InOrderTraverse(T->lchild);
        printf("%d ", T->data);
        InOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    if (T != NULL) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ", T->data);

    }
}
int main()
{
    int n, tmp;

    while (scanf("%d", &n) != EOF)
    {
        BiTree T = NULL;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            CreatBitree(&T, tmp);
        }
        PreOrderTraverse(T);
        printf("\n");
        InOrderTraverse(T);
        printf("\n");
        PostOrderTraverse(T);
        printf("\n");
    }

    return 0;
}