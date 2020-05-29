#include <stdio.h>

int main(void){
    int cheap_ham = 2000;
    int cheap_bev = 2000;
    int input;
    for(int i = 0; i < 3; i++){
        scanf("%d", &input);
        if(input < cheap_ham) cheap_ham = input;
    }
    for(int i = 0; i < 2; i++){
        scanf("%d", &input);
        if(input < cheap_bev) cheap_bev = input;
    }
    printf("%d\n", cheap_ham + cheap_bev - 50);
    
    return 0;
}