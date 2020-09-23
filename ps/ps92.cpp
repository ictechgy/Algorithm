#include <bits/stdc++.h>
using namespace std;
int arr[46];

int D(int m){
    if(m <= 2) return m;
    else if(arr[m] != 0) return arr[m];
    else{
        arr[m] = D(m-1) + D(m-2);
        return arr[m];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << D(n) << "\n";

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int dy[101];
int DFS(int n){
    if(dy[n] != 0) return dy[n];
    if(n == 1 || n == 2) return n;
    else return dy[n] = DFS(n-1) + DFS(n-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    cout<<DFS(n);

    return 0;
}