#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    //1, 7, 19, 37, 61 순서로 층이 쌓인다. 이는 6, 12, 18 로 값이 더해지는 규칙이 있음
    //해당 수의 범위 내에 있는 숫자들은 무조건 최소 해당 층만큼 방을 지남
    //1은 1개, 2~7은 2개, 8~19는 3개...
    //범위의 하한 값: 1, 2, 8, 20, 38, 62 - 상한 값: 1, 7, 19, 37, 61...
    int room = 1, compare = 1;  //room: 몇개의 방을 지나느냐, compare: 비교 상한 값
    while(1){
        if(n <= compare){
            printf("%d\n", room);
            break;
        }
        compare += 6*room;
        room++;
    }

    return 0;
}