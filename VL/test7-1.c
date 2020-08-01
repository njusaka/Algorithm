#include<stdio.h>  //除了质数和0，就是和数，最终亮灯的只有平方数，综合来说就是求n以内的平方数
int main()
{
    int n, num_lightOn = 0;
    while (scanf("%d", &n) != EOF) {
        if(n > 1,000,00) return 0;
        for(int i = 1; i*i<= n; i++){
            if(i*i<= n) num_lightOn++;
        }
        printf("%d\n", num_lightOn);
        num_lightOn = 0;
    }
    return 0;
}