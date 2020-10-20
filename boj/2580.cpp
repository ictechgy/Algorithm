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
Coord starts[9] = {{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}};

bool DFS(int k){
    if(k >= blanks.size()){
        //유효성 검증
        for(int k = 0; k < 9; k++){
            bool isUsed[10] = {false, };
            Coord start = starts[k];
            for(int i = start.y; i < start.y+3; i++){
                for(int j = start.x; j < start.x+3; j++){
                    isUsed[Map[i][j]] = true;
                }
            }
            for(int i = 1; i <= 9; i++){
                if(isUsed[i] == false) return false;
            }
        }   //마지막에는 각각의 3x3칸 내에서의 유효성만을 검증 
        
        return true;
    }else{
        Coord coord = blanks[k];
        bool isUsed[10] = {false, };
        for(int i = 1; i <= 9; i++){
            isUsed[Map[coord.y][i]] = true;
            isUsed[Map[i][coord.x]] = true;
        }   //빈 공간의 행, 열에서 이미 사용된 숫자 값은 제외

        for(int i = 1; i <= 9; i++){
            if(isUsed[i] == false){
                Map[blanks[k].y][blanks[k].x] = i;      //기존 코드의 이 부분에서 x와 y를 서로 바꿔쓰는 치명적 실수를 저질렀다.
                //테스트 해보니 x, y를 제대로 작성 했어도 시간이 오래 걸려 문제를 해결하는데 충분하지는 않았다. 하지만 이런 실수 조심하자. 
                if(DFS(k+1)) return true; 
            }
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
//아니면 이미 작성했던 위의 DFS코드에서 쓰이지 않은 숫자값에 대한 조건을 이용할 수는 없을까?
//재귀적으로 DFS탐색을 하되 각 행과 열, 공간에서 쓰이지 않은 숫자값에 대해서만 탐색을 하도록.
//그렇다면 어떻게 구현해야 할까? 

/*
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
vector<Coord> starts = {{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;    //총 빈 공간의 개수 카운팅
    vector<Coord> blanks;

    for(int i = 1; i < 10; i++){
        bool isUsed[10] = {false, };    //각 숫자가 각 행에서 쓰였는지 체크.
        for(int j = 1; j < 10; j++){
            cin >> Map[i][j];
            isUsed[Map[i][j]] = true;
            if(Map[i][j] == 0) {
                blanks.push_back(Coord(i, j));
                cnt++;
            }
        }
        if(blanks.size() == 1){ //1개의 공간만 비어있다면 해당 공간의 값은 입력받으면서도 바로 유추 가능하다.
            int notUsed;
            for(int i = 1; i < 10; i++){
                if(isUsed[i] == false) notUsed = i;
            }
            Map[blanks[0].y][blanks[0].x] = notUsed;
            cnt--;
        }
    }
    
    while(cnt > 0){
        for(int i = 1; i < 10; i++){
            bool isUsed[10] = {false, };
            blanks.clear();
            for(int j = 1; j < 10; j++){
                isUsed[Map[i][j]] = true;
                if(Map[i][j] == 0){
                    blanks.push_back(Coord(i, j));
                }
            }
            if(blanks.size() == 1){
                int notUsed;
                for(int i = 1; i < 10; i++){
                    if(isUsed[i] == false) notUsed = i;
                }
                Map[blanks[0].y][blanks[0].x] = notUsed;
                cnt--;
            }
        }   //행 탐색

        for(int i = 1; i < 10; i++){
            bool isUsed[10] = {false, };
            blanks.clear();
            for(int j = 1; j < 10; j++){
                isUsed[Map[j][i]] = true;
                if(Map[j][i] == 0){
                    blanks.push_back(Coord(j, i));
                }
            }
            if(blanks.size() == 1){
                int notUsed;
                for(int i = 1; i < 10; i++){
                    if(isUsed[i] == false) notUsed = i;
                }
                Map[blanks[0].y][blanks[0].x] = notUsed;
                cnt--;
            }
        }   //열 탐색

        for(int k = 0; k < 9; k++){
            bool isUsed[10] = {false, };
            blanks.clear();
            Coord start = starts[k];
            for(int i = start.y; i < start.y+3; i++){
                for(int j = start.x; j < start.x+3; j++){
                    isUsed[Map[i][j]] = true;
                    if(Map[i][j] == 0){
                        blanks.push_back(Coord(i, j));
                    }
                }
            }
            if(blanks.size() == 1){
                int notUsed;
                for(int i = 1; i < 10; i++){
                    if(isUsed[i] == false) notUsed = i;
                }
                Map[blanks[0].y][blanks[0].x] = notUsed;
                cnt--;
            }
        }   //각각의 3x3공간에서의 탐색
    }

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cout << Map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
*/