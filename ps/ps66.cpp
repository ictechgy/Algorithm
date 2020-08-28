#include <stdio.h>
#include <vector>
using namespace std;

vector<int> adj[21];    //linked list 형태의 adjacency list라고 볼 수는 없지만 이와 비슷하게 사용
int n, ck[21], cnt = 0;

void DFS(int v){
    int i, u;
    if(v == n) cnt++;
    else{
        for(i = 0; i < adj[v].size(); i++){
            u = adj[v][i];
            if(ck[u] == 0){
                ck[u] = 1;
                DFS(u);
                ck[u] = 0;
            }
        }
    }
}

int main(void){
    int m, i, u, v;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    ck[1] = 1;
    DFS(1);
    printf("%d\n", cnt);

    return 0;
}

//그래프에 인접행렬, 인접리스트를 이용할 수 있는데 vector로 인접리스트 구현시 편리
//std::vector가 std::list로부터 파생된 것은 아니어서 linked list형식은 아니지만 약간의 트릭처럼 이용. 
#include <stdio.h>
#include <vector>
using namespace std;
int ch[30], cnt = 0, n;
vector<int> map[30];

void DFS(int v){
    int i;
    if(v == n){
        cnt++;
    }else{
        for(i = 0; i < map[v].size(); i++){
            if(ch[map[v][i]] == 0){
                ch[map[v][i]] = 1;
                DFS(map[v][i]);
                ch[map[v][i]] = 0;
            }
        }
    }
}

int main(){
    int m, i, a, b;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
    }
    ch[1] = 1;
    DFS(1);
    printf("%d\n", cnt);

    return 0;
}