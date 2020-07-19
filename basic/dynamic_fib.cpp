//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>

//일반적인 방법의 피보나치 수 계산
int fib(int n){
    if(n == 1 || n == 2) return 1;
    else return fib(n-2) + fib(n-1);    //recursive
}   //-> 많은 계산이 중복된다.

//Memoization
int f[210000];   //배열의 크기는 구하고자 하는 수에 따라.. 배열의 각 인덱스 공간 값은 -1로 초기화
int fib(int n){
    if(n == 1 || n == 2) return 1;
    else if(f[n] > -1) return f[n]; //값이 구해진 부분은 -1이 아니므로 값 계산 필요없이 바로 return 
    else{
        f[n] = fib(n-2) + fib(n-1); //중간 계산 결과를 caching
        return f[n];
    }
}

//Bottom up, dynamic programming
int fib(int n){
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i++)
        f[n] = f[n-1] + f[n-2];
    return f[n];
}
//순환식의 f(n) = f(n-2) + f(n-1) 에서 우변이 이미 계산되어있는 방식