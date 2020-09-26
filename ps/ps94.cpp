#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    vector<int> ans(n, 1);
    int Max = 1;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(arr[i] > arr[j] && ans[i] <= ans[j]){
                ans[i] = ans[j] + 1;
                if(Max < ans[i]) Max = ans[i];
            }
        }
    }
    cout << Max << "\n";

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n, res = 0;
    cin>>n;
    vector<int> arr(n+1), dy(n+1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    dy[1] = 1;
    for(int i = 2; i <= n; i++){
        int max = 0;
        for(int j = i-1; j >= 1; j--){
            if(arr[j] < arr[i] && dy[j] > max){
                max = dy[j];
            }
        }
        dy[i] = max + 1;
        if(dy[i] > res) res = dy[i];
    }
    cout<<res;

    return 0;
}