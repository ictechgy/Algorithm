#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int> > Map(n+1, vector<int>(n+1));
    vector<int> in_degree(n+1, 0);
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        Map[u][v] = 1;
        in_degree[v]++;
    }
    
    int cnt = n;
    while(cnt > 0){
        for(int i = 1; i <= n; i++){
            if(in_degree[i] == 0){
                cout << i << " ";
                cnt--;
                in_degree[i] = -1;
                for(int j = 1; j <= n; j++){
                    if(Map[i][j] == 1){
                        Map[i][j] = 0;
                        in_degree[j]--;
                    }
                }
            }
        }
    }

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n, m, a, b, score;
    cin>>n>>m;
    vector<vector<int> > graph(n+1, vector<int>(n+1, 0));
    vector<int> degree(n+1);
    queue<int> Q;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        graph[a][b] = 1;
        degree[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0) Q.push(i);
    }
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        cout<<now<<" ";
        for(int i = 1; i <= n; i++){
            if(graph[now][i] == 1){
                degree[i]--;
                if(degree[i] == 0) Q.push(i);
            }
        }
    }

    return 0;
}