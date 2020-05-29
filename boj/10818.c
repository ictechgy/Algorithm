#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    int min = 1000000;
    int max = -1000000;
    int input;
    for(int i = 1; i <= num; i++){
        scanf("%d", &input);
        if(input > max) max = input;
        if(input < min) min = input;
    }
    printf("%d %d\n", min, max);
    
    return 0;
}