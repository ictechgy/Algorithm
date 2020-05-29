#include <stdio.h>
#include <math.h>

int reverse(int);
bool isPrime(int);

int main(void){
    int n, su, reversed;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &su);
        reversed = reverse(su);
        if(isPrime(reversed)) printf("%d ", reversed);
    }
    printf("\n");

    return 0;
}

int reverse(int origin){   //숫자를 받아 뒤집는 함수 ex) 32 -> 23
    int reversed = 0;
    int tmp = origin;
    while(tmp){
        reversed = reversed * 10 + tmp % 10;
        tmp = tmp / 10;
    }
    return reversed;
}
bool isPrime(int num){  //해당 숫자가 소수인지 판단
    if(num == 2) return true;  //소수중에 짝수는 2밖에 없다. 숫자가 2면 바로 소수라고 반환
    if(num % 2 == 0) return false; //2로 나누어진다면 소수가 아님. false 반환
    for(int i = 3; i <= sqrt(num); i+=2 ){  //이외의 수는 홀수로 나누어지는지 판단한다. 
        if(num % i == 0) return false;
    }
    return true;
}

//강의 코드
#include <stdio.h>
int reverse(int x){
    int res = 0, tmp;
    while(x > 0){
        tmp = x % 10;
        res = res * 10 + tmp;
        x = x / 10;
    }
    return res;
}
bool isPrime(int x){
    int i;
    if(x == 1) return false; //1은 소수가 아니다. 이 부분에 유의. 
    bool flag = true;
    for(i = 2; i < x; i++){
        if(x % i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}
int main(){
    int n, num, i, tmp;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &num);
        tmp = reverse(num);
        if(isPrime(tmp)) printf("%d ", tmp);
    }

    return 0;
}