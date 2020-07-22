#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int i, j, cnt;
    bitset<32> num(n);
    i = 0;
    while(num[i] != 1) i++; //bitset의 오른쪽부터 읽기, bit값 중 1이 최초로 나타나는 위치 찾기  -> 맨 오른쪽이 0번인덱스이고 왼쪽으로 갈 수록 인덱스 값 증가
    j = i+1;
    while(num[j] != 0) j++; //i이전 비트 중 0이 최초로 나타나는 위치 찾기
    //맨 오른쪽부터 읽어서 1로 구성된 비트그룹의 위치를 특정해낸다. 
    //해당 비트그룹 중 맨 왼쪽 값만 하나 왼쪽으로 옮겨주고 나머지 1값들은 맨 오른쪽으로 붙이면 그게 다음값이 된다.
    num.set(j, true);
    cnt = j - i - 1;    //1의 그룹 개수 중 맨 오른쪽으로 몰 1의 개수만을 구하기 위해 1을 더 빼줌
    for(j = j-1; j >= 0; j--) num[j] = 0;   //오른쪽 나머지 비트를 모두 0으로 만든다.
    for(i = 0; cnt > 0; i++, cnt--) num[i] = 1;    //오른쪽 비트에서 cnt개수만큼 1로 만들기
    
    int answer = (int)num.to_ulong();
    
    return answer;
}