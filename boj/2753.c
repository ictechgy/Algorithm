#include <stdio.h>

int main(void){
    int year;
    scanf("%d", &year);
    printf("%d\n", (year % 400 == 0)? 1 : (year % 4 == 0 && year % 100 != 0)? 1 : 0);
    return 0;
}