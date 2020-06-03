#include <stdio.h>
#include <vector>
using namespace std;

int main(void){
    int n, i, s[101] = {0}, r = 1, num; //s - 분포도
    scanf("%d", &n);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        s[arr[i]]++;
    }
    for(i = 100; i >= 0; i--){
        if(s[i] != 0){
            num = s[i];
            s[i] = r; //랭크 부여
            r += num;
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", s[arr[i]]);
    }
    puts("");

    return 0;
}


//특정 값보다 앞에 몇명이 앞서있는가
#include <stdio.h>
int main(){
    int i, j, a[200], b[200], n;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[i] = 1;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(a[j] > a[i]) b[i]++; //뒤로 밀기
        }
    }
    for(i = 1; i <= n; i++){
        printf("%d ", b[i]);
    }

    return 0;
}