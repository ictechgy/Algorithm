#include <stdio.h>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
int main(){
    clock_t start, end;
    int n, cnt = 0, digit = 0, tmp, i, div, lt, rt, ct;    //left, right, center
    scanf("%d", &n);
    tmp = n;
    start = clock();
    while(tmp > 0){
        tmp /= 10;
        digit++;    //자리수 카운팅
    }
    for(i = 1, div = 1; i <= digit; i++, div *= 10){
        rt = n % div;   //오른쪽 수
        lt = n / (div * 10);    //왼쪽 수
        ct = (n / div) % 10;  //기준 수
        
        if(ct > 3){
            cnt += (lt + 1) * div;
        }else if(ct == 3){
            cnt += lt * div + rt + 1;
        }else{  //ct < 3       - 예를 들어 12222
            cnt += lt * div;
        }
    }
    end = clock();
    printf("%d\n", cnt);
    printf("소요시간: %f\n", (double)(end - start)/CLOCKS_PER_SEC); //굉장히 빠르다. 

    return 0;
}

//
#include <stdio.h>
int main(){
    int n, lt = 1, rt, cur, k = 1, res = 0;
    scanf("%d", &n);
    while(lt != 0){
        lt = n / (k * 10);
        rt = n % k;
        cur = (n / k) % 10;
        if(cur > 3){
            res = res + ((lt + 1) * k);
        }else if(cur == 3){
            res = res + ((lt * k) + (rt + 1));
        }else{
            res = res + (lt * k);
        }
        k = k * 10;
    }
    printf("%d\n", res);

    return 0;
}