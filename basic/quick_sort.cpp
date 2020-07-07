//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

int partition(int data[], int left, int right){
    int i, j, pivot = data[right], tmp;     
    for(i = left-1, j = left; j < right; j++){
        if(data[j] < pivot){
            i++;
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    tmp = data[++i];
    data[i] = pivot;
    data[right] = tmp;
    return i;
}
//pivot을 선택하는 방법은 많다. 첫번째 인덱스 값을 고르거나 마지막 인덱스 값을 선택하는 방법 외에도
//Median of Three라고 해서 위치상 첫번째, 가운데, 마지막 값 중 크기상 가운데 값을 택하는 방법도 존재한다. 
//Randomized Quicksort라고 하여 pivot 선택 자체를 랜덤에 맡기는 방법도 존재한다. 이 경우 최악의 입력이라는 것이 존재하지는 않게 되지만
//랜덤 선택에 따른 최악의 실행 경우의 수가 존재하게 된다. 

void quick_sort(int data[], int left, int right){
    if(left < right){
        int pivot = partition(data, left, right);   //pivot값 기준으로 분류한 후 pivot의 위치 반환
        quick_sort(data, left, pivot-1);
        quick_sort(data, pivot+1, right);
    }
}

int main(void){
    int data[] = {2, 4, 6, 1, 3, 5}, i;
    quick_sort(data, 0, 5);
    for(i = 0; i <= 5; i++) printf("%d ", data[i]);
    printf("\n");

    return 0;
}