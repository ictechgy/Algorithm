//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

#define PATHWAY_COLOR 0
#define WALL_COLOR 1
#define BLOCKED_COLOR 2
#define PATH_COLOR 3

int N = 8;
int maze[][8] = {
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 1, 0, 0}
};
//문제에 따라 맨 바깥쪽을 벽으로 감싸는 경우도 존재.

bool findMazePath(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N || maze[x][y] != PATHWAY_COLOR) return false; //맨 바깥쪽을 벽으로 감싸는 경우 앞의 네 조건은 없어도 됨. 
    else if(x == N-1 && y == N-1){
        maze[x][y] = PATH_COLOR;
        return true;
    } else{
        maze[x][y] = PATH_COLOR;
        if(findMazePath(x-1, y) || findMazePath(x, y+1) || findMazePath(x+1, y) || findMazePath(x, y-1)) return true;
        maze[x][y] = BLOCKED_COLOR;
        return false;
    }
}

void printMaze(){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++) printf("%d ", maze[i][j]);
        printf("\n");
    }
}

int main(void){
    printMaze();
    printf("\n");
    findMazePath(0, 0);
    printMaze();
    return 0;
}

//위의 재귀적 방식은 Stack으로도 구현가능