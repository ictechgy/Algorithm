#include <stdio.h>
#include <time.h>

int main(void){
    int n, i, cnt = 0, tmp;
    clock_t start, end;
    scanf("%d", &n);
    //3이라는 값을 아스키코드적으로 처리하여 셈하거나..
    //3이 등장하는 것은 3, 3x, 3xx 등이니 그 규칙성을 따져보거나..
    //10으로 나누어보면서 셈하거나..?
    start = clock();
    for(i = 1; i <= n; i++){
        tmp = i;
        while(tmp){
            if(tmp % 10 == 3) cnt++;
            tmp /= 10;
        }
    }
    end = clock();
    printf("%d\n", cnt);
    printf("소요시간: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    //1자리 수 중 3은 1번, 2자리 수에서는 3이 9 + 10번(1의 자리수에서 9번, 30번대 10개. 33은 중복하여)
    //100의 자리에서는 (9 + 10)*9 + 100
    //기존 값에다가 9를 곱하고 10의 승수를 더하는 느낌이다. 100의 자리에서는 300번대가 100번.. 1000에서는 3000대 있으므로 1000번..
    
    //12345라고 들어오면 9999까지의 개수는 바로 구하고.. 10000 ~ 12345를 구하는 부분이 문제이다.

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, tmp, i, cnt = 0, digit;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        tmp = i;
        while(tmp > 0){
            digit = tmp % 10;
            if(digit == 3) cnt++;
            tmp = tmp / 10;
        }
    }
    printf("%d\n", cnt);

    return 0;
}//12345 입력 시 4721개