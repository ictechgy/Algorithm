#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int day_of_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day_of_week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int total = 0, i;   
    for(i = 0; i < a-1; i++){
        total += day_of_month[i];
    }
    total += b; //a월 b일이 그 해의 몇번째 일인지 계산
    
    return day_of_week[(total-1+5)%7];
}
//1월 1일과의 차이값인 1을 빼주고 1일이 금요일(5번 인덱스)부터 시작하므로 +5를 해준 뒤 %7로 모드연산