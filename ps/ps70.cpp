#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, ck[30], d[30];
vector<int> adj[30];

int main(void){
    int m, u, v, i;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    queue<int> q;
    q.push(1);
    ck[1] = 1;
    d[1] = 0;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(i = 0; i < adj[v].size(); i++){
            if(ck[adj[v][i]] == 0){
                ck[adj[v][i]] = 1;
                d[adj[v][i]] = d[v] + 1;
                q.push(adj[v][i]);
            }
        }
    }
    for(i = 2; i <= n; i++){
        printf("%d : %d\n", i, d[i]);
    }

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ch[30], dis[30];

int main(){
    int n, m, a, b, x, i;
    vector<int> map[30];
    queue<int> Q;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
    }
    Q.push(1);
    ck[1] = 1;
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        for(i = 0; i < map[x].size(); i++){
            if(ch[map[x][i]] == 0){
                ch[map[x][i]] = 1;
                Q.push(map[x][i]);
                dis[map[x][i]] = dis[x] + 1;
            }
        }
    }
    for(i = 2; i <= n; i++){
        printf("%d : %d\n", i, dis[i]);
    }

    return 0;
}