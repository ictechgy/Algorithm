#include <stdio.h>

int main(void){
    int n, i, j, cnt = 0;
    char arr[101] = {0}, prev, now;
    int alpha[26] = {0};    //알파벳이 나왔는지 체크
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < 26; j++) alpha[j] = 0;   //모든 공간 값 0으로 세팅
        
        scanf("%s", arr);       //꼭 배열에다 저장해야할까. char에 하나씩 따져서 저장하고 \n으로 구분하는 방법..
        prev = arr[0];
        for(j = 1; arr[j] != 0; j++){
            now = arr[j];
            if(prev != now) {   //이전 글자와 현재 글자가 다르다면 이전 글자가 더이상 나오지 않아야 됨
                if(alpha[prev-97] != 0) break;  //해당 알파벳이 이전에 이미 나온 것인 경우
                alpha[prev-97]++;
                prev = now;
            }
        }
        if(arr[j] == 0 && alpha[now-97] == 0) cnt++;  

        //위의 반복문 형식보다는 .. (다른 알파벳이 나오면 이전 알파벳에 대한 체크를 하는 것보다는)
        prev = 0;
        for(j = 0; arr[j] != 0; j++){
            now = arr[j];
            if(prev != now){
                if(alpha[now-97] != 0) break; 
                alpha[now-97]++;
                prev = now;
            }
        }
        if(arr[j] == 0) cnt++;
        //이렇게 새로운 글자가 나오면 해당 글자를 체크해주는게 더 나을듯
        //prev와 now는 마지막 알파벳에 대한 값을 가지고 있을 것임..
    }
    printf("%d\n", cnt);    

    return 0;
}