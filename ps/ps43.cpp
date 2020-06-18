#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, m, i, pl = 0, pr, pc, sum = 0;
    scanf("%d %d", &n, &m);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    pr = n-1;
    //sort(arr.begin(), arr.end());   //need?
    for(i = 1; i < m; i++){
        pc = (pl + pr) / 2;
        pl = pc + 1;
    }
    for(i = pl; i <= pr; i++) sum+=arr[i];  //max value?
    printf("%d\n", sum);
    //이 접근방식이 아닌 것 같다..

    return 0;
}

//방식은..
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, m, i, pl, pr, pc, sum = 0, value, cnt, per, max = -2100000000;
    scanf("%d %d", &n, &m);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] > max) max = arr[i];
    }
    // max ~ sum 중 하나
    pl = max;   //이것보다는 최소한 커야함. 
    pr = sum;
    while(pl<=pr){
        cnt = 1;
        per = 0;
        pc = (pl + pr) / 2;
        for(i = 0; i < n; i++){
            per+=arr[i];
            if(per > pc){
                cnt++;
                per = arr[i];
                if(cnt > m) break;  //Overflow
            }
        }
        if(cnt <= m) {  //cnt < m 인 경우 사실 pc를 줄여야 하기 때문에 그냥 pr = pc - 1 만 해줘도 될 듯
            value = pc;
            pr = pc - 1;    //작은 값으로 재시도
        }else{
            pl = pc + 1;    //큰 값으로 재시도
        }
    }
    printf("%d\n", value);

    return 0;
}

//
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1001], n;

int Count(int s){
    int i, cnt = 1, sum = 0;
    for(i = 1; i <= n; i++){
        if(sum + a[i] > s){
            cnt++;
            sum = a[i];
        }else sum += a[i];
    }
    return cnt;
}

int main(){
    int m, i, lt = 1, rt = 0, mid, res, maxx = -2147000000;
    scanf("%d %d", &n, &m);
    for(i = 1; i<= n; i++){
        scanf("%d", &a[i]);
        rt = rt + a[i];
        if(a[i] > maxx) maxx = a[i];
    }
    while(lt <= rt){
        mid = (lt + rt) / 2;
        if(mid >= maxx && Count(mid) <= m){
            res = mid;
            rt = mid - 1;
        }else lt = mid + 1;
    }
    printf("%d\n", res);

    return 0;
}