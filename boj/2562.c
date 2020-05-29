#include <stdio.h>

int main(void){
    int th = 0;    //번째
    int max = 1;
    int input;
    for(int i = 1; i <= 9; i++){
        scanf("%d", &input);
        if(input > max){
            max = input;
            th = i;
        }
    }
    printf("%d\n", max);
    printf("%d\n", th);
    
    return 0;
}