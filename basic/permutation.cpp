//from Youtube by 권오흠 교수님 - https://youtu.be/MjW10t9ppok
#include <iostream>

char data[] = {'a', 'b', 'c', 'd'};
int n = 4;

void perm(int);
void swap(char[], int, int);

int main(){
    perm(0);
    
    std::cin.get();
    return 0;
}

void perm(int k){       //배열에서 k가 가리키는 부분 이전의 값들은 prefix string, 이상의 값들은 순열집합 S이며, perm함수가 하는 일은 순열조합 S를 구한 뒤 그 앞에 prefix 값을 붙여 출력하는 것
    if(k == n){
        for(int i = 0; i < n; i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
        return;
    }

    for(int i = k; i < n; i++){
        swap(data, k, i);   //대장 정하기(순열 집합 S에서 맨 왼쪽에 갈 값을 정하여 prefix로 만들기)
        perm(k + 1);        //이 함수가 끝나고 돌아왔을 때 k 이후의 값의 위치가 그대로인가 하는 문제가 이 방식이 맞는지를 결정짓는 중요한 부분이다. 
        swap(data, k, i);   //중요한 부분. 원위치 되돌리기
    }
}

void swap(char array[], int x, int y){
    char tmp = array[x];
    array[x] = array[y];
    array[y] = tmp; 
}

//멱집합은 Knapsack에서 활용될 수 있다. - dp로 풀 수도 있지만, 모든 물품의 멱집합을 구한 뒤 집합 중 무게가 초과하는 것은 가지치고, 나머지 가능한 집합 중 가장 가격이 많이나가는 집합을 선택할 수도 있다.
//순열 나열은 TSP(Traveling Salesperson's Problem)에서 활용될 수 있다. - 어떤 순서로 방문하는 것이 효율적인가 하는 문제는 모든 방문가능한 순서 순열을 구한 뒤 그 중 가장 저렴한 노선을 선택함으로써 해결할 수 있다. 