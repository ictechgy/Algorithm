//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

//iterative
int binary_search(int data[], int n, int target){       //반환 값은 인덱스가 될 수도, 주소가 될 수도
    int pl = 0, pr = n-1, pc;
    while(pl <= pr){
        pc = (pl + pr)/2;
        if(data[pc] == target) return pc;
        else if(data[pc] > target) pr = pc - 1;
        else pl = pc + 1;
    }
    return -1;
}

//recursive
int binary_search(int data[], int begin, int end, int target){
    if(begin > end) return -1;
    int center = (begin + end)/2;
    if(data[center] == target) return center;
    else if(data[center] > target) binary_search(data, begin, center-1, target);
    else binary_search(data, center+1, end, target);
}

//정리. 
//1. 기본적으로 recursive 구현시에는 하나 이상의 base-case를 가져야 하며 recursive-case는 base-case로 언젠가는 수렴해야 함
//2. recursive로 할 시 매개변수는 명시적으로. 