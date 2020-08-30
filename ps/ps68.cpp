#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > adj[30];
int n, charge = 2147000000, ck[30];

void DFS(int v, int cost){
    int i, next, weight;
    if(v == n && cost < charge) charge = cost;
    else{
        for(i = 0; i < adj[v].size(); i++){
            next = adj[v][i].first;
            weight = adj[v][i].second;
            if(ck[next] == 0){
                ck[next] = 1;
                DFS(next, cost + weight);
                ck[next] = 0;
            }
        }
    }
}

int main(void){
    int i, m, u, v, w;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
    }
    ck[1] = 1;
    DFS(1, 0);
    printf("%d\n", charge);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;

vector<pair<int, int> > map[30];
int ch[30], n, cost = 2147000000;

void DFS(int v, int sum){
    int i;
    if(v == n){
        if(sum < cost) cost = sum;
    }else{
        for(i = 0; i < map[v].size(); i++){
            if(ch[map[v][i].x] == 0){
                ch[map[v][i].x] == 1;
                DFS(map[v][i].x, sum + map[v][i].y);
                ch[map[v][i].x] == 0;
            }
        }
    }
}

int main(){
    int m, i, a, b, c;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b, c));
    }
    ch[1] = 1;
    DFS(1, 0);
    printf("%d\n", cost);

    return 0;
}
