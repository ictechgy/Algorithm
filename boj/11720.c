#include <stdio.h>

int parseChar(char su){
    return su - 48;    
}

int main(void){
    int num;
    scanf("%d", &num);
    getchar();
    int sum = 0;
    char in;
    for(int i = 1; i <= num; i++){
        scanf("%c", &in);
        sum += parseChar(in);
    }
    printf("%d\n", sum);
    
    return 0;
}