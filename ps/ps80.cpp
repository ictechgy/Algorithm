#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define UNREACHABLE 2147000000

typedef struct data{
    int v;
    int d;
    data(int v, int d){
        this->v = v;
        this->d = d;
    }
    bool operator<(const data &o)const{
        return d > o.d;
    }
} DATA;     //or use 'pair' data structure

int main(void){
    int n, m, i, u, v, w, cnt = 0;
    scanf("%d %d", &n, &m);
    vector<pair<int, int> > map[n+1];
    vector<int> d(n+1);
    vector<int> pred(n+1);
    vector<bool> ck(n+1, false);
    priority_queue<DATA> pQ;
    
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        map[u].push_back(make_pair(v, w));
    }

    for(i = 1; i <= n; i++){
        d[i] = UNREACHABLE;
        pred[i] = i;    //default
    }
    
    d[1] = 0;
    pQ.push(DATA(1, d[1]));
    while(!pQ.empty()/* cnt < n */){
        u = pQ.top().v;
        pQ.pop();
        if(ck[u] == false){
            ck[u] = true;
            cnt++;
            for(i = 0; i < map[u].size(); i++){
                v = map[u][i].first;
                w = map[u][i].second;
                if(ck[v] == false && d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    pred[v] = u;
                    pQ.push(DATA(v, d[v]));
                }
            }
        }
    }
    for(i = 2; i <= n; i++){
        printf("%d : ", i);
        if(d[i] == UNREACHABLE) printf("impossible\n");
        else printf("%d\n", d[i]);
    }

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    bool operator<(const Edge &b)const{
        return dis > b.dis;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    priority_queue<Edge> Q;
    vector<pair<int, int> > graph[30];
    int i, n, m, a, b, c;
    cin>>n>>m;
    vector<int> dist(n+1, 2147000000);
    for(i = 1; i <= m; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b, c));
    }
    Q.push(Edge(1, 0));
    dist[1] = 0;
    while(!Q.empty()){
        int now = Q.top().vex;
        int cost = Q.top().dis;
        Q.pop();
        if(cost > dist[now]) continue;
        for(i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].first;
            int nextDis = cost + graph[now][i].second;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                Q.push(Edge(next, nextDis));
            }
        }
    }
    for(i = 2; i <= n; i++){
        if(dist[i] != 2147000000) cout<<i<<" : "<<dist[i]<<endl;
        else cout<<i<<" : impossible"<<endl;
    }

    return 0;
}