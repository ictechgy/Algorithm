//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

#define BACKGROUND_COLOR = 0
#define IMAGE_COLOR 1
#define ALREADY_COUNTED 2

int N = 8;
int cell[][8] = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 0, 0},
    {1, 1, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1, 1}
};

int countCells(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N || cell[x][y] != IMAGE_COLOR) return 0;   //base-case
    else{
        cell[x][y] = ALREADY_COUNTED;
        return 1 + countCells(x-1, y) + countCells(x-1, y+1) + countCells(x, y+1) +
            countCells(x+1, y+1) + countCells(x+1, y) + countCells(x+1, y-1) + countCells(x, y-1) +
            countCells(x-1, y-1);
    }
}

int main(void){
    printf("%d\n", countCells(3, 5));

    return 0;
}