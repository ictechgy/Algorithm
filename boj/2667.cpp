#include <bits/stdc++.h>
using namespace std;

int Map[30][30], n, cnt = 0, area;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> district;

void DFS(int x, int y){
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && xx < n && y >= 0 && yy < n && Map[xx][yy] == 1){
            area++;
            Map[xx][yy] = 0;
            DFS(xx, yy);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char buffer[30];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> buffer;
        for(int j = 0; j < n; j++){
            Map[i][j] = buffer[j] - 48;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(Map[i][j] == 1){
                cnt++;
                area = 1;
                Map[i][j] = 0;
                DFS(i, j);
                district.push_back(area);
            }
        }
    }
    cout << cnt << "\n";
    sort(district.begin(), district.end());
    for(int i = 0; i < district.size(); i++){
        cout << district[i] << "\n";
    }

    return 0;
}