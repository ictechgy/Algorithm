#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, i, j, sum = 0;
    scanf("%d", &n);
    vector<int> front(n), right(n);
    for(i = 0; i < n; i++){
        scanf("%d", &front[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &right[i]);
    }
    vector<vector<int> > upside(n, vector<int>(n)); //n * n
    
    //우선 정면값으로 upside를 채우기
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            upside[j][i] = front[i];
        }
    }
    //right값으로 쳐내기
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(upside[i][j] > right[n-i-1]) upside[i][j] = right[n-i-1];
        }
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            sum += upside[i][j];
        }
    }

    printf("%d\n", sum);

    return 0;
}
//또는 아예 처음부터 정면값과 right값 비교해서 가능한 값중 최대값으로 upside vector 각 공간을 할당하는 방법도 있을 듯
//정면은 각 열에서의 가능한 최대값, right는 각 행에서의 가능한 최대값이므로 특정 행열에서는 두 최대값 중 작은 값으로.

//위에서 설명한 방법?
int main2(void){
    int n, i, j, sum = 0;
    scanf("%d", &n);
    vector<int> front(n), right(n);
    for(i = 0; i < n; i++){
        scanf("%d", &front[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &right[i]);
    }

    vector<vector<int> > upside(n, vector<int>(n));
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            upside[i][j] = min(front[j], right[n-i-1]);
            sum += upside[i][j];
        }
    }
    printf("%d\n", sum);

    return 0;
}