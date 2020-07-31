#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool checkPeak(vector<vector<int> >&, int, int, vector<vector<int> >&);

int main(void){
    int n, i, j, cnt = 0;
    scanf("%d", &n);
    vector<vector<int> > map(n+2, vector<int>(n+2, 0));
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    //2중 for문을 돌면서 모든 공간에 대해 봉우리인지 검사? 또는 recursive?
    //잘 보면 봉우리 근처의 공간들(동서남북)은 봉우리가 될 수 없다.. 
    vector<vector<int> > chk(n+2, vector<int>(n+2, 0)); //봉우리인 부분은 1로 만들고 봉우리가 될 수 없는 부분은 -1로 만든다.
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(checkPeak(map, i, j, chk)) cnt++; //(i,j)가 봉우리라면 true를 반환하고 이를 카운팅
        }
    }
    printf("%d\n", cnt);

    return 0;
}

//chk배열에서 0은 봉우리가 될 수 있는지 없는지 아직 평가되지 않음, 1은 봉우리, -1은 봉우리가 될 수 없음을 의미한다.
bool checkPeak(vector<vector<int> > &map, int i, int j, vector<vector<int> > &chk){
    if(chk[i][j] == -1) return false;   //봉우리가 될 수 없는 부분인 경우
    else{   //chk[i][j] == 0 인 경우
        int height = map[i][j];
        if(map[i-1][j] < height && map[i][j+1] < height && map[i+1][j] < height && map[i][j-1] < height){   
            //또는 상하좌우지점 중 max값만을 가져와서 height와 비교하는 것도 괜찮을 듯
            chk[i-1][j] = -1;
            chk[i][j+1] = -1;
            chk[i+1][j] = -1;
            chk[i][j-1] = -1;
            chk[i][j] = 1;  //해당 지역은 봉우리
            return true;
        }
        chk[i][j] = -1; //해당 지역은 봉우리가 아님. 
        return false;
    }
}

//
