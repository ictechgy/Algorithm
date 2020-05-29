// 1 ~ 10000까지의 셀프넘버를 구해라
// 33 -> 33 + 3 + 3 = 39 이런걸 지속하는 수열이 있다. 이 때 이전 수가 존재하지 않는 수(생성자가 없는 수)를 나타내라. 

#include <stdio.h>

int d(int num){     //다음 수를 생성하는 함수
    int next = num;
    while(num){
        next += num % 10;
        num /= 10;
    }
    return next;
}

int main(void){
    //가장 큰 수는 9999로 만들어지는 10035일 것이다. 따라서 배열은 0 ~ 10035가 들어갈 수 있도록 10036개의 공간을 만들어주었다.
    int arr[10036] = {0}; //모든 공간을 0으로 세팅하고 생성자에 의해 생성 가능한 다음 수의 경우 1의 값으로 대체
    for(int i = 1; i<=10000; i++){  //반복문의 반복은 10000까지만... (사실 만까지 할 필요는 없을 것 같음)
        arr[d(i)] = 1;
    }
    for(int i = 1;  i<= 10000; i++){
        if(!arr[i]) printf("%d\n", i);
    }
    return 0;
}