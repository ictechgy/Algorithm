#include <stdio.h>
#include <time.h>

int cnt_digit(int);

int main(void){
    int n;
    scanf("%d", &n);
    clock_t start, end;
    start = clock();
    printf("%d\n", cnt_digit(n));
    end = clock();
    printf("시간 소요: %f", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}

//재귀처럼 풀어보자.
//n이라는 숫자가 들어왔다면 이 숫자에 대한 해답은 n-1까지의 숫자개수 총 합에다가 n의 자리수를 합한 값이다.
int cnt_digit(int x){   //x라는 숫자가 들어오면 해당 수를 구성하는 숫자의 개수를 계산하여 반환.
    if(x<1) return 0;    //base case
    int cnt = 0, temp = x;
    while(temp){
        temp/=10;
        cnt++;              //x숫자에 대한 자리수를 카운팅
    }
    return cnt_digit(x-1) + cnt;
}
//드디어 풀었다 ㅠㅠ 감격스럽다...
//for문을 쓴다면..

int main(void){
    int n;
    scanf("%d",&n);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp){
            temp/=10;
            cnt++;
        }
    }

    return 0;
}
//헐 이렇게 간단한걸... ㅠㅠㅠㅠㅠㅠ 하


//강의 코드
#include <stdio.h>
int main(void){
    int n, i, cnt = 0, tmp;
    scanf("%d", n);
    for(i = 1; i <= n; i++){
        tmp = i;
        while(tmp>0){
            tmp = tmp/10;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
