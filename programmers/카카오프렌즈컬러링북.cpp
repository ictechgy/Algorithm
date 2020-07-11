#include <vector>

using namespace std;

int r, c;   //row, column
vector<vector<int>> pic;

int count_cells(int x, int y, int color){
    if(x < 0 || y < 0 || x >= r || y >= c || pic[x][y] != color) return 0;
    pic[x][y] = 0;  //현재 위치를 0으로 변경
    return 1 + count_cells(x-1, y, color) + count_cells(x, y+1, color)
        + count_cells(x+1, y, color) + count_cells(x, y-1, color);
        //북동남서 방향으로 현재 픽셀과 같은 색의 값이 몇개나 있는지 재귀적으로 호출하여 셈한다. 
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    r = m;
    c = n;
    pic = picture;

    int i, j, cnt, max = 0, district = 0;  
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(pic[i][j] == 0) continue;    //0부분의 경우 건너뛰기
            cnt = count_cells(i, j, pic[i][j]); //해당 영역과 같은 색의 픽셀 개수 구하기
            district++;
            if(cnt > max) max = cnt;
        }
    }
    
    vector<int> answer(2);
    answer[0] = district;
    answer[1] = max;
    return answer;
}

//BFS를 이용한 풀이도 존재한다. 