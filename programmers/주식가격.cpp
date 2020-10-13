#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int cnt, i, j;
    vector<int> answer;
    for(i = 0; i < prices.size(); i++){
        cnt = 0;
        for(j = i+1; j < prices.size(); j++){
            if(prices[i] > prices[j]){
                answer.push_back(j-i);
                break;
            }
        }
        if(j == prices.size()){
            answer.push_back(j-i-1);
        }
    }
    return answer;
}

//스택으로 이 문제를 푼 사람의 풀이 - 프로그래머스
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}