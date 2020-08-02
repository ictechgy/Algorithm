#include <stdio.h>
#include <vector>
#include <algorithm>
#define N 9
int main(void){
    int grid[N][N], i, j;
    int avg[N], sum, nearby[N] = {0, }, gap, res;
    for(i = 0; i < N; i++){
        sum = 0;
        for(j = 0; j < N; j++){
            scanf("%d", &grid[i][j]);
            sum += grid[i][j];
        }
        //한 행을 다 입력 받았을 때 평균을 바로 계산
        avg[i] = (int)(((float)sum/N) + 0.5);   //소수점 첫 째 자리에서 반올림

        //값 찾기 - 인덱스를 저장할 수도 있고 값 자체를 저장할 수도 있고.. 
        gap = 100;
        for(j = 0; j < N; j++){
            res = abs(avg[i] - grid[i][j]);
            if(res < gap || (res == gap && nearby[i] < grid[i][j])){
                gap = res;
                nearby[i] = grid[i][j];
            }
        }
        
        //출력
        printf("%d %d\n", avg[i], nearby[i]);
    }
    
    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[10][10];
int main(void){
    int i, j, sum, ave, min, tmp, res; 
    for(i = 1; i <= 9; i++){
        sum = 0;
        for(j = 1; j <= 9; j++){
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
        ave = (sum/9.0)+0.5;    //굳이 int로 감싸지 않아도 되겠구나. 
        printf("%d ", ave);
        min = 2147000000;
        for(j = 1; j <= 9; j++){
            tmp = abs(a[i][j] - ave);
            if(tmp < min){
                min = tmp;
                res = a[i][j];
            }else if(tmp == min){
                if(a[i][j] > res) res = a[i][j];
            }
        }
        printf("%d\n", res);
    }

    return 0;
}
//grid배열은 사실 1차원 배열로 해도 되는구만.. 어차피 한줄만 데이터를 쓰고 버리므로.
//avg, nearby 또한 배열이 아닌 단순 int변수로 설정해도 됨. (출력만 하고 끝이므로)