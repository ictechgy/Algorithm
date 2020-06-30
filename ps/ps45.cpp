#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, k, i, cnt, idx = 0;
    scanf("%d %d", &n, &k);
    //3의 배수로 돌아가는 것은 당연(사라지는 곳 고려).. 원형 Linked List방식으로 푸는 것도 가능할 것 같음. or 링형 큐?
    vector<int> arr(n, 1); //0번 인덱스부터 시작, 초기값은 1
    
    for(i = 0; i < n - 1; i++){ //n-1회 반복
        cnt = 0;
        while(cnt < k){
            if(arr[idx] != 0){
                cnt++;
                if(cnt == k){
                    arr[idx] = 0;
                    //break;    //조건식이 cnt <= k 라면 이 위치에 break문이 꼭 있어야 함. 
                }
            }
            ++idx %= n;
        }
    }
    for(i = 0; i < n; i++){
        if(arr[i] != 0){
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, k, pos = 0, bp = 0, cnt = 0, i;
    scanf("%d %d", &n, &k);
    vector<int> prince(n+1);
    while(1){
        pos++;
        if(pos > n) pos = 1;
        if(prince[pos] == 0){
            cnt++;
            if(cnt == k) {
                prince[pos] = 1;
                cnt = 0;
                bp++;
            }
        }
        if(bp == n-1) break;
    }
    for(i = 1; i <= n; i++){
        if(prince[i] == 0){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}