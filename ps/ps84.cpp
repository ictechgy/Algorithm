#include <stdio.h>
using namespace std;
int n, T[20], P[20], sum = 0;

void DFS(int day, int cost){
    if(day == n+1){
        if(cost > sum) sum = cost;
    }else{
        if(day+T[day] <= n+1){
            DFS(day+T[day], cost+P[day]);
        }
        DFS(day+1, cost);
    }
}

int main(void){
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d %d", &T[i], &P[i]);
    }
    DFS(1, 0);
    printf("%d\n", sum);

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int n, res = -2147000000;
vector<int> T, P;

void DFS(int L, int sum){
    if(L == n+1){
        if(sum > res) res = sum;
    }else{
        if(L + T[L] <= n+1) DFS(L + T[L], sum + P[L]);
        DFS(L+1, sum);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int a, b;
    cin>>n;
    T.push_back(0);
    P.push_back(0);
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        T.push_back(a);
        P.push_back(b);
    }
    DFS(1, 0);
    cout<<res;
    
    return 0;
}