#include <bits/stdc++.h>
using namespace std;

int Map[30][30], path[30][30];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> Map[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        path[1][i] = path[1][i-1] + Map[1][i];
        path[i][1] = path[i-1][1] + Map[i][1];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            path[i][j] = min(path[i][j-1], path[i-1][j]) + Map[i][j];
        }
    }

    cout << path[n][n] << "\n";

    return 0;
}   //or DFS, BFS?

//
#include <bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];
int main(){
    ios_base::sync_with_stdio(false);
    int n, cnt = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    dy[0][0] = arr[0][0];
    for(int i = 1; i < n; i++){
        dy[0][i] = dy[0][i-1] + arr[0][i];
        dy[i][0] = dy[i-1][0] + arr[i][0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dy[i][j] = min(dy[i-1][j], dy[i][j-1]) + arr[i][j];
        }
    }
    cout<<dy[n-1][n-1];

    return 0;
}