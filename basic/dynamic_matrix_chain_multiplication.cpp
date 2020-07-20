//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

//일반적으로 행렬의 곱셈은 아래와 같이 해결이 가능하다. 
void product(int **A, int **B, int **C, int p, int q, int r){
//A는 p*q 행렬, B는 q*r행렬, 결과값을 저장할 C행렬은 p*r행렬이다. 
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            C[i][j] = 0;
            for(int k = 0; j < q; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}
//시간복잡도는 pqr이다. 

//하지만 위와같이 해결하려 한다면 matrix chain 즉, 여러개 행렬들의 곱셈에서 시간복잡도는 굉장히 커질 것이다. 
//행렬은 교환법칙이 성립하지 않으나 결합법칙은 성립하므로 곱의 순서를 바꿔 시간복잡도를 줄이는 것은 가능하다.
//그렇다면 어떻게 곱을 하는게 연산량을 줄일 수 있는 방법일까? 최적의 순서는?

//A1*A2*A3*...Ai*Ai+1*...An까지의 행렬 곱이 있다고 했을 때
//최종 결과인 값이 나오기 전에는 어떤 두 행렬만이 남아있었을 것이다. 두 행렬을 마지막으로 곱했을 때 최종 결과가 도출되는.
//그러면 그 이전 결과값인 두 행렬이 그 부분에 대한 최적해인가? 라고 묻는다면 맞다고 할 수 있다.
//(모든 문제에 대해 최적해의 일부분이 그 부분에 대한 최적해인가 물어보고 순환식을 세워볼 수는 있지만 항상 단순하게 순환식이 맞아떨어지지는 않는다. ex-최장경로문제)

//이 때 두 행렬이 되는 부분에 대하여 구분점을 k라고 하자. 즉 행렬 하나는 Ai부터 Ak까지의 곱이고 다른 행렬은 Ak+1부터 An까지의 곱이다.(i<=k<=j-1)
//행렬 i~j까지의 곱의 최소 연산수를 m[i, j]라고 한다면 이에 대한 순환식은 아래와 같이 세워진다.
//  0 -> i=j인 경우
//  min(m[i, k] + m[k+1, j] + Pi-1*Pk*Pj) -> i<j 이면서 i<=k<=j-1 일 때
//=> 최적해들은 다시 더 작은 subproblem들의 최적해로 나누어지므로 general case는 base case로 수렴한다.

//따라서 위의 식을 아래와 같은 함수로 만들어 볼 수 있다. 
//2차원 m배열이 주어진다. 해당 배열의 m[i, j]는 Ai~Aj까지의 최소 연산값을 저장한다. 
int m[9][9];
int p[9];   //p배열은 각 배열의 행렬을 의미한다. 0번인덱스는 A1의 행, 1번인덱스는 A1의 열, A2의 행, 2번인덱스는 A2의 열이자 A3의 행..
int matrixChain(int n){ //우리가 원하는 최종값은 A1 ~ An까지의 최소연산값이므로 n값을 매개변수로
    for(int i = 1; i <= n; i++){
        m[i][i] = 0;  //i<=j 이므로 대각선의 값들은 모두 0으로 채운다. 그리고 그 대각선 위의 값만을 사용 할 것이다.
    }
    for(int r = 1; r <= n-1; r++){  //r은 대각선을 의미한다.
        for(int i = 1; i <= n-r; i++){  //각 대각선에서의 값의 개수
            int j = i + r;  //대각선을 타고 내려갈 때 행번호는 i를 그대로 타고 내려가지만 열번호인 j는 i+r로 구할 수 있다.
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]; //k가 i인 경우를 최소값으로 먼저 가정
            for(int k = i+1; k <= j-1; k++){
                if(m[i][j] > m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[k]){
                    m[i][j] = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[k];
                }
            }
        }
    }
    return m[1][n]; //원하는 답
}

//시간 복잡도는 Θ(n^3)