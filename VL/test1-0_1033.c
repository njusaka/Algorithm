#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num, array[100], mv, *tmp, tmpF = 0;
    scanf("%d\n", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }
    scanf("%d", &mv);
    if(mv > num) mv = mv%num;
    tmp = (int *)malloc(num*sizeof(int));
    // for(int i = 0; i < num; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    //printf("\n");
    for(int i = num - mv; i < num; i++)
    {
        tmp[tmpF++] = array[i];
           
    }
    for(int i = 0; i < num - mv; i++)
    {
        tmp[tmpF++] = array[i];
    }
    for(int i = 0; i < num; i++)
    {
        printf("%d ", tmp[i]);
    }
    printf("\n");
    return 0;
}