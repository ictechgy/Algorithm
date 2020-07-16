//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

//Minimum Spanning Tree 최소비용신장트리
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/*
    크루스칼 알고리즘은 먼저 모든 간선의 비용을 오름차순으로 정렬한 후에 비용이 낮은 간선부터 하나씩 선택해 나가는 알고리즘이다.
    이 때 cycle을 이루는 간선이 있는 경우 해당 간선은 선택하지 않는다.(이미 해당 vertex들을 연결하는 경로가 존재한다는 뜻)
    이렇게 어떤 MST의 부분집합을 이루는 edge들에 대해 한쪽을 S, 다른쪽을 V-S로 cut한 것이 부분집합 edge들을 respect할 때
    두 집합을 cross하는 edge 중 최소값 edge(u, v)를 선택해 나아간다.(safe) -> edge가 n-1개가 될 때까지

    이 때 사이클을 이루는지 안이루는지의 문제를 집합을 통해 해결한다. 중복된 노드는 존재하지 않으므로 이는 disjoint sets에 대한 문제이며
    Union-Find 문제라고도 한다. MST의 부분집합을 만족하는 간선으로 어떤 vertex들이 연결되어 있다면 이vertex들은 같은 집합에 속해있다고 한다.
    (처음에는 모든 노드들이 각자가 원소가 되는 개별집합으로 생성)
    같은 집합에 이미 속해있다면 해당 vertex들끼리의 간선은 더이상 불필요하다.(이미 간선으로 연결되있음을 의미)
    각 집합은 하나의 트리로 표현하며 집합의 이름은 root노드로 대신한다.(같은 집합에 속해있는지 찾는 것은 root노드가 같은지를 비교) - 상향식 트리
    -> 부모가 자식의 주소를 가지는 것이 아닌 자식이 부모의 주소를 가짐
    
    집합에서 root노드를 찾는 find-set과 두 MST 부분집합이 연결된 경우 두 집합을 합집합하는 UNION 함수가 필요하다.
    다만 이 두 함수는 단순히 구현하는 것이 아니라 Union은 weighted union으로 구현할 것이고(노드의 개수가 적은 트리를 노드의 개수가 많은 트리의 자식으로 합집합)
    find-set은 root노드를 찾아가는 과정에서 트리의 높이를 낮춰주는 과정을 부가적으로 넣을 것이다. 
*/

//강의에서의 그래프를 인접행렬로 표현해본다면...
enum {a, b, c, d, e, f, g, h, i};   //총 9개의 노드
//각각의 간선에 존재하는 가중치를 특정 노드에서 해당 노드로 가기 위한 값(비용)으로 보자
//자기 자신으로 가는데 필요한 비용은 0이고, 간선이 없다면 해당 노드로 가는데에 드는 비용을 INT_MAX로 설정
#define x INT_MAX   //갈 수 없음을 INT_MAX 대신 x로 표현
#define N 9
int adj[][N] = {    
    {0, 4, x, x, x, x, x, 8, x},
    {4, 0, 8, x, x, x, x, 11, x},
    {x, 8, 0, 7, x, 4, x, x, 2},
    {x, x, 7, 0, 9, 14, x, x, x},
    {x, x, x, 9, 0, 10, x, x, x},
    {x, x, 4, 14, 10, 0, 2, x, x},
    {x, x, x, x, x, 2, 0, 1, 6},
    {8, 11, x, x, x, x, 1, 0, 7},
    {x, x, 2, x, x, x, 6, 7, 0}
};

//Union-Find disjoint set에 대한 문제
int parent[N] = {a, b, c, d, e, f, g, h, i};    //각각의 집합을 트리로 표현할 때 최초에는 부모가 자기 자신이다.
int _size[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1};  //모든 집합(트리)의 노드개수는 1부터 시작한다.

int find_set(int node){ //node 값이 들어오면 해당 노드의 집합이름(루트 노드 값) 반환
    //root를 찾아 올라가면서 최적화 수행
    while(node != parent[node]){
        parent[node] = parent[parent[node]];
        //위의 라인이 최적화를 수행하는 라인인데, 이와 같이 최적화를 수행하지 않고 root를 먼저 찾은 뒤에 다시 while문으로 밑에서부터 올라가면서
        //(올라가면서 만나는)모든 부모노드들을 root노드에 붙이는 방식으로 최적화 시킬 수도 있다.
        node = parent[node];
    }
    return node;
}

void union_set(int u, int v){   //u가 속한 집합과 v가 속한 집합을 합집합
    int q = find_set(u);
    int r = find_set(v);
    if(_size[q] >= _size[r]){
        parent[r] = q;
        _size[q] += _size[r];
    }else{  //_size[q] < _size[r]
        parent[q] = r;
        _size[r] += _size[q];
    }   //원래는 병합되었을 때 크기가 작은 트리집합의 size를 0으로 만들었으나 서브트리의 노드개수 개념처럼 0으로 만드는 부분을 삭제하였음
}

bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
    return a.first < b.first;   //여기에 등호가 들어가니 결과값이 이상해지네.. 
}   //a는 현재값, b는 그 뒤의 값, false 나왔을 시 swap

void MST_Kruskal(){ //여러 MST 해답 중 하나에 대해 그 트리를 구성하는 edge들 집합을 return 하는 함수
    vector<pair<int, int>> mst;   //MST를 구성하는 egde 집합
    int cost = 0;   //전체 비용 계산
    int i, j, u, v;
    vector<pair<int, pair<int, int>>> edges;   //그래프의 edge표현 - pair의 first는 가중치 값, second pair의 두 pair는 두 vertex의 각각 숫자값을 의미한다.
    for(i = 0; i < N; i++){
        for(j = i+1; j < N; j++){ //무방향 그래프이므로 인접행렬에서 대각선 윗부분만 봐도 된다. (자기자신 미포함)
            if(adj[i][j] != x) edges.push_back(make_pair(adj[i][j], make_pair(i, j)));
            //가중치 값과 해당 간선의 양끝 vertex를 vector에 추가
        }
    }
    sort(edges.begin(), edges.end(), compare);   //정렬이 될까..? -> 정렬 함수 구현해주자. 기본적으로는 first 기준 정렬이라고 한다.(즉, compare함수를 안만들어줘도 되긴 할듯 이 경우에는. )
    
    vector<pair<int, pair<int, int>>>::iterator it = edges.begin(); //정렬된 vector용 순회 iterator
    while(mst.size() < N-1){   //n-1이 될 때까지 반복
        u = it->second.first;
        v = it->second.second;
        if(find_set(u) != find_set(v)){
            mst.push_back(it->second);
            union_set(u, v);
            cost += it->first;
        }
        it++;
    }

    for(i = 0; i < mst.size(); i++){
        printf("%c-%c ", mst[i].first+65, mst[i].second+65);
    }
    printf("\n총 비용은 %d\n", cost);
}

int main(void){
    MST_Kruskal();
    return 0;
}