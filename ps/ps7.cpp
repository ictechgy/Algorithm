#include <iostream>
using namespace std;

int main(){
    char a;
    string origin = "";
    while(true){
        scanf("%c", &a);
        if(a == '\n' || a == '\0') break;
        if(a == ' ') continue;
        if(a<=90) a+=32;    //대문자라면 소문자로 변환
        origin.push_back(a);
    }
    cout<<origin<<endl;

    //scanf에서 %s사이에 스페이스바 넣지 말라고 했는데 입력받을 때 공백을 제거하려는 일종의 방법이 timeout을 일으킬 수 있어서인듯.


    //또는..
    char arr[101];    //최대 100의 문자. 널문자를 위해 하나 더
    char a; //입력되는 문자를 하나씩 read
    int idx = 0;    //글자의 길이를 측정할 수도 있지만 값을 넣을 인덱스를 지칭
    char real[101]; //실제 글자를 넣을 배열
    while(true){
        scanf("%c", &a);
        if(a == '\n') break;
        if(a == ' ') continue;
        if(a <= 90) a+=32;
        real[idx++] = a;
    }
    real[idx] = '\0'; //마지막에는 NULL문자 넣어주기
    printf("%s\n", real);

    return 0;
}

//다른 풀이
#include <stdio.h>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    char a[101], b[101];    //a는 입력, b는 출력
    int i, p = 0;
    gets(a);    //\n을 기준으로 한줄 쭉 읽어옴.
    for(i = 0; a[i] != '\0'; i++){
        if(a[i] != ' '){
            if(a[i]>=65 && a[i] <= 90){
                b[p++] = a[i] + 32;
            }else{
                b[p++] = a[i];
            }
        }
    }
    b[p] = '\0';
    printf("%s\n", b);

    return 0;
}