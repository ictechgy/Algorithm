#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    int temp = b;
    printf("%d\n", a * (temp % 10));
    temp /= 10;
    printf("%d\n", a * (temp % 10));
    temp /= 10;
    printf("%d\n", a * (temp % 10));
    printf("%d\n", a * b);
    return 0;
}