#include <bits/stdc++.h>
using namespace std;
int n, su[20], op[5], Max = -2147000000, Min = 2147000000;

void DFS(int L, int val){   //이전 결과 값 val에 현재 레벨값 계산하여 합산 후 재귀
    int i;
    if(L == n+1){
        if(val > Max) Max = val;
        if(val < Min) Min = val;
    }else{
        for(i = 1; i <= 4; i++){
            if(op[i] > 0){
                op[i]--;
                switch(i){
                    case 1:
                        DFS(L+1, val + su[L]);
                        break;
                    case 2:
                        DFS(L+1, val - su[L]);
                        break;
                    case 3:
                        DFS(L+1, val * su[L]);
                        break;
                    case 4:
                        DFS(L+1, val / su[L]);
                        break;
                }
                op[i]++;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    int i;
    cin>>n;
    for(i = 1; i <= n; i++){
        cin>>su[i];
    }
    for(i = 1; i <= 4; i++){
        cin>>op[i];
    }
    DFS(2, su[1]);
    cout<<Max<<endl;
    cout<<Min<<endl;

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[20], op[5], n, maxi = -2147000000, mini = 2147000000;
void DFS(int L, int res){
    if(L == n){
        if(res > maxi) maxi = res;
        if(res < mini) mini = res;
    }else{
        if(op[0] > 0){
            op[0]--;
            DFS(L+1, res+a[L]);
            op[0]++;
        }
        if(op[1] > 0){
            op[1]--;
            DFS(L+1, res-a[L]);
            op[1]++;
        }
        if(op[2] > 0){
            op[2]--;
            DFS(L+1, res*a[L]);
            op[2]++;
        }
        if(op[3] > 0){
            op[3]--;
            DFS(L+1, res/a[L]);
            op[3]++;
        }
    }
}

int main(){
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < 4; i++){
        scanf("%d", &op[i]);
    }
    DFS(1, a[0]);
    printf("%d\n%d\n", maxi, mini);

    return 0;
}