#include <stdio.h>
#include <time.h>

int main(void){
    int n;
    scanf("%d", &n);    //입력
    //고전적인 풀이방식
    int cnt = 0;
    for(int i = 2; i <= n; i++){    //1은 소수가 아니다.
        //i가 소수인지 검증
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                break;
            }
        }
        
    }
    
    return 0;
}