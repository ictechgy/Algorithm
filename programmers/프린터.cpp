#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> j_num(10, 0);  //각 중요도별 작업이 몇개있는지 체크하기 위한 배열
    //중요도는 1~9로 부여되어있으며 0번 인덱스는 사용x, 모든 인덱스 값 0값으로 초기화
    int i, cnt = 0, next_p;
    //cnt는 몇번째인지 세기위한 변수
    //next_p는 요청문서의 중요도보다 하나 높은 중요도를 가진 작업의 중요도를 의미한다. 
    for(i = 0; i < priorities.size(); i++){
        j_num[priorities[i]]++;
    }
    //인쇄의 순서는 자기보다 몇개가 우선순위가 높느냐 + 자기보다 우선순위가 하나 높은 작업 수행 이후에 
    //나와 같은 우선순위를 가진 작업이 몇개가 있느냐에 따라 결정
    for(i = j_num.size()-1; i != priorities[location]; i--){    //맨 뒤부터 읽기
        cnt += j_num[i];    //내 요청보다 우선순위가 높은 작업들의 개수 누적
    }
    for(i = priorities[location] + 1; i < j_num.size(); i++){
        if(j_num[i] != 0) {
            next_p = i;   //중요도 하나 높은 작업의 중요도를 얻음
            break;
        }
    }

    //여기까지 했다면 요청한 작업보다 몇개가 더 우선하는지를 계산 완료 및 내 요청보다 마지막으로 앞설 작업의 우선순의를 구함
    
    if(cnt == 0){   //내가 원한 작업이 가장 높은 우선순위 작업인 경우
        for(i = location - 1; i >= 0; i--){
            if(priorities[i] == priorities[location]) cnt++;
        }
        //내가 원한 작업과 동일우선순위의 작업이 앞에 몇개가 있는지 체크
    }else{  
        for(i = location - 1; priorities[i] != next_p; i--){
            if(i < 0) i = priorities.size()-1;
            if(priorities[i] == priorities[location]) cnt++;
        }
        
    }
    
    cnt += 1; //~ 번째이므로 자기보다 앞선 작업의 개수에 +1번째가 된다. 
    return cnt;
}

//왜 틀린 테스트 케이스가 있는걸까..? 
//고려해볼만한 상황 1. 모든 작업의 우선순위가 동일할 때 -> cnt == 0 조건에 부합
//2. 작업이 하나 있을 때 -> cnt == 0 조건 부합
//3. '322222322' -> 반례. location이 4인 작업(중요도 2)의 실제 순서는 8번째인데 내 코드에 의하면 6번째로 나옴
//      => 내 작업보다 앞서 종료되는 높은 우선순위 작업이 무조건 앞에있다는 보장이 없다.  22322222322 등등 반례 많음
//내 작업보다 우선순위가 높은 것 중 마지막으로 출력되는 작업이 내 작업보다 앞에만/뒤에만 있는 경우는 위 코드로 가능한데 앞뒤로 다 있는 경우가
//문제가 된다. 게다가.. 4322222322, 3224222322, 3222223242 과 같이 더 높은 우선순위 작업이 어디에 있느냐에 따라 위 코드는 더 반례가 많아진다. 
//(내 작업보다 우선순위가 높은 것 중 마지막으로 끝나는 작업의 위치가 매번 달라짐) -> 그렇다면 또 그 마지막 위치를 구할 수 있을까..? 

//queue로 구현해보자..  -> 그냥 위의 방식이 나을 것 같다.
//큐로 구현 시 가장 간단하게는 front값을 pop할 때 뒤에 우선순위가 더 높은 값이 있는지 매번 체크해서 push를 다시 할지 말지를 결정하는건데..
//pop만 수행되었을 시 cnt값을 증가시키고, 내가 요청한 작업의 위치값을 추적하는 방식으로.. 
//근데 이렇게 하면 맨 앞의 원소 하나당 뒤의 원소 n-1개를 비교해야하는거고, n이 굉장히 커지면 복잡도는 O(n^2)정도 될거같음.. 
//큐를 굳이 써야할까? 써야한다면 어떤 방식으로 쓰는게 맞는걸까..? 

//어느정도의 최적화는 할 수 있을거같은데.. 각 중요도별 작업개수를 셈한 뒤에, pop하려는 작업보다 더 큰 중요도 작업이 아직 개수가 0이 아니면
//뒤로 다시 push하고.. 높은 우선순위 작업이 없는 경우 pop만 한 뒤에 해당 우선순위 작업의 작업개수를 -1하는 방식으로. 
//이 때 우선순위가 가장 높은 작업(개수가 0이 아닌)의 우선순위를 따로 변수에 저장만 해둔다면 모든 작업을 pop할때마다 우선순위별 작업 개수 배열을
//탐색할 필요도 없을거고.. (가장 높은 우선순위 작업의 개수가 0이 되는 경우 그 밑 우선순위 작업을 찾아 해당 값으로 다시 할당하는 방식.. )

//큐처럼 원소를 pop하고 push하는게 아니라 뽑을 작업을 가리키는 포인터가 있다고 생각하는건 어떨까? 첫번째에서 맨 뒤로, 맨 뒤에서는 다시 첫번째로 
//이동하는 포인터(인덱스 값을 가지는 방식으로) 원소가 pop되면 해당 부분은 0으로 채우고 0인 부분은 포인터가 건너뛰는 방식으로 


//위의 반례로 인해 다른 방법을 고안해야 할 것 같다. 기존 코드는 생각해야 할 부분(예외)이 너무 많아진다. 
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> freq(10, 0);   //우선순위별 작업 개수 체크
    int i, cnt = 0, high, ptr = -1, val = priorities[location];   //val은 내 요청의 우선순위 
    for(i = 0; i < priorities.size(); i++){
        freq[priorities[i]]++;
    }
    for(i = 9; i >= 1; i--){    
        if(freq[i] != 0){
            high = i;
            break;
        }
    }
    //가장 높은 우선순위 작업의 우선순위 구하기. 최고 값은 freq를 만드는 위 for문에서 구할 수도 있지만 작업의 수가 많아지는 경우 여기서 하는게 나을 것임

    //큐 방식이 아닌 포인터방식
    while(1){
        ++ptr;
        if(ptr >= priorities.size()) ptr = 0;
        if(priorities[ptr] == 0) continue;
        if(high == val && ptr == location){ //내 우선순위와 동일한 작업들이 요청될 차례이면서 ptr이 내 요청을 처리하려고 가리켰을 때
            cnt++;  //~번째이므로.
            break;
        }
        if(priorities[ptr] == high){
            priorities[ptr] = 0;
            cnt++;
            freq[high]--;
            if(freq[high] == 0){
                for(i = high-1; freq[i] == 0; i--);
                high = i;
            }
        }
    }
    return cnt;
}