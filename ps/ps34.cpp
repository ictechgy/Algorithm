#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int n, i, tmp, j;
    scanf("%d", &n);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = n - 1 ; i > 0; i--){
        for(j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

//
#include <stdio.h>
int main(){
    int a[101], n, i, j, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n - 1 ; i++){
        for(j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}