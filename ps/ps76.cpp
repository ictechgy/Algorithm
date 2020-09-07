#include <stdio.h>

int map[21][21];

int binomial(int x, int y){
    if(map[x][y] == 0){
        map[x][y] = binomial(x-1, y) + binomial(x-1, y-1);
    }
    return map[x][y];
}

int main(void){
    int n, r, i;
    for(i = 0; i <= 20; i++){
        map[i][0] = 1;
        map[i][i] = 1;
    }
    scanf("%d %d", &n, &r);
    printf("%d\n", binomial(n, r));

    return 0;
}

//
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int DFS(int n){
    if(n == 1) return 1;
    else return n * DFS(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", DFS(n));

    return 0;
}

//
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int DFS(int n, int r){
    if(n == r || r == 0) return 1;
    else return DFS(n-1, r-1) + DFS(n-1, r);
}

int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d\n", DFS(n, r));
    return 0;
}

//
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dy[21][21];

int DFS(int n, int r){
    if(dy[n][r] > 0) return dy[n][r];
    if(n == r || r == 0) return 1;
    else return dy[n][r] = DFS(n-1, r-1) + DFS(n-1, r);
}

int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d\n", DFS(n, r));
    return 0;
}