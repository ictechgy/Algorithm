#include <stdio.h>

int main(void){
    int n, a[101], b[101], i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &b[i]);
    }
    int gap;
    char r;
    for(i = 1; i <= n; i++){
        gap = a[i] - b[i];
        if(gap == 0) r = 'D';
        else if(gap == -2 || gap == 1) r = 'A';
        else r = 'B';
        printf("%c\n", r);
    }

    return 0;
}

//
#include <stdio.h>
int main(){
    int n, i, a[101], b[101];
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &b[i]);
    }
    for(i = 1; i <= n; i++){
        if(a[i] == b[i]) printf("D\n");
        else if(a[i] == 1 && b[i] == 3) printf("A\n");
        else if(a[i] == 2 && b[i] == 1) printf("A\n");
        else if(a[i] == 3 && b[i] == 2) printf("A\n");
        else printf("B\n");
    }

    return 0;
}