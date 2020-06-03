#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int n, i, j;
    freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    vector<int> arr(n), ran(n, 1);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < i; j++){
            if(arr[j] >= arr[i]) ran[i]++;
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", ran[i]);
    }
    

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int i, j, n, cnt = 0;
    scanf("%d", &n);
    vector<int> a(n+1); //1부터 사용
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    printf("1 ");
    for(i = 2; i <= n; i++){
        cnt = 0;
        for(j = i - 1; j >= 1; j--){
            if(a[j] >= a[i]) cnt++;
        }
        printf("%d ", cnt + 1);
    }

    return 0;
}
