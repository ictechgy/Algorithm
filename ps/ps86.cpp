#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Coord{
    int x;
    int y;
    Coord(int a, int b){
        x = a;
        y = b;
    }
};

struct Store{
    int x;
    int y;
    Store(int a, int b){
        x = a;
        y = b;
    }
};

struct House{
    int x;
    int y;
    House(int a, int b){
        x = a;
        y = b;
    }
};

int n, m, map[51][51], Min = 2147000000, ck[51][51];
vector<Store> list;
vector<House> h_list;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(House h){
    int i, j, x, y;
    queue<Coord> q;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            ck[i][j] = 0;
        }
    }

    q.push(Coord(h.x, h.y));
    ck[h.x][h.y] = 1;
    
    while(!q.empty()){
        Coord c = q.front();
        q.pop();
        if(map[c.x][c.y] == 2){
            return abs(h.x-c.x)+abs(h.y-c.y);
        }
        for(i = 0; i < 4; i++){
            x = c.x + dx[i];
            y = c.y + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= n && ck[x][y] == 0){
                ck[x][y] = 1;
                q.push(Coord(x, y));
            }
        }
    }
    //return ?
}

void DFS(int L){    //체크된 것의 개수를 별도의 전역변수나 매개변수로 다뤄볼 수도 있을 듯
    int i, sum = 0;
    if(m == 0){ //check
        for(i = 0; i < h_list.size(); i++){
            sum += BFS(h_list[i]);
        }
        if(sum < Min) Min = sum;
    }else{
        if(L < list.size()){
            Store s = list[L];
            map[s.x][s.y] = 2;
            m--;
            DFS(L+1);
            m++;
            map[s.x][s.y] = 0;
            DFS(L+1);
        }
    }
}

int main(void){
    int i, j;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) h_list.push_back(House(i, j));
            else if(map[i][j] == 2){
                list.push_back(Store(i, j));
                map[i][j] = 0;
            }
        }
    }
    DFS(0);
    printf("%d\n", Min);

    return 0;
}

//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, r;
int ch[20];

void DFS(int s, int L){
    if(L == r){
        for(int j = 0; j < L; j++){
            cout<<ch[j]<<" ";
        }
        cout<<endl;
    }else{
        for(int i = s; i < n; i++){
            ch[L] = i;
            DFS(i+1, L+1);
        }
    }
}

int main(){
    cin>>n>>r;
    DFS(0, 0);
    return 0;
}


//
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Coord{
    int x;
    int y;
    Coord(int a, int b){
        x = a;
        y = b;
    }
};

struct Store{
    int x;
    int y;
    Store(int a, int b){
        x = a;
        y = b;
    }
};

struct House{
    int x;
    int y;
    House(int a, int b){
        x = a;
        y = b;
    }
};

int n, m, map[51][51], Min = 2147000000, ck[51][51];
vector<Store> list;
vector<House> h_list;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(House h){
    int i, j, x, y;
    queue<Coord> q;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            ck[i][j] = 0;
        }
    }

    q.push(Coord(h.x, h.y));
    ck[h.x][h.y] = 1;
    
    while(!q.empty()){
        Coord c = q.front();
        q.pop();
        if(map[c.x][c.y] == 2){
            return abs(h.x-c.x)+abs(h.y-c.y);
        }
        for(i = 0; i < 4; i++){
            x = c.x + dx[i];
            y = c.y + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= n && ck[x][y] == 0){
                ck[x][y] = 1;
                q.push(Coord(x, y));
            }
        }
    }
}

void DFS(int s, int L){ 
    int i, sum = 0;
    if(L == m){ 
        for(i = 0; i < h_list.size(); i++){
            sum += BFS(h_list[i]);
        }
        if(sum < Min) Min = sum;
    }else{
        for(i = s; i < list.size(); i++){
            Store s = list[i];
            map[s.x][s.y] = 2;
            DFS(i+1, L+1);
            map[s.x][s.y] = 0;
        }
    }
}

int main(void){
    int i, j;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) h_list.push_back(House(i, j));
            else if(map[i][j] == 2){
                list.push_back(Store(i, j));
                map[i][j] = 0;
            }
        }
    }
    DFS(0, 0);
    printf("%d\n", Min);

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > pz;
vector<pair<int, int> > hs;
int ch[20], m, res = 2147000000, dis, sum = 0;

void DFS(int L, int s){
    if(L == m){
        sum = 0;
        for(int i = 0; i < hs.size(); i++){
            int x1 = hs[i].first;
            int y1 = hs[i].second;
            dis = 2147000000;
            for(int j = 0; j < m; j++){
                int x2 = pz[ch[j]].first;
                int y2 = pz[ch[j]].second;
                dis = min(dis, abs(x1-x2) + abs(y1-y2));
            }
            sum = sum+dis;
        }
        if(sum < res) res = sum;
    }else{
        for(int i = s; i < pz.size(); i++){
            ch[L] = i;
            DFS(L+1, i+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, a;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a;
            if(a == 1) hs.push_back(make_pair(i, j));
            else if(a == 2) pz.push_back(make_pair(i, j));
        }
    }
    DFS(0, 0);
    cout<<res;

    return 0;
}