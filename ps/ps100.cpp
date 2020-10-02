#include <bits/stdc++.h>
using namespace std;

int dy[13][501];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> coins(n+1);
    for(int i = 1; i <= n; i++){
        cin >> coins[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) dy[0][i] = 2147000000;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j < coins[i]) dy[i][j] = dy[i-1][j];
            else dy[i][j] = min(dy[i-1][j], dy[i][j-coins[i]] + 1);
        }
    }
    cout << dy[n][m] << "\n";

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n;
    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin>>coin[i];
    cin>>m;
    vector<int> dy(m+1, 1000);
    dy[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = coin[i]; j <= m; j++){
            dy[j] = min(dy[j], dy[j-coin[i]] + 1);
        }
    }
    cout << dy[m];

    return 0;
}