#include <iostream>
#include <string>

using namespace std;

int main(void){
    string num;
    cin>>num;
    string s_birth = num.substr(0, 2); 
    int birth = stoi(s_birth, NULL);    //두번째 인자는 사이즈

    int hyphen = num.find("-", 0);   //두번째 인자는 검색을 시작할 위치
    string s_sex = num.substr(hyphen+1, 1);
    int sex = stoi(s_sex, NULL);

    switch(sex){    //뒷자리의 첫글자가 1~4 중 어느것인지에 따른 처리
        case 3: 
            birth += 100;
        case 1:
            birth += 1900;
            s_sex = "M";
            break;
        case 4:
            birth += 100;
        case 2:
            birth += 1900;
            s_sex = "W";
            break;
    }
    cout<<2019-birth+1<<" "<<s_sex<<endl;

    return 0;
}

#include <stdio.h>      //scanf, printf가 대용량 처리에는 좋음
using namespace std;

int main(void){
    freopen("input.txt", "rt", stdin); //입력 처리
    char a[20];
    int year, age;
    scanf("%s", &a);    //여기에 왜 &가 붙지..??
    if(a[7] == '1' || a[7] == '2') year = 1900 + ((a[0]-48)*10 + (a[1]-48)); //문자값은 아스키코드로 48부터 시작 ('0')
    else year = 2000 + ((a[0]-48)*10 + (a[1]-48));
    age = 2019 - year + 1;  //한국식 나이
    printf("%d ", age);

    if(a[7] == '1' || a[7] == '3') printf("M\n");
    else printf("W\n");

    return 0;
}