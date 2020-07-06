//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <algorithm>    //max함수용.

int findMax(int data[], int n){ //일반적인 최대값 찾기 함수
    int max = data[0], i;    
    for(i = 1; i < n; i++){ //찾는 구간의 시작지점이 암시적임 (검색 시작은 0이거나 1이거나.. )
        if(data[i] > max) max = data[i];    
    }
    return max;
}

int findMax(int data[], int begin, int end){    //검색의 구간을 명시적으로  
    if(begin == end) return data[begin];    //base case는 요소의 개수가 한개일 때 
    else return std::max(data[begin], findMax(data, begin + 1, end));
    //맨 앞의 값과 나머지 값들 중 가장 큰 값을 비교하여 더 큰 값을 반환한다. 
}

int findMax(int data[], int begin, int end){
    if(begin == end) return data[begin];
    else{
        int middle = (begin + end)/2;
        int max1 = findMax(data, begin, middle);
        int max2 = findMax(data, middle+1, end);
        return std::max(max1, max2);    //반으로 쪼갠 뒤 앞과 뒤 중 가장 큰 값들을 마지막으로 비교하여 반환
    }
}