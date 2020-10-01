#include <bits/stdc++.h>
using namespace std;

struct Jewel{
    int w, val;
    Jewel(int a, int b){
        w = a;
        val = b;
    }
};
vector<Jewel> arr;
int dy[31][1001];
int calc(int n, int limit){
    if(n == 0 || limit == 0) return 0;
    else if(dy[n][limit] > 0) return dy[n][limit];
    else if(limit < arr[n].w) return dy[n][limit] = calc(n-1, limit);
    else{
        dy[n][limit] = max(calc(n-1, limit), calc(n, limit-arr[n].w) + arr[n].val);
        return dy[n][limit];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, limit, a, b;
    cin >> n >> limit;
    arr.push_back(Jewel(0, 0));
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        arr.push_back(Jewel(a, b));
    }    
    cout << calc(n, limit);

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n, m, w, v;
    cin>>n>>m;
    vector<int> dy(m+1, 0);
    for(int i = 0; i < n; i++){
        cin>>w>>v;
        for(int j = w; j <= m; j++){
            dy[j] = max(dy[j], dy[j-w] + v);
        }
    }
    cout<<dy[m];

    return 0;
}