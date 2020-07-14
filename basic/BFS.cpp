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
void BFS_print(char start){
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

int main(void){
    BFS_print('A');
    return 0;
}