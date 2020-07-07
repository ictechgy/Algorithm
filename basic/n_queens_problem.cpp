//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 8;

int cols[N+1];
bool promising(int level){  //이전에 놓인 말들과 level번째 놓인 말이 충돌하는지 검사
    int i;
    for(i = 1; i < level; i++){
        if(cols[i] == cols[level]) return false;    //같은 열에 있는지 검사
        else if(level - i == abs(cols[level] - cols[i])) return false;  //대각선 검사
    }
    return true;
}   //행에 대한 검사는 필요 없다. 어차피 한 행당 말은 하나씩만 놓을 것이므로.

bool queen(int level){  //상태 공간 트리에서 level에 해당하는 노드에 도착한 이후. 
    int i;
    if(!promising(level)) return false;
    else if(level == N) return true;
    else{
        for(i = 1; i <= N; i++){
            cols[level+1] = i;
            if(queen(level+1)) return true;
        }
        return false;
    }
}

void printQueens(){
    int i, j;
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            if(cols[i] == j) printf("*");
            else printf("#");
        }
        printf("\n");
    }
}

int main(void){
    queen(0);   //level 0은 상태공간트리의 root노드로서 시작지점의 역할일 뿐 아무런 영향도 끼치지 않는다. 
    printQueens();
    return 0;
}
