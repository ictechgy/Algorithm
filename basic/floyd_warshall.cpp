//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <limits.h>
#define inf 10000   //INT_MAX로 하니 k를 지나서 가는 경로에 대해 d[i][k] + d[k][j]가 오버플로우되서 -값이 되는 현상 발생
#define N 5

//강의자료 그래프 예시
int adj[N][N]{       //self edge는 없으므로 자기자신에 대한 경로는 무한대로
    {inf, 10, 5, inf, inf},
    {inf, inf, 2, 1, inf},
    {inf, 3, inf, 9, 2},
    {inf, inf, inf, inf, 4},
    {7, inf, inf, 6, inf}
};
/*
    플로이드 와샬 알고리즘은 동적계획법을 이용한 알고리즘이다. (순환식 이용)
    d^k[i, j] 가 1~k번의 노드를 지나 i에서 j까지 가는 최단경로라면, 
    d^0[i, j]는 쉽게 구할 수 있다. i와 j가 직접 연결되어있다면 그 간선의 가중치일 것이고 연결되어있지 않다면 무한대일 것이다.
    d^k[i, j] = min(d^k-1[i, j], d^k-1[i, k] + d^k-1[k,j]) -> i에서 j까지 1~k의 노드를 이용하는 최단경로는 1~k-1의 노드를 이용한 최단경로와
    k를 지나서 가는 최단 경로 중 더 작은 값이 된다. => k에 관한 답이 k-1에 의한 식으로 도출된다.
    따라서 우리가 원하는 최종 답인 d^n[i, j]는 K를 0부터 시작하여 n까지 늘려나가면 구할 수 있다.

    이 때 k에 관한 부분때문에 d[k][i][j] = min(d[k-1][i][j], d[k-1][i][k] + d[k-1][k][j])와 같이 식이 세워질 수 있고 이는 3차원배열이 필요하다는 것인데
    그냥 d[i][j] = min(d[i][j], d[i][k] + d[k][j])로 해도 된다. 그 이유는 중간에 이용되는 k에 관한 i, j값을 저장시킬 필요는 없기 때문이다.
    현재의 2차원 배열이 k-1에 관한 값으로 채워져 있을 때 d^k[i][j]의 값을 구하고 싶다면 현재 d[i][j]에 있는 d^k-1[i][j]와 d^k-1[i][k] + d^k-1[k][j]를 이용하면 되기 때문.
    그런데 이 경우 k가 i나 j보다 작게 되면 행렬의 갱신 순서상 d^k-1[i][k] + d^k-1[k][j] 가 d^k[i][k] + d^k[k][j]로 갱신되어 위의 순환식을 사용 불가능하게 될것같아 보인다.
    하지만 d^k-1[i][k] + d^k-1[k][j] 와 d^k[i][k] + d^k[k][j]는 동일하다. 1~k-1을 거쳐 k로 가든 1~k를 거쳐 k로 가든 동일하기 때문. 
*/
void print_path(int, int, int(*)[N]);
void floyd_warshall(int s, int t){
    int i, j, k;    //i는 출발지, j는 도착지, k는 순환식 값(동시에 거치는 노드의 값이 되기도 함)
    int d[N][N];    //i->j로 가는 최단경로값을 저장할 배열
    int inter[N][N]; //경로를 찾기 위한 π값 저장 2차원 배열(중간경로에 대한 값을 저장. i에서 j까지 갈 때 거치는 k값 저장)
    //- predecessor는 아니다. i에서 j까지 갈 때 k를 거치는 것이 최단이라고 해서 k를 π[i][j]에 저장했다고 하자. 그러면 경로는 i -> k -> j인데 π[k][j]에 아무것도 없다는 보장은 없음

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            d[i][j] = adj[i][j];    //d^0[i][j]는 adj인접행렬 그 자체가 된다. 
            inter[i][j] = -1;    //모든 노드쌍의 최단경로 상 중간경로는 -1로 설정(없음을 의미)
        }
    }

    for(k = 0; k < N-1; k++){ //N번 반복. 순환식은 노드가 1~N로 있음을 가정했지만 실질적으로 노드번호는 0~N-1까지 있다. 
    //k노드를 거치냐 안거치냐의 문제이므로 0번노드를 거치냐 안거치냐부터 시작하여 N-1번노드를 거치냐 안거치냐의 문제이므로 N번 반복
    //순환식에서는 1번노드를 거치냐 안거치냐부터 N번노드를 거치냐 안거치냐라고 정의했었음
    //'d^0[i][j]는 adj인접행렬 그 자체가 된다.' 라고 위에서 말한 것은 사실상 d^-1[i][j]라고 보아야 할지도..(아무것도 거치지 않고 가는걸 의미해야 하므로로
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(d[i][j] > d[i][k] + d[k][j]){    //k번째 반복중에 i에서 j로 가는 경로에 대해 k를 거치고 가는것과 그렇지 않은 값 비교
                    d[i][j] = d[i][k] + d[k][j];
                    inter[i][j] = k;
                }
            }
        }
    }
    
    //매개변수로 받은 s, t-> s에서 t로 가는 최단경로 출력
    printf("최단거리: %d\n", d[s][t]);
    printf("%d -> ", s);
    print_path(s, t, inter);
    printf("%d\n", t);
}

void print_path(int s, int t, int (*inter)[N]){
    if(inter[s][t] == -1) return;
    print_path(s, inter[s][t], inter);
    printf("%d -> ", inter[s][t]);
    print_path(inter[s][t], t, inter);
}

int main(void){
    floyd_warshall(0, 4);
    return 0;
}