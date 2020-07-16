//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

//Minimum Spanning Tree 최소비용신장트리
#include <stdio.h>
#include <limits.h>
#include <queue>
#include <utility>
#include "min_priority_queue.cpp"
using namespace std;

/*
    MST에 포함되는 엣지들로 연결된 노드들을 V_A라고 한다면..
    프림의 알고리즘은 그래프 중 하나의 노드를 먼저 선택한다.(V_A에 포함시킨다.)
    이후에 V_A에 포함된 노드와 포함되지 않은 노드들의 간선 중 최소값을 가지는 간선을 선택하고, 그 끝에 있는 노드를 V_A에 포함시킨다.
    V_A에 포함된 노드와 그렇지 않은 노드를 연결(cross)하는 간선 중 최소값 간선을 계속 선택해나간다. (간선이 n-1개 또는 노드가 n개가 다 채워질 때까지)
    (정확히는 처음에 V_A는 공집합이고, 모든 key값은 무한대, π값은 NIL로 해둔 뒤 최초 노드의 key값만 0으로 만들고 시작하면 된다. 그러면 최초노드는
    처음에 무조건 선택되고, 인접한 노드들의 key와 π값 업데이트가 시작된다. 이후에는 같은 과정 반복)

    이를 구현할 때에는...
    어떤 노드v에 대하여 V_A와 연결되는 간선이 있는 경우 그 연결된 간선 중 최소값을 Key[v]로 저장한다. 그리고 그 끝에 달린 V_A노드를 π[v]로 저장한다.
    이후에 추가할 간선을 검색할 때는 이 key[v]만 읽어보면 되며, 최소값이 있다면 해당 노드 u와 π[u]를 연결한 뒤 노드 u를 V_A에 포함시키면 된다.
    그리고 노드u와 인접한 다른 노드들에 대해서만 key값과 π값을 업데이트 해주면 된다. 

    위와같이 구현할수도 있지만 key값을 검색할 때 V_A가 아닌 모든 노드의 key를 볼 필요 없이 최소 우선순위 큐를 이용할 수 있다.
    (그러면 Extract-Min에 logn 복잡도, 인접한 노드들에 대해 key값 업데이트가 이루어지며 걸리는 재정렬 logn 복잡도 소요)
    단순구현시 O(n^2), 우선순위 큐 이용시 O(mlogn), 피보나치 힙 이용시 O(m + nlogn) -> 간선의 수에 따라 수행시간이 조금 달라질 수는 있음
*/

enum {a, b, c, d, e, f, g, h, i}; 
#define x INT_MAX   //갈 수 없음을 x로 표현
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

int key[N];     //각 노드들에 대해 V_A노드와 연결되는 간선 중 최소값 저장
int pred[N];    //최소값으로 V_A노드와 연결되는 간선에 대한 V_A노드 값 저장
int pos[N]; //각 노드의 key값이 저장된 위치(인덱스) 찾기용 - priority queue에서

struct compare{
    bool operator()(const pair<int,int> &a, const pair<int, int> &b){
        return a.first < b.first;
    }
};

void MST_Prim(int s){   //출발노드를 하나 선택받기
    int i;
    priority_queue<pair<int, int>, vector<pair<int,int> >, compare> min_q;   
    //최소값과 그 최소값 키를 가진 노드, 내부 형태는 vector형태로, custom compare 추가
    //기본 제공 라이브러리를 쓰려고 했는데 이미 삽입된 값들에 대해 수정을 할 수가 없어서 직접 구현한 우선순위 큐 사용

    vector<pair<int, int> > q;
    //음.. 직접만든 우선순위 큐를 써보려 해도.. heapify하면서 각 노드의 키값이 우선순위큐의 어느 위치에 저장되어있는지 기억시켜주는게 너무 까다롭다.
    //일단은 키값과 pred값을 단순하게 쓰는 방법으로 구현해보자. 

    vector<pair<int, int> > mst;    //mst 구성 edge 저장
    bool added[N] = {false, };  //추가되었는지 여부 판단 -> V_A여부 판단
    int cost = 0;   //총 비용
    for(i = 0; i < N; i++){
        key[i] = x; //모든 노드의 키 초기값은 무한대
        pred[i] = s; //V_A노드와의 연결 없음, 출발노드로 기본값 설정
    }
    key[s] = 0; //출발노드의 key값을 0으로 만든다.(최초 선택을 위해)
    int min, node;    //최소비용 간선 찾기용
    while(mst.size() < N){  //최초 출발노드가 기본 포함되므로 N번 반복
        min = x;
        for(i = 0; i < N; i++){
            if(added[i] == false && min > key[i]){
                min = key[i];
                node = i;
            }
        }
        //간선의 최소값과 그 노드를 찾은 상태
        mst.push_back(make_pair(pred[node], node));
        cost += min;
        added[node] = true;  //해당 간선은 연결되었으므로 다음 검색에 나오지 않도록

        for(int i = 0; i < N; i++){
            if(added[i] == false && adj[node][i] < key[i]) {
                key[i] = adj[node][i];
                pred[i] = node;
            }
        }
    }

    for(i = 0; i < mst.size(); i++){
        printf("%c-%c ", mst[i].first+65, mst[i].second+65);
    }
    printf("\n총 비용은 %d\n", cost);
}

int main(void){
    MST_Prim(a);
    return 0;
}