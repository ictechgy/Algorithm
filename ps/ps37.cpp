#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int s, n, i, tmp, idx, j;
    scanf("%d %d", &s, &n);
    vector<int> arr(s), hty(n);
    for(i = 0; i < n; i++){
        scanf("%d", &hty[i]);   //입력한 것을 다 일단 저장
    }
    idx = n-1;  //hty는 거꾸로 읽기
    for(i = 0; i < s; i++){ //s만큼만 arr에 넣을 것이다.
        for(j = 0; j < i; j++){ //arr에 기존 값이 있는지 체크
            if(arr[j] == hty[idx]) break;   //이미 추가된 값이라면 skip
        }
        if(i == j) arr[i] = hty[idx];   //추가되어있는 값이 아니라면 넣는다.
        else i--;   //이미 추가된 값이어서 스킵된 경우 i의 위치(넣는 위치)를 바꾸지 않게 하기 위함
        idx--;  //그 다음의 기록 보기
    }
    for(i = 0; i < s; i++){
        printf("%d ", arr[i]);
    }
    //접근방식을 다르게 해봤다. (문제에서 원하는게 이게 아니겠다만..)
    //번호를 모두 특정 배열에 저장시켜놓고 해당 배열을 거꾸로 읽으면서
    //사용 된 것을 역순으로 arr배열에 담는다. 담는 도중에 이미 나온 값이면 해당 값은 패스한다. 

    puts("");
    //정석..? sentinel
    scanf("%d %d", &s, &n);
    vector<int> ary(s+1);   //보초법을 쓰기 위해 공간 하나 +1
    for(i = 0; i < n; i++){
        scanf("%d", &ary[s]);   //맨 뒤 공간에 일단 넣는다. 
        for(j = 0; j <= s; j++){
            if(ary[j] == ary[s]) break; //같은 값이 있는지 찾는다.
        }
        tmp = ary[s];
        for(j = j-1; j >= 0; j--){  //찾은 값 바로 앞부터
            ary[j+1] = ary[j];
        }
        ary[0] = tmp;
    }
    for(i = 0; i < s; i++){
        printf("%d ", ary[i]);  //출력은 보초 전까지만. 
    }
    //보초법은 안쓸 수도 있을 것.
    
    return 0;
}

//
#include <stdio.h>
int C[20];
int main(){
    int s, n, a, i, j, pos;
    scanf("%d %d", &s, &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a);
        pos = -1;
        for(j = 0; j < s; j++) if(C[j] == a) pos = j;
        if(pos == -1){
            for(j = s-1; j >= 1; j--) C[j] = C[j-1];
        }else {
            for(j = pos; j >= 1; j--) C[j] = C[j-1];
        }
        C[0] = a;   //C[j] = a;
    }
    for(i = 0; i < s; i++) printf("%d ", C[i]);

    return 0;
}