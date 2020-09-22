#include <bits/stdc++.h>
using namespace std;
int arr[46] = {0, 1, 2};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i;
    cin>>n;
    for(i = 3; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n];

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
int dy[50];
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    dy[1] = 1;
    dy[2] = 2;
    for(int i = 3; i <= n; i++){
        dy[i] = dy[i-2] + dy[i-1];
    }
    cout << dy[n];

    return 0;
}