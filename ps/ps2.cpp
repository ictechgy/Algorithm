#include <iostream>
using namespace std;

int main(void){
    int a, b, sum = 0;
    cin>>a>>b;
    for(int i = a; i < b; i++){
        printf("%d + ", i);
        sum+=i;
    }
    sum+=b;
    printf("%d = %d\n", b, sum);

    return 0;
}


//다른 풀이
#include <iostream>
using namespace std;

int main(void){
    int a, b, i, sum = 0;
    cin>>a>>b;
    for(i = a; i < b; i++){
        cout<<i<<" + ";
        sum = sum + i;
    }
    cout<<i<<" = ";     //i를 써도 되고 b를 써도 되고 
    cout<<sum + i ;

    return 0;
}