#include <stdio.h>

int main(void){
    char c, prev;
    int cnt = 0;
    while(1){
        scanf("%c", &c);
        if(c == '\n') break;

        if(c == '=' || c == '-');
        else if(c == 'z' && prev == 'd');
        else if(c == 'j' && (prev == 'l' || prev == 'n'));
        else cnt++; //조건에 만족하는 경우에만 카운팅해주기

        prev = c;
    }
    printf("%d\n", cnt);

    return 0;
}   //왜 틀렸다고 나오지?! 
//반례 -> dz= 부분 처리에서 반례 발생한다. dzd 입력시 이는 알파벳 3개로 인식해야 하는데 2개로 인식

