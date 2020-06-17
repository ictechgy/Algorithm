// #include <stdio.h>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(void){
//     int n, m, i, pl = 0, pr, pc, sum = 0;
//     scanf("%d %d", &n, &m);
//     vector<int> arr(n);
//     for(i = 0; i < n; i++){
//         scanf("%d", &arr[i]);
//     }
//     pr = n-1;
//     //sort(arr.begin(), arr.end());   //need?
//     for(i = 1; i < m; i++){
//         pc = (pl + pr) / 2;
//         pl = pc + 1;
//     }
//     for(i = pl; i <= pr; i++) sum+=arr[i];  //max value?
//     printf("%d\n", sum);
//     //이 접근방식이 아닌 것 같다..

//     return 0;
// }

//방식은..
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, m, i, pl, pr, pc, sum = 0, value, cnt, per;
    scanf("%d %d", &n, &m);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    // 1 ~ sum 중 하나
    pl = arr[0];
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
        if(cnt <= m) {
            value = pc;
            pr = pc - 1;
        }else{
            pl = pc + 1;
        }
    }
    printf("%d\n", cnt);

    return 0;
}