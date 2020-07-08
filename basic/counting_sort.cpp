//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <vector>
using namespace std;

vector<int> counting_sort(vector<int>& data, int k){   //k는 배열에 들어있는 값의 상한 값(값이 0 ~ k이하인 경우)
    int n = data.size(), i;
    vector<int> freq(k+1, 0);    //각 값이 몇개나 나왔는지 카운팅, 0~k를 담아야 하므로 크기는 k+1로 설정
    for(i = 0; i < n; i++){
        freq[data[i]]++;
    }
    for(i = 1; i <= k; i++){
        freq[i] += freq[i-1];     //누적합 계산
    }

    vector<int> sorted(n);  //정렬된 값을 저장할 배열
    for(i = n-1; i >= 0; i--){
        sorted[--freq[data[i]]] = data[i];
    }
    return sorted;
}

int main(void){
    vector<int> data = {2, 5, 1, 9, 10, 2, 1, 0, 4, 6, 2, 8, 5, 7};   //0 ~ 10까지의 값 존재
    vector<int> sorted = counting_sort(data, 10);
    for(int i = 0; i < data.size(); i++) printf("%d ", sorted[i]);
    printf("\n");

    return 0;
}