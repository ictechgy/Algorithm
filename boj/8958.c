#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    getchar(); //'\n' 제거
    char input;
    for(int i = 1; i <= num; i++){
        int sum = 0;
        int accum_score = 1;
        while((input = getchar()) != '\n'){
            if(input == 'O'){
                sum+=accum_score;
                accum_score++;
            }else{
                accum_score = 1;
            }
        }
        printf("%d\n", sum);
    }
    
    return 0;
}