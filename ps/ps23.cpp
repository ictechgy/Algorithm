#include <stdio.h>
#include <limits.h>

int main(void){
    int n, pre = INT_MIN, i, now, cnt = 0, max = 0;
    freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    //vector 사용가능할듯
    for(i = 0; i < n; i++){
        scanf("%d", &now);
        if(now >= pre) {
            cnt++;
            if(cnt > max) max = cnt;    //즉시 반영 - 맨 마지막까지의 값이 가장 클 수도 있으므로
        }else{
            cnt = 1;    //현재 입력받은 값부터 다시 카운트 시작
        }
        pre = now;  //최신 값 반영
    }
    printf("%d\n", max);

    return 0;
}

//
#include <stdio.h>
int main(){
    int n, i, pre, now, cnt, max;
    scanf("%d", &n);
    scanf("%d", &pre);
    cnt = 1;
    max = 1;
    for(i = 2; i <= n; i++){
        scanf("%d", &now);
        if(now >= pre){
            cnt++;
            if(cnt > max) max = cnt;
        }
        else cnt = 1;
        pre = now;
    }
    printf("%d\n", max);

    return 0;
}