//한 수 문제
#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);

    int count = 0;      // 한 수의 개수를 체크

    for(int i = 1; i <= num; num++){
        int oldGap, newGap;
        while(num){     //num을 234로 가정
            newGap = num % 10 - num/10%10;
            num /= 10;
        }
        if (num % 10 == num /10 % 10 == num / 100 % 10 == num / 1000 % 10)
    }


    return 0;
}