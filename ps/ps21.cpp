#include <stdio.h>

int main(void){
    int a[10], b[10], i, sa = 0, sb = 0;
    char last = 'D';
    for(i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < 10; i++){
        scanf("%d", &b[i]);
    }
    for(i = 0; i < 10; i++){
        if(a[i] > b[i]) {
            sa += 3;
            last = 'A';
        }else if(b[i] > a[i]) {
            sb += 3;
            last = 'B';
        }else {
            sa += 1;
            sb += 1;
        }
    }
    printf("%d %d\n", sa, sb);
    if(sa > sb) printf("A\n");
    else if (sb > sa) printf("B\n");
    else printf("%c\n", last);

    return 0;
}

//
#include <stdio.h>
int main(){
    int i, A[10], B[10], as = 0, bs = 0, lw = 0;
    for(i = 0; i < 10; i++){
        scanf("%d", &A[i]);
    }
    for(i = 0; i < 10; i++){
        scanf("%d", &B[i]);
    }
    for(i = 0; i < 10; i++){
        if(A[i] > B[i]){
            as = as + 3;
            lw = 1;
        }else if(A[i] < B[i]){
            bs = bs + 3;
            lw = 2;
        }else{
            as += 1;
            bs += 1;
        }
    }
    printf("%d %d\n", as, bs);
    if(as == bs){
        if(lw == 0) printf("D\n");
        else if(lw == 1) printf("A\n");
        else printf("B\n");
    }else if(as > bs) printf("A\n");
    else printf("B\n");

    return 0;
}