#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, arr[10], cnt = 0;

void DFS(int l, int sum){
    if(l >= n){
        if(sum == m) cnt++;
        return;
    }
    DFS(l+1, sum + arr[l]);
    DFS(l+1, sum);
    DFS(l+1, sum - arr[l]);
}

int main(void){
    int i;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    DFS(0, 0);
    if(cnt != 0) printf("%d\n", cnt);
    else printf("-1\n");

    return 0;
}

//
#include <stdio.h>

int a[11], n, m, cnt = 0, path[11];

void DFS(int L, int val){
    if(L == n+1){
        if(val == m) {
            cnt++;
            for(int i = 1; i < L; i++){
                printf("%d ", path[i]);
            }
            puts("");
        }
    }else{
        path[L] = a[L];
        DFS(L+1, val + a[L]);

        path[L] = -a[L];
        DFS(L+1, val - a[L]);

        path[L] = 0;
        DFS(L+1, val);
    }
}

int main(){
    int i;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    DFS(1, 0);
    if(cnt == 0) printf("-1\n");
    else printf("%d\n", cnt);

    return 0;
}
