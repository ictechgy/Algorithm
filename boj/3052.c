#include <stdio.h>

int main(void){
    int num;
    int arr[42] = {0}; //0~41
    int rest, count = 0;
    for(int i = 1; i <= 10; i++){
        scanf("%d", &num);
        rest = num % 42;
        if(!arr[rest]) count++;
        arr[rest]++;
    }
    printf("%d\n", count);
    
    return 0;
}