#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int n, i, j, tmp, idx, r = 0, val = 101;
    scanf("%d", &n);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n - 1; i++){
        idx = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] > arr[idx]) idx = j;
        }
        tmp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = tmp;
        if(val != arr[i]){
            val = arr[i];
            r++;
            if(r == 3) break;
        }   //정렬을 다 한 뒤에 체크를 해볼수도 있겠다만..그러지 않아도 될 듯
    }
    printf("%d\n", val);
    
    return 0;
}

//
#include <stdio.h>
int main(){
    int n, a[101], i, j, tmp, idx, cnt = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n - 1; i++){
        idx = i;
        for(j = i + 1; j < n; j++){
            if(a[j] > a[idx]) idx = j;
        }
        tmp = a[i];
        a[i] = a[idx];
        a[idx] = tmp;
    }
    for(i = 1; i < n; i++){
        if(a[i-1] != a[i]) cnt++;
        if(cnt == 2) {
            printf("%d\n", a[i]);
            break;
        }
    }

    return 0;
}