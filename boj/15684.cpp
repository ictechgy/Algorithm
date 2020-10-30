#include <iostream>
using namespace std;
int N, H, M;
int ladder[31][11];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> N >> M >> H;
    //N은 세로선의 수, M은 현재 연결되어있는 가로선 수, H는 가로선을 둘 수 있는 라인 수

    //사다리 구조를 int형 2차원 배열로 만들자.
    //1번에서 2번으로 가는 길이 1번가로줄에 있다고 가정한다면 이는
    //배열의 [1, 1] 의 값을 2로, [2, 1]의 값을 1로 만든다.
    //이렇게 하면 값이 이미 있으므로 2번에서는 3번으로 1번라인에서는 연결하는 것이 불가능하다는 것을 표시할 수 있다.
    //단순히 bool형으로 두지 않는 이유는 [2, 1]이 true라면 이는 1번과 연결된 것인지, 3번과 연결된 것인지 알 수 없기 때문이다.


    for(int i = 1; i <= M; i++){
        cin >> a >> b;  

    }



    return 0;
}