#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num*2-1; i++){
        for(int k = 0; k < i && k < num*2-i-2; k++){
            printf(" ");
        }
        for(int j = 1; j <= num*2-1-i*2 || j <= (i-num+1)*2+1 ; j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}