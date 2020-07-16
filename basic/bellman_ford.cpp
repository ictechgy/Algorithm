//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <limits.h>
#include <vector>
#include <utility>
using namespace std;

#define inf INT_MAX-1000    //그냥 INT_MAX했다가는 비교과정에서 overflow
#define N 5

//강의자료 그래프 예시
int adj[][N]{       //self edge는 없으므로 자기자신에 대한 경로는 무한대로
    {inf, 10, 5, inf, inf},
    {inf, inf, 2, 1, inf},
    {inf, 3, inf, 9, inf},
    {inf, inf, inf, inf, 4},
    {7, inf, inf, 6, inf}
};

//벨만포드 알고리즘은 모든 엣지에 대하여 relax연산을 n-1번 수행한다.
//어떤 노드 s에서 v까지의 최단경로에 포함된 엣지는 최대 n-1개이기 때문(노드의 개수가 n개일 때 모든 엣지를 지나는 경우)
//음수 사이클이 있는지도 판단이 가능하다. 


bool bellman_ford(int s){   //시작지점 지정
    int d[N];   //s부터 각 노드에 대한 distance
    int pred[N];    //각 노드에 대한 최단경로 상 바로 앞 노드
    int i, j;
    for(i = 0; i < N; i++){
        d[i] = inf;
        pred[i] = -1;
        //모든 노드의 출발지로부터의 거리는 무한대로, predecessor는 없는 것으로.
    }
    d[s] = 0;
    pred[s] = s;
    
    vector<pair<int, pair<int, int> > > edges; //간선 정보 저장
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(adj[i][j] != inf){
                edges.push_back(make_pair(adj[i][j], make_pair(i, j)));    //i->j로 가는 간선의 정보와 그 가중치 저장
            }
        }
    }

    int node, weight;
    for(i = 0; i < N; i++){ //n-1번 반복
        for(j = 0; j = edges.size(); j++){
            node = edges[j].second.second;  //이 간선정보가 어느 노드를 대상으로 하는가
            if(d[node] > d[edges[j].second.first] + edges[j].first){    //relax
                d[node] = d[edges[j].second.first] + edges[j].first;
                pred[node] = edges[j].second.first;
            }
        }

    }
    //negative cycle 검사
    for(j = 0; j = edges.size(); j++){
        node = edges[j].second.second; 
        if(d[node] > d[edges[j].second.first] + edges[j].first){   
            return false;   //음수 사이클 존재
        }
    }
    return true;
}