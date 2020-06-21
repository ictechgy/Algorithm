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

#include <stdio.h>

int main(void){
    char c, prev;
    int cnt = 0;
    while(1){
        scanf("%c", &c);
        if(c == '\n') break;

        if(prev == 'c' && c == '=' || c == '-');
        else if(prev == 'd' && c == '-');
        else if(prev == 'l' || prev == 'n' && c == 'j');
        else if(prev == 's' || prev == 'z' && c == '=');
        else cnt++; 

        prev = c;
    }
    printf("%d\n", cnt);

    return 0;
}   //막연히 이렇게만 하려니까 dz=에 대한 처리를 할 수가 없다. z=이 나왔을 때 앞에 d가있는지 없는지

#include <stdio.h>

int main(void){
    //최대 100글자의 단어가 주어짐
    char croat[110] = {0};          
    char c;
    int i, cnt = 0;
    scanf("%s", croat);
    for(i = 0; croat[i] != 0; i++){
        // if(c == 'c' && croat[i+1] == '=' || croat[i+1] == '-') i++;
        // else if(c == 'd' && croat[i+1] == 'z' && croat[i+2] == '=') i += 2;
        // else if(c == 'd' && croat[i+1] == '-')
        //위와 같이 굳이 일일히 써줘야 할까?
        
        //어차피 =과 -가 나오는 경우는 당연히 크로아티아 알파벳이다. (이전 글자가 c나 d, s, z임이 분명)
        c = croat[i];
        if(c == '-' || c == '=') continue;
        else if(((c == 'l') || (c == 'n')) && (croat[i+1] == 'j')) i++;
        else if((c == 'd') && (croat[i+1] == 'z') && (croat[i+2] == '=')) i+=2;   //인덱스 오버해서 참조하는것 때문에 배열 크기를 더 크게 잡긴 했는데..
        else if(!(c>=97 && c<=122)) continue;   //예외적인 상황이 있는건가?  -> 넣어주니 처리됨 
        //뭔가 dz=과 z=를 동시이용 가능할거 같은데..

        cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}   //맞왜틀..  -> 마지막 else if 구문을 넣어주니 맞았다고 나온다. 입력조건에 알파벳 소문자와 -, =만 있다고 했는데 그게 아닌건가

//일단 입력받은 뒤에 거꾸로 읽는 방식을 시도해볼까 -> 이게 더 깔끔할수도? 
// =이나 - 과같은 알파벳이 아닌 기호 나오면 무시하고 그 앞의 값을 읽도록 구성
//읽다가 z가 나왔다면 앞뒷값 확인하여 dz=에 대한 처리(z=처리)
//j나오면 그 앞의 값 읽어 lj, nj처리
