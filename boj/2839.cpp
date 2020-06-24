#include <stdio.h>

int main(void){
    int n, cnt5 = 0, cnt3 = 0, remain;
    scanf("%d", &n);
    
    cnt5 = n / 5;   //일단 5kg대로 최대한 채워본다.
    remain = n % 5; //남은 kg 수
    while(1){
        if(remain % 3 == 0){
            cnt3 = remain / 3;  //남은 무게가 3의 배수로 메꿔지면 break
            break;
        }
        cnt5 -= 1;  //남은 것이 3의 배수로 안나눠지면 5kg을 하나 내려놓는다.
        remain += 5;    //남은 무게에 5추가
        if(cnt5 == -1){ //cnt5가 -1이라는 것은 5kg을 하나도 들지않았는데 3kg으로도 목표무게를 채울 수 없음을 뜻한다.
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", cnt5 + cnt3);
    
    return 0;
}