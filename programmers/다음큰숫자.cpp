#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int i, j, cnt;
    bitset<32> num(n);
    i = 31;
    while(num[i] != 1) i--; //bitset의 오른쪽부터 읽기
    j = i-1;
    while(num[j] != 0) j--;
    //맨 오른쪽부터 읽어서 1로 구성된 비트그룹의 위치를 특정해낸다. 
    //해당 비트그룹 중 맨 왼쪽 값만 하나 왼쪽으로 옮겨주고 나머지 1값들은 맨 오른쪽으로 붙이면 그게 다음값이 된다.
    num.set(j, true);
    cnt = i - j - 1;    //1의 그룹 개수 중 맨 오른쪽으로 몰 1의 개수만을 구하기 위해 1을 더 빼줌
    for(j = j+1; j < 32; j++) num[j] = 0;   //오른쪽 나머지 비트를 모두 0으로 만든다.
    for(i = 31; cnt > 0; i--, cnt--) num[i] = 1;    //오른쪽 비트에서 cnt개수만큼 1로 만들기
    
    int answer = (int)num.to_ulong();
    
    return answer;
}