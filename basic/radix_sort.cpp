//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

//counting sort를 이용하여 radix sort를 할 수 있다.
//세자리의 숫자가 있을 경우 1의자리 수부터 100의 자리 수 순서대로 각 digit별 counting sort를 해주면 radix sort가 된다. -> stable 정렬이여서 가능

#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

void radix_sort(vector<int>&data, int k, int d){    //k는 각 자리의 값 유형 수 중 최대 값, d는 총 자리수
    int i, j, div, n = data.size();
    vector<int> sorted(n), freq(k+1, 0);   //정렬된 값을 담을 배열과 각 분포 값을 담을 배열
    for(i = 0; i < d; i++){
        for(j = 0; j <= k; j++) freq[j] = 0;    //매번 사용 전에 0으로 만들어줘야 한다. 그렇지 않으면 다음 사용 때 영향을 미칠 수도 있음
        div = 1 * pow(10, i);   //각 digit별 값을 얻기 위한 기본작업
        for(j = 0; j < n; j++){
            freq[(data[j]/div)%10]++;
        }
        for(j = 1; j <= k; j++) freq[j] += freq[j-1];   //누적합 계산
        for(j = n-1; j >= 0; j--){
            sorted[--freq[(data[j]/div)%10]] = data[j];
        }
        for(j = 0; j < n; j++) data[j] = sorted[j];
    }
}

int main(void){
    vector<int> data = {100, 150, 234, 121, 523, 164, 322, 643, 794, 956, 833, 720};
    radix_sort(data, 9, 3);    //10진법 0~9이므로 k에 9를 전달
    for(int i = 0; i < data.size(); i++) printf("%d ", data[i]);
    printf("\n");

    return 0;
}