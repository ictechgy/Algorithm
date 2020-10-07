//다리의 길이가 n일 때 길이 1인 트럭이 지나는데 소요되는 시간은 n+1이다.
//weight 이하의 값으로 트럭들 k개를 묶을 것인데 이 경우 소요되는 시간은 n+k초
//다만 한가지 고려해야 하는 상황은 단순히 이렇게만 풀리지는 않는다는 것이다.. 
//길이가 2이고 weight가 10인 다리에 [5,5,4]의 트럭이 주어진다면 이는 5초가 답인데, 
//위처럼 단순히 풀려고 하면 6, 7초가 나와버린다. 무게제한만 초과 안된다면 중첩되어서 올라갈 수 있음에 주의
//즉 어떤 트럭의 집합이 완전히 건너가기 전에 새로운 트럭(집합)이 올라올 수 있고, 새로운 트럭이 아직 올라올 수 없는 경우에도
//이전 트럭집합이 다 지나간 그 순간 해당 초에는 이미 새로운 트럭(또는 트럭집합 중 일부)가 올라갈 수 있다는 뜻이다.
//음.. 그러면 묶음처리한다는게 과연 올바른 접근방법일까..? 

//꼭 큐를 이용해서 bridge_length만큼 그 공간을 만들고, 다리 위에 존재하는 트럭의 무게를 셈하면서 트럭값의 이동을 추적해야 할까..? 

//weight이하가 되도록 각 트럭을 그룹화 하고, 해당 그룹들이 통과하는데 소요되는 시간을 계산한다.
//통과하는 시간 - 그룹의 첫번째 트럭이 다리에 올라가고 마지막 트럭이 다리의 끝에 있을때까지의 시간
//(어차피 앞 그룹이 통과하자마자 뒷 그룹이 바로 다리에 올라가므로) -> 마지막 트럭그룹의 경우에는 +1을 해줘야 함. 완전히 사라져야 하므로
//그리고 각각의 그룹별로 중첩가능한 트럭의 개수를 센다. 이를테면 앞그룹의 뒤쪽 3개와 뒷그룹의 앞쪽 3개가 서로 중첩되어 다리에 올라가있을 수
//있다면 뒤쪽그룹의 소요시간은 -3이 된다.


//큐가 아닌 배열이나 비츠를 써보면 어떨까? 값을 하나씩 왼쪽으로 옮겨보는거지. 
//bridge 길이가 최대 10000이니까 배열쓰기에는 너무 클수도 있으니... 비츠를 쓴다면? 
//근데 굳이 꼭 배열이나 bitset을 써야할까? 
//아쉽게도 bitset은 크기 지정시 상수를 써야 해서 bridge_length 크기를 할당할 수 없다.
//가장 비슷한 vector<bool>을 쓰고 싶어도 shift 연산이 불가능

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int capacity, vector<int> trucks) {            
    int time = 0, i, weight = 0, cnt = 0;
    queue<int> Q;
    
    for(i = 0; i < bridge_length; i++){
        Q.push(0);
    }
    
    i = 0;
    while(cnt < trucks.size()){
        if(Q.front() != 0) cnt++;
        weight -= Q.front();
        Q.pop();
        if(i < trucks.size() && weight + trucks[i] <= capacity){
            Q.push(trucks[i]);
            weight += trucks[i];
            i++;
        }else{
            Q.push(0);
        }
        time++;
        
    }
    
    return time;
}