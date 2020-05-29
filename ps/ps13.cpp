#include <stdio.h>

int main(void){
    //char num[101] = {0};    //숫자는 100글자를 넘지 않으므로 최대 100글자. 따라서 공간은 101개 마련(널 고려)
    //scanf("%s", num);
    //이처럼 입력받은 숫자를 한번에 저장한 후 계산해도 되지만..
    
    int arr[10] = {0};  //숫자 사용빈도 저장 배열
    char su; //하나씩 읽기
    while(true){        //scanf("%c", &su) != 0 를 조건으로 해볼까 했는데 \n 개행문자도 1개의 문자로서 인식할 것으로 예상함
        scanf("%c", &su);   //값 하나씩 읽는다
        if(su == '\n') break;   //숫자가 아닌 경우 빠져나가기
        arr[su-48]++;   //빈도값 체크
    }

    int max = -1;   //가장 많이 등장한 수의 사용횟수 저장 -> 최소 0개이므로 -1로 초기화
    int num = 0;    //가장 많이 등장한 수 저장 -> 0 ~ 9 의 값
    for(int i = 0; i < 10; i++){
        if(arr[i] > max){
            max = arr[i];
            num = i;
        }else if(arr[i] == max && i > num){
            num = i;
        } 
    }
    printf("%d\n", num);

    return 0;
}

//강의 코드
#include <stdio.h>
int ch[10];
int main(){
    int i, digit, max = -2147000000, res;
    char a[101];
    scanf("%s", a); //한번에 읽기
    for(i = 0; a[i] != '\0'; i++){
        digit = a[i] - 48;
        ch[digit]++;
    }
    for(i = 0; i <= 9; i++){
        if(ch[i] >= max){   //빈도 수가 같은 경우에도 똑같이 해줘도 된다. 작은 수부터 큰 수로 검색해나가므로.
            max = ch[i];
            res = i;
        }
    }
    printf("%d\n", res);

    return 0;
}