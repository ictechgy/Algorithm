#include <stdio.h>

int main(void){
    int fix, var, price, num = 0, sum = 0, benefit = 0;
    scanf("%d %d %d", &fix, &var, &price);
    
    if(var >= price){
        printf("-1\n"); //하나 만드는데 이익보다 비용이 같거나 더 크면 손익분기점을 갈 수 없음
        return;
    }
    sum = fix;  //고정비용 추가
    while(1){
        num++;  //한대 생산
        sum += var; //한대에 대한 가변비용 추가
        benefit += price; //한대에 대한 이익 추가
        if(benefit > sum) break;
    }
    printf("%d\n", num);

    return 0;
}
//위와같이 해도 되지만..
#include <stdio.h>

int main(void){
    int fix, var, price, num;
    scanf("%d %d %d", &fix, &var, &price);
    //한대를 생산할 때 발생하는 이익은 price - var이다.
    //그 이익이 고정비용을 넘기기만 하면 된다.
    if(var >= price){
        printf("-1\n");
    }else{
        num = (int)((double)fix / (price - var) + 1);
        printf("%d\n", num);
    }

    return 0;
}