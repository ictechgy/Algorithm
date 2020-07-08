//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <vector>

using namespace std;

void max_heap_insert(vector<int>&, int);
int heap_extract_max(vector<int>&);
void max_heapify(vector<int>&, int, int);

//maximum priority queue
//이번에는 원소값의 삽입이 일어나니까 vector로 구현해보자. c의 일반배열로 구현한다면 원소가 다 찼을 때 realloc 해야 할 듯

void max_heap_insert(vector<int>& data, int value){ //data vector 최대우선순위 큐에 value 값 삽입 함수
    data.push_back(value);  //맨 뒤에 넣는다. 
    int tmp, i = data.size()-1;  //방금 넣은 원소 인덱스 가리키기
    while( i>0 && data[(i-1)/2] < data[i] ){   //반복은 해당 값이 root에 도달하면 종료 / 부모가 더 크거나 같은 값이면 종료
        tmp = data[i];
        data[i] = data[(i-1)/2];
        data[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

int heap_extract_max(vector<int>& data){
    if(data.size() < 1) return NULL;    //원소가 없을 시 반환값은 때에 따라 다를 수 있음
    int tmp, max = data[0];
    data[0] = data[data.size()-1];  //pop될 부분을 맨 마지막 값으로 채운다.
    data.erase(data.end()-1);   //맨 뒤 인자 삭제
    max_heapify(data, data.size(), 0);

    return max;
}

void max_heapify(vector<int>& data, int n, int i){    
    int left = i*2+1, right = i*2+2, child, tmp;  
    if(left >= n) return;   
    else if(right >= n) child = left;  
    else child = (data[left] >= data[right])? left : right; 
    
    if(data[i] >= data[child]) return;
    
    //자식이 더 크다면
    tmp = data[i];
    data[i] = data[child];
    data[child] = tmp;
    max_heapify(data, n, child);
}