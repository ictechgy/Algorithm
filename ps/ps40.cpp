#include <stdio.h>
#include <vector>
using namespace std;

void mergesort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

int main(void){
    int n, m, i;
    scanf("%d", &n);
    vector<int> arr1(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &m);
    vector<int> arr2(m);
    for(i = 0; i < m; i++){
        scanf("%d", &arr2[i]);
    }

    //두 배열을 우선 각각 정렬 - merge sort / top down 방식을 쓸 건데 bottom up은 어떻게 하지..?
    mergesort(arr1, 0, n-1);
    mergesort(arr2, 0, m-1);

    int small = ( n < m )? n : m;
    //교집합의 최대 개수는 작은 집합의 수 
    vector<int> inter(small);   //intersects
    int p1, p2, p3;
    p1 = p2 = p3 = 0;
    while(p1 < n && p2 < m){
        if(arr1[p1] == arr2[p2]) {
            inter[p3] = arr1[p1];
            p1++;
            p2++; 
            p3++;
        }else if(arr1[p1] < arr2[p2]){
            p1++;
        }else p2++;
    }
    printf("intersects -> ");
    for(i = 0; inter[i] != 0; i++){
        printf("%d ", inter[i]);
    }

    return 0;
}

void mergesort(vector<int>& arr, int start, int end){
    if(!(start<end)) return; //base case
    int center = (start + end) / 2;
    mergesort(arr, start, center);
    mergesort(arr, center + 1, end);
    merge(arr, start, center, end);
}


void merge(vector<int>& arr, int start, int center, int end){
    vector<int> tmp(end-start+1);   //임시 배열 생성
    int p1 = start;
    int p2 = center + 1;
    int p3 = 0;

    while(p1 <= center && p2 <= end){
        if(arr[p1] < arr[p2]) tmp[p3++] = arr[p1++];
        else tmp[p3++] = arr[p2++];
    }
    while(p1 <= center) tmp[p3++] = arr[p1++];
    while(p2 <= end) tmp[p3++] = arr[p2++];

    for(int i = 0; i < tmp.size(); i++){
        arr[start++] = tmp[i];
    }
}



//가능한 또다른 방법 - 복잡도는 n^2
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n, m, i, j, p = 0;
    scanf("%d", &n);
    vector<int> arr1(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &m);
    vector<int> arr2(m);
    for(i = 0; i < m; i++){
        scanf("%d", &arr2[i]);
    }
    int small = (n < m)? n : m;
    vector<int> inter(small);
    for(i = 0; i < n; i++){ //n이든 m이든 뭐가 안/밖에 있든 상관이 없다. 복잡도는 동일
        for(j = 0; j < m; j++){
            if(arr1[i] == arr2[j]) {
                inter[p++] = arr1[i];
                break;
            }
        }
    }

    //여기서 정렬 필요

    for(i = 0; inter[i] != 0; i++){
        printf("%d ", inter[i]);
    }

    return 0;
}



//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m, i, p1 = 0, p2 = 0, p3 = 0;
    scanf("%d", &n);
    vector<int> a(n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());   //quick
    scanf("%d", &m);
    vector<int> b(m), c(n+m);
    for(i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }
    sort(b.begin(), b.end());

    while(p1 < n && p2 < m){
        if(a[p1] == b[p2]){
            c[p3++] = a[p1++];
            p2++;
        }else if(a[p1] < b[p2]) p1++;
        else p2++;
    }
    for(i = 0; i < p3; i++){
        printf("%d ", c[i]);
    }

    return 0;
}