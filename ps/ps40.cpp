#include <stdio.h>
#include <vector>
using namespace std;

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
    

    return 0;
}