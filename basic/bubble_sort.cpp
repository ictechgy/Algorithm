//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#define swap(type, x, y) do{ type t = x; x = y; y = t; }while(0)

int* bubble_sort(int data[], int n){
    int i, j;
    for(i = n-1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(data[j] > data[j+1]) swap(int, data[j], data[j+1]);
        }
    }

    return data;
}
