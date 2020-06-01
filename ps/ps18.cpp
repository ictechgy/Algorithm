#include <stdio.h>

int main(void){
    int n, ref, sound, max = 0, over = 0;
    bool isWarned = false;
    scanf("%d %d", &n, &ref);
    for(int i = 1; i <= n; i++){
        scanf("%d", &sound);

        if(sound > ref){
            isWarned = true;
            over++;
            if(over > max) max = over;
        }else{
            over = 0;
        }
    }
    if(!isWarned) max = -1; //굳이 flag를 안두고 max == 0 일 경우 max = -1로 해도 됨
    printf("%d\n", max);

    return 0;
}

//
#include <stdio.h>
int main(){
    int n, a, val, i, cnt = 0, max = -2147000000;
    scanf("%d %d", &n, &val);

    for(i = 1; i <= n; i++){
        scanf("%d", &a);
        if(a > val) cnt++;
        else cnt = 0;
        if(cnt > max) max = cnt;
    }
    if(max == 0) printf("-1\n");
    else printf("%d\n", max);

    return 0;
}