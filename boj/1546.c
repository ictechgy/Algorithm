#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    int input;
    int max = 0, sum = 0;
    for(int i = 0; i < num; i++){
        scanf("%d", &input);
        sum += input;
        if(input > max) {
            max = input;
        }
    }
    double avg = ((double)sum/max*100) / num;
    printf("%f\n", avg);
        
    return 0;
}