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
    if(n < 10) return n;    //한자리 수인 경우에는 굳이 처리할 필요가 없다.
    int len = 1, tmp = n;
    while(tmp >= 10){
        tmp /= 10;
        len *= 10;
    }   //이 과정을 거치면 tmp는 n의 맨 앞자리 숫자가 되고 len은 n과 동일한 자릿수의 10의 승 수가 된다.
    return (n - (tmp * len))*10 + tmp;
}

int right(int n){
    if(n < 10) return n;
    int back = n % 10;  //1의 자리 수
    int len = 1, tmp = n;
    while(tmp >= 10){
        tmp /= 10;
        len *= 10;
    }
    n /= 10;
    return n + (back*len);
}

struct Register{
    int num;
    string command;
    Register(int n, /*const string &s*/ string s){
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
            //Register &node = q.front();
            Register node = q.front();
            q.pop();
            int n = node.num;
            //string &s = node.command;
            string s = node.command;

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