#include <bits/stdc++.h>
using namespace std;
int Map[10][10];

struct Coord{
    int y, x;
    
    Coord(int a, int b){
        y = a;
        x = b;
    }
};
vector<Coord> blanks;
vector<Coord> starts = {{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}};

bool DFS(int k){
    if(k >= blanks.size()){
        //유효성 검증
        for(int i = 1; i <= 9; i++){
            int low = 0;
            for(int j = 1; j <= 9; j++){
                low += Map[i][j];
            }
            if(low != 45) return false;
        }   //행 유효성

        for(int i = 1; i <= 9; i++){
            int column = 0;
            for(int j = 1; j <= 9; j++){
                column += Map[j][i];
            }
            if(column != 45) return false;
        }   //열 유효성

        for(int k = 0; k < 9; k++){
            int sum = 0;
            Coord start = starts[k];
            for(int i = start.y; i < start.y+3; i++){
                for(int j = start.x; j < start.x+3; j++){
                    sum += Map[i][j];
                }
            }
            if(sum != 45) return false;
        }   //각각의 3x3칸 내에서의 유효성 검증 

        return true;
    }else{
        for(int i = 1; i <= 9; i++){
            Map[blanks[k].x][blanks[k].y] = i;
            if(DFS(k+1)) return true;
        }
        return false;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 0) blanks.push_back(Coord(i, j));
        }
    }

    DFS(0);

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cout << Map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}