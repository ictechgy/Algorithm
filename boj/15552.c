#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    int a, b;
    for(int i = 0; i < num; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}