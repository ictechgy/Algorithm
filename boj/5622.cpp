#include <stdio.h>

int main(void){
    char c;
    int sec = 0;
    while(1){
        scanf("%c", &c);
        if(c=='\n') break;
        
        //ABC-3초, DEF-4초 ... 
        if(c <= 'C') sec += 3;
        else if(c <= 'F') sec += 4;
        else if(c <= 'I') sec += 5;
        else if(c <= 'L') sec += 6;
        else if(c <= 'O') sec += 7;
        else if(c <= 'S') sec += 8;
        else if(c <= 'V') sec += 9;
        else if(c <= 'Z') sec += 10;
    }
    printf("%d\n", sec);

    return 0;
}   //다른 방법도 있을까..