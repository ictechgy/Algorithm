#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int n, i, j, tmp;
    scanf("%d", &n);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 1; i < n; i++){
        tmp = arr[i];
        for(j = i-1; j >= 0; j--){
            if(arr[j] < tmp) break;
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
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
int main(){
    int a[100], n, tmp, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 1; i < n; i++){
        tmp = a[i];
        for(j = i-1; j >= 0; j--){
            if(a[j] > tmp) a[j+1] = a[j];
            else break;
        }
        a[j+1] = tmp;
    }
    for(i = 0; i < n; i++){
        printf("%d", a[i]);
    }

    return 0;
}