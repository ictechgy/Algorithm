#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int parent[101];
int _size[101];

int Find(int v){
    while(v != parent[v]){
        parent[v] = parent[parent[v]];
        v = parent[v];
    }
    return v;
}

void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    if(_size[u] >= _size[v]){
        parent[v] = u;
        _size[u] += _size[v];
    }else{
        parent[u] = v;
        _size[v] += _size[u];
    }
}

bool compare(pair<int, pair<int, int> > &left, pair<int, pair<int, int> > &right){
    return left.first < right.first;
}

int main(void){
    int n, m, i, u, v, w, num = 0, cnt = 0;
    scanf("%d %d", &n, &m);
    vector<pair<int, pair<int, int> > > list;
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        list.push_back({w, {u, v}});
    }   
    sort(list.begin(), list.end(), compare);    //or use priority queue

    for(i = 1; i <= n; i++){
        parent[i] = i;
        _size[i] = 1;
    }
    
    i = 0;      //or vector iterator
    while(cnt < n-1){
        u = list[i].second.first;
        v = list[i].second.second;
        if(Find(u) != Find(v)){
            Union(u, v);
            num += list[i].first;
            cnt++;
        }
        i++;
    }
    printf("%d\n", num);

    return 0;
}

//
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int unf[10001];

struct Edge{
    int v1;
    int v2;
    int val;
    Edge(int a, int b, int c){
        v1 = a;
        v2 = b;
        val = c;
    }
    bool operator<(Edge &b){
        return val < b.val;
    }
};

int Find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) unf[a] = b;
}

int main(){
    vector<Edge> Ed;
    int i, n, m, a, b, c, cnt = 0, res = 0;
    scanf("%d %d", &n, &m);
    for(i = 1; i<= n; i++){
        unf[i] = i;
    }
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a, b, c));
    }
    sort(Ed.begin(), Ed.end());
    
    for(i = 0; i < m; i++){
        int fa = Find(Ed[i].v1);
        int fb = Find(Ed[i].v2);
        if(fa != fb){
            res += Ed[i].val;
            Union(Ed[i].v1, Ed[i].v2);
        }
    }
    printf("%d\n", res);

    return 0;
}