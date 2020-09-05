#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    priority_queue<int, vector<int>, greater<int> > min_heap;
    int n;
    while(1){
        scanf("%d", &n);
        if(n == -1) break;
        else if(n == 0){
            if(min_heap.empty()) n = -1;
            else {
                n = min_heap.top();
                min_heap.pop();
            }
            printf("%d\n", n);
        }else min_heap.push(n);
    }

    return 0; 
}

//
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int a;
    priority_queue<int> pQ;
    while(true){
        scanf("%d", &a);
        if(a == -1) break;
        if(a == 0){
            if(pQ.empty()) printf("-1\n");
            else{
                printf("%d\n", -pQ.top());
                pQ.pop();
            }
        }
        else pQ.push(-a);
    }

    return 0;
}