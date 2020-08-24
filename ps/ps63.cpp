#include <stdio.h>

int main(void){
    int adj[21][21] = {0, }, i, j, k, l, n, m;
    scanf("%d %d", &n, &m);
    for(l = 0; l < m; l++){
        scanf("%d %d %d", &i, &j, &k);
        adj[i][j] = k;
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            printf("%d ", adj[i][j]);
        }
        puts("");
    }
    puts("");

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int map[51][51];
int main(){
    int n, m, i, a, b, c, j;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}