#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, i, ps, pe, sum = 0, cnt = 0;   //point to start, point to end
    scanf("%d", &n);

    pe = n/2 + 1;
    ps = pe - 1;
    //연속으로 수 합해서 원하는 값이 나오는 경우 -> 최대 절반+1까지만 pe를 보면 됨.
    while(1 < pe){  //ps가 1, pe가 2인 경우가 마지막

        //sum을 for문으로 돌리지 않고 가우스식을 써보자.
        sum = (ps + pe) * (pe - ps + 1) / 2;
        if(sum == n){
            for(i = ps; i < pe; i++) printf("%d + ", i);
            printf("%d = %d\n", pe, n);
            cnt++;
            ps--;
            pe--;
            //찾은 상태에서 ps만 --하는건 의미가 없고(sum이 커지므로)
            //pe를 하나 내린 상태에서 ps를 내려가며 재탐색하면서 값을 더 찾아야함
            //당연히 ps도 --하는게 맞을 듯. pe를 1 내렸으면 당연히 그만큼 ps는 더 내려가야 함.
        }else if(sum > n){  //값이 더 커져버린 경우 -> 해당 pe로는 만들 수 없음
            pe--;
            //ps = pe - 1;
            //굳이 ps를 pe 왼쪽으로 옮길 필요는 없어보임. 값을 초과해서 pe를 내렸다면 그만큼 ps는 더 왼쪽으로 가줘야 하므로
        }else ps --;    //sum < n   -> sum이 작으면 ps를 내려서 sum값을 증가시키기
        
        if(ps == 0){    //sum이 계속 작아서 ps를 계속 내렸는데 0이 된다면 
            // pe--;
            // ps = pe - 1;
            break;  //종료해도 됨. 이후에 더 찾아봤자 의미가 없을 듯
        }
    }
    printf("%d\n", cnt);

    return 0;
}

//다른 방식으로 풀어보면.. 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, sub, i, j, tmp, val, k, cnt = 0;
    scanf("%d", &n);
    for(i = 2; i < n; i++){ //2개짜리 ~ n-1개짜리
        sub = 0;
        for(j = 1; j < i; j++) sub+=j;  //sub는 빼려는 수
        if(sub >= n) break; 
        tmp = n - sub;
        if(tmp % i == 0){
            val = tmp / i;  //기준 값 획득
            for(k = 0; k < i - 1; k++){
                printf("%d + ", val + k);
            }
            printf("%d = %d\n", val + k, n);
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a, b = 1, cnt = 0, tmp, i; 
    scanf("%d", &a);
    tmp = a;
    a--;
    while(a>0){
        b++;
        a = a - b;
        if(a % b == 0){
            for(i = 1; i < b; i++){
                printf("%d + ", (a / b) + i);
            }
            printf("%d = %d\n", (a / b) + i, tmp);
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}