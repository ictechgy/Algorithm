#include <iostream>
using namespace std;
int N, M, H;
int ladder[31][11];
int MIN = 2147000000;
bool isConnected[11];   //특정 열의 사다리가 다른 사다리랑 연결되어있는지 체크 -> 이걸로 가지치기가 가능할까? 
//아무것도 연결 안되어있는 사다리 열은 그대로 지나치는게 전체적으로 더 빠른 속도를 낼까?
//이전에 git commit message에서 100 0 100이 오래걸린다 했는데 이는 배열 인덱스 값을 넘어선 값이라 결과 값 도출이 제대로 안된거같고.
//M이 0일 때 바로 0을 출력하는 구문을 없애고 10 0 30으로 N과 H의 최대치 해봤는데 시간이 오래걸린다. 가지치기가 필요한 듯

//isConnected에 cnt를 이용한 가지치기를 추가했는데도 시간초과가 뜬다 ㅠㅠㅠㅠㅠ 

//사다리의 왼쪽에서 오른쪽으로 훑어가면서 연결가능한 부위가 있다면 연결도 해보고 연결안함도 해보면서 다음 DFS호출
void DFS(int y, int x, int cnt){ 
    if(y >= H && x >= N){     //종단노드 - 모든 사다리는 자신 기준으로 오른쪽으로 연결하므로 맨 끝인 x는 N이 된다. 
        for(int i = 1; i <= N; i++){
            //사다리를 타고 내려가는걸 어떻게 표현하지?
            int col = i;   //어느 사다리 열에 있는지
            for(int j = 1; j <= H; j++){    //아래로 내려가면서
                col = ladder[j][col];
            }
            if(col != i) return;
        }
        //모든 i열이 i열로 갔다면
        if(MIN > cnt) MIN = cnt;
    }else if(x >= N){    //특정 가로줄의 맨 끝에 도달 시
        DFS(y+1, 1, cnt);    //그 다음줄 맨 왼쪽으로 조정
    }else if(isConnected[x] == false || isConnected[x+1] == false){
        DFS(y, x+1, cnt);
    }else{
        if(ladder[y][x] == x && ladder[y][x+1] == x+1){  //주변 사다리와 연결 안된상태 && 오른쪽 사다리도 다른 사다리와 연결 안된 상태
            
            if(cnt < MIN){
                ladder[y][x] = x + 1;
                ladder[y][x+1] = x; //쌍방연결
                DFS(y, x+2, cnt+1); //x+1은 볼 필요 없음
            }   
            //가지치기. cnt가 MIN보다 작은경우에만 연결해서 DFS깊이를 더 들어갈 필요가 있음. cnt가 이미 MIN과 같거나 큰 경우 더 연결해서 들어가볼 필요 x

            ladder[y][x] = x;
            ladder[y][x+1] = x+1;   //백트래킹
            DFS(y, x+1, cnt);

        }else DFS(y, x+1, cnt); //이미 연결된 상태이면 스킵
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> N >> M >> H;
    //N은 세로선의 수, M은 현재 연결되어있는 가로선 수, H는 가로선을 둘 수 있는 라인 수
    if(M == 0){
        cout << 0;
        return 0;
    }

    //사다리 구조를 int형 2차원 배열로 만들자.
    //1번에서 2번으로 가는 길이 1번가로줄에 있다고 가정한다면 이는
    //배열의 [1, 1] 의 값을 2로, [1, 2]의 값을 1로 만든다.
    //이렇게 하면 값이 이미 있으므로 세로줄 2번에서는 세로줄 3번으로 가로줄 1번라인에서는 연결하는 것이 불가능하다는 것을 표시할 수 있다.
    //단순히 bool형으로 두지 않는 이유는 [1, 2]이 true라면 이는 1번과 연결된 것인지, 3번과 연결된 것인지 알 수 없기 때문이다.

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            ladder[i][j] = j;   //0으로 두는 것보다 초기 기본값을 자기 자신으로 두는게 나을 듯
        }
    }

    for(int i = 1; i <= M; i++){
        cin >> a >> b;  
        ladder[a][b] = b+1;
        ladder[a][b+1] = b;

        isConnected[b] = true;
        isConnected[b+1] = true;
    }
    
    //모든 경우를 다 탐색한 이후에 가장 적은 값이 3을 초과하는지 아닌지에 따라서 값 출력
    DFS(1, 1, 0);
    cout << ((MIN > 3)? -1 : MIN);
    //불가능한 경우에는 2147000000 그대로일 것이므로 똑같이 -1 출력 

    return 0;
}