#include <bits/stdc++.h>
using namespace std;
int T, A, B;

int multiply(int n){
    return (2*n)%10000;
}

int subtract(int n){
    n -= 1;
    if(n < 0) n = 9999;
    return n;
}

int left(int n){
    if(n < 1000) return n * 10;
    int front = n / 1000;   //맨 앞자리 수
    n = (n - (front * 1000))*10 + front;
    return n;
}

int right(int n){
    int last = n % 10;  //맨 뒤의 수
    n = (n / 10) + (last * 1000);
    return n;
}

struct Register{
    int num;
    string command;
    Register(int n, const string &s){
        num = n;
        command = s;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool ck[10000];     //큐에 이미 들어갔던 숫자는 다시 넣지 않기 위한 체크배열
    
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> A >> B;
        memset(ck, 0, sizeof(ck));

        queue<Register> q;      //Queue는 별도로 clear함수가 없어서 외부에서 선언해서 재사용할 수가 없구나..
        q.push(Register(A, ""));
        ck[A] = true;

        while(!q.empty()){
            Register &node = q.front();
            q.pop();
            int n = node.num;
            string &s = node.command;

            int after;
            after = multiply(n);
            if(after == B) {cout << s + "D" << "\n"; break;}
            if(!ck[after]) {q.push(Register(after, s + "D")); ck[after] = true;}

            after = subtract(n);
            if(after == B) {cout << s + "S" << "\n"; break;}
            if(!ck[after]) {q.push(Register(after, s + "S")); ck[after] = true;}

            after = left(n);
            if(after == B) {cout << s + "L" << "\n"; break;}
            if(!ck[after]) {q.push(Register(after, s + "L")); ck[after] = true;}

            after = right(n);
            if(after == B) {cout << s + "R" << "\n"; break;}
            if(!ck[after]) {q.push(Register(after, s + "R")); ck[after] = true;}
        }
    }

    return 0;
}

/*
혹시나 해서인데 계속 7%대에서 틀리는 이유가.. 
A가 1, B가 10일 때
결과 값으로는 DDSDSD가 나오는데
A값을 0001로 준거여서.. 정답이 L 하나만 나와야 한다는건가..?
0001 -> 0010 ..?
*/

//작성하다보니 든 생각인데 이렇게 string으로 자릿수와 상관없는 0도 살려서 처리하는게 맞는걸까? 
//예제입력에서는 A와 B 다 0001처럼 주어지지는 않는거같은데
//너무 모르겠어서 설마설마 하고 질문글 쪽을 봤는데.. 0을 살려서 보는게 맞는 듯 하다.
//123을 L하면 231이 아니라 1230이라고 한다... 
//string으로서 구현할려고 했는데 그냥 int로서 숫자 값 구현하는게 나을 것 같다. 