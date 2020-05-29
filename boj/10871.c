#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, x;
    scanf("%d %d", &n, &x);
    int* arr = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        if(x>arr[i]) printf("%d ", arr[i]);
    }
    return 0;
}