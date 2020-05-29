#include <stdio.h>
#include <limits.h>

int digit_sum(int);

int main(void){
    int n, su, max = INT_MIN, res = INT_MIN, digit_res;
    scanf("%d", &n);
    for(int i = 1; i<= n; i++){
        scanf("%d", &su);
        digit_res = digit_sum(su);
        if(digit_res > max){
            max = digit_res;
            res = su;   
        }else if(digit_res == max && su > res) res = su;
    }
    printf("%d\n", res);

    return 0;
}

int digit_sum(int x){
    int sum = 0;
    while(x){
        sum += x%10;
        x = x/10;
    }
    return sum;
}

//강의코드
#include <stdio.h>
int digit_sum(int x){
    int tmp, sum = 0;
    while(x > 0){
        tmp = x % 10;
        sum += tmp;
        x = x/10;
    }
    return sum;
}

int main(void){
    int n, num, i, sum, max = -2147000000, res;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        sum = digit_sum(num);
        if(sum > max){
            max = sum;
            res = num;
        }
        else if(sum == max){
            if(num > res) res = num;
        }
    }
    printf("%d\n", res);

    return 0;
}