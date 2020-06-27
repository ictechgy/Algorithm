#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    if(len%2==0) answer.push_back(s[len/2-1]);
    answer.push_back(s[len/2]);
    return answer;
}
//string.substr을 이용하는 방법도 있음
//인상깊은 풀이는 삼항연산자에 조건식 조건을 &1로 비트마스킹해서 짝/홀수 구분하여 처리하는 방식