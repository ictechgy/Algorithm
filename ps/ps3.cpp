#include <iostream>

using namespace std;

int main(void){
    int n, sum = 0;
    cin>>n;
    for(int i = 1; i <= n/2; i++){  //값의 체크는 진약수이니 최대로 해봤자 2로 나눈 값까지만 해도 됨(2로 나누어지든 나누어 지지 않든)
        if(n % i == 0){
            cout<<i<<" + ";
            sum += i;
        }
    }
    cout<<"\b\b= "<<sum<<endl;

    return 0;
}
//뭐랄까 sqrt 쓰고 막 그러고 싶은데.. 흠..


//다른 코드
#include <iostream>

using namespace std;

int main(void){
    int n, i, sum = 1;
    cin>>n;
    cout<<"1";  //1은 모든 수의 약수이다.
    for(i = 2;i < n; i++){
        if(n % i == 0){
            cout<<" + "<<i;
            sum = sum + i;
        }
    }
    cout<<" = "<<sum;

    return 0;
}
