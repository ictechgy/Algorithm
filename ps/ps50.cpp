#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int h, w, i, j, max = 0, y, x, sum, k, l;
    scanf("%d %d", &y, &x);
    vector<vector<int> > arr(y, vector<int>(x));
    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d %d", &h, &w);

    //가장 간단한 방법은 가능한 모든 공간영역(상태공간)을 탐색해보는것..
    //하지만 그렇게 하면 시간복잡도가 너무 커진다. 
    //n*n이 전체크기, 합산범위를 n/2*n/2라고 한다면 합산하는데 n^2/4의 시간복잡도에 가로 세로 각각 n/2+1 만큼 반복계산해야 하므로
    //총 O(n^4)정도의 시간복잡도가 소요될려나.. 합산을 상수시간 O(1)이라고 해도 O(n^2)은 피하기 어려워보인다. 

    //또는 탐색을 할 때 값을 처음부터 다시 합산하는게 아니라 이동된 만큼만 제외된 부분은 빼고 추가된 부분은 더하는 방식도
    //가능할거같은데.. (단 이 경우 이후에 입력받는 h, w의 값에 따라 어디가 제외되고 추가되는지가 달라지므로 일반화를 고려)


    //단순히 모든 공간을 탐색하는 가장 일반적인 방법
    for(i = 0; i < y-h+1; i++){
        for(j = 0; j < x-w+1; j++){ //합산의 시작점은 좌측상단의 좌표값을 기준으로 한다. 따라서 가로 세로 범위를 벗어나는 덧셈이 일어나지 않도록 제한
            sum = 0;
            for(k = 0; k < h; k++){
                for(l = 0; l < w; l++){
                    sum += arr[i+k][j+l];
                }
            }
            if(sum > max) max = sum;
        }
    }
    printf("%d\n", max);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[51][51];
int main(){
    int h, w, n, m, i, j, k, s, sum = 0, max = -2147000000;
    scanf("%d %d", &h, &w);
    for(i = 1; i <= h; i++){
        for(j = 1; j <= w; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &n, &m);
    for(i = 1; i <= h-n+1; i++){
        for(j = 1; j <= w-m+1; j++){
            sum = 0;
            for(k = i; k < i+n; k++){
                for(s = j; s < j+m; s++){
                    sum = sum+a[k][s];
                }
            }
            if(sum > max){
                max = sum;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}