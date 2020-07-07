//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#define swap(type, x, y) do{ type t = x; x = y; y = t; }while(0)    //매크로 함수

int* selection_sort(int data[], int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(data[j] < data[min]) min = j;
        }
        if(i != min) swap(int, data[i], data[min]);
    }

    return data;
}