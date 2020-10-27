#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;

struct Loc{
    int now;    //현재 층 수
    int cnt;    //버튼 작동횟수
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> F >> S >> G >> U >> D;
    //F는 건물의 층 수, S는 현재 위치, G는 가고자 하는 목적지, U, D는 엘리베이터의 버튼 누를 시 이동하는 층 수이다.
    //원하는 층에 가기위한 버튼의 최소 작동횟수를 세고 엘리베이터로 갈 수 없는 경우 use the stairs를 출력하자

    if(S < G && U <= 0 || S > G && D >= 0) cout << "use the stairs";
    //계단을 써야하는 예외 미리 처리
    

    

    return 0;
}

//아니면 구조체 쓰지말고 배열을 쓸까? 특정 층까지 가는데 걸리는 최소작동횟수를 기록하는.. 
//그러면 배열을 F의 크기에 맞춰 선언해줘야하는데 최대 크기가 1,000,000이다.. 