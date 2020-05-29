#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num*2-1; i++){
        for(int j = 1; j <= i && j <= num*2-i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}