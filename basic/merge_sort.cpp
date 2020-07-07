//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

void merge(int data[], int left, int center, int right){
    int i = left, j = center+1, k = 0;
    int merged[right-left+1];
    while(i <= center && j <= right){
        if(data[i] <= data[j]) merged[k++] = data[i++];
        else merged[k++] = data[j++];
    }
    while(i<=center) merged[k++] = data[i++];
    while(j<=right) merged[k++] = data[j++];
    for(k = 0, i = left; k < right-left+1; i++, k++) data[i] = merged[k];
}

void merge_sort(int data[], int left, int right){   //recursive -> 매개변수를 명시적으로 
    if(left < right){   //base-case는 left >= right인 경우이다. 이는 원소가 한개 이하라는 뜻으로 이미 정렬된 상태라고 볼 수 있다. 
        int center = (left + right) / 2;
        merge_sort(data, left, center);
        merge_sort(data, center+1, right);
        merge(data, left, center, right);
    }
}

int main(void){
    int data[] = {2, 3, 1, 6, 3, 8, 1, 9}, i;
    merge_sort(data, 0, 7);
    for(i = 0; i < 8; i++) printf("%d ", data[i]);
    printf("\n");
    return 0;
}