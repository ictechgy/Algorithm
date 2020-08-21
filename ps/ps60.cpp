#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10], n, half;
int group[10] = {0, }; //1번그룹, 2번그룹

bool select(int k){ //k는 트리에서의 레벨을 나타냄, group 배열의 상태는 어떤 노드에 있는지 그 위치를 나타내는 역할
    int i, sum = 0;
    bool res;
    if(k >= n){     //중간중간에 값이 이미 half를 넘었을지 체크하여 상태공간트리에서의 가지치기를 해볼 수도 있지만 굳이 그래야 할까? 그게 더 오버헤드가 들지는 않는가? 
        for(i = 0; i < n; i++){
            if(group[i] == 1) sum += arr[i];
        }
        if(sum == half) return true;
        else return false;
    }   //base case, leaf 노드인 경우

    group[k] = 1;
    res = select(k+1);      //트리의 왼쪽으로 분기
    if(res) return true;
    group[k] = 2;
    res = select(k+1);      //트리의 오른쪽으로 분기
    if(res) return true;
    return false;

    //트리의 어떤 한 종단노드에서 원하는 해를 발견한 경우 바로 탐색을 종료할 수 있도록 bool형을 return하고 이를 이용.
    //false를 리턴하는 경우 다른 자식노드를 탐색하거나 그래도 원하는 해가 없는 경우에는 백트래킹

    //8 queens 문제도 이렇게 원하는 해를 하나 찾으면 종료할 수도 있지만.. 다른 여러 해를 더 탐색해볼수도 있을 것.. 
    //조건 충족 시 아예 종료시키지 않고 더 탐색하는 방식으로.. 
    //가지치기를 할 수 있을 때 한다면 그건 그것대로 더 효율적이다. 특히 8퀸문제에서는.
    //-> 권오흠 교수님대로 푸는게 나을까 알고리즘 기초책에 나왔던대로(대각선 판별배열 존재) 푸는게 나은걸까..? 
}

int main(void){
    int i, sum = 0;
    bool res;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    if(n == 1 || sum % 2 == 1){   //개수가 하나이거나 전체 합이 홀수라면 같은 크기로 쪼개기가 애초부터 불가능하다.
        printf("NO\n");
        return 0;
    }

    half = sum / 2;
    res = select(0);    //상태공간트리 탐색 - 스택을 그려놓고 트리 탐색을 해보면 된다. 
    if(res) printf("YES\n");
    else printf("NO\n");    //모든 leaf노드 탐색했는데 원하는 해가 없는 경우 NO.

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, a[11], total = 0;
bool flag = false;

void DFS(int L, int sum){
    if(sum > (total/2)) return;   //가지치기
    if(flag == true) return;
    if(L == n+1){
        if(sum == (total-sum)){
            flag = true;
        }
    }else{
        DFS(L+1, sum+a[L]);
        DFS(L+1, sum);
    }
}

int main(){
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        total += a[i];
    }
    DFS(1, 0);
    if(flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}