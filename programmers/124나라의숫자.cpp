#include <string>
#include <vector>

using namespace std;

string proc_carry(string s, int p){    //carry processing
    //p인덱스에서 넘어온 캐리를 처리하여 s를 변경시킨다.
    if(p == 0){ //0번 인덱스 위치에서 캐리가 발생했다면 자리수를 늘려야 한다.
        string value = 
    }
    char c = s[p-1];
    switch (c)
    {
    case '1':
        /* code */
        break;
    
    default:
        break;
    }
}

string solution(int n) {
    //3으로 나눈 나머지가 1, 2, 0이냐에 따라 맨 뒤 숫자가 1, 2, 4가 되는 것은 알겠는데..
    //그 앞의 숫자는 어떻게 정해나가야 하지? cnt변수같은걸 둬서 n값에 이를 때까지 answer string을 바꿔주는 식으로 해야하나
    //1의 자리에서는 숫자 하나를, 10의 자리부분에서는 1의 자리 숫자 3개를, 100의 자리 값은 그 자리값 하나에서 9개의 수를 포함 -> 이걸 이용할 수 있을까?
    //10진법은 0 ~ 9를 넘으면 carry가 발생하고 다시 1의 자리는 0부터 시작하듯이 1, 2, 4 이후에 1의 자리는 1로 돌아오고 carry를 처리하는 방식으로? 

    string base[] = {"0", "1", "2", "4"};  //0번 인덱스 값은 쓰지 않음
    string prev = base[3];  //prev값은 "4"의 값을 가지고 있음
    string now;
    int i;
    for(i = 4; i <= n; i++){    //n까지 계산해 나아간다. 
        if(prev.back() == '4'){ //이전 수의 맨 뒤의 수가 4였다면 이번 수를 구할 때는 캐리를 올려야 한다.
            prev.back() == '1';

        }
    }
    string answer = "";
    
    return answer;
}