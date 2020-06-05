#include <stdio.h>

int main(void){
    int n, i, cnt_2 = 0, cnt_5 = 0, tmp;
    scanf("%d", &n);
    //굳이 n에 의한 값을 다 구해야 할까? 구한뒤에 10으로 나누기? 10의 승수만을 추출하는건?
    //10은 2 * 5이다. 각각 하나씩은 있어야 10을 하나 만들 수 있음
    for(i = 2; i <= n; i++){
        tmp = i;
        while(1){
            if(tmp % 2 == 0){
            cnt_2++;
            tmp = tmp / 2;
            }else if(tmp % 5 == 0){
                cnt_5++;
                tmp = tmp / 5;
            }else break;    
        }   //2와 5의 개수만을 수집.
    }
    printf("%d\n", (cnt_2 > cnt_5)? cnt_5 : cnt_2);
    
    return 0;
}

//일반적으로 5의 개수가 적으므로 5 인수 개수만 세어도 될 듯
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, i, j, tmp, cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for(i = 2; i <= n; i++){
        tmp = i;
        j = 2;
        while(1){
            if(tmp % j == 0){
                if(j == 2) cnt1++;
                else if(j == 5) cnt2++;
                tmp = tmp / j;
            }else j++;
            if(tmp == 1) break;
        }
    }
    if(cnt1 < cnt2) printf("%d\n", cnt1);
    else printf("%d\n", cnt2);

    return 0;
}