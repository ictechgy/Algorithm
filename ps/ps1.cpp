//3<=M<N<=1000

//내 풀이
#include <iostream>

using namespace std;

int main(void){
    int n, m;
    cin>>n;     //수의 제한 값
    cin>>m;    
    int quo = n/m;  //몫
    int sum = 0;
    for(int i = 1; i <= quo; i++){
        sum += m*i;
    }
    cout<<sum<<endl;

    return 0;
}

//다른 풀이
#include <iostream>
using namespace std;
int main(){
    int n, m, i, sum = 0;
    cin>>n>>m;
    for(i = 1; i <= n; i++){
        if(i % m == 0){
            sum = sum + i;
        }
    }
    cout<<sum;
    return 0;
}