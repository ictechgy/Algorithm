#include <stdio.h>

int main(void){
    char in;
    int alphabet[26] = {0};
    while((in = getchar())!='\n'){    //한글자씩 읽는다.
        if(in>=97) in-=32;    //읽은 글자가 소문자라면 대문자로 변환
        alphabet[in-65]++;    //읽은 알파벳에 해당하는 공간의 값을 1 증가
    }
    int maxIndex = 0;    //가장 많이 나온 알파벳 가리키는 값
    int flag = 0;   //같은 회수로 나온 알파벳이 있는지 확인하기 위한 변수
    for(int i = 1; i < 26; i++){
        if(alphabet[i] > alphabet[maxIndex]) {
            maxIndex = i;
            flag = 0;
        }
        else if(alphabet[i] == alphabet[maxIndex]){
            flag = 1;
        }
    }
    if(flag){
        printf("?\n");
        return 0;
    }
    printf("%c\n", maxIndex + 65);
    return 0;
}