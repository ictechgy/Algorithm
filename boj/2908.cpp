#include <stdio.h>

int main(void){
    int n, m, big;
    scanf("%d %d", &n, &m);
    //입력받은 수를 10으로 나누면서 수를 뒤집고 그 이후에 변환된 두 수를 비교할 수도 있을 것이다. 
    if(n % 10 > m % 10){    //1의 자리 수를 비교하여 큰 수가 -> 뒤집었을 때 큰 수이다.
        big = n;
    }else if(n % 10 < m % 10){
        big = m;
    }else{  //1의 자리 수가 동일한 경우 두번째 자리 수 비교
        if(n/10%10 > m/10%10) big = n;
        else if(n/10%10 < m/10%10) big = m;
        else{   //두번째 자리수까지 같다면 세번째 자리 수 비교
            if(n/100 > m/100) big = n;
            else big = m;
        }   //세번째 수 까지 같은 경우는 없음
    }
    //여기까지 오면 큰 수가 정해짐
    printf("%d%d%d\n", big%10, big/10%10, big/100); //역순출력

    return 0;
}