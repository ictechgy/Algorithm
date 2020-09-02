#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    int s, e, pos, level, i, nxt;
    pair<int, int> vertex;
    int dx[3] = {-1, 1, 5};
    int ck[10001] = {0};
    //각각의 좌표값 지점에 몇번만에 도착했는지 셈하는 것은 불필요해 보임. -> 레벨값만 저장하면 충분할 듯(레벨 값 자체가 몇번만에 도착하는건지가 됨)
    //따라서 ck배열이나 dist배열은 두지 않음(특정 좌표에 이미 도착했는지, 몇번만에 도착했는지)
    //이미 간곳에 대해 또 방문해볼 필요는 없긴 한데 좌표값이 커서 방문여부 체크를 하거나 가는데 걸린 최소 횟수(거리) 측정하는건 오버헤드가 클 것 같다.
    // -> 처음에는 이렇게 생각하고 ck배열을 두지 않았는데, 숫자 값이 커질 수록(탐색 레벨이 깊어질 수록) 시간을 감당할 수가 없어서 방문여부 체크 배열 추가함.
    //(ck배열을 쓰지 않는경우 트리의 레벨당 탐색해야 하는 노드의 수가 3^n으로 증가. n은 트리의 레벨, 생각보다 중복되어 탐색하게 되는 경우가 많음)
    //따라서 공간복잡도를 조금 희생해서라도 ck를 이용한 가지치기를 하였다. 각각의 모든 좌표에 몇번만에 도착했는지는 중요치 않으므로 이 부분은 저장하지 않고
    //원하는 상태값에 도달했을 시의 '번째'만을 알기 위해 각 상태노드별로 레벨값을 따로 마킹해주었다. (pair의 second 값)
    scanf("%d %d", &s, &e);
    queue<pair<int, int> > que;
    que.push(make_pair(s, 0));  //첫 값은 위치 값, 두번째 값은 레벨 값
    ck[s] = 1;
    while(!que.empty()){
        vertex = que.front();
        que.pop();
        pos = vertex.first;
        level = vertex.second;

        for(i = 0; i < 3; i++){
            nxt = pos + dx[i];
            if(ck[nxt] != 0 || nxt < 1 || nxt > 10000) continue;    
            //방문해볼 필요가 없는 곳에 대한 가지치기. 이미 방문한 곳이나 값의 범위를 넘어간 부분에 대한 상태노드는 건너뛴다.
            que.push(make_pair(nxt, level+1));
            ck[nxt] = 1;    //체크 - 큐에 넣기 전/후 체크해주는게 좋다. 큐에서 팝한 후에 체크하는건 늦음(같은 레벨에서 동시에 방문하게 되는 경우 존재하므로)
            if(nxt == e){
                printf("%d\n", level + 1);
                return 0;   //혹은 이 구문을 큐에서 특정 노드를 팝했을 때 확인하는 방식으로 할 수도 있다. (pos == e라면 level을 바로 출력하는 방식 -> 다만 다음 레벨을 전부 탐색하게 되므로 좋지는 않아보임)
            }
        }
    }
    
    return 0;
}
//결국 pair의 second인 level 자체가 각 좌표에 몇번만에 도착했느냐가 되므로.. 그냥 거리배열(각 좌표별 도달하는데의 최소 횟수)을 두고 푸는것도 나쁘지 않을 것 같다...
//아니면 ch 배열 자체를 level값 저장하는 방식으로 써도 될 듯. 

//
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ch[10001], d[3] = {1, -1, 5};
int main(){
    int e, x, s, pos, i;
    queue<int> Q;
    scanf("%d %d", &s, &e);
    ch[s] = 1;
    Q.push(s);
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        for(i = 0; i < 3; i++){
            pos = x + d[i];
            if(pos <= 0 || pos > 10000) continue;
            if(ch[pos] == e){
                printf("%d\n", ch[x]);
                exit(0);
            }
            if(ch[pos] == 0){
                ch[pos] = ch[x] + 1;    //체크배열 겸 거리 배열
                Q.push(pos);
            }
        }
    }

    return 0;
}