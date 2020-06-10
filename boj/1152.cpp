#include <stdio.h>

int main(void){
    char c;
    int flag = 1;   //이전 값이 스페이스고 새로운 문자를 만나면 단어가 나온 것으로 인식한다.
    int count = 0;
    while(1){
        scanf("%c", &c);
        if(c == '\n') break;
        else if(c == ' '){  //공백을 만나는 경우 다음 문자를 만날 준비 
            flag = 1;
        }else if(flag){  //문자를 만난 경우
            flag = 0;
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}