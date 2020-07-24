#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    stack<char> st;
    for(int i = 0; i < arrangement.length(); i++){
        st.push(arrangement[i]);
    }
    //string의 맨 왼쪽은 무조건 '(' 이고 마지막은 ')' 이다. 
    char now, next;
    now = st.top(); 
    st.pop();
    int cnt = 0;    //막대의 개수를 실시간으로 체크
    int answer = 0;
    while(!st.empty()){
        next = st.top();
        st.pop();
        if(next == '(' && now == ')'){   //레이저
            answer += cnt;
        }else if(next == ')' && now == ')'){
            cnt += 1;
        }else if(next == '(' && now == '('){
            cnt -= 1;
            answer += 1;
        }
        //next == ')' && now == '('인 경우는 무시
        now = next;
    }
    return answer;
}
//배열로도 충분히 구현 가능할 듯(맨 뒤 또는 맨 앞부터 읽어나가기)
//필요한 값만 push, pop하면서 굉장히 간단히 푼 풀이가 있는데 훨씬 명료하다.. 
//나는 현재의 값과 그 다음의 값만 비교하면서 계산을 했는데 다른 사람은 stack과 주어진 배열을 적절히 잘 조합하여 풀었다. 
//-> 스택을 훨씬 더 스택답게 이용하여 푼 풀이.. 