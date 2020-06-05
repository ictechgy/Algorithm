#include <stdio.h>
#include <vector>
using namespace std;
#define swap(type, x, y) do{ type t = x; x = y; y = t; }while(0)

int main(void){
    int n, i, j;
    scanf("%d", &n);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    //safe하게 이동시키면서도 옮기려는 왼쪽 값이 양수인 경우에만 swap?
    for(i = n - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(arr[j] > 0 && arr[j+1] < 0 /* && arr[j] > arr[j+1] */) swap(int, arr[j], arr[j+1]);
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
int main(){
    int a[101], n, i, j, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n-1; i ++){
        for(j = 0; j < n-i-1; j++){
            if(a[j] > 0 && a[j+1] < 0){
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
//선택방식은 힘들거같고 삽입방식은 가능할거같다. 