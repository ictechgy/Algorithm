#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, i;
bool include[11] = {false, };

void powerset(int e){
    if(e > n){
        for(i = 1; i <= n; i++){
            if(include[i]) printf("%d ", i);
        }
        printf("\n");
        return;
    }
    include[e] = false;
    powerset(e+1);
    include[e] = true;
    powerset(e+1);
}

int main(void){
    scanf("%d", &n);
    powerset(1);

    return 0;
}

//멱집합인데 재귀이기도 하고 완전탐색부류이기도 하다. 상태공간트리에서 원하는 해인 종단노드까지 찾아가는 문제

//
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, ch[11];
void DFS(int L){
    int i;
    if(L == n+1){
        for(i = 1; i <= n; i++){
            if(ch[i] == 1) printf("%d ", i);
        }
        puts("");
    }else{
        ch[L] = 1;
        DFS(L+1);
        ch[L] = 0;
        DFS(L+1);
    }
}

int main(){
    scanf("%d", &n);
    DFS(1);

    return 0;
}