//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <limits.h>

using namespace std;

#define inf INT_MAX-10000
#define N 5

//강의자료 그래프 예시
int adj[][N]{       //self edge는 없으므로 자기자신에 대한 경로는 무한대로
    {inf, 10, 5, inf, inf},
    {inf, inf, 2, 1, inf},
    {inf, 3, inf, 9, 2},
    {inf, inf, inf, inf, 4},
    {7, inf, inf, 6, inf}
};

//다익스트라 알고리즘은 음수 가중치가 없는 경우에 적용 가능하다.
//경로가 정해진 집합 s에 속하지 않은 노드 중 d[u]가 최소값인 노드를 찾아 집합 s에 포함시키고 그 노드에 인접한 노드들에 대하여 relax연산을 수행하며 
//모든 노드에 대한 최단경로를 찾아내는 one to all 알고리즘이다. 
//'집합 s에 포함되지 않은 노드 중 d[u]가 최소인 노드의 d[u]는 출발지 s로부터 u까지 가는 최단경로이다'라는 증명에서 출발
//prim의 알고리즘과 많이 비슷하며 우선순위 큐와 피보나치 힙 이용가능하다. 일반적인 구현부터 해보자

void dijkstra(int s){   //출발노드를 입력받는다. 
    int i;
    bool visited[N] = {false, };    //집합 s에 포함되면 true로 변환. 자료구조 중 set 구조를 이용해도 될 듯 싶다.
    int d[N];   //각 노드에 대한 최단경로 저장
    int pred[N];    //최단경로에 이르는 path 중 이전노드 값 저장
    int cnt = 0;    //집합 s에 속한 노드의 개수 카운팅(종료조건용)

    for(i = 0; i < N; i++){
        d[i] = inf; //모든 노드들에 대한 최소경로 무한대로 설정
        pred[i] = s;    //모든 노드들에 대한 최소경로 상 이전 노드를 출발노드로 설정
    }

    d[s] = 0;   //출발노드의 거리 0으로 설정
    int min, node;  //d[v]가 최소인 노드와 그 값을 찾기 위한 변수
    while(cnt < N){
        min = inf;
        for(i = 0; i < N; i++){
            if(visited[i] == false && d[i] < min){  //s에 포함되지 않은 노드 중 d[v]값이 최소인 노드 찾기
                min = d[i];
                node = i;
            }
        }
        //d[v]가 최소인 노드(node)를 찾은 상태
        visited[node] = true;   //방문 체크(집합 s에 포함시키기)
        cnt++;  //집합 s수 증가
        
        for(i = 0; i < N; i++){
            if(visited[i] == false && (d[node] + adj[node][i]) < d[i]){ //집합 s에 포함되지 않은 노드 중에서 방금 선택된 node로 인해 최단경로가 갱신될 필요가 있는 노드 대상
                d[i] = d[node] + adj[node][i];
                pred[i] = node;
            }
        }
    }

    for(i = 0; i < N; i++){
        printf("%d to %d - distance: %d, predecessor: %d\n", s, i, d[i], pred[i]);
    }
}

int main(void){
    dijkstra(0);
    return 0;
}