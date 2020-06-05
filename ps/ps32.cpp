#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int n, i, tmp, idx, j;
    scanf("%d", &n);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n -1; i++){
        idx = i;
        for(j = i + 1; j < n; j++){
            if(arr[idx] > arr[j]) idx = j;
        }
        if(idx != i){
            tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int a[100], n, idx, i, j, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n - 1; i++){
        idx = i;
        for(j = i + 1; j < n; j++){
            if(a[j] < a[idx]) idx = j;
        }
        tmp = a[i];
        a[i] = a[idx];
        a[idx] = tmp;
    }
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}