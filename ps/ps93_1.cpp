#include <bits/stdc++.h>
using namespace std;
int arr[46];

int D(int n){
    if(n == 1 || n == 2) return n;
    else if(arr[n] != 0) return arr[n];
    else return arr[n] = D(n-1) + D(n-2);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << D(n) << "\n";

    return 0;
}