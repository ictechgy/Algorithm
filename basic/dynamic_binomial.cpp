//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

//이항계수 binomial Coefficient 구하기
//이항계수는 nCk 라고 하고 n개 중에서 k개를 선택하는 경우의 수라고 보면 된다. 
//nCk는 n과 k가 같거나 k가 0인 경우 1이고 그 이외에는 n!/(n-k)!*k! 로 구할 수도 있지만 
//nCk = (n-1)Ck + (n-1)C(k-1)이라는 순환식도 세워볼 수 있다. 
//-> n개 중에서 특정한 한개를 뽑지 않고(n-1) k개를 뽑는 경우, n개 중에서 특정한 한개를 뽑고(n-1) 나머지 k-1개를 뽑는 경우

int binomial(int n, int k){    //n >= k
    if(n == k || k == 0) return 1;  //n개 중에서 n개를 뽑거나 아무것도 뽑지 않는 경우의 수는 1개이다. - base case
    else return binomial(n-1, k) + binomial(n-1, k-1);
    //recursive case인데, 왼쪽 재귀호출은 n이 1씩 줄어드므로 반복되다보면 언젠가 n == k인 순간이 올 것이며
    //오른쪽 재귀호출은 언젠가 k==0이 되는 경우가 올 것이다. 즉 base case로 수렴
    //-> 많은 계산이 중복된다. 
}

//Memoization
//n과 k에 의해 결정되므로 2차원 배열 생각
int binom[100][100];    //배열의 크기는 가변, 모든 공간은 -1로 초기화
//배열의 행은 n, 배열의 열은 k라고 생각한다면 대각선 위쪽은 사용하지 않는다. (n >= k)
int binomial(int n, int k){
    if(n == k || k == 0) return 1;
    else if(binom[n][k] > -1) return binom[n][k];
    else{
        binom[n][k] = binomial(n-1, k) + binomial(n-1, k-1);
        return binom[n][k];
    }
}

//dynamic programming - 순환식의 우변 값을 먼저 계산하여 좌변 값을 바로 도출
int binomial(int n, int k){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k && j <= i; j++){
            if(k == 0 || n == k) binom[i][j] = 1;
            else binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
        }
    }
    return binom[n][k];
}
