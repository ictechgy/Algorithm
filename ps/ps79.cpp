#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct compare{
    bool operator()(pair<int, int> &left, pair<int, int> &right){
        return left.second > right.second;
    }
};
//sort같은 경우 구조체 내에 operator< overloading을 해주거나 compare함수 정의해서 넘겨주는 방식이 가능하나
//priority_queue같은 경우는 비교함수를 구조체 내에 넣고 전달해주어야 하는 듯. 
//sort()함수에 대한 함수 정의 시 (오름차순)return left < right를 해주면 되지만
//pq에서는 함수에서 우선순위에 대한 bool을 반환해야하며 두번째 인자가 우선순위가 높을 시 true, 아닐 시 false를 리턴해야 한다고 함

int main(void){
    int n, m, i, u, v, w, cnt = 0, num = 0;
    scanf("%d %d", &n, &m);
    vector<pair<int, int> > map[n+1];
    vector<int> d(n+1);
    vector<bool> ck(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pQ; 
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        map[u].push_back({v, w});
        map[v].push_back({u, w});
    }
    
    d[1] = 0;   //start
    pQ.push({1, d[1]});
    for(i = 2; i <= n; i++){
        d[i] = 2147000000;
    }
    
    while(cnt < n){
        do{
            u = pQ.top().first;
            w = pQ.top().second;
            pQ.pop();
        }while(ck[u] == true);  
        ck[u] = true;
        cnt++;
        num += w;
        
        for(i = 0; i < map[u].size(); i++){
            v = map[u][i].first;
            w = map[u][i].second;
            if(ck[v] == false && d[v] > w){
                d[v] = w;
                pQ.push({v, d[v]});
//이미 pq에 들어간 것에 대해 d[v]값을 w로 업데이트 하는 것이 불가능하기 때문에 더 작은 값이 있다면 추가적으로 다시 넣되, 나중에 진행하다가 이미 체크된 값이 있다면 그것은 
//무시하도록 한다. (do-while의 조건문을 통해.) 즉 pq에 어떤 한 노드에 대한 중복된 d[v] 값들이 있다면 그 중 가장 작은것만 사용하고 나머지는 사용이 안되도록 처리.
//이렇게 하는 것이 pq에서 d값이 바뀐 원소를 찾아서 업데이트하거나 애초부터 모든 노드에 대한 pq상의 위치를 기억하고 있는 것보다 간단하고 시간복잡도는 낮을 것으로 보인다.
//(검색을 이용하여 d값이 바뀐 노드를 찾아야 한다면.. 노드번호에 대해서는 규칙이 없으므로 선형검색을 해야하고 이후에 재정렬이 필요하지만 단순 삽입만 한다면 logn 복잡도로 끝난다.)
            }
        }
    }
    printf("%d\n", num);

    return 0;
}
//다익스트라에서의 d는 출발지로부터의 거리를 의미하는 반면, 프림에서의 d는 mst부분집합에 대한 거리 중 가장 가까운 거리를 의미
//그 중 가장 작은 값을 고른다는 점에서는 비슷. (단순검색보다는 우선순위 큐 or 피보나치 힙이 시간복잡도에서 나음 - 경우에 따라 다를 때도 있지만)

//
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int ch[30];
struct Edge{
    int e;
    int val;
    Edge(int a, int b){
        e = a;
        val = b;
    }
    bool operator<(const Edge &b)const{
        return val > b.val;
    }
};

int main(){
    priority_queue<Edge> Q;
    vector<pair<int, int> > map[30];
    int i, n, m, a, b, c, res = 0;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }
    Q.push(Edge(1, 0));
    while(!Q.empty()){
        Edge tmp = Q.top();
        Q.pop();
        int v = tmp.e;
        int cost = tmp.val;
        if(ch[v] == 0){
            res += cost;
            ch[v] = 1;
            for(i = 0; i < map[v].size(); i++){
                Q.push(Edge(map[v][i].first, map[v][i].second));
            }
        }
    }
    printf("%d\n", res);

    return 0;
}