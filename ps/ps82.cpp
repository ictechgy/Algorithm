#include <stdio.h>

int num[15], n, r, cnt = 0;

void perm(int);
void swap(int, int);

int main(void){
    int i;
    scanf("%d %d", &n, &r);
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    perm(0);
    printf("%d\n", cnt);

    return 0;
}

void perm(int k){   //k번째 인덱스에 들어갈 대장 선택
    int i;
    if(k == r){     //r명의 대장 선택 완료시 출력
        for(i = 0; i < r; i++){
            printf("%d ", num[i]);
        }
        puts("");
        cnt++;
        return;
    }
    for(i = k; i < n; i++){ //모든 k이상의 원소들이 한번씩 k번째의 대장이 될 수 있도록 한다. 
        swap(k, i);
        perm(k+1);     
        swap(k, i);
    }
}

void swap(int i, int j){
    int k = num[i];
    num[i] = num[j];
    num[j] = k;
}
//하지만 위의 방식으로는 순서가 맞지 않는다..


#include <stdio.h>

int data[15], num[15], n, r, cnt = 0;
bool ck[15];    //값 들어갔는지 여부 체크

void perm(int L){   //num의 L번째 인덱스에 들어갈 값 결정
    int i;
    if(L == r){
        for(i = 0; i < r; i++){
            printf("%d ", num[i]);
        }
        puts("");
        cnt++;
        return;
    }
    for(i = 0; i < n; i++){ //어떤것을 선택하냐 선택하지 않느냐의 가지뻗기가 아니라, n개의 가지 뻗기
        if(ck[i] == false){
            ck[i] = true;
            num[L] = data[i];
            perm(L+1);
            ck[i] = false;
        }
    }
}

int main(void){
    int i;
    scanf("%d %d", &n, &r);
    for(i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }
    perm(0);
    printf("%d\n", cnt);

    return 0;
}

//
#include <stdio.h>
using namespace std;
int n, r, cnt = 0;
int a[20], res[20], ch[20];

int DFS(int L){
    if(L == r){
        for(int j = 0; j < L; j++){
            printf("%d ", res[j]);
        }
        cnt++;
        puts("");
    }else{
        for(int i = 1; i <= n; i++){
            if(ch[i] == 0){
                res[L] = a[i];
                ch[i] = 1;
                DFS(L+1);
                ch[i] = 0;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &r);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    DFS(0);
    printf("%d\n", cnt);
    
    return 0;
}