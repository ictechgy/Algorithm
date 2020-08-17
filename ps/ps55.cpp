#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void){
    //처리 불가능한 경우를 사전에 거를 수 있을까? 아니면 처리하는 과정에서 걸러야하나? 
    //스택에 값이 역피라미드로 쌓이는 경우에 처리 불가능하긴 한데... 주어진 값을 최초로 선형탐색하여 
    //처리 불가능한 경우를 찾는다면 더 효율적일까. 
    int i, n, num, order = 1;
    scanf("%d", &n);
    stack<int> stk;
    vector<char> ans;
    for(i = 1; i <= n; i++){
        scanf("%d", &num);  //order보다 작은 값이 들어오는 경우는 있을 수 없다. 
        if(num == order){
            ans.push_back('P');
            ans.push_back('O');
            order++;
        }else{  //원하는 순서가 아님
            if(!stk.empty() && stk.top() < num){
                //성립 불가한 상황
                printf("impossible\n");
                return 0;
            }
            stk.push(num);
            ans.push_back('P');
        }
        while(!stk.empty() && stk.top() == order){
            stk.pop();
            order++;
            ans.push_back('O');
        }
    }
    for(i = 0; i < ans.size(); i++) printf("%c", ans[i]);
    printf("\n");

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void){
    int i, n, j, num;
    int a[50];
    stack<int> stk;
    char ans[100] = {0};
    int ansIdx = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) a[i] = i;
    j = 1;
    for(i = 1; i <= n; i++){
        scanf("%d", &num);
        stk.push(num);
        ans[ansIdx++] = 'P';
        
        while(!stk.empty() && stk.top() == a[j]){
            stk.pop();
            ans[ansIdx++] = 'O';
            j++;
        }
    }
    if(stk.empty()){
        for(i = 0; i < ansIdx; i++) printf("%c", ans[i]);
    }else printf("impossible");
    printf("\n");

    return 0;
}

//
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

int main(){
    stack<int> s;
    int i, j = 1, n, m;
    scanf("%d", &n);
    vector<char> str;
    for(i = 1; i <= n; i++){
        scanf("%d", &m);
        s.push(m);
        str.push_back('P');

        while(1){
            if(s.empty()) break;
            if(j == s.top()){
                s.pop();
                j++;
                str.push_back('O');
            }else break;
        }
    }
    if(!s.empty()) printf("impossible\n");
    else{
        for(i = 0; i < str.size(); i++){
            printf("%c", str[i]);
        }
    }

    return 0;
}