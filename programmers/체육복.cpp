#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size(); //기본적으로 본인 것들이 있는 학생 수
    int p1 = 0, p2 = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    while(p1 < reserve.size() && p2 < lost.size()){
        if(reserve[p1] == lost[p2]){    //잃어버렸으나 여벌을 가지고 있는 사람에 대한 사전 처리
            answer++;
            reserve.erase(reserve.begin()+p1);  //해당 element 제거
            lost.erase(lost.begin()+p2);    //이와같이 제거를 하면 뒤에 있던 원소들이 다 앞으로 땡겨지므로 인덱스 포인터는 그대로 둬도 됨
        }else if(reserve[p1] > lost[p2]) p2++;
        else p1++;
    }

    p1 = p2 = 0;
    
    while(p1 < reserve.size() && p2 < lost.size()){
        if(abs(reserve[p1] - lost[p2]) == 1){   //사이즈 값이 1차이만 나는 경우 빌려주는 것으로 처리
            answer++;
            p1++;
            p2++;
        }else if(reserve[p1] > lost[p2]) p2++;
        else p1++;
    }
    
    return answer;
}