#include <stdio.h>

int arr[100], tmp[100];

void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main(void){
    int i, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n-1);

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}

void mergesort(int arr[], int s, int e){
    if(s >= e) return;  //그 자체로 정렬 
    int m = (s+e)/2;
    mergesort(arr, s, m);
    mergesort(arr, m+1, e);
    merge(arr, s, m, e);
}

void merge(int arr[], int s, int m, int e){
    int l = s, r = m+1, i = 0, j;
    while(l <= m && r <= e){
        if(arr[l] < arr[r]) tmp[i++] = arr[l++];
        else tmp[i++] = arr[r++];
    }
    while(l <= m) tmp[i++] = arr[l++];
    while(r <= e) tmp[i++] = arr[r++];

    for(i = s, j = 0; i <= e; i++, j++){
        arr[i] = tmp[j];
    }
}

//
#include <stdio.h>
int data[10], tmp[10];

void divide(int lt, int rt){
    int mid, p1, p2, p3;
    if(lt < rt){
        mid = (lt + rt)/2;
        divide(lt, mid);
        divide(mid+1, rt);
        
        p1 = lt;
        p2 = mid+1;
        p3 = lt;
        while(p1 <= mid && p2 <= rt){
            if(data[p1] < data[p2]) tmp[p3++] = data[p1++];
            else tmp[p3++] = data[p2++];
        }
        while(p1 <= mid) tmp[p3++] = data[p1++];
        while(p2 <= rt) tmp[p3++] = data[p2++];
        
        for(int i = lt; i <= rt; i++){
            data[i] = tmp[i];
        }

    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &data[i]);
    }
    divide(1, n);
    for(i = 1; i <= n; i++){
        printf("%d ", data[i]);
    }
    return 0;
}
