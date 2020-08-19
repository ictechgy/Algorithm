#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void recur(int n){
    if(n <= 0) return;
    recur(n/2);
    printf("%d", n%2);
}

int main(void){
    int n;
    scanf("%d", &n);
    recur(n);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void D(int x){
    if(x == 0) return;
    else{
        D(x/2);
        printf("%d", x%2);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    D(n);

    return 0;
}