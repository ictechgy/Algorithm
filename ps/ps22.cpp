#include <stdio.h>
#include <time.h>

int main(void){
    time_t start, end;
    int n, ref, max = 0, i, val[100000], sum = 0, last;
    freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &ref);
    for(i = 0; i < n; i++){
        scanf("%d", &val[i]);   //입력받기
    }
    start = clock();
    for(i = 0; i < ref; i++){
        sum += val[i];  //가장 첫 누적합 값을 구한다.
    }
    max = sum;  //첫 누적합 값이 가장 크다고 가정

    //전체 부분합의 계산 횟수는 n-ref+1번이다. 위에서 한번을 미리 했으므로
    //n-ref번만 더 해봐주면 된다.
    last = ref-1;   //가장 마지막에 더했던 요소의 인덱스번호
    for(i = 0; i < n-ref; i++){
        sum = sum - val[i];   //누적합 중 가장 앞의 요소를 합에서 뺀다.
        sum = sum + val[++last];   //누적합에 가장 뒤의 다음요소를 더한다. 
        if(sum > max) max = sum;    //만약 해당 누적합이 더 크면 바꾸기
    }
    end = clock();
    printf("%d\n", max);
    printf("걸린 시간: %f\n", (double)(end-start)/CLOCKS_PER_SEC);      //최대 소요시간: 0.000291초

    return 0;
}

//이중for문으로 짜보는 경우
#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    freopen("input.txt", "rt", stdin);
    int n, k, i, j, sum = 0, max = -2147000000;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i <= n-k; i++){
        sum = 0;
        for(j = i; j < i + k; j++){
            sum = sum + a[j];   //합을 계속 새로 구함
        }
        if(sum > max) max = sum;
    }
    printf("%d\n", max);

    return 0;
}

//
#include <stdio.h>
#include <vector>
int main(){
    int n, k, i, sum = 0, max;
    scanf("%d %d", &n, &k);
    std::vector<int> a(n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < k; i++){
        sum += a[i];
    }
    max = sum;  //첫 구간합
    for(i = k; i < n; i++){
        sum = sum + (a[i] - a[i-k]);
        if(sum > max) max = sum;
    }
    printf("%d\n", max);

    return 0;
}