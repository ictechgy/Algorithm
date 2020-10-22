//아니면.. 행, 열, 3x3공간별로 쓰이지 않은 숫자 값에 대한 vector를 만들어두거나 bool형 체크 배열을 만들고
//DFS해나가면서 쓰이지 않은 값만 선택되도록 만들어야 하나? 어떻게 작성 해야하지 그럼?
//쓰이지 않은 값에 대한 vector를 사용한다면 DFS하면서 각 단계에서 특정 숫자를 선택하여 쓴 경우
//해당 숫자에 대한 사용처리를 하기가 애매하니까 bool형 배열을 쓰는게 나을 수도 있겠다.. 
//(vector로는 지웠다가 다시 추가하는 등의 백트래킹이 불편)
#include <bits/stdc++.h>
using namespace std;
int Map[10][10];
bool ckRow[10][10], ckColumn[10][10], ckBox[10][10];    //각각의 행, 열, 3x3박스에서 1~9의 숫자가 쓰였는지 체크할 배열

struct Coord{
    int y, x;
    
    Coord(int a, int b){
        y = a;
        x = b;
    }
};
Coord starts[9] = {{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}};
vector<Coord> blanks;

bool DFS(int k){
    if(k >= blanks.size()){
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                cout << Map[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }else{
        Coord blank = blanks[k];
        int index = 3*((blank.y-1)/3) + ((blank.x-1)/3)+1;
        //blank좌표가 있는 곳의 위치가 ckBox의 몇번째 칸에 해당하는지 구하는 공식. 
        //배열값이 0,0으로 시작한다면 3으로 나눈 몫으로 각각의 칸을 구분할 수 있으므로 (같은 칸의 좌표들은 3으로 나누는 경우 모두 동일 값으로 귀결) 
        //x,y좌표에 1을 뺀 값을 3으로 나누고, ckBox가 1부터 시작하므로 마지막에 1을 더함

        for(int i = 1; i <= 9; i++){
            if(ckRow[blank.y][i] == false && ckColumn[i][blank.x] == false && ckBox[index][i] == false){   
                //빈 공간의 가로, 세로, 박스칸에서 동시에 쓰이지 않은 숫자가 있다면
                Map[blank.y][blank.x] = i;  //해당 빈칸에 값 할당
                ckRow[blank.y][i] = ckColumn[i][blank.x] = ckBox[index][i] = true;  //사용체크
                if(DFS(k+1)) return true;
                Map[blank.y][blank.x] = 0;  //이 구문은 있어도 되고 없어도 되고
                ckRow[blank.y][i] = ckColumn[i][blank.x] = ckBox[index][i] = false; //해당 숫자를 이용하였을 때 문제가 안풀리므로 사용체크 해제
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
            ckRow[i][Map[i][j]] = true;
            ckColumn[Map[i][j]][j] = true;
            if(Map[i][j] == 0) blanks.push_back(Coord(i, j));
        }
    }
    for(int k = 1; k <= 9; k++){
        Coord start = starts[k-1];
        for(int i = start.y; i < start.y+3; i++){
            for(int j = start.x; j < start.x+3; j++){
                ckBox[k][Map[i][j]] = true;
            }
        }
    }

    DFS(0);

    return 0;
}


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
vector<Coord> blanks;   //값을 채워야 하는 부분들을 모아놓을 vector
Coord starts[9] = {{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}};
//기존에 vector로 선언해두었으나 {}를 이용한 초기화가 boj의 컴파일러 버전(C++98)에서 불가능하여 변경

bool DFS(int k){
    if(k >= blanks.size()){
        //유효성 검증
        for(int k = 1; k <= 9; k++){
            bool isUsed[10] = {false, };
            Coord start = starts[k];
            for(int i = start.y; i < start.y+3; i++){
                for(int j = start.x; j < start.x+3; j++){
                    isUsed[Map[i][j]] = true;
                }
            }
            for(int i = 1; i <= 9; i++){
                if(isUsed[i] == false) return false;    //기존에는 3x3공간의 총합 값이 45인지 검증하였었음. 
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
                Map[coord.y][coord.x] = i;      //기존 코드의 이 부분에서 x와 y를 서로 바꿔쓰는 치명적 실수를 저질렀다.
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
}*/
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
        blanks.clear();
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