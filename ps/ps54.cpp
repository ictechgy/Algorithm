//기준점 정수값을 두어 해결하는 방법도 존재(덧셈 뺄셈 방식으로 판별)
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void){
    char c;
    stack<char> stk;
    while(1){
        scanf("%c", &c);
        if(c == '\n') break;
        if(c == '(') stk.push('(');
        else{  
            if(stk.empty()) {
                printf("NO\n");
                return 0;
            }else stk.pop();
        }
    }
    if(stk.empty()) printf("YES\n");
    else printf("NO\n");

    return 0;
}

//
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    stack<char> s;
    char a[50];
    int i, flag = 1;
    scanf("%s", a);
    for(i = 0; a[i] != '\0'; i++){
        if(a[i] == '(') s.push(a[i]);
        else{
            if(s.empty()){
                printf("NO\n");
                flag = 0;
                break;
            }else s.pop();
        }
    }
    if(s.empty() && flag == 1) printf("YES\n");
    else if(!s.empty() && flag == 1) printf("NO\n");

    return 0;
}