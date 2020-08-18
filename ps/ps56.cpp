#include <stdio.h>

using namespace std;

void recursive_print(int n){
    if(n <= 0) return;
    recursive_print(n-1);
    printf("%d ", n);
}

int main(void){
    int n;
    scanf("%d", &n);
    recursive_print(n);
    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void recur(int x){
    if(x == 0) return;
    else{
        recur(x-1);
        printf("%d ", x);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    recur(n);
    return 0;
}