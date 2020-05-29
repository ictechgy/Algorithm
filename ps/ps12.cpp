//ps11.cpp의 large 숫자 버전.. 
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void){
    /*
    int n;
    scanf("%d", &n);

    int arr[10] = {0};  //각 자리 숫자가 얼마나 쓰였는지 측정할 배열
    for(int i = 1; i <= n; i++){
        int tmp = i;
        while(tmp){
            arr[tmp%10]++;
            tmp/=10;
        }
    }
    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += arr[i];
    }
    printf("%d\n", sum);
    //100,000,000 입력시 너무 늦게 나온다. 그리고 굳이 각 자리 수가 몇개가 쓰였는지 알아야 하나? 
    */
   
    //945가 들어왔다고 치자. 이 숫자는 3글자이다. 100 ~ 945의 세글자와 10 ~ 99의 두글자, 1 ~ 9의 한글자로 이루어졌을 것이다.
    //개수는 9개 90개 900개 순서로 증가한다. (각 자리수에 해당하는 수들의 개수)
    //이 경우 총 개수는 9 * 1, 90 * 2, 900 * 3이 된다. 
    int n;
    scanf("%d", &n);

    clock_t start, end;
    start = clock();

    int digit = 0;
    int temp = n;
    while(temp){
        digit++;
        temp/=10;
    }//n이 몇자리 수인지 체크한다.

    int cnt = 0;
    for(int i = 1; i < digit; i++){ //i는 자리수를 의미
        cnt += 9 * pow(10, i-1) * i;
    }
    //마지막으로 자리수에 해당하는 수들의 총 합을 구해야 한다.
    int num = n - pow(10, digit-1) + 1;
    cnt += num * digit;
    end = clock();
    printf("%d\n", cnt); //빠르게 잘 구해진다. 
    printf("소요시간: %f\n", (double)(end - start)/CLOCKS_PER_SEC);     //0.000017초 소요

    return 0;
}

//강의 코드
#include <stdio.h>

int main(void){
    /*
    1자리 숫자는 1 ~ 9의 9개
    2자리 숫자는 10 ~ 99의 90개
    3자리 숫자는 100 ~ 999의 900개

    256이라는 숫자가 들어왔다면 1 ~ 256까지의 숫자가 사용된 것이다.
    1의 자리 수 중에서 가장 큰 수인 9는 이보다 작다. -> 9개 누적 (1 * 9)
    10의 자리 수 중에서 가장 큰 수 99는 이보다 작다. -> 90개 추가 누적 (실제로는 2 * 90)
    100의 자리 수 999는 256보다는 크다. 따라서 세자리 숫자는 따로 구한다.
    이미 99까지를 셈했으므로 256 - 99 = 157, 157 * 3을 누적합시킨다. 
    */
    int n, sum = 0, c = 1, d = 9, res = 0;
    scanf("%d", &n);
    while(sum + d < n){
        res = res + (c * d);
        sum = sum + d;          //sum은 몇번째 수까지 셈했다 이런 의미인듯
        c++;    //다음 자리 수의 자리 수
        d = d * 10; //다음 자리 수의 총 개수
    }
    res = res + ((n - sum) * c);
    printf("%d\n", res);

    return 0;
}