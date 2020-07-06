//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

//순차탐색
#include <stdio.h>

//iterative
int search(int data[], int n, int target){
    int i;
    for(i = 0; i < n; i++){     //검색의 시작 위치가 암시적임
        if(data[i] == target) return i;
    }
    return -1;
}

//recursive -> 검색 구간을 명시적으로
int search(int data[], int begin, int end, int target){
    if(begin > end) return -1;  //base case
    else if(target == data[begin]) return begin;
    else return search(data, begin + 1, end, target);
}
//첫번째 값과 target이 같은지 재귀적으로 검색 
//- 외부에서 이 함수를 한번 호출하는 상황만 고려할 것이 아니라 재귀적으로 내부에서 재호출 할 상황을 고려하여 매개변수 설정

//binary search와 비슷해보이지만 다른 방식
int search(int data[], int begin, int end, int target){
    if(begin > end) return -1;
    else{
        int middle = (begin + end)/2;
        if(data[middle] == target) return middle;   //가운데 값이 target이면 반환
        int index = search(data, begin, middle -1, target);
        if(index != -1) return index;   //앞쪽에서 찾았다면 해당 인덱스 반환
        else return search(data, middle + 1, end, target);
    }
}   
//검색 값들 중 가운데에 있는 값을 확인, 원하는 값이 아니라면 그 왼쪽의 값들을 검색하기 위해 재귀호출, 그래도 원하는 값이 없다면 오른쪽 값들에 대한 재귀 호출검색