#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);    //num of test cases
    int loop; //Number of repetitions of each character
    for(int i = 1; i <= num; i++){
        scanf("%d", &loop);
        getchar(); //delete space between reptNum and alpha
        char alpha;
        while((alpha=getchar())!='\n'){
            for(int j = 1; j <= loop; j++){
                printf("%c", alpha);
            }
        }
        printf("%c", alpha); //'\n'
    }
    return 0;
}