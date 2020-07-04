#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> j_num(10, 0);  //각 중요도별 작업이 몇개있는지 체크
    int i, cnt = 0, next_p;
    //cnt는 몇번째인지 세기위한 변수, prior는 요청문서의 중요도
    //next_p는 요청문서의 중요도보다 하나 높은 중요도를 가진 작업의 중요도를 의미한다. 
    for(i = 0; i < priorities.size(); i++){
        j_num[priorities[i]]++;
    }
    //인쇄의 순서는 자기보다 몇개가 우선순위가 높느냐 + 자기보다 우선순위가 하나 높은 작업 이후에 
    //나와 같은 우선순위를 가진 작업이 몇개가 있느냐에 따라 결정
    for(i = j_num.size()-1; i != priorities[location]; i--){    //맨 뒤부터 읽기
        cnt += j_num[i];
        if(j_num[i] != 0) next_p = i;   //중요도 하나 높은 작업의 중요도를 얻음
    }
    //여기까지 했다면 요청한 작업보다 몇개가 더 우선하는지를 계산 완료
    
    
    if(cnt == 0){   //가장 높은 우선순위 작업인 경우
        for(i = location - 1; i >= 0; i--){
            if(priorities[i] == priorities[location]) cnt++;
        }
    }else{    //next_p는 location작업보다 우선순위가 하나 높은 작업을 의미하므로.. 
        for(i = location - 1; priorities[i] != next_p; i--){
            if(i < 0) i = priorities.size()-1;
            if(priorities[i] == priorities[location]) cnt++;
        }
    }
    
    cnt += 1; //~ 번째이므로 자기보다 앞선 작업의 개수에 +1번째가 된다. 
    return cnt;
}

//queue로 구현해보자.. 
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> que;
    vector<int> feq(10);
    int i, tmp, cnt = 0, val = priorities[location], max = 0;
    for(i = 0; i < priorities.size(); i++){
        tmp = priorities[i];
        que.push(tmp);  //큐에 옮기기
        feq[tmp]++;     //각 우선순위별 수 저장 
        if(max < tmp) max = tmp;    //최고 우선순위 작업의 우선순위 값을 저장
    }

    while(1){
        if(feq[max] == 0) max--;    //최고우선순위 작업의 개수가 0개가 된 경우 그 밑의 우선순위 작업 가리키기
        tmp = que.front();
        //tmp보다 큐에 우선순위가 높은 값이 있을까?
        if(tmp < max){  //max값이 tmp보다 크다는건 더 큰 우선순위 작업이 있음을 의미. 굳이 feq[max] 안해도 됨
            que.pop();
            que.push(tmp);  //뒤로 보내기
        }
        

        if(tmp > val){
            //내 요청보다 높은 우선순위라면 그 숫자의 값에 상관 없이 어차피 내 요청보다는 먼저 실행될 것
            cnt++;
            que.pop();
            location--;
        }else if(tmp == val){   //맨 앞에 있는 숫자가 내 요청과 동일한 우선순위라면 내 요청인지 검증해야 함
            if(location == 0){
                return cnt++; //~번째이므로 
            }else{  //내 작업이 아니라면

            }
        }
        
    }
}