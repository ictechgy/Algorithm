#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    clock_t start, end;
    int n;
    scanf("%d", &n);    //입력
    //고전적인 풀이방식
    int cnt = 0;
    start = clock();
    int i, j;
    for(i = 2; i <= n; i++){    //1은 소수가 아니다.
        //i가 소수인지 검증
        for(j = 2; j < i; j++){
            if(i % j == 0){
                break;
            }
        }
        if(i == j){
            cnt++;
        }
    }
    end = clock();
    printf("%d\n", cnt);
    printf("방법 1 - 소요시간 : %f\n", (double)(end - start) / CLOCKS_PER_SEC); //약 5초
    puts("");

    //개선 1
    scanf("%d", &n);
    bool flag;
    cnt = 0;
    start = clock();
    for(int i = 2; i <= n; i++){
        flag = true;        //일단 소수라고 가정
        for(int j = 2; j <= sqrt(i); j++){  //탐색은 제곱근까지만 해도 된다. 
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag) cnt ++;
    }
    end = clock();
    printf("%d\n", cnt);
    printf("개선 1 - 소요시간 : %f\n", (double)(end - start) / CLOCKS_PER_SEC); //약 0.06초
    puts("");

    //개선 2 - 역으로 생각하기
    scanf("%d", &n);
    int *arr = (int*)calloc(n+1, sizeof(int));  //use index 2 to n, initialize all value to 0
    start = clock();
    for(int i = 2; i <= n/2; i++){
        for(int j = i*2; j <= n; j += i){
            arr[j]++;
        }
    }
    cnt = 0;
    for(int i = 2; i <= n; i++){
        if(arr[i] == 0) cnt++;
    }
    end = clock();

    printf("%d\n", cnt);
    printf("개선 2 - 소요시간 : %f\n", (double)(end - start) / CLOCKS_PER_SEC); //약 0.007초
    
    
    return 0;
}

//
#include <stdio.h>
int main(){
    int n, i, j, flag, cnt = 0;
    scanf("%d", &n);
    for(i = 2; i <=n; i++){
        flag = 1;
        for(j = 2; j*j < i; j++){   //sqrt까지는 필요없다.
            if(i % j == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}