#include <stdio.h>

int main(void){
    char c, num_c = 0, num_h = 0;
    getchar();
    while(1){
        scanf("%c", &c);
        if(c == 'H') break;
        num_c = num_c * 10 + c-48;
    }
    while(1){
        scanf("%c", &c);
        if(c == '\n') break;
        num_h = num_h * 10 + c - 48;
    }
    if(num_c == 0) num_c = 1;
    if(num_h == 0) num_h = 1;
    printf("%d\n", (12 * num_c) + (1 * num_h));

    return 0;
}

//
#include <stdio.h>
int main(){
    char a[10];
    int c = 0, h = 0, i, pos;
    scanf("%s", a);
    if(a[1] == 'H') {
        c = 1;
        pos = 1;
    }else{
        for(i = 1; a[i] != 'H'; i++){
            c = c * 10 + (a[i] - 48);
        }
        pos = i; //H의 위치
    }
    if(a[pos + 1] == '\0') h = 1;
    else{
        for(i = pos + 1; a[i] != '\0'; i++){
            h = h * 10 + (a[i] - 48);
        }
    }
    printf("%d\n", c*12+h);

    return 0;
}