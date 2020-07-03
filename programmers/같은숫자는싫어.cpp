#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int i, prev = -1, now;
    for(i = 0; i < arr.size(); i++){
        now = arr[i];
        if(prev != now){
            answer.push_back(now);
            prev = now;
        }
    }

    return answer;
}

//인상깊은 풀이는 #include <algorithm>하여 unique와 erase함수를 사용한 것(정렬하지 않고)