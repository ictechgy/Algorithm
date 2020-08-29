#include <stdio.h>

int adj[21][21], n, min = 2147000000;
int ck[21];

void DFS(int v, int cost){
    int i;
    if(v == n && cost < min) min = cost;
    else{
        for(i = 1; i <= n; i++){
            if(adj[v][i] != 0 && ck[i] == 0){
                ck[i] = 1;
                DFS(i, cost + adj[v][i]);
                ck[i] = 0;
            }
        }
    }
}

int main(void){
    int m, i, u, v, w;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }
    ck[1] = 1;
    DFS(1, 0);
    printf("%d\n", min);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int map[30][30], ch[30], n, cost = 2147000000;

void DFS(int v, int sum){
    int i;
    if(v == n){
        if(sum < cost) cost = sum;
    }else{
        for(i = 1; i <= n; i++){
            if(map[v][i] > 0 && ch[i] == 0){
                ch[i] = 1;
                DFS(i, sum + map[v][i]);
                ch[i] = 0;
            }
        }
    }
}

int main(){
    int m, i, a, b, c;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
    }
    ch[1] = 1;
    DFS(1, 0);
    printf("%d\n", cost);

    return 0;
}

//방문체크를 언제 할 것이냐, sum값같은 것에 대한 부분을 각 재귀별로 넘겨줄 것이냐 전역적으로 (다른 방식 포함)관리할 것이냐는 취향차이일 듯
//가지치기는 가능한 경우 처리해줘야 더 효율적이고.
//ps60도 그렇고. 


//dijkstra
#include <stdio.h>
#define MAX 2147000000

int adj[30][30], n;
int ck[30], d[30], pred[30];

void dijkstra(int s){
    int i, cnt = 0, min, vertex;
    for(i = 1; i <= n; i++){
        d[i] = MAX;
        pred[i] = -1;
    }
    d[s] = 0;
    pred[s] = s;

    while(cnt < n){
        min = MAX;
        for(i = 1; i <= n; i++){
            if(ck[i] == 0 && d[i] < min){   //priority queue needed
                min = d[i];
                vertex = i;
            }
        }

        ck[vertex] = 1;
        cnt++;

        for(i = 1; i <= n; i++){
            if(ck[i] == 0 && d[i] > d[vertex] + adj[vertex][i]){    //만약 연결되지 않은 노드에 대한 가중치를 MAX가 아닌 0으로 잡았다면 vertex에 연결된 노드들에 대해서만 업데이트 하겠다는 추가 조건식 필요. 
                d[i] = d[vertex] + adj[vertex][i];
                pred[i] = vertex;
            }
        }   

    }
}

int main(void){
    int m, i, j, u, v, w;
    for(i = 0; i < 30; i++){
        for(j = 0; j < 30; j++){
            adj[i][j] = MAX;
        }
    }
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }
    dijkstra(1);
    printf("%d\n", d[n]);

    return 0;
}