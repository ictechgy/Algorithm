//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

//recursive
void max_heapify(int data[], int n, int i){    //n은 원소의 개수, i번째 인덱스 값을 max-heapify
    int left = i*2+1, right = i*2+2, child, tmp;    //인덱스는 0부터 시작하므로
    if(left >= n) return;   //왼쪽자식이 없는 경우 return. 왼쪽자식이 없다는 것은 오른쪽 자식도 없다는 뜻임
    else if(right >= n) child = left;    //오른쪽 자식만 없는 경우 두 자식 중 최대값은 왼쪽자식
    else child = (data[left] >= data[right])? left : right; //두 자식 중 더 큰쪽 가리키기
    
    if(data[i] >= data[child]) return;
    
    //자식이 더 크다면
    tmp = data[i];
    data[i] = data[child];
    data[child] = tmp;
    max_heapify(data, n, child);
}

//iterative
void max_heapify2(int data[], int n, int i){
    int left, right, child, tmp;
    while(i*2+1 < n){    //왼쪽 자식이 존재하는 한 반복
        left = i*2+1, right = i*2+2;
        if(right >= n) child = left;
        else child = (data[left] >= data[right])? left : right;
        
        if(data[i] >= data[child]) return;

        tmp = data[i];
        data[i] = data[child];
        data[child] = tmp;
        i = child;
    }
}

void build_max_heap(int data[], int n){ //주어진 배열을 힙구조로 만드는 함수
    int i;
    for(i = (n-2)/2; i >= 0; i--){  //배열의 시작을 0으로 보았기 때문에 i의 시작을 (n-1-1)/2로 두었다.
        max_heapify(data, n, i);
    }
}

//인덱스를 0부터 시작하는 것으로 할거냐, 1부터 시작하는 것으로 할거냐에 따라 (부모자식)계산식이 달라질 수 있다.

void heap_sort(int data[], int n){
    int i, tmp;
    build_max_heap(data, n);    //먼저 주어진 배열을 힙 구조로 만든다. -> 가장 큰 값이 root(인덱스 0)에 위치한다. 
    for(i = n-1; i >= 1; i--){
        tmp = data[i];
        data[i] = data[0];
        data[0] = tmp;
        max_heapify(data, i, 0);  //두번째 매개변수에 주의. i는 맨 마지막 요소를 가리키고 있으며 교환이 끝난 후에는
        //정렬이 완료된 가장 큰 값을 가리키고 있다. 이 때 해야하는 heapify는 그 앞까지만을 대상으로 해야한다. 
        //이 때 i의 값은 값 그대로 정렬해야하는 남은 원소의 개수 값과 같다. 따라서 i값을 그대로 써도 되며 --n을 해주어도 된다. 
    }
}

int main(void){
    int data[] = {9, 2, 6, 3, 4, 7, 5}, i;
    heap_sort(data, 7);
    for(i = 0; i < 7; i++) printf("%d ", data[i]);
    printf("\n");
    return 0;
}