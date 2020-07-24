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
//다른 방식의 풀이가 있을까? 
//-> 일단 눈에 띄는 풀이는 비트연산으로 값에 1이 몇개있는지 셈하는 함수를 만든 뒤 입력 값의 1의 개수를 세고, 입력 값 다음 10진수부터
//1의 개수가 같은 숫자가 나올 때까지 동일한 함수를 이용하여 차례차례 검색해나아가는 코드가 눈에 띈다. 
//1의 개수를 세는 방법에는 1을 시프트연산 하면서 숫자와 비트 & 연산을 하거나 나머지/나눗셈 연산을 주로 이용..
//또 위와같은 방법을 bitset을 이용하지 않고 while문과 특정 flag 변수로 구현한 사람도 있다. 