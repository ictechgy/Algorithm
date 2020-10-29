#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;

struct Loc{
    int now;    //현재 층 수
    int cnt;    //버튼 작동횟수
};
//아니면 구조체 쓰지말고 배열을 쓸까? 특정 층까지 가는데 걸리는 최소작동횟수를 기록하는.. 
//그러면 배열을 F의 크기에 맞춰 선언해줘야하는데 최대 크기가 1,000,000이다.. -> vector사용

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> F >> S >> G >> U >> D;
    //F는 건물의 층 수, S는 현재 위치, G는 가고자 하는 목적지, U, D는 엘리베이터의 버튼 누를 시 이동하는 층 수이다.
    //원하는 층에 가기위한 버튼의 최소 작동횟수를 세고 엘리베이터로 갈 수 없는 경우 use the stairs를 출력하자

    if((S < G && U == 0) || (S > G && D == 0)) {
        cout << "use the stairs";
        return 0;
    }
    else if(S == G) {
        cout << "0";
        return 0;
    }
    //계단을 써야하는 예외, 움직이지 않아도 되는 예외 미리 처리
    
    vector<int> path(F+1, -1);    //구조체를 쓰지 않고 배열 써보기, 크기를 1 크게 잡아줘야 하는 것 유의. 
    //각 층에 도착하는데 걸리는 최소 버튼 작동횟수 기록, -1로 초기값 둠으로써 방문여부도 동시 체크.

    queue<int> q;
    q.push(S);
    path[S] = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        int nxt_up = now + U, nxt_down = now - D;
        if(nxt_up == G || nxt_down == G){   //다음 가려는 곳이 목적지라면
            cout << path[now]+1;    //현재까지 오는데 걸린 작동횟수 +1 출력
            return 0;
        }
        
        if(nxt_up <= F && path[nxt_up] == -1){
            q.push(nxt_up);
            path[nxt_up] = path[now] + 1;
        }
        if(nxt_down >= 1 && path[nxt_down] == -1){
            q.push(nxt_down);
            path[nxt_down] = path[now] + 1;
        }
    }
    cout << "use the stairs";
    //U또는 D가 0이 아니더라도 S에서 G까지 도달 못하는 경우가 있을 수 있다.
    //ex) 10 1 10 4 0 으로 입력이 주어진다면 U는 0은 아니지만 9층이 최대로 도달할 수 있는 곳이다.
    //이는 while이 끝나고나서도 도달 못한경우 출력시킬 수도 있지만 미리 체크해서 확인해도 된다.
    //그렇게 하고자 하는 경우 S와 G의 차이 절대값을 구한 후 이 값에
    //S, G 중 어느 값이 큰지에 따라 U 또는 D로 나누어서 나머지가 0인지 보고, U와 D의 차이 절대값 나눗셈으로 나머지가 0인지를 보면 된다.

    return 0;
}