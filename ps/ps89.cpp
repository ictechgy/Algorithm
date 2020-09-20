#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int m, n, Max = -2147000000;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Loc{
    int x;
    int y;
    int d;  //or use array
    Loc(int a, int b, int c){
        x = a;
        y = b;
        d = c;
    }
};

int main(void){
    int i, j, x, y;
    freopen("input.txt", "rt", stdin);
    scanf("%d %d", &m, &n);
    vector<vector<int> > map(n, vector<int>(m));
    queue<Loc> q;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) q.push(Loc(i, j, 0));
        }
    }

    while(!q.empty()){
        Loc tmp = q.front();
        q.pop();
        for(i = 0; i < 4; i++){
            x = tmp.x + dx[i];
            y = tmp.y + dy[i];
            if(tmp.d > Max) Max = tmp.d;
            if(x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 0){
                map[x][y] = 1;
                q.push(Loc(x, y, tmp.d+1));
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(map[i][j] == 0){
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", Max);

    return 0;
}

//
#include <stdio.h>
#include <queue>
using namespace std;
int m, n, tom[1010][1010], res = -2147000000, dis[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct Loc{
    int x, y;
    Loc(int a, int b){
        x = a;
        y = b;
    }
};

queue<Loc> Q;
int main(){
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &tom[i][j]);
            if(tom[i][j] == 1){
                Q.push(Loc(i, j));
            }
        }
    }
    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int xx = tmp.x + dx[i];
            int yy = tmp.y + dy[i];
            if(tom[xx][yy] == 0){
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= m){
                    Q.push(Loc(xx, yy));
                    tom[xx][yy] = 1;
                    dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
                }
            }
        }
    }
    int f = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(tom[i][j] == 0) f = 0;
        }
    }
    if(f == 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(res < dis[i][j]) res = dis[i][j];
            }
        }
        printf("%d\n", res);
    }
    else printf("-1");

    return 0;
}