//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

int partition(int data[], int left, int right){ //pivot을 기준으로 피봇보다 작은 값, 큰 값으로 나누는 함수
    int i, j, pivot = data[right], tmp;     
    for(i = left-1, j = left; j < right; j++){  //i는 피봇보다 작은 값들 중 가장 오른쪽 값을 가리키며(피봇을 기준으로 작은 값과 큰 값을 나누는 기준) j는 다음에 피봇과 크기를 비교할 인덱스를 가리킨다.
        if(data[j] < pivot){    //data[j]가 pivot보다 크다면 그건 그 위치에 있는 것으로 충분
            i++;
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    //마지막으로 피봇값을 가운데쪽에 넣어준다.
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
    if(left < right){   //base case는 left >= right인 경우로서 원소가 하나이거나 0개인 경우 -> sort 할 것이 없음
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