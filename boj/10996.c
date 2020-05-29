#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num*2; i++){
        for(int j = 0; j < num; j++){
            if((i+j)%2 == 0) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}