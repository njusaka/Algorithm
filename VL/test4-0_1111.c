#include<stdio.h>
int RJ_calc(int tmp);
int main()
{
    int R_num = 0, J_num = 0;
    for(int i = 1; i <= 1000; i++){
        if(RJ_calc(i) == 1) R_num++;
        else J_num++;
    }
    printf("%d %d", R_num, J_num);
    return 0;
}

int RJ_calc(int tmp)
{
    int i, one_num = 0, zero_num = 0;
    while(tmp)
    {
        if(tmp % 2 == 0)zero_num++;
        else one_num++;
        tmp = tmp /2;        
    }
    if(one_num > zero_num) return 1;
    else return 0;
}