#include <string>
#include <vector>

using namespace std;

void proc_carry(string& s, int p){    //processe carry, s - 숫자 원문, p - carry가 발생한 위치(carry를 올려주고 1이 된 위치의 인덱스)
    if(p == 0){ //0번 인덱스 위치에서 캐리가 발생했다면 자리수를 늘려야 한다.
        string temp = "1";
        s = temp.append(s);
        return;
    }
    switch (s[p-1]){     //carry를 넘겨 받은 위치의 값을 파악한다. -> carry를 넘겨받은 위치의 값을 바꿔준다. 
    case '1':
        s[p-1] = '2';
        break;
    case '2':
        s[p-1] = '4';
        break;
    case '4':   //이 경우 carry를 넘겨받았는데 또 carry가 발생하게 되는 경우가 된다. 
        s[p-1] = '1';
        proc_carry(s, p-1); //recurcive call
        break;
    }
}

string solution(int n) {
    //3으로 나눈 나머지가 1, 2, 0이냐에 따라 맨 뒤 숫자가 1, 2, 4가 되는 것은 알겠는데..
    //그 앞의 숫자는 어떻게 정해나가야 하지? cnt변수같은걸 둬서 n값에 이를 때까지 answer string을 바꿔주는 식으로 해야하나
    //1의 자리에서는 숫자 하나를, 10의 자리부분에서는 1의 자리 숫자 3개를, 100의 자리 값은 그 자리값 하나에서 9개의 수를 포함 -> 이걸 이용할 수 있을까?
    //10진법은 0 ~ 9를 넘으면 carry가 발생하고 다시 1의 자리는 0부터 시작하듯이 1, 2, 4 이후에 1의 자리는 1로 돌아오고 carry를 처리하는 방식으로? 
    //어떤 2진수적인 숫자방식으로 풀 수도 있을까?

    string num = "1";
    if(n == 1) return num;
    int i;
    char m; //modifying, 변경할 값
    for(i = 2; i <= n; i++){    //n까지 계산해 나아간다. 
        switch (num.back()){
        case '1':
            m = '2';
            break;
        case '2':
            m = '4';
            break;
        case '4':   //이전 수의 맨 뒤의 수가 4였다면 이번 수를 구할 때는 캐리를 올려야 한다.
            m = '1';
            proc_carry(num, num.length()-1);
            break;
        }
        num.back() = m;
    }
    return num;
}