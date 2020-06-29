#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //stack이나 queue를 꼭 써야 할까?
    vector<int> require_days(progresses.size());
    int i, cnt, j;
    for(i = 0; i < progresses.size(); i++){
        require_days[i] = (100-progresses[i])/speeds[i];    //각 프로세스에 요구되는 요일 수 계산(올림 계산)
        require_days[i] += ((100-progresses[i])%speeds[i]==0)? 0 : 1;
        //speed값으로 나머지 없이 나누어떨어지지 않는 경우 1일의 작업을 더 해야함 -> ceil()사용가능
    }
    for(i = 0; i < require_days.size(); i++){ //i번째 작업이 완료된 시점을 기준으로 뒤에 같이 배포 가능한 작업 확인
        cnt = 1;    //현재 작업 배포가능하므로 1부터 카운팅 시작
        for(j = i + 1; j < require_days.size(); j++){
            if(require_days[j]<=require_days[i]){   //뒷 작업이 앞 작업과 동시에 또는 더 일찍 끝나는 경우
               cnt++; //한번에 같이 배포
            }else{  //뒷 작업이 더 오래걸리는 작업인 경우
                //i = j-1;  //이 식이 여기 있으면 안됨. 마지막 배포 프로세스가 여러개가 되는 경우 문제가 됨
                break;
            }
        }
        answer.push_back(cnt);
        i = j - 1;
    }//복잡도는 O(n^2)처럼 보여도 O(n)인거같은데. 선형검색처럼 수행돼서..
    //스택이나 큐 중에서는 큐를 쓸 수 있을 것 같다.  
    
    return answer;
}
//맨 앞의 작업 완료 요구일과 같거나 작은 작업은 한번에 배포하고 그보다 큰 수가 나오면 그 때부터는 또 새로운 작업배포
//묶음이 시작된다. 따라서 for문을 아래와 같이도 작성 가능할 것.
/*
    max = require_days[0];
    cnt = 1;
    for(i = 1; i < require_days.size(); i++){
        if(max<require_days[i]){
            answer.push_back(cnt);
            max = require_days[i];
            cnt = 1;
        }else{
            cnt++;
        }
    }
    answer.push_back(cnt);  //마지막 배포
*/

//다른 풀이중에서..
//소요 일수를 day = (99 - progresses[i]) / speeds[i] + 1; 로 구하는 방법이 특히 신선하다.
//++answer.back()을 이용한 방법도 특히 신선. -> 위의 내 두번째 풀이와 비슷하면서도 훨씬 간결하다. 
//(소요일수 자체를 배열에 만들어두지 않고 바로바로 계산하여 사용)
//스택/큐 중에서는 큐를 이용.
