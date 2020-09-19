#include <stdio.h>
#include <queue>
using namespace std;
int n, map[30][30];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Loc{
    int x;
    int y;
    int dist;
    Loc(int a, int b, int c){
        x = a;
        y = b;
        dist = c;
    }
};

int main(void){
    int i, j, x, y;
    queue<Loc> q;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    q.push(Loc(1, 1, 0));
    map[1][1] = 1;
    while(!q.empty()){
        Loc tmp = q.front();
        q.pop();
        for(i = 0; i < 4; i++){
            x = tmp.x + dx[i];
            y = tmp.y + dy[i];
            if(x == n && y == n) { printf("%d\n", tmp.dist+1); return 0; }
            if(x > 0 && x <= n && y > 0 && y <= n && map[x][y] == 0){
                map[x][y] = 1;
                q.push(Loc(x, y, tmp.dist+1));
            }
        }
    }

    return 0;
}

//
#include <stdio.h>
#include <queue>
using namespace std;
int n, map[10][10], dis[10][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x = a;
        y = b;
    }
};

queue<Loc> Q;
int main(){
    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= 7; j++){
            scanf("%d", &map[i][j]);
        }
    }
    Q.push(Loc(1, 1));
    map[1][1] = 1;
    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int xx = tmp.x + dx[i];
            int yy = tmp.y + dy[i];
            if(map[xx][yy] == 0 && xx >= 1 && xx <= 7 && yy >= 1 && yy <= 7){
                Q.push(Loc(xx, yy));
                map[xx][yy] = 1;
                dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
            }
        }
    }
    printf("%d", dis[7][7]);

    return 0;
}