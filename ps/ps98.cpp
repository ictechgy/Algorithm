#include <bits/stdc++.h>
using namespace std;

int Map[30][30], path[30][30];

int calc(int i, int j){
    if(path[i][j] != 0) return path[i][j];
    else if(i == 1){
        return path[i][j] = calc(i, j-1) + Map[i][j];
    }else if(j == 1){
        return path[i][j] = calc(i-1, j) + Map[i][j];
    }else{
        return path[i][j] = min(calc(i-1, j), calc(i, j-1)) + Map[i][j];
    }
}

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
    path[1][1] = Map[1][1];
    cout << calc(n, n) << "\n";

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];

int DFS(int x, int y){
    if(dy[x][y] > 0) return dy[x][y]; 
    if(x == 0 && y == 0) return arr[0][0];
    else{
        if(y == 0) return dy[x][y] = DFS(x-1, y) + arr[x][y];
        else if(x == 0) return dy[x][y] = DFS(x, y-1) + arr[x][y];
        else return dy[x][y] = min(DFS(x-1, y), DFS(x, y-1)) + arr[x][y];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<DFS(n-1, n-1);

    return 0;
}