#include <stdio.h>
#include <string.h>

int main(void){
    int alphabet[26]; //알파벳은 26글자. 0인덱스에는 a가 나오는 위치를 저장
    memset(alphabet, -1, sizeof(alphabet)); //모든 배열공간의 값을 -1로 초기화
    char in;
    int count = 0; //몇번째 글자를 읽고 있는 것인지 체크
    while((in=getchar())!='\n'){
        if(alphabet[in-97] == -1) alphabet[in-97] = count;
        count++;
    }
    for(int i = 0; i < 26; i++){
        printf("%d ", alphabet[i]);
    }
    
    return 0;
}