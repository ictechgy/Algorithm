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
    if(!isWarned) max = -1;
    printf("%d\n", max);

    return 0;
}

//
