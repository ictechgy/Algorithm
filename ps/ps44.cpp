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
    //pl과 pr은 가능한 거리의 값 중 최소 값과 최대 값을 나타내고 이 값들 중 정답 값을 이분탐색으로 찾아가기
    while(pl <= pr){
        dist = (pl + pr) / 2;   //중간 거리 값 선택
        j = 0;  //arr에 대한 인덱스
        gap = 0;    //거리차이 값
        for(i = 2; i < c; i++){ //해당 dist 이상으로 모두 배치가 가능한지 체크
            //0과 1에 해당하는 값 두개는 범위(arr값) 중 맨 앞과 맨 뒤에 미리 배치
            //모두 배치하기 전 범위를 넘어가버린다면 dist를 줄이고, 모두 배치하기에 충분했다면 dist를 늘리는 방식으로 진행
            j++;
            if(j < n-1){    //j는 1 ~ n-2의 값을 가진다. 맨 앞과 맨 뒤에는 이미 배치하였다고 가정하였으므로 가능한 값은 그 중간값만.
                gap += arr[j] - arr[j-1];   //거리차이
                if(gap < dist) i--; //거리가 부족하다면 그 다음 공간으로
                else gap = 0;   //배치
            }else break;    //if문의 조건을 j<n 으로 하여 계산 할 수도 있을 것 
        }
        
        if(i == c && (arr[n-1] - arr[j] >= dist )  /* && max < dist */){   //배치가 끝났으며 배치 가능한 거리로 설정한 최소값이 여태까지의 수 보다 더 긴 거리인 경우(세번째 주석 조건의 경우 없어도 될 듯)
            //(arr[n-1] - arr[j] >= dist  -> 마지막 배치한 값과 맨 뒤의 값의 거리도 따져야 하므로 넣은 조건식
            max = dist;
            pl = dist + 1;  //거리를 더 띄워서 retry
        }else{  
            pr = dist - 1;  //해당 값의 거리로 배치를 다 못한 경우 or 맨 뒤의 값과 그 전 배치값이 dist거리 미만인 경우 거리 값을 줄이고 다시 try
        }
    }
    printf("%d\n", max);

    return 0;
}

//binary search는 배열에서 원하는 값을 찾는 알고리즘으로 시작하지만
//결정알고리즘에서는 답이 될 수 있는 후보군을 반씩 줄여나가며 진짜 정답을 찾아나가는 알고리즘으로써
//쓰이는 것으로 보인다. 


//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int Count(int len, int x[]){
    int i, cnt = 1, pos = x[1];
    for(i = 2; i <= n; i++){
        if(x[i]-pos >= len){
            cnt ++;
            pos = x[i];
        }
    }
    return cnt;
}

int main(){
    int m, i, lt = 1, rt, mid, res;
    scanf("%d %d", &n, &m);
    int *x = new int[n + 1];
    for(i = 1; i < n; i++){
        scanf("%d", &x[i]);
    }
    sort(x+1, x+n+1);
    rt = x[n];
    while(lt <= rt){
        mid = (lt + rt) / 2;
        if(Count(mid, x) >= m){
            res = mid;
            lt = mid + 1;
        }
        else rt = mid - 1;
    }
    printf("%d\n", res);
    delete[] x;
    return 0;
}