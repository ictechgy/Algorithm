#include <stdio.h>

int parent[1001];
int _size[1001];

int _find(int node){
    while(node != parent[node]){
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    //또는 반복문을 다시 돌면서 모든 개별 하위노드를 바로 최상위 부모노드에 붙이는 방식도 있다.
    return node;
}

void _union(int u, int v){
    int v1 = _find(u);
    int v2 = _find(v);
    if(_size[v1] >= _size[v2]){
        parent[v2] = v1;
        _size[v1] += _size[v2];
    }else{
        parent[v1] = v2;
        _size[v2] += _size[v1];
    }
}

int main(void){
    int n, m, i, u, v;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++){
        parent[i] = i;
        _size[i] = 1;
    }
    for(i = 1; i <= m; i++){
        scanf("%d %d", &u, &v);
        if(_find(u) != _find(v)) _union(u, v);
    }
    scanf("%d %d", &u, &v);
    if(_find(u) == _find(v)) printf("YES\n");
    else printf("NO\n");

    return 0;
}

//
#include <iostream>
using namespace std;
int unf[1001];

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
    ios_base::sync_with_stdio(false);
    int n, m, a, b;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }
    for(int i = 1; i <= m; i++){
        cin>>a>>b;
        Union(a, b);
    }
    cin>>a>>b;
    a = Find(a);
    b = Find(b);
    if(a == b) cout<<"YES";
    else cout<<"NO";

    return 0;
}