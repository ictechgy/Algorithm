#include <iostream>
#include <math.h>
using namespace std;
int main(void){
    char a;
    string number = "";
    while(true){
        scanf("%c", &a);
        if(a == '\n' || a == '\0') break;   //파일인 경우 EOF(-1) 처리
        if(a<='9') number.push_back(a); //읽은 문자가 숫자라면 number에 추가
    }
    int num = stoi(number, NULL);
    printf("%d\n", num);
    
    int cnt = 0;        //약수의 개수
    for(int i = 1; i <= sqrt(num); i++){    //약수의 검색은 제곱근까지만 하면 됨 
        if(num % i == 0) cnt++;
    }
    cnt *= 2;   //2를 곱해주면 약수의 개수가 된다. 
    if(sqrt(num) == floor(sqrt(num))) cnt -= 1; //25나 100과 같이 약수가 홀수개인 수들에 대한 처리(제곱근이 약수인 경우)
    printf("%d\n", cnt);

    return 0;
}

//다른 풀이
#include <stdio.h>
using namespace std;
int main(void){
    freopen("input.txt", "rt", stdin);
    char a[100];
    int res = 0, cnt = 0, i;
    scanf("%s", &a);
    for(i = 0; a[i]!='\0'; i++){
        if(a[i]>=48 && a[i] <= 57){
            res = res * 10 + (a[i] - 48);
        }
    }
    printf("%d\n", res);
    for(i = 1; i <= res; i++){
        if(res % i == 0){
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}