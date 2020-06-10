#include <stdio.h>

int main(void){
    int i, num, tmp, count = 0, gap, flag; //count - 한수의 개수를 체크, flag - 한수 여부
    scanf("%d", &num);

    for(i = 1; i <= num; i++){
        tmp = i;
        flag = 1;   //일단 한수라고 가정
        gap = tmp % 10 - ((tmp/10)%10); //1의 자리와 10의 자리 차이 계산
        tmp /= 10;      //한번 계산은 했으므로 10으로 나눔  
        while(tmp/10 != 0){    //모든 수에 대한 차이 계산 시 종료(한자리 숫자만 남게 되는 경우 더이상 계산할 필요가 없음)
            if(gap != tmp % 10 - ((tmp/10)%10)){
                flag = 0;
                break;
            }
            tmp /= 10;
        }
        if(flag) count++;
    }
    printf("%d\n", count);

    return 0;
}