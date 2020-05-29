#include <stdio.h>

int main(void){
    int a, b;
    while(scanf("%d %d", &a, &b)+1){
        printf("%d\n", a + b);
    }
    return 0;
}

//또는

#include <stdio.h>

int main(void){
    int a, b;
    while(1){
        int check = scanf("%d %d", &a, &b);
        if(check == EOF) break;
        printf("%d\n", a + b);
    }
    return 0;
}