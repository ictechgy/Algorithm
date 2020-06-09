#include <stdio.h>

int main(void){
    int n, arr[101] = {0}, i, tmp, idx, cnt, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){ //index 0은 쓰지 않는다. 
        //i가 넣으려는 숫자이면서 동시에 입력순서이기도 하다.
        scanf("%d", &tmp);
        idx = 1;
        cnt = 0; //해당 수 이전에 이미 값이 들어간 것들 카운팅
        for(j = idx; j <= idx+tmp+cnt; j++){
            if(arr[j] != 0) cnt++;
        }
        idx = idx + tmp + cnt;  //값이 들어갈 위치의 인덱스
        arr[idx] = i;
    }
    for(i = 1; i <= n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0; 
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, i, j, pos;
    scanf("%d", &n);
    vector<int> s(n+1), os(n+1);
    for(i = 1; i <= n; i++){
        scanf("%d", &s[i]);
    }
    for(i = n; i >= 1; i--){
        pos = i;
        for(j = 1; j <= s[i]; j++){
            os[pos] = os[pos+1];
            pos++;
        }
        os[pos] = i;
    }
    for(i = 1; i <= n; i++){
        printf("%d ", &os[i]);
    }

    return 0;
}