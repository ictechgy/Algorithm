#include <stdio.h>

int main(void){
    int i, c, h, w, n;
    scanf("%d", &c);
    for(i = 0; i < c; i++){
        scanf("%d %d %d", &h, &w, &n);
        //한 열에 존재하는 방의 개수는 h개이다.
        if(n%h==0){ //원하는 방이 맨 위에 존재
            printf("%d%02d\n", h, n/h);
        }else{
            printf("%d%02d\n",n%h ,n/h+1);
        }
    } 

    return 0;
}