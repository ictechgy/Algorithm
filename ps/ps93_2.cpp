#include <bits/stdc++.h>
using namespace std;
int arr[50];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    arr[1] = 2;
    arr[2] = 3;
    for(int i = 3; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n] << "\n";

    return 0;
}

//or
#include <bits/stdc++.h>
using namespace std;
int arr[50];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= n+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n+1] << "\n";

    return 0;
}