#include <bits/stdc++.h>
using namespace std;
int n, Map[21][21], res = 0;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(void){
    ios_base::sync_with_stdio(false);
    int i, j, k;
    cin>>n;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cin>>Map[i][j];
        }
    }
    queue<pair<int, int> > q;
    pair<int, int> coord;
    int x, y;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(Map[i][j] == 1){
                Map[i][j] = 0;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    coord = q.front();
                    q.pop();
                    for(k = 0; k < 8; k++){
                        x = coord.first + dx[k];
                        y = coord.second + dy[k];
                        if(x > 0 && x <= n && y > 0 && y <= n && Map[x][y] == 1){
                            Map[x][y] = 0;
                            q.push(make_pair(x, y));
                        }
                    }
                }
                res++;
            }
        }
    }
    cout<<res<<endl;

    return 0;
}

//
#include <stdio.h>
#include <queue>
using namespace std;
int n, map[30][30], cnt = 0;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
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
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) scanf("%d", &map[i][j]);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(map[i][j] == 1){
                Q.push(Loc(i, j));
                map[i][j] = 0;
                while(!Q.empty()){
                    Loc tmp = Q.front();
                    Q.pop();
                    for(int i = 0; i < 8; i++){
                        int xx = tmp.x + dx[i];
                        int yy = tmp.y + dy[i];
                        if(map[xx][yy] == 1){
                            Q.push(Loc(xx, yy));
                            map[xx][yy] = 0;
                        }
                    }
                }
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}