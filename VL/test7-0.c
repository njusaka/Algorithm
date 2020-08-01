#include<stdio.h>
int main()
{
    int light[1001];
    int n, num_lightOn = 0;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            light[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n / i; j++) {
                light[j * i] = !light[j * i];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (light[i] == 1) num_lightOn++;
        }
        printf("%d\n", num_lightOn);
        num_lightOn = 0;
    }
    return 0;
}