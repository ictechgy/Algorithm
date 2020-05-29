#include <stdio.h>
#include <string.h>

int main(void){
    int a, b;
    char result[3];
    scanf("%d %d", &a, &b);
    strcpy(result, (a > b)? ">" :((a < b)? "<":"=="));
    printf("%s\n", result);
    return 0;
}