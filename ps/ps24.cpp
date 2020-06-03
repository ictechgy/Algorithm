#include <stdio.h>
#include <vector>

using namespace std;

int main(void){
    int n, i, pre, now, gap;
    scanf("%d", &n);
    vector<int> arr(n, 1);  //n개의 공간을 1의 값으로 초기화 - 인덱스 값에 해당하는 차이가 발생했는지 확인용
    //0번 인덱스는 쓰지 않으며 1 ~ n-1의 인덱스만을 사용한다. 해당 차이가 발생한 경우 인덱스의 공간 값을 0으로
    scanf("%d", &pre);  //첫 값은 우선 읽는다.
    for(i = 2; i <= n; i++){    //n-1번 추가 읽기
        scanf("%d", &now);
        gap = pre - now;
        if(gap < 0) gap *= -1; //절대값으로 변경
        arr[gap]--; //해당 차이는 사용되었습니다.
        pre = now;
    }

    for(i = 1; i < n; i++){ //0번 인덱스는 무시한다. 
        if(arr[i]) break;
    }
    if(i == n) printf("YES\n");
    else printf("NO\n");

    return 0;
}

//굳이 차이 값을 확인하여 배열에 반영하고, 나중에 한번에 순차탐색으로 확인할 필요 X
//도중에 하나라도 2번 이상 나오거나 값의 차이 허용범위를 넘는 때에 바로 중지 가능
#include <stdio.h>
#include <vector>
#include <algorithm>    //각종 함수 포함 - abs() 등
using namespace std;
int main(){
    int n, i, now, pre, pos;
    scanf("%d", &n);
    vector<int> ck(n);  //모든 인덱스의 값 기본 0으로 초기화
    scanf("%d", &pre);
    for(i = 1; i < n; i++){
        scanf("%d", &now);
        pos = abs(pre - now);
        if(pos > 0 && pos < n && ck[pos] == 0) ck[pos] = 1; //if문의 논리식 순서에 유의한다. ck[pos]가 맨 앞에 존재하면 참조 오류 생길 수 있다.
        else{
            printf("NO\n");
            return 0;
        }
        pre = now;
    }
    printf("YES\n");

    return 0;
}