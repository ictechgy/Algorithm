#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int s1, s2, i, j, k;
    scanf("%d", &s1);
    vector<int> arr1(s1);
    for(i = 0; i < s1; i++){
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &s2);
    vector<int> arr2(s2);
    for(i = 0; i < s2; i++){
        scanf("%d", &arr2[i]);
    }
    vector<int> arr3(s1 + s2);
    i = j = k = 0;
    while(i < s1 && j < s2){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }else{
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < s1) arr3[k++] = arr1[i++];
    while(j < s2) arr3[k++] = arr2[j++];
    
    for(i = 0; i < s1 + s2; i++){
        printf("%d ", arr3[i]);
    }

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[101], b[101], c[300];
int main(){
    int n, m, i, p1 = 1, p2 = 1, p3 = 1;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(i = 1; i <= m; i++){
        scanf("%d", &b[i]);
    }
    while(p1 <= n && p2 <= m){
        if(a[p1] < b[p2]){
            c[p3++] = a[p1++];
        }else{
            c[p3++] = b[p2++];
        }
    }
    while(p1 <= n) c[p3++] = a[p1++];
    while(p2 <= m) c[p3++] = b[p2++];
    for(i = 1; i < p3; i++){
        printf("%d ", c[i]);
    }

    return 0;
}