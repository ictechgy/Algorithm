#include <stdio.h>
#include <stdlib.h>

int main(void){
    int case_num;
    scanf("%d", &case_num);
    int num;
    for(int i = 1; i <= case_num; i++){
        scanf("%d", &num);
        int* students = (int*)calloc(num, sizeof(int));
        int sum = 0;
        for(int j = 0; j < num; j++){
            scanf("%d", &students[j]);
            sum += students[j];
        }
        double avg = (double)sum / num;
        int count = 0;
        for(int j = 0; j < num; j++){
            if(students[j] > avg) count++;
        }
        printf("%.3f%%\n", (double)count/num * 100);
        students = NULL;
    }
    
    return 0;
}