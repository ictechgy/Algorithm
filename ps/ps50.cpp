#include <stdio.h>
#include <vector>
#include <algorithm>

int main(void){
    int h, w, i, j, max = 0;
    scanf("%d %d", h, w);
    vector<vector<int> > arr(h, vector<int>(w));
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            scanf("%d", arr[i][j]);
        }
    }
    scanf("%d %d", h, w);

    //가장 간단한 방법은 가능한 모든 공간영역(상태공간)을 탐색해보는것..
    //하지만 그렇게 하면 시간복잡도가 너무 커진다. 
    //또는 탐색을 할 때 값을 처음부터 다시 합산하는게 아니라 이동된 만큼만 왼쪽 값에서 빼고 오른쪽 값은 더하는 방식도
    //가능할거같은데.. (오른쪽 방향으로 검색한다고 했을 때)
    

    return 0;
}