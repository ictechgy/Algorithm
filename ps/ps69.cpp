#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int adj[10][10];

int main(void){
    int n = 7, m = 6, i, u, v;
    int que[10], front = 0, rear = 0;
    for(i = 1; i <= m; i++){
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        //adj[v][u] = 1; -> 트리이므로 사실 이 부분이 있어야 하고 그 경우 방문여부를 체크할 배열을 두거나 노드의 인접체크시 인접행렬의 대각선 윗부분만 보는 것이 필요
    }
    que[rear++] = 1;
    while(front != rear){
        v = que[front++];
        printf("%d ", v);
        for(i = 1; i <= n; i++){
            if(adj[v][i] != 0){
                que[rear++] = i;
            }
        }
    }

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int Q[100], front = -1, back = -1, ch[10];
vector<int> map[10];

int main(){
    int i, a, b, x;
    for(i = 1; i <= 6; i++){
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    Q[++back] = 1;
    ch[1] = 1;
    while(front < back){
        x = Q[++front];
        printf("%d ", x);
        for(i = 0; i < map[x].size(); i++){
            if(ch[map[x][i]] == 0){
                ch[map[x][i]] == 1;
                Q[++back] = map[x][i];
            }
        }
    }

    return 0;
}
//큐에서 꺼낸 뒤 방문체크할지.. 큐에 넣을 때 방문체크할지.. 
//DFS에서도 호출 전에 체크하냐 호출 후에 체크하냐 / 호출이 끝나고 복귀 전에 체크를 해제하냐 복귀를 마친 뒤 복귀함수에서 체크를 해제하냐 