#include <stdio.h>

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int res = a * b * c;
    int arr[10] = {0};
    while(res){
        arr[res%10]++;
        res/=10;
    }
    for(int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}