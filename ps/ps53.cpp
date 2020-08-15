//STL stack을 쓰지 않고 스택을 직접 구현하는 경우. -> 배열하나와 인덱스 포인터만 이용하여 구현할 수도 있지만..
#include <stdio.h>
#include <memory>
#include <vector>
#include <algorithm>

//아래의 스택 정의나 함수 정의는 별도 헤더에 두고 링크하는게 더 깔끔하긴 함. (함수 선언은 별도 cpp파일에)
#define DEFAULT_SIZE 512
typedef int element;

typedef struct stk{
    element* stack;
    int top;
    int capacity;
} STACK;

bool initialize_stk(STACK *stk){    //구조체 자체의 주소 받기
    if(stk == NULL) return false;
    stk->stack = (element*)malloc(sizeof(element)*DEFAULT_SIZE);
    if(stk->stack == NULL) return false;
    stk->top = 0;
    stk->capacity = DEFAULT_SIZE;
    return true;
}

bool extend_stk(STACK *stk){
    if(stk == NULL || stk->stack == NULL) return false;
    stk->stack = (element*)realloc(stk->stack, (stk->capacity)*2);
    if(stk->stack == NULL) return false;
    stk->capacity *= 2;
    return true;
}

bool push(STACK *stk, element ele){
    if(stk == NULL || stk->stack == NULL) return false;
    if(stk->top == stk->capacity) extend_stk(stk);
    stk->stack[(stk->top)++] = ele;
    return true;
}

element pop(STACK *stk){
    if(stk == NULL || stk->stack == NULL || stk->top == 0) return false;
    return stk->stack[--(stk->top)];
}

bool isEmpty(STACK *stk){
    return stk->top <= 0;
}

int main(void){
    int n, k;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    scanf("%d %d", &n, &k);
    STACK *stk = (STACK*)malloc(sizeof(STACK));
    initialize_stk(stk);
    while(n != 0){
        push(stk, (element)n%k);
        n/=k;
    }
    while(!isEmpty(stk)){
        printf("%c", arr[(int)pop(stk)]);
    }
    printf("\n");

    return 0;
}


//STL stack
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main2(void){
    int n, k;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    scanf("%d %d", &n, &k);
    stack<int> stk;
    while(n != 0){
        stk.push(n%k);
        n/=k;
    }
    while(!stk.empty()){
        printf("%c", arr[stk.top()]);
        stk.pop();
    }
    printf("\n");

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int stack[100], top = -1;

void push(int x){
    stack[++top] = x;
}
int pop(){
    return stack[top--];
}

int main(){
    int n, k;
    //stack<int> s;
    char str[20] = "0123456789ABCDEF";
    scanf("%d %d", &n, &k);
    while(n > 0){
        push(n%k);
        //s.push(n%k);
        n=n/k;
    }
    while(top != -1/* !s.empty() */){
        printf("%c", str[pop()]);
        //printf("%c", str[s.top()]);
        //s.pop();
    }
    return 0;
}