#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n+1), val(n+1, 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int max = 1;
    for(int i = 2; i <= n; i++){
        for(int j = i-1; j >= 1; j--){
            if(arr[i] > arr[j] && val[i] <= val[j]){
                val[i] = val[j] + 1;
                if(max < val[i]) max = val[i];
            }
        }
    }
    cout << max << "\n";

    return 0;
}