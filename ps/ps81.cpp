#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    int n, m, i, u, v, w, s, e, j, k, next, cost;
    vector<pair<int, int> > map[101];
    cin>>n>>m;
    vector<int> d(n+1, 2147000000);
    for(i = 1; i <= m; i++){
        cin>>u>>v>>w;
        map[u].push_back(make_pair(v, w));
    }
    cin>>s>>e;
    
    d[s] = 0;
    for(i = 1; i <= n-1; i++){
        for(j = 1; j <= n; j++){
            for(k = 0; k < map[j].size(); k++){
                next = map[j][k].first;
                cost = map[j][k].second;
                if(d[next] > d[j] + cost){
                    d[next] = d[j] + cost;
                }
            }
        }
    }

    for(j = 1; j <= n; j++){
        for(k = 0; k < map[j].size(); k++){
            next = map[j][k].first;
            cost = map[j][k].second;
            if(d[next] > d[j] + cost){
                printf("-1\n");
                exit(1);
            }
        }
    }

    printf("%d\n", d[e]);

    return 0;
}

//
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dist[101];
struct Edge{
    int s;
    int e;
    int val;
    Edge(int a, int b, int c){
        s = a;
        e = b;
        val = c;
    }
};

int main(){
    vector<Edge> Ed;
    int i, n, m, a, b, c, j, s, e;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a, b, c));
    }
    scanf("%d %d", &s, &e);
    dist[s] = 0;
    for(i = 1; i < n; i++){
        for(j = 0; j < Ed.size(); j++){
            int u = Ed[j].s;
            int v = Ed[j].e;
            int w = Ed[j].val;
            if(dist[u] != 2147000000 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(j = 0; j < Ed.size(); j++){
        int u = Ed[j].s;
        int v = Ed[j].e;
        int w = Ed[j].val;
        if(dist[u] != 2147000000 && dist[u] + w < dist[v]){
            printf("-1\n");
            exit(0);
        }
    }
    printf("%d\n", dist[e]);
    
    return 0;
}