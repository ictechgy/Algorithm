#include <bits/stdc++.h>
using namespace std;

struct Problem{
    int s, t;
    Problem(int a, int b){
        s = a;
        t = b;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > dy(n+1, vector<int>(m+1, 0));

    vector<Problem> pbs;
    pbs.push_back(Problem(0, 0));
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        pbs.push_back(Problem(a, b));
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j < pbs[i].t) dy[i][j] = dy[i-1][j];
            else dy[i][j] = max(dy[i-1][j], dy[i-1][j-pbs[i].t] + pbs[i].s);
        }
    }
    cout << dy[n][m] << "\n";

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n, m, ps, pt;
    cin>>n>>m;
    vector<int> dy(m+1);
    for(int i = 0; i < n; i++){
        cin>>ps>>pt;
        for(int j = m; j >= pt; j--){
            dy[j] = max(dy[j], dy[j-pt] + ps);
        }
    }
    cout<<dy[m];

    return 0;
}

//개수가 2개 이상인경우
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(false);
	int n, m, ps, pt, pc;
	cin>>n>>m;
	vector<int> dy(m+1);
	for(int i=0; i<n; i++){
		cin>>ps>>pt>>pc;
		for(int j=m; j>=pt; j--){
			for(int k=1; k<=pc; k++){
				if(j-pt*k<0) break;
				dy[j]=max(dy[j], dy[j-pt*k]+ps*k);  
                //처음에는 기존값과 1번 적용한 값 비교, 이후에는 기존값 또는 1번 적용한 값과 2번 적용한 값과 비교 .. 이 비교를 개수/시간 한도내에서 함으로써 최적 값 찾음
			}			
		}			
	}
	cout<<dy[m]<<"\n";		
	return 0;
}