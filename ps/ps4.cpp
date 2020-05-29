#include <iostream>

using namespace std;

int main(void){
    int n, min, max, buffer;
    cin>>n;
    cin>>buffer;
    min = max = buffer; //min과 max는 첫번째 값으로 초기화
    for(int i = 2; i <= n; i++){
        cin>>buffer;
        if(buffer > max){
            max = buffer;
        }else if(min > buffer){
            min = buffer;
        }
    }
    cout<<max-min<<endl;

    return 0;
}

//다른 풀이
#include <iostream>

using namespace std;

int main(void){
    int n, i, a, max = -2147000000, min = 2147000000;   //max값은 일단 INT값의 최소값쪽에, min값은 INT값의 최대값쪽으로
    cin>>n;
    for(i = 1; i <= n; i++){
        cin>>a;                 //첫 번째 a값은 max와 min 모두에 들어간다. 
        if(a>max) max = a;
        if(a<min) min = a;
    }
    cout<<max-min;

    return 0;
}

//별도의 파일을 읽어서
#include <iostream>

using namespace std;

int main(void){
    freopen("input.txt", "rt", stdin);      //stdin으로 파일을 설정하여 cin에 파일 내용이 들어온다.
    int n, i, a, max = -2147000000, min = 2147000000;   
    cin>>n;
    for(i = 1; i <= n; i++){
        cin>>a;                
        if(a>max) max = a;
        if(a<min) min = a;
    }
    cout<<max-min;

    return 0; 
}