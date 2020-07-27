#include <stdio.h>

//진행순서를 일종의 피라미드로 생각. 각 층의 노드?개수는 1, 2, 3 순서로 증가한다. 
int main(void){
    int n, acc, su, gap;
    scanf("%d", &n);
    acc = 0;    //1, 2, 3씩 더해나가면서 n이 몇번째 피라미드층에 존재하는지 확인
    //즉 acc는 각 피라미드 층에서의 최대값을 나타낼 것이다. 
    su = 0; //더할 수
    while(1){
        ++su;
        acc += su;
        if(n <= acc) break;
    }
    gap = acc - n;  //해당 층과 찾는 값과의 차이값
    //su가 짝수냐 홀수냐에 따라 피라미드에서 왼쪽에서 시작/오른쪽에서 시작이 갈림
    if(su%2 == 0){  //해당 층의 숫자는 오른쪽에서 시작(최대 값은 맨 왼쪽에 존재)
        printf("%d/%d\n", su-gap, gap+1);
    }else{  //왼쪽에서 시작(최대 값은 맨 오른쪽에 존재)
        printf("%d/%d\n", gap+1, su-gap);

    }

    return 0;
}