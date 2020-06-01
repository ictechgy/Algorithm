#include <stdio.h>

int main(void){
    int n, num, answer;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num);
        scanf("%d", &answer);
        if((num+1)*num/2 == answer) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

//
#include <stdio.h>
int main(void){
    int n, sum = 0, i, j, m, ans;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d %d", &m, &ans);
        sum = 0;
        for(j = 1; j <= m; j++){
            sum +=j;
        }
        if(ans == sum) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}