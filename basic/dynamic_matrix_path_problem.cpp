//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <algorithm>

//행렬 경로문제. (1,1)에서 특정 지점까지 비용의 최소가 되도록 진행하기

//일반적 구현
int m[100][100];    //matrix의 각 방에는 특정 비용 값으로 채워짐.
int mat(int i, int j){
    if(i == 1 && j == 1) return m[i][j];
    else if(i == 1) return mat(1, j-1) + m[i][j];
    else if(j == 1) return mat(i-1, 1) + m[i][j];
    else return std::min(mat(i-1, j), mat(i, j-1)) + m[i][j];
}

//Memoization
int L[100][100];    //최소비용을 따로 저장하는 배열, 모든 공간의 값은 -1로 초기화
int mat(int i, int j){
    if(L[i][j] != -1) return L[i][j];

    if(i == 1 && j == 1) return m[i][j];
    else if(i == 1) L[i][j] = mat(1, j-1) + m[i][j];
    else if(j == 1) L[i][j] = mat(i-1, 1) + m[i][j];
    else L[i][j] = std::min(mat(i-1, j), mat(i, j-1)) + m[i][j];

    return L[i][j];
}

//bottom-up
int mat(int n, int l){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= l; j++){
            if(i == 1 && j == 1) L[i][j] = m[1][1];
            else if(i == 1) L[i][j] = m[i][j] + L[i][j-1];
            else if(j == 1) L[i][j] = m[i][j] + L[i-1][j];
            else L[i][j] = m[i][j] + std::min(L[i-1][j], L[i][j-1]);
        }
    }
    return L[n][l];
}

//배열은 0부터 시작하므로 L[0][j]와 L[i][0]의 비용을 무한대로 놓는다고 생각하면 식이 훨씬 간결해진다. 
int mat(int n){ //n, n까지 이동
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && j == 1) L[i][j] = m[1][1];
            else L[i][j] = m[i][j] + std::min(L[i-1][j], L[i][j-1]);    //별개의 case들을 하나로 통합
        }
    }
    return L[n][n];
}

//경로 -> 경로를 저장할 배열을 하나 더 만든다.
char P[100][100];
int mat(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && j == 1){
                L[i][j] = m[1][1];
                P[i][j] = '-';
            }else{
                if(L[i-1][j] < L[i][j-1]){
                    L[i][j] = m[i][j] + L[i-1][j];
                    P[i][j] = '↑';
                }else{
                    L[i][j] = m[i][j] + L[i][j-1];
                    P[i][j] = '←';
                }
            }
        }
    }
    return L[n][n];
}

void printPath(int n){  //거꾸로 출력
    int i = n, j = n;
    while(P[i][j] != '-'){
        printf("(%d,%d)\n", i, j);  //현재 위치 출력
        if(P[i][j] == '←') j = j-1;
        else i = i-1;
    }
    printf("(%d,%d)\n", i, j);  //출발지 위치 출력
}

void printPathRecursive(int i, int j){  //정방향 출력, 최초 호출시에는 목적지 좌표를 인수로.
    if(P[i][j] == '-') printf("(%d,%d)\n", i, j);
    else{
        if(P[i][j] == '←') printPathRecursive(i, j-1);
        else printPathRecursive(i-1, j);
        printf("(%d,%d)\n", i, j);
    }
}