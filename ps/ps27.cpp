#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 
    int i, j, n, tmp;
    scanf("%d", &n);
    vector<int> ck(n+1);    //n!에서 최대로 나올 수 있는 소수는 n
    //소수로 나누어 떨어진다면 n보다 작으며, 나누어 떨어지지 않는 소수라면 그 수 자체가 소수이므로 최대라고 해도 n이 최대 
    for(i = 2; i <= n; i++){
        tmp = i;
        j = 2;
        while(1){
            if(tmp % j == 0){
                tmp = tmp/j;
                ck[j]++;
            }else j++;
            if(tmp == 1) break;
        }
    }
    printf("%d! = ", n);
    for(i = 2; i <= n; i++){
        if(ck[i] != 0) printf("%d ", ck[i]);
    }

    return 0;
}