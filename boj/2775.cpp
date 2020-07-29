#include <stdio.h>
#include <memory.h>

int apt[15][15];

//(i, j)의 거주자 수는 (i-1, 1) ~ (i-1, j)의 거주자 수의 합이다.
//Memoization or dp -> (i, j)의 거주자 수는 (i, j-1) + (i-1, j)이다. 
int numResidents(int k, int n){ //k층 n호 거주자 수 반환 - recursive
    if(apt[k][n] != -1) return apt[k][n];
    else{
        apt[k][n] = numResidents(k, n-1) + numResidents(k-1, n);
        return apt[k][n];
    }
}

int main(void){
    int t, i, k, n;
    memset(apt, 255, sizeof(apt));  //모든 배열공간을 1바이트씩 255로 초기화 -> -1로 초기화
    for(i = 0; i < 15; i++){
        apt[0][i] = i;
        apt[i][0] = 0;
    }
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d\n%d", &k, &n);
        printf("%d\n", numResidents(k, n));
    }

    return 0;
}