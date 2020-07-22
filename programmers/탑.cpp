#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size(), 0);  //기본 수신 안테나 값 0으로 초기화
    //가장 단순한 방법
    int i, j;
    for(i = heights.size()-1; i > 0; i--){  //0번인덱스 안테나는 어차피 0
        for(int j = i-1; j >= 0; j--){
            if(heights[j] > heights[i]) {
                answer[i] = j + 1;  //~번째이므로 +1
                break;  //stack 쓰는 경우 여기서 pop시키면 될 듯 
            }
        }
    }
    
    return answer;
}
//뭐랄까 더 단순하고 좋은 방법 없을까? 위의 방식은 최악의 경우 O(n^2)정도까지 복잡도가 증가할 것 같다. 