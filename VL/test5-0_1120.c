#include<stdio.h>

int main()
{
    int n;
    long tmp = 1;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
		tmp = tmp*(4*i-2)/(i+1);
	}
    printf("%ld", tmp);
    return 0;
}