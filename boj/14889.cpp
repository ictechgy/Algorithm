#include <bits/stdc++.h>
using namespace std;
int n, Map[21][21], gap = 2147000000;
int team[21];   //값이 1인경우 start팀, 0인경우 link팀

void DFS(int m, int k){
    if(k > n) return;   //예외상황
    else if(m >= n/2){   //start 팀 소속이 이미 절반이 된 상황이라면
        vector<int> teamStart, teamLink;

        for(int i = 1; i <= n; i++){
            if(team[i] == 1) teamStart.push_back(i);
            else teamLink.push_back(i);
        }

        int sumOfStart = 0, sumOfLink = 0;

        for(int i = 0; i < n/2; i++){
            for(int j = i+1; j < n/2; j++){
                sumOfStart += (Map[teamStart[i]][teamStart[j]] + Map[teamStart[j]][teamStart[i]]);
                sumOfLink += (Map[teamLink[i]][teamLink[j]] + Map[teamLink[j]][teamLink[i]]);
            }
        }
        int res = abs(sumOfStart - sumOfLink);
        if(res < gap) gap = res;
    }else{
        team[k] = 1;
        DFS(m+1, k+1);
        team[k] = 0;
        DFS(m, k+1);
    }
}
//k레벨의 DFS가 할 일 - k번째 사람이 start팀에 소속되게 할지 link팀에 소속되게 할지를 결정

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> Map[i][j];
        }
    }
    
    DFS(0, 1);
    cout << gap;

    return 0;
}