//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#include <stack>

using namespace std;

char nodes[] = {'A', 'B', 'C', 'D', 'E'};

int adj[][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0}
}; 

bool visited[5] = {false,}; //방문여부 체크

void DFS_traverse(char s){
    printf("%c ", s);
    visited[s-65] = true;
    int i;
    for(i = 0; i < 5; i++){
        if(adj[s-65][i] == 1 && visited[i] == false) DFS_traverse(i+65);
    }
}

void DFS_stack_traverse(char s){
    int i;
    for(i = 0; i < 5; i++) visited[i] = false;
    stack<int> st;
    
    st.push(s-65);
    int v;  //vertex
    while(!st.empty()){
        v = st.top();
        st.pop();
        printf("%c ", nodes[v]);
        visited[v] = true;
        for(i = 0; i < 5; i++){
            if(adj[v][i] == 1 && visited[i] == false) st.push(i);
        }
    }
}

int main(void){
    DFS_traverse('A');
    puts("");
    DFS_stack_traverse('A');
    return 0;
}