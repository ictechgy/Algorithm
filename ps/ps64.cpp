#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int adj[21][21], cnt = 0, n;
bool ck[21];
int path[21], p = 1;

void DFS(int v){
    ck[v] = true;
    path[p++] = v;
    if(v == n) {
        for(int r = 1; r < p; r++) printf("%d ", path[r]);
        puts("");
        cnt++;
        ck[v] = false;
        p--;
        return;
    }
    int i;
    for(i = 1; i <= n; i++){
        if(adj[v][i] != 0 && !ck[i]) DFS(i);
    }
    ck[v] = false;
    p--;
}

int main(void){
    int m, i, j, k;
    scanf("%d %d", &n, &m);
    for(k = 1; k <= m; k++){
        scanf("%d %d", &i, &j);
        adj[i][j] = 1;
    }
    DFS(1);
    printf("%d\n", cnt);

    return 0;
}

//
#include <stdio.h>
int map[30][30], ch[30], cnt = 0, n;

void DFS(int v){
    int i;
    if(v == n){
        cnt++;
    }else{
        for(i = 1; i <= n; i++){
            if(map[v][i] == 1 && ch[i] == 0){
                ch[i] = 1;
                DFS(i);
                ch[i] = 0;
            }
        }
    }
}

int main(){
    int m, i, a, b;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    ch[1] = 1;
    DFS(1);
    printf("%d\n", cnt);

    return 0;
}