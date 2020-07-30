#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, k, i, pos = 0, cnt = 0, sum = 0;
    scanf("%d", &n);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    scanf("%d", &k);
    //2차원 배열로 만들어보면 각 값만큼 세로열로 늘려놓았을 때(1 값으로)
    //1의 값이 있는 부분만 순서대로 읽어나가다가 k번째 이후 뒤에 1이 있는 곳의 인덱스를 구하면 될 것 같다.
    //하지만 이 방법은 공간복잡도가 너무 클 것 같은데.. 

    //다른 방법으로는 k값만큼 순회하면서 값을 줄여나가서 찾는 방법(0이 된 곳은 건너뛰고)
    //또 다른 방법은 없을까? 자료구조로는 원형 Linked list나 큐정도 쓸법하고..(다 된 작업은 pop, 다 안됐으면 뒤로 다시 push) or 원형 큐.. 

    if(sum <= k){
        printf("-1\n");
        return 0;
    }
    while(1){
        if(arr[pos] != 0){
            cnt++;
            if(cnt == k + 1) break;
            arr[pos]--;
        }
        ++pos %= n;
    }
    printf("%d\n", pos+1);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[2001];
int main(){
    int n, k, i, p = 0, cnt = 0, tot = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        tot += a[i];
    }
    scanf("%d", &k);
    if(k >= tot){
        printf("-1\n");
        return 0;
    }
    while(1){
        p++;
        if(p > n) p = 1;
        if(a[p] == 0) continue;
        a[p]--;
        cnt++;
        if(cnt == k) break;
    }
    while(1){
        p++;
        if(p > n) p = 1;
        if(a[p] != 0) break;
    }
    printf("%d\n", p);

    return 0;
}