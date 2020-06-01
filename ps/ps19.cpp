#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, h;
    scanf("%d", &n);
    int *s = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    int max = s[n-1];   //맨 뒤의 요소를 최대값으로 가정
    int cnt = 0;
    for(int i = n-2; i >=0; i--){
        if(s[i] > max){
            cnt++;
            max = s[i];
        }
    }
    printf("%d\n", cnt);

    free(s);
    return 0;
}

//
#include <stdio.h>
int main(){
    int n, i, cnt = 0, h[101], max;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &h[i]);
    }
    max = h[n];
    for(i = n-1; i >= 1; i--){
        if(h[i] > max){
            max = h[i];
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}