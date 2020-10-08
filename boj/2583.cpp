#include <bits/stdc++.h>
using namespace std;

int Map[100][100];  //좌표값의 최대가 (0,0) ~ (100,100)일 때 배열로는 최대 100x100 크기
int m, n, cnt = 0, area;
vector<int> district;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y){
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && xx < m && yy >= 0 && yy < n && Map[xx][yy] == 0){
            Map[xx][yy] = 2;
            area++;
            DFS(xx, yy);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, x1, y1, x2, y2;
    cin >> m >> n >> k;
    for(int i = 1; i <= k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        //왼쪽 아래 좌표를 (x1,y1), 오른쪽 위 좌표를 (x2,y2)라고 했을 때 이를 배열로 변환하면
        //왼쪽 맨 위 배열공간 좌표는 (m-y2, x1)이며 오른쪽 맨 아래 좌표는 (m-y1-1, x2-1)이 된다.

        for(int i = m-y2; i <= m-y1-1; i++){
            for(int j = x1; j <= x2-1; j++){
                Map[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(Map[i][j] == 0) {
                cnt++;
                area = 1;
                Map[i][j] = 2;
                DFS(i, j);
                district.push_back(area);
            }

    cout << cnt << "\n";
    sort(district.begin(), district.end());
    for(int i = 0; i < district.size(); i++)
        cout << district[i] << " ";

    return 0;
}