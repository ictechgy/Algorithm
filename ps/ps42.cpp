#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>&, int, int);
void heapsort(vector<int>&);
int* binarysearch(vector<int>&, int);

int main(void){
    int n, m, i, *ptr;
    scanf("%d %d", &n, &m);
    vector<int> arr(n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    //이번에는 heap sort를 해보자. max-heap 사용
    heapsort(arr);
    ptr = binarysearch(arr, m); //arr배열에서 m값이 어느 위치에 있는지 그 주소를 반환
    if(ptr == NULL) printf("Not Found\n");
    else printf("%ld\n", ptr-&arr[0]+1); //몇번째인지를 나타내야 하므로 +1

    return 0;
}

//arr의 index는 0부터 시작한다고 볼 것이다.
void heapify(vector<int>& arr, int p, int end){  //p는 포인팅역할, end는 heapify할 끝 인덱스를 가리킴(범위의 끝)
    int tmp;
    int nxt; //next

    //iterative -> recursive 구현 가능
    while(p*2+1 <= end){ //(최소) 좌측 자식이 존재한다면 반복

        if(p*2+2 <= end){ //우측자식도 존재 한다면
            nxt = p*2 + ((arr[p*2+1] > arr[p*2+2])? 1 : 2);   //둘중에 큰 자식 선택
        }else{  //왼쪽자식만 존재하는 경우
            nxt = p*2+1;        //왼쪽 자식을 선택
        }

        if(arr[p] < arr[nxt]){      //해당 자식이 부모보다 더 큰 경우 exchange
            tmp = arr[p];
            arr[p] = arr[nxt];
            arr[nxt] = tmp;
            p = nxt;    //해당 자식의 위치로 부모가 이동했음
        }else break;    //내려가지 않아도 되는 경우 ->  해당 노드 값 이동 끝. 
    }
}

void heapsort(vector<int>& arr){
    int i, tmp;
    int last_index = arr.size()-1;
    for(i = (last_index-1)/2; i >= 0; i--) heapify(arr, i, last_index); //max-heapify
    for(i = last_index; i >= 1; i--){ //i는 끝 인덱스 가리킴
        tmp = arr[i];
        arr[i] = arr[0];    //max값을 뒤로 이동
        arr[0] = tmp;
        heapify(arr, 0, i-1);
    }
}

int* binarysearch(vector<int>& arr, int val){
    int pl = 0, pr = arr.size()-1, pc;
    while(pl<=pr){
        pc = (pl + pr) / 2;
        if(arr[pc] == val) return &arr[pc]; //pc를 반환하면 인덱스 값을 반환하는 것임
        else if(val < arr[pc]) pr = pc-1;
        else pl = pc+1;
    }
    return NULL;    //찾지 못한경우 NULL 반환   -> pc라는 인덱스를 반환하는 형식인 경우 여기서 -1 반환해주면 됨
}

void __heapify(vector<int>& arr, int i){   //heapify의 recursive 구현 -> index는 0부터 시작한다고 생각
    //arr에서 i가 가리키는 부분의 값을 아래로 내려보내줘야 한다.
    //이 말은 곧 i를 루트로 하는 완전이진트리에서 i의 왼쪽자식과 오른쪽자식은 이미 heap이 되어있는 상태임을 가정하는 것
    //위의 heapify()함수도 동일한 가정을 기반으로 한다. 

    if(i*2+1 >= arr.size()) return; //base-case

    int nxt, tmp;
    if(i*2+2 < arr.size()) nxt = i*2 + ((arr[i*2+1] > arr[i*2+2])? 1 : 2);
    else nxt = i*2+1;

    if(arr[i] < arr[nxt]){  //자식 중 더 큰놈이 부모보다 크면
        tmp = arr[i];
        arr[i] = arr[nxt];
        arr[nxt] = tmp;
        __heapify(arr, nxt);
    }

}
//heapify()나 __heapify()에서 접근 범위를 지정해야 한다면 그 범위를 전역변수로 선언해두는 것도 나쁘지 않을 듯
//heap sort를 하기 위한 배열은 1부터 시작하도록 만들어도 괜찮다. 

//
#include <stdio.h>
#include <vector>
#include <algorithm>
int main(){
    int n, i, key, lt = 0, rt, mid;
    scanf("%d %d", &n, &key);
    vector<int> a(n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    /*
    int tmp;
    vector<int> a;
    for(i = 0; i < n; i++){
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    */
    
    printf("%d\n", *a.begin());
    printf("%d\n", *(a.end()-1));
    
    sort(a.begin(), a.end());

    rt = n-1;
    while(lt<=rt){
        mid = (lt + rt) / 2;
        if(a[mid] == key){
            printf("%d\n", key+1);
            return 0;
        }else if(a[mid] > key) rt = mid - 1;
        else lt = mid + 1;
    }
    

    return 0;
}