//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <queue>

using namespace std;

char nodes[] = {'A', 'B', 'C', 'D', 'E'};

int adj[][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0}
};   //이와같은 그래프에 대한 인접행렬이 있다고 가정

bool visited[5] = {false,}; //방문여부 체크

//방문 순서대로 출력하는 함수
void BFS_traverse(char start){
    int s = start-65;
    printf("%c\n", nodes[s]);   //시작점 방문
    visited[s] = true;
    queue<int> q;
    q.push(s);
    
    int node, i;
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(i = 0; i < 5; i++){
            if(adj[node][i] != 0 && visited[i] == false){   //인접해있으면서 아직 방문하지 않은 인접 노드들에 대하여
                printf("%c\n", nodes[i]);   //인접한 노드를 방문했다고 출력
                visited[i] = true;  //방문 체크 
                q.push(i); 
            }
        }
    }
}

//특정 출발점을 기준으로 각 노드에 대한 거리(최단경로)와 predecessor를 구해보자
int dist[5];    //출발지점에서 각 Vertex에 대한 거리
int pred[5];    //predecessor. 각 노드에 대한 경로 중에서 이전 노드에 대한 값을 저장
void BFS_find_path(char s){
    int i;
    for(i = 0; i < 5; i++){
        dist[i] = -1;   //출발지점에서 모든 Vertex에 대한 거리는 아직 모르는 상태
        pred[i] = -1;   //이전 vertex도 모르는 상태
    } 
    int start = s-65;
    dist[start] = 0;   //시작지점에서 시작지점까지의 거리는 0   -> 방문체크도 동시에 됨
    pred[start] = -1;   //시작지점에서 시작지점까지 가는데의 이전 vertex는 없음 
    
    queue<int> q;
    q.push(start);
    int vertex;
    while(!q.empty()){
        vertex = q.front();
        q.pop();
        for(i = 0; i < 5; i++){ 
            if(adj[vertex][i] != 0 && dist[i] == -1){ //vertex에 인접한 다른 모든 노드들에 대해, 방문하지 않은경우(거리가 계산되지 않은 경우)
                dist[i] = dist[vertex] + 1; //모든 Edge의 가중치는 1로 생각
                pred[i] = vertex;
                q.push(i);
            }
        }
    }
}

void BFS_print_path(int s, int e){    //s부터 e까지의 경로 출력 - 단 여기서 find_path를 s에 대해 먼저 수행한 상황으로 생각
    //s와 e의 값은 정수값이 들어온다고 하자. 0 ~ SIZE-1
    if(s == e) printf("%c ", nodes[s]);
    else if(pred[e] == -1) printf("no path to %c\n", nodes[e]);
    else{
        BFS_print_path(s, pred[e]);      //recursive
        printf("%c ", nodes[e]);
    }
}


int main(void){
    BFS_traverse('A');
    BFS_find_path('A');
    BFS_print_path(0, 3);   //'A'에서 'D'까지의 경로 출력
    return 0;
}