#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, c, i;
    scanf("%d %d", &n, &c);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    return 0;
}