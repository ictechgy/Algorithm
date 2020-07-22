#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size(), 0);  //기본 수신 안테나 값 0으로 초기화
    //가장 단순한 방법
    int i, j;
    for(i = heights.size()-1; i > 0; i--){  //0번인덱스 안테나는 어차피 0
        for(j = i-1; j >= 0; j--){
            if(heights[j] > heights[i]) {
                answer[i] = j + 1;  //~번째이므로 +1
                break;  //stack 쓰는 경우 여기서 pop시키면 될 듯 
            }
        }
    }
    
    return answer;
}
//뭐랄까 더 단순하고 좋은 방법 없을까? 위의 방식은 최악의 경우 O(n^2)정도까지 복잡도가 증가할 것 같다. 
//안테나 n개가 들어왔을 때 맨 뒤의 n번째 안테나에 대하여 더 큰 안테나를 앞에서 찾아야하는데 최악의 경우 첫번째까지 다 봐야 하므로 n-1번 비교 
//물론 아무리 최악이어도 비교횟수가 n-1, n-2...2, 1로 줄어들 것이고 총 n-1개에 대하여 수행이 되므로 n(n-1)/2 -> O(n^2)