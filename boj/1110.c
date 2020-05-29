#include <stdio.h>

int main(void){
    int count = 0, num;
    scanf("%d", &num);
    int origin_num = num;
    while(1){
        int new_right = ((num / 10) + (num % 10)) % 10;
        int new_num = (num % 10 * 10) + new_right;
        count++;
        if(origin_num == new_num) break;
        num = new_num;
    }
    printf("%d\n", count);
    return 0;
}