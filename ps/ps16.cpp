#include <stdio.h>

int main(void){
    //입력받는 문자열을 배열에 저장시킬 수도 있을 것
    char c;
    int arr[52] = {0}; //알파벳은 총 52개
    while(true){
        scanf("%c", &c);
        if(c == '\n') break;
        if(c <= 90){    //대문자인경우
            arr[c-65]++;    //0~25
        }else{
            arr[c-71]++;    //26~51
        }
    }
    while(true){
        scanf("%c", &c);
        if(c == '\n') break;
        if(c <= 90){    //대문자인경우
            arr[c-65]--;    //0~25
        }else{
            arr[c-71]--;    //26~51
        }
    }
    for(int i = 0; i < 52; i++){
        if(arr[i] != 0){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}


//
#include <stdio.h>
#include <algorithm>
int a[60], b[60];
int main(){
    char str[100];
    int i;
    scanf("%s", &str);
    for(i = 0; str[i] != '\0'; i++){
        if(str[i]>=65 && str[i] <= 90){
            a[str[i]-64]++;
        }else a[str[i]-70]++;
    }
    scanf("%s", &str);
    for(i = 0; str[i] != '\0'; i++){
        if(str[i]>=65 && str[i] <= 90){
            b[str[i]-64]++;
        }else b[str[i]-70]++;
    }
    for(i = 1; i <= 52; i++){
        if(a[i] != b[i]){
            printf("NO\n");
            exit(0);
        }
    }
    printf("YES\n");

    return 0;
}