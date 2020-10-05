#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u, v;
    cin >> n;
    vector<vector<int> > Map(n+1, vector<int>(n+1, 50));
    for(int i = 1; i <= n; i++) Map[i][i] = 0;
    while(1){
        cin >> u >> v;
        if(u == -1 && v == -1) break;
        Map[u][v] = 1;
        Map[v][u] = 1;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
            }
        }
    }
    
    vector<int> dist(n+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i] = max(dist[i], Map[i][j]);
        }
    }

    int minimum = 2147000000;
    for(int i = 1; i <= n; i++){
        if(minimum > dist[i]) minimum = dist[i];
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(minimum == dist[i]) cnt++;
    }

    cout << minimum << " " << cnt << "\n";

    for(int i = 1; i <= n; i++){
        if(dist[i] == minimum) cout << i << " ";
    }
    cout << "\n";

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, a, b, score;
    cin>>n;
    vector<vector<int> > dis(n+1, vector<int>(n+1, 100));
    vector<int> res(n+1);
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    while(true){
        cin>>a>>b;
        if(a == -1 && b == -1) break;
        dis[a][b] = 1;
        dis[b][a] = 1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    score = 100;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<dis[i][j]<<" ";
            res[i] = max(res[i], dis[i][j]);
        }
        cout<<endl;
        score = min(score, res[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(res[i] == score) cnt++;
    }

    cout<<score<<" "<<cnt<<endl;
    for(int i = 1; i <= n; i++){
        if(res[i] == score) cout<<i<<" "; 
    }

    return 0;
}