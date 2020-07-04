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

//queue로 구현해보자..  -> 그냥 위의 방식이 나을 것 같다.
//큐로 구현 시 가장 간단하게는 front값을 pop할 때 뒤에 우선순위가 더 높은 값이 있는지 매번 체크해서 push를 다시 할지 말지를 결정하는건데..
//pop만 수행되었을 시 cnt값을 증가시키고, 내가 요청한 작업의 위치값을 추적하는 방식으로.. 
//근데 이렇게 하면 맨 앞의 원소 하나당 뒤의 원소 n개를 비교해야하는거고, n이 굉장히 커지면 복잡도는 O(n^2)정도 될거같음.. 
//큐를 굳이 써야할까? 써야한다면 어떤 방식으로 쓰는게 맞는걸까..? 