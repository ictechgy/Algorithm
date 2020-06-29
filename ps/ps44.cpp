#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, c, i;
    scanf("%d %d", &n, &c);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());   //arr.begin(), arr.end()는 arr.front()와 arr.back()과 다름
    //최소거리는 1, 최대거리는 arr.end()-arr.front()이다. 이 중 가능한 가장 최대의 거리 구하기
    int pl = 1, pr = arr.back() - arr.front(), dist, max = -2140000000, j, gap;
    while(pl <= pr){
        dist = (pl + pr) / 2;   //중간 거리 값 선택
        j = 0;  //arr에 대한 인덱스
        gap = 0;
        for(i = 2; i < c; i++){ //해당 dist 이상으로 모두 배치가 가능한지 체크
            //0과 1에 해당하는 값 두개는 범위(arr값) 중 맨 앞과 맨 뒤에 미리 배치
            //모두 배치하기 전 범위를 넘어가버린다면 dist를 줄이고, 모두 배치하기에 충분했다면 dist를 늘리는 방식으로 진행
            j++;
            if(j < n-1){
                gap += arr[j] - arr[j-1];   //거리차이
                if(gap < dist) i--;
                else gap = 0;   //배치
            }else break;
        }
        
        if(i == c && (arr[n-1] - arr[j] >= dist )  /* && max < dist */){   //배치가 끝났으며 배치 가능한 거리로 설정한 최소값이 여태까지의 수 보다 더 긴 거리인 경우(두번째 조건의 경우 없어도 될 듯)
            //(arr[n-1] - arr[j] >= dist  -> 마지막 배치한 값과 맨 뒤의 값의 거리도 따져야 하므로 넣은 조건식
            max = dist;
            pl = dist + 1;  //거리를 더 띄워서 retry
        }else{  
            pr = dist - 1;  //해당 값의 거리로 배치를 다 못한 경우 거리 값을 줄이고 다시 try
        }
    }
    printf("%d\n", dist);

    return 0;
}

//binary search는 배열에서 원하는 값을 찾는 알고리즘으로 시작하지만
//결정알고리즘에서는 답이 될 수 있는 후보군을 반씩 줄여나가며 진짜 정답을 찾아나가는 알고리즘으로써
//쓰이는 것으로 보인다. 