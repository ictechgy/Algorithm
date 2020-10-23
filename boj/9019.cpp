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
    Register(int n, const string &s){
        num = n;
        command = s;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> A >> B;
        queue<Register> q;
        q.push(Register(A, ""));
        while(!q.empty()){
            Register &node = q.front();
            q.pop();
            int n = node.num;
            string &s = node.command;

            int after;
            after = multiply(n);
            if(after == B) cout << s + "D" << "\n"; break;
            q.push(Register(after, s + "D"));

            after = subtract(n);
            if(after == B) cout << s + "S" << "\n"; break;
            q.push(Register(after, s + "S"));

            after = left(n);
            if(after == B) cout << s + "L" << "\n"; break;
            q.push(Register(after, s + "L"));

            after = right(n);
            if(after == B) cout << s + "R" << "\n"; break;
            q.push(Register(after, s + "R"));
        }
    }

    return 0;
}