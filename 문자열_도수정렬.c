//문자열 정렬하기 (도수정렬)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* solution(const char* s) {
    char* answer = (char*)calloc(strlen(s) + 1, sizeof(char));
    //z가 가장 큰 값이라고 생각하고 도수 정렬을 수행 'A'~'Z','a'~'z' 순서
    //도수분포표
    int* dosu = (int*)calloc(UCHAR_MAX+1, sizeof(int));  //문자의 개수만큼 도수분포표 배열 생성
    for(int i = 0; i < strlen(s); i++){
        dosu[s[i]]++;       //문자열 체크하여 도수분포표에서 해당하는 인덱스의 값 증가
    }
    
    for(int i = 1; i<= UCHAR_MAX; i++){
        dosu[i] += dosu[i-1];   //누적도수분포표 만들기
    }
    
    for(int i = strlen(s)-1; i>=0; i--){
        answer[--dosu[(int)s[i]]] = s[i];        //목적배열은 answer
    }
    answer[strlen(s)] = '\0';   //맨 마지막 인덱스에는 널값 대입
    
    return answer;
}

int main(void){
    char s[100]="";
    scanf("%s", s);
    char* s2 = solution(s);
    printf("%s\n", s2);
    return 0;
}

int getRect(int w, int h){
    if(w == h) return w*h - w*h/w;

    return w * h - ( w < h)? w*2 : h*2;
}