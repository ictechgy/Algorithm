#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int judge = 0, i;
    for(i = 0; i < s.length(); i++){
        if(s[i] == '(') judge++;
        else judge--;
        if(judge < 0) return false; //한번이라도 음수값이 되는 경우 그 경우는 되돌릴 수 없음. 뒤를 더 보지 않아도 된다. 
    }
    if(judge == 0) answer = true;
    else answer = false;    //judge가 양수인 경우 -> '(' 가 더 나온 경우
    return answer;
}

//보통은 스택을 이용하는 경우가 많음... 