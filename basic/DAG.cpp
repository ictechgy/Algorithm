//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

//Directed Acyclic Graph
#include <stdio.h>

int adj[][7] = {    //임의의 인접행렬
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

void topological_ordering(){    //위상정렬
    //우선 각 노드들에 대해 indegree를 계산하자
    int indegree[7] = {0, };
    int i, j, k;
    for(i = 0; i < 7; i++){
        for(j = 0; j < 7; j++){
            if(adj[i][j] != 0) indegree[j]++;
            //i에서 j로 가는 edge가 있을 시 j노드에 대한 indegree를 1 증가
        }
    }
    int ordered[7]; //정렬된 순서를 저장 - 단 정렬의 순서는 유일하지 않다. 

    for(i = 0; i < 7; i++){
        //ordered[i]에 들어갈 값을 정한다.
        for(j = 0; j < 7; j++){
            if(indegree[j] == 0) break; //indegree가 0인 값을 찾으면 break
        }
        ordered[i] = j; //indegree가 0인 노드를 먼저 넣는다.
        indegree[j] = -1;   //해당 노드가 삭제된 것으로 본다.
        for(k = 0; k < 7; j++){
            if(adj[j][k] != 0) indegree[k]--;
            //해당 노드가 삭제되었으므로 해당 노드로부터 진입간선이 존재하는 노드들의 indegree를 줄여준다.
        }
    }
}
//위의 함수가 가장 먼저 나와야 할 노드를 찾는 것이라면 아래는 가장 늦게 나와야 할 노드부터 찾는 것
#include <list>

bool visited[7];    //방문여부 체크
std::list<int> ordered; //방문 순서 저장 리스트 - 정답은 유일하지 않음

void DFS_TS(int vertex){
    visited[vertex] = true; //방문
    int i;
    for(i = 0; i < 7; i++){
        if(adj[vertex][i] != 0 && visited[i] == false) DFS_TS(i);
        //인접한 노드 중에서 아직 방문하지 않은 노드가 있다면 해당 노드에 대해 recursive DFS
    }
    ordered.push_front(vertex);
    //더이상 진출간선이 없는 노드에 이르르면 list의 맨 앞에 해당 노드의 번호를 삽입한다. 
    //진출간선이 없다는 것은 DAG에서 가장 마지막에 수행되어야 하는 작업임을 나타낸다. 따라서 리스트의 head에 계속 넣어주는 방식을 취해주면
    //이후에 수행되어야 하는 작업은 뒤에 존재하게 된다. 
}

void topological_ordering2(){
    int i;
    for(i = 0; i < 7; i++){
        if(visited[i] == false) DFS_TS(i);
        //i노드가 방문되지 않았다면 DFS 시작
    }
}
