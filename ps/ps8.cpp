#include <iostream>
using namespace std;

int main(void){
    int cnt = 0;
    char ch;
    while(true){
        scanf("%c", &ch);
        if(ch == '\n') break;
        (ch == '(')? ++cnt : --cnt;
        if(cnt<0){
            printf("NO\n");
            return 0;       
            //만약에 cnt가 한번이라도 음수로 떨어진다면 이는 닫는 괄호가 먼저 등장했다는 것이고 
            //이는 온전한 괄호로 되돌릴 수 없는 상태가 된다. 따라서 바로 NO를 출력하고 종료한다.
        }
    }
    if(!cnt){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;
}

//다른 풀이 - 원래는 스택 사용
#include <stdio.h>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    char a[100];
    int i, cnt = 0;
    scanf("%s", &a);
    for(i = 0; a[i] != '\0'; i++){
        if(a[i] == '(') cnt++;
        else if(a[i] == ')') cnt--;
        if(cnt < 0) break;
    }
    if(cnt == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}