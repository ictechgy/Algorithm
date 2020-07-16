//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님
//MST_Prim에서 쓰기 위한 최소우선순위 큐 정의

#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

void min_heap_insert(vector<pair<int, int> >&, pair<int, int>);
pair<int, int> heap_extract_min(vector<pair<int,int> >&);
void min_heapify(vector<pair<int, int> >&, int, int);

void min_heap_insert(vector<pair<int, int> >& data, pair<int, int> value){ 
    data.push_back(value);  //맨 뒤에
    pair<int, int> tmp;
    int i = data.size()-1;  
    while( i>0 && data[(i-1)/2] > data[i] ){  //데이터가 2개 이상일 때 삽입한 값에 대한 우선순위 큐 조건 만족시키기
        tmp = data[i];
        data[i] = data[(i-1)/2];
        data[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

pair<int, int> heap_extract_min(vector<pair<int, int> >& data){
    if(data.size() < 1) return make_pair(NULL, NULL);   
    pair<int, int> min = data[0];
    data[0] = data[data.size()-1];  
    data.erase(data.end()-1);   
    min_heapify(data, data.size(), 0);

    return min;
}

void min_heapify(vector<pair<int, int> >& data, int n, int i){  //n은 데이터의 개수, i는 인덱스
    int left = i*2+1, right = i*2+2, child;
    pair<int, int> tmp;  
    if(left >= n) return;   
    else if(right >= n) child = left;  
    else child = (data[left] < data[right])? left : right; 
    
    if(data[i] < data[child]) return;
    
    tmp = data[i];
    data[i] = data[child];
    data[child] = tmp;
    min_heapify(data, n, child);
}