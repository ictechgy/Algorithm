#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//greedy? knapsack? dp?... 
int main(void){
    int n, m, d, i, last = 0, sum = 0, j;
    vector<int> cal[10001];
    priority_queue<int> pQ;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d %d", &m, &d);
        cal[d].push_back(m);
        if(last < d) last = d;
    }
    
    for(i = last; i >= 1; i--){
        for(j = 0; j < cal[i].size(); j++){
            pQ.push(cal[i][j]);
        }
        if(pQ.empty()) sum += 0;
        else{
            sum += pQ.top();
            pQ.pop();
        }
    }
    printf("%d\n", sum);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Data{
    int money;
    int when;
    Data(int a, int b){
        money = a;
        when = b;
    }
    bool operator<(Data &b){
        return when > b.when;
    }
};
int main(){
    int n, i, j, a, b, res = 0, max = -2147000000;
    vector<Data> T;
    priority_queue<int> pQ;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d %d", &a, &b);
        T.push_back(Data(a, b));
        if(b > max)
            max = b;
    }
    sort(T.begin(), T.end());
    j = 0;
    for(i = max; i >= 1; i--){
        for( ; j<n; j++){
            if(T[j].when<i) break;
            pQ.push(T[j].money);
        }
        if(!pQ.empty()){
            res += pQ.top();
            pQ.pop();
        }
    }
    printf("%d\n", res);

    return 0;
}