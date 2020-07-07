//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

//최선의 경우 O(n-1), 최악의 경우 O(n^2)    -> 모든 원소들에 대해 한번만 비교하게 되는 경우 최선. 
int* insertion_sort(int data[], int n){
    int i, j, tmp;
    for(i = 2; i < n; i++){
        tmp = data[i];
        for(j = i-1; j >= 0; j--){
            if(data[j] < tmp) break;
            else data[j+1] = data[j];
        }
        data[j+1] = tmp;
    }

    return data;
}