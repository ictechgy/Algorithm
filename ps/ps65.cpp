#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m[30][30], cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y){
    int i;
    if(x < 1 || x > n || y < 1 || y > n || m[x][y] != 0) return;
    if(x == n && y == n){
        cnt++;
        return;
    }
    m[x][y] = 2;
    for(i = 0; i < 4; i++){
        DFS(x + dx[i], y + dy[i]);
    }
    m[x][y] = 0;
}

int main(void){
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &m[i][j]);
        }
    }
    DFS(1, 1);
    printf("%d\n", cnt);

    return 0;
}

//
#include <stdio.h>
int map[10][10], ch[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

void DFS(int x, int y){
    int i, xx, yy;
    if(x == 7 && y == 7){
        cnt++;
    }else{
        for(i = 0; i < 4; i++){
            xx = x + dx[i];
            yy = y + dy[i];
            if(xx < 1 || xx > 7 || yy < 1 || yy > 7) continue;
            if(map[xx][yy] == 0 && ch[xx][yy] == 0){
                ch[xx][yy] = 1;
                DFS(xx, yy);
                ch[xx][yy] = 0;
            }
        }
    }
}

int main(){
    int i, j;
    for(i = 1; i <= 7; i++){
        for(j = 1; j <= 7; j++){
            scanf("%d", &map[i][j]);
        }
    }
    ch[1][1] = 1;
    DFS(1, 1);
    printf("%d\n", cnt);

    return 0;
}