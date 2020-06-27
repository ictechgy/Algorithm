#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, i, sp = -1, column, row, goods;

    vector<int> stack(moves.size());    //집게로 집는 횟수만큼의 스택 생성
    for(i = 0; i < moves.size(); i++){
        //push_back, pop_back을 쓸 수도 있지만 어차피 내용물을 확인해야 하므로 스택포인터 사용
        column = moves[i] - 1;  //크레인이 뽑는 숫자는 1부터 시작하도록 주어지므로 1을 뻄
        for(row = 0; row < board[0].size(); row++){   //한 행의 원소 개수 == 한 열의 원소 개수
            goods = board[row][column];
            if(goods) {
                stack[++sp] = goods;  //0이 아닌 값을 뽑은 경우 스택에 추가
                board[row][column] = 0;
                break;
            }
        }
        if(sp > 0 && stack[sp-1] == stack[sp]){
            answer += 2;
            sp -= 2;
        }   //현재 인형을 넣은 이후에 비교를 하지만 인형을 넣기 전에 크레인으로 뽑은 것과 스택의 Top이 같은지 비교하여 계산하는 방법도 존재
    }
    
    return answer;
    
    /*
    00000
    00103
    02501
    42442
    35131
    
    크레인이 1,5,3,5,1,2,1,4 집어간 경우
    스택 -> 4311324
    */
}
//다른사람들은 명시적으로 <stack>을 include하여 풀이함. 
//1. board[0].size 라고 내가 한 부분은 그냥 board.size라고 풀이함
