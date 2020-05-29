#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

int main(void){
    clock_t start, end;
    int n;
    scanf("%d", &n);
    
    start = clock();

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        //숫자 i의 약수의 개수 출력
        for(int j = 1; j <= sqrt(i); j++){
            if(i % j == 0) cnt++;
        }
        cnt *= 2;
        if(sqrt(i) == floor(sqrt(i))) cnt--;
        printf("%d ", cnt);
    }
    end = clock();
    puts("");
    printf("경과시간 : %f", (double)(end - start)/CLOCKS_PER_SEC);
    puts("");


    //강의에 나오는 접근전략을 써본다면.. 
    int in;
    scanf("%d", &in);
    int* arr = (int*)calloc(in + 1, sizeof(int));  //0번 인덱스는 사용하지 않고 1 ~ in번까지의 인덱스를 사용 
    start = clock();
    for(int i = 1; i <= in; i++){
        //i를 약수로 가지는 수들의 배열 값을 증가
        for(int j = 1; j <= in / i; j++){   //j는 곱해줄 수를 의미한다. 
            arr[i*j]++;
        }
    }
    end = clock();
    for(int i = 1; i<=in; i++) printf("%d ", arr[i]);
    puts("");
    printf("경과시간 : %f", (double)(end - start)/CLOCKS_PER_SEC);
    //미쳤다. 내가 처음에 생각한 코드가 0.077634초정도 걸리는데, 이 코드는 0.003044 정도 걸린다... 
    //나는 단순히 탐색의 범위를 줄였는데.. 1초내로 통과하기는 하는데.. 강의에서는 아예 역으로 접근함.

    return 0;
}

//강의 코드
#include <stdio.h>
int cnt[50001];
int main(){
    int n, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j = j + i){
            cnt[j]++;
        }
    }
    for(i = 1; i <= n; i++){
        printf("%d ", cnt[i]);
    }
    return 0;
}