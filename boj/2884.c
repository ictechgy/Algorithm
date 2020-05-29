#include <stdio.h>

int main(int argc, const char * argv[]) {
    int h, m;
    scanf("%d %d", &h, &m);
    m -= 45;
    if(m < 0){
        m = 60 + m;
        h -= 1;
        if(h < 0) h = 24 + h;
    }
    printf("%d %d\n", h, m);
    return 0;
}
