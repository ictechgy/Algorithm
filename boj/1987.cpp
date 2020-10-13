#include <bits/stdc++.h>
using namespace std;
int R, C, MAX = -2147000000;
char Map[25][25];
bool visited[26] = {false, };   //알파벳은 26개, 알파벳을 만났는지 체크
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y, int cnt){
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 1 && xx <= R && yy >= 1 && yy <= C && visited[Map[xx][yy]-65] == false){
            visited[Map[xx][yy]-65] = true;
            DFS(xx, yy, cnt+1);
            visited[Map[xx][yy]-65] = false;    //가장 중요한 부분이라고 생각하는 라인.
        }
    }
    if(cnt > MAX) MAX = cnt;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> Map[i][j];
        }
        //개행 제거 필요? cin.get() -> 없어도 됨. cin이 개행을 알아서 무시해줌.   
    }
    
    visited[Map[1][1]-65] = true;   //(1, 1) 방문 체크
    DFS(1, 1, 1);
    cout << MAX << "\n";

    return 0;
}