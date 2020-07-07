//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

#define N 6
char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};   //전체 부분집합의 개수는 2^6개이다. 
bool include[N];
//powerset함수는 집합 P와 S에 대하여 S의 부분집합을 다 구한 뒤 거기에 집합 P를 합집합하여 구하는 함수.
//집합 P에 대한 표현은 include 배열로 하며 집합 S에 대한 표현은 인덱스 k값으로 결정한다. 
void powerset(int k){   //include 배열과 k값에 의해 상태공간트리에서의 위치가 결정된다. 
    int i;
    if(k == N){ //base case
        for(i = 0; i < N; i++) if(include[i]) printf("%c ", data[i]);
        printf("\n");
    }else{
        include[k] = false;
        powerset(k+1);
        include[k] = true;
        powerset(k+1);
    }
}

int main(void){
    powerset(0);
    return 0;
}