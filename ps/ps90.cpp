/*#include <stdio.h>
#include <queue>
using namespace std;
int n, map[30][30], sim_s = 2, num = 0, t = 0;
int hist[30][30];
int sim_c = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct Loc{
    int x, y;
    Loc(){}
    Loc(int a, int b){
        x = a;
        y = b;
    }
};

Loc sim;
int main(void){
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                sim.x = i;
                sim.y = j;
            }
            else if(map[i][j] != 0) num++;
        }
    }

    int f;
    while(num > 0){
        f = 1;
        queue<Loc> q;
        q.push(sim);
        hist[sim.x][sim.y] = 1;
        while(f == 1){
            Loc tmp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = tmp.x + dx[i];
                int y = tmp.y + dy[i];
                if(x >= 1 && x <= n && y >= 1 && y <= n && hist[x][y] == 0){
                    if(map[x][y] == 0 || map[x][y] == sim_s){
                        q.push(Loc(x, y));
                        hist[x][y] = 1;
                    }else if(map[x][y] > sim_s) continue;
                    else{
                        t += abs(sim.x-x) + abs(sim.y - y);
                        map[x][y] = 9;
                        map[sim.x][sim.y] = 0;
                        sim_c++;
                        if(sim_s == sim_c){
                            sim_s++;
                            sim_c = 0;
                        }
                        for(int i = 1; i <= n; i++)
                            for(int j = 1; j <= n; j++)
                                hist[i][j] = 0;
                        sim.x = x;
                        sim.y = y;
                        f = 0;
                        num--;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", t);

    return 0;
}*/
//반례 존재. 동일거리일 때 왼쪽방향에서 탐색된 것이 오른쪽 방향에서 탐색된 것보다 먼저 보이게되는데,
//오른쪽을 통해 발견된 것이 높이가 더 높은 경우에도 왼쪽을 먼저 처리하게 됨. 

#include <stdio.h>
#include <queue>
using namespace std;
int n, map[30][30], num = 0, t = 0;
int sim_s = 2, sim_c = 0;
int hist[30][30], dist;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Loc{
    int x, y, d;
    Loc(){}
    Loc(int a, int b, int c){
        x = a;
        y = b;
        d = c;
    }
    bool operator<(const Loc o)const{
        if(x != o.x){
            return x > o.x;
        }else{
            return y > o.y;
        }
    }
};

int main(void){
    int i, j;
    Loc sim;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                sim.x = i;
                sim.y = j;
                sim.d = 0;
            }else if(map[i][j] != 0) num++;
        }
    }
    
    while(num > 0){
        queue<Loc> q;
        priority_queue<Loc> pQ;
        q.push(sim);
        hist[sim.x][sim.y] = 1;
        dist = 0;
        while(!q.empty()){
            Loc tmp = q.front();
            if(tmp.d != dist){
                if(!pQ.empty()) break;
                else dist = tmp.d;  //dist++;
            }
            q.pop();
            for(i = 0; i < 4; i++){
                int x = tmp.x + dx[i];
                int y = tmp.y + dy[i];
                if(x >= 1 && x <= n && y >= 1 && y <= n && hist[x][y] == 0){
                    if(map[x][y] == 0 || map[x][y] == sim_s){
                        q.push(Loc(x, y, tmp.d+1));
                    }else if(map[x][y] > sim_s) continue;
                    else if(map[x][y] < sim_s){
                        pQ.push(Loc(x, y, tmp.d+1));
                    }
                    hist[x][y] = 1;
                }
            }
        }
        Loc nx = pQ.top();
        pQ.pop();
        //t += abs(sim.x - nx.x) + abs(sim.y - nx.y);
        t += nx.d;
        map[sim.x][sim.y] = 0;
        map[nx.x][nx.y] = 9;
        sim.x = nx.x;
        sim.y = nx.y;
        num--;
        sim_c++;
        if(sim_c == sim_s){
            sim_s++;
            sim_c = 0;
        }
        for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) hist[i][j] = 0;
    }
    printf("%d\n", t);

    return 0;
}   //안됨.. 


//
#include <stdio.h>
#include <queue>
using namespace std;
int n, map[30][30], hist[30][30], num = 0, t = 0;
int sim_s = 2, sim_c = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Loc{
    int x, y, d;
    Loc(){}
    Loc(int a, int b, int c){
        x = a;
        y = b;
        d = c;
    }
    bool operator<(const Loc &o)const{
        if(d != o.d) return d > o.d;
        else if(x != o.x) return x > o.x;
        else return y > o.y;
    }
};

Loc sim;
int main(void){
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                sim.x = i;
                sim.y = j;
                sim.d = 0;
                map[i][j] = 0;
            }else if(map[i][j] > 0) num++;
        }
    }

    int f;
    while(num > 0){
        priority_queue<Loc> pQ;
        pQ.push(sim);
        hist[sim.x][sim.y] = 1;
        f = 1;
        while(f == 1){
            Loc tmp = pQ.top();
            pQ.pop();
            if(map[tmp.x][tmp.y] > 0 && map[tmp.x][tmp.y] < sim_s){
                map[tmp.x][tmp.y] = 0;
                sim.x = tmp.x;
                sim.y = tmp.y;
                t += tmp.d;
                num--;
                sim_c++;
                if(sim_s == sim_c){
                    sim_s++;
                    sim_c = 0;
                }
                for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) hist[i][j] = 0;
                f = 0;
                break;
            }
            for(i = 0; i < 4; i++){
                int x = tmp.x + dx[i];
                int y = tmp.y + dy[i];
                if(x >= 1 && x <= n && y >= 1 && y <= n && hist[x][y] == 0){
                    if(map[x][y] > sim_s) continue;
                    else{
                        pQ.push(Loc(x, y, tmp.d+1));
                        hist[x][y] = 1;
                    }
                }
            }
        }
    }
    printf("%d\n", t);

    return 0;
}

//
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int map[21][21], ch[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct State{
    int x, y, dis;
    State(int a, int b, int c){
        x = a;
        y = b;
        dis = c;
    }
    bool operator<(const State &bb)const{
        if(dis == bb.dis){
            if(x == bb.x) return y > bb.y;
            else return x > bb.x;
        }
        else return dis > bb.dis;
    }
};

struct Lion{
    int x, y, s, ate;
    void sizeUp(){
        ate = 0;
        s++;
    }
};

int main(){
    int n, i, j, res = 0;
    priority_queue<State> Q;
    Lion simba;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                simba.x = i;
                simba.y = j;
                map[i][j] = 0;
            }
        }
    }
    Q.push(State(simba.x, simba.y, 0));
    simba.s = 2;
    simba.ate = 0;
    while(!Q.empty()){
        State tmp = Q.top();
        Q.pop();
        int x = tmp.x;
        int y = tmp.y;
        int z = tmp.dis;
        if(map[x][y] != 0 && map[x][y] < simba.s){
            simba.x = x;
            simba.y = y;
            simba.ate++;
            if(simba.ate >= simba.s) simba.sizeUp();
            map[x][y] = 0;
            for(i = 1; i <= n; i++){
                for(j = 1; j <= n; j++){
                    ch[i][j] = 0;
                }
            }
            while(!Q.empty()) Q.pop();
            res = tmp.dis;
        }
        for(i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > n || map[xx][yy] > simba.s || ch[xx][yy] > 0) continue;
            Q.push(State(xx, yy, z+1));
            ch[xx][yy] = 1;
        }
    }
    printf("%d\n", res);

    return 0;
}