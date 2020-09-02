#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    int n, k, i, cnt = 0, num;
    queue<int> que;
    scanf("%d %d", &n, &k);
    for(i = 1; i <= n; i++){
        que.push(i);
    }
    while(que.size() > 1){
        num = que.front();
        que.pop();
        cnt++;
        if(cnt == k) cnt = 0;
        else que.push(num);
    }
    printf("%d\n", que.front());

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n, k, i;
    queue<int> Q;
    scanf("%d %d", &n, &k);
    for(i = 1; i <= n; i++){
        Q.push(i);
    }
    while(!Q.empty()){
        for(i = 1; i < k; i++){
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
        if(Q.size() == 1){
            printf("%d\n", Q.front());
            Q.pop();
        }
    }

    return 0;
}