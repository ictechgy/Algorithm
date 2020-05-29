#include <stdio.h>

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int middle;
    if(a > b){
        if(c > a) middle = a;
        else if(c > b) middle = c;
        else middle = b;
    }// b >= a
    else if(c > b) middle = b;
    else if(c > a) middle = c;
    else middle = a;
    printf("%d\n", middle);
    
    return 0;
}