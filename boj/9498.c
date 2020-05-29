#include <stdio.h>

int main(void){
    int score;
    scanf("%d", &score);
    score /= 10;
    char result;
    switch(score){
        case 10:
        case 9:
            result = 'A';
            break;
        case 8:
            result = 'B';
            break;
        case 7:
            result = 'C';
            break;
        case 6:
            result = 'D';
            break;
        default:
            result = 'F';
            break;
    }
    printf("%c\n", result);
    return 0;
}