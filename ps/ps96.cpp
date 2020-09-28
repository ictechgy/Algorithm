#include <bits/stdc++.h>
using namespace std;

struct Brk{
    int a, h, w;
    bool operator<(const Brk &b) const{
        return a > b.a; //또는 w기준으로 정렬할 수도 있으며 오름/내림차순 선택가능
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Brk> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].a >> arr[i].h >> arr[i].w;
    }
    sort(arr.begin()+1, arr.end());
    vector<int> val(n+1);
    int res = 0, max = 0;

    for(int i = 1; i <= n; i++) val[i] = arr[i].h;

    for(int i = 2; i <= n; i++){
        max = 0;
        for(int j = i-1; j >= 1; j--){
            if(arr[i].w < arr[j].w && max < val[j]){    //w기준 정렬 후에 a를 비교하여 계산할 수도 있다. 
                max = val[j];
            }
        }
        val[i] += max;
        if(res < val[i]) res = val[i];
    }
    cout << res << "\n";

    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;

struct Brick{
    int s, h, w;
    Brick(int a, int b, int c){
        s = a, h = b, w = c;
    }
    bool operator<(const Brick &b)const{
        return s > b.s;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    int n, a, b, c, max_h = 0, res = 0;
    cin>>n;
    vector<Brick> Bricks;
    vector<int> dy(n, 0);
    for(int i = 0; i < n; i++){
        cin>>a>>b>>c;
        Bricks.push_back(Brick(a, b, c));
    }
    sort(Bricks.begin(), Bricks.end());
    dy[0] = Bricks[0].h;
    res = dy[0];

    for(int i = 1; i < n; i++){
        max_h = 0;
        for(int j = i-1; j >= 0; j--){
            if(Bricks[j].w > Bricks[i].w && dy[j] > max_h){
                max_h = dy[j];
            }
        }
        dy[i] = max_h + Bricks[i].h;
        res = max(res, dy[i]);
    }
    cout << res;

    return 0;
}