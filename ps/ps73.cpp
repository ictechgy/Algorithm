#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    priority_queue<int, vector<int>, less<int> > max_heap;
    int n, x;
    while(1){
        scanf("%d", &n);
        if(n == -1) break;
        else if(n == 0){
            if(max_heap.size() == 0) x = -1;
            else {
                x = max_heap.top();
                max_heap.pop();
            }
            printf("%d\n", x);
        }else max_heap.push(n);
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
                printf("%d\n", pQ.top());
                pQ.pop();
            }
        }else pQ.push(a);
    }

    return 0;
}