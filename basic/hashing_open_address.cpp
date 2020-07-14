//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

//open address, linear probing
#include <stdio.h>
#define SIZE 100

typedef struct table_node {
    int value = -1;
} SLOT;

//슬롯배열이 직접적으로 값을 지니고 있도록 해보자. 값이 없다면 해당 공간의 value는 -1
//특정 슬롯의 값이 삭제되었는지를 다르게 나타내려면 구조체 내에 다른 변수가 추가적으로 필요할 것.. DELETED 여부 판별 변수(bool형) 등
SLOT hash_table[SIZE];

int hash_function(int value){
    return value % SIZE;
}

int hash_insert(int value){       //동일한 입력은 없다고 가정 
    int hashed = hash_function(value);
    int idx = -1;    //값이 들어간 공간의 인덱스를 반환할 것
    for(idx = hashed; idx < (hashed + SIZE); idx++){
        if(hash_table[idx%SIZE].value == -1){
            hash_table[idx%SIZE].value = value;
            break;
        }
    }
    if(idx != -1) idx %= SIZE;
    return idx; //-1인 경우 값을 삽입하지 못했다는 것이며 이는 Overflow 의미
}

int hash_search(int value){
    int hashed = hash_function(value);
    int idx = -1;
    for(idx = hashed; idx < (hashed + SIZE); idx++){
        if(hash_table[idx%SIZE].value == -1) break; //중간에 비어있는 공간 만나면 종료
        else if(hash_table[idx%SIZE].value == value) break;
    }
    if(idx != -1) idx%=SIZE;
    return idx;
}

void hash_delete(int value){    //값을 삭제하는데, 해당 슬롯 이후 값중 가져올만한 값을 가져와서 채우기
    int idx = hash_search(value);
    if(idx == -1) return;   //해당 값 없는 경우 종료

    //값을 삭제할 때 뒤의 배열 값들을 하나씩 당기는 대신에 특정 해시값 클러스터 중 가장 뒤의 값을 가져와 채우는 방식으로..
    //이를 반복시켜보자.. 
    hash_table[idx].value = -1; //일단 해당 값 삭제

    if(hash_table[(idx+1)%SIZE].value == -1) return;    //삭제된 값이 클러스터의 끝이었다면 바로 종료
    
    for(int i = (idx+1)%SIZE; i != idx; i++){   //다음 인덱스부분부터 한바퀴 돌때까지 일단 반복
        if(i > SIZE) i%=SIZE;
        if(hash_table[i].value == -1);  break;  //바로 -1을 만났을 때와 나중에 -1을 만났을 때를 다르게 처리해야 한다. - 바로 만난 경우에 위에서 처리

        //현재 공간의 해시값과 다음 공간의 해시값을 비교하여 다음 공간의 해시값이 커지는 경우 현재 공간의 값을 삭제된 공간으로 옮겨넣는다.
        //현재 공간이 삭제된 것으로 보고 다시 보정과정을 시작한다.  -> 이렇게 판단하는게 과연 괜찮을까..? 해시값의 저장이 22244422 이런식으로 충돌난 경우라면?
        //value가 -1인 공간을 만나거나, 한바퀴를 돌았거나, 해시값과 인덱스 값이 동일한(충돌이 발생되지 않은 슬롯) 공간을 만나는 경우 종료?
        //또 고려해야 하는 부분이 있을까..?  
        //음.. 
    }
    /*
    int i = idx;
    while(1){
        i++;
        if(i > SIZE) i %= SIZE;
        if(i == idx) break;     //한바퀴 돈 경우 종료
        if(hash_table[i].value == -1) break;
        next = hash_function(hash_table[i].value);
        if(i == hashed) break;
        if(next > hashed){
            hash_table[idx].value = hash_table[i-1].value;
            hash_table[i-1].value = -1;

        }
    }
    */
}

/*
크기관계가 필요할 때는 트리형태의 자료구조를 - ordered_set, ordered_map / TreeSet, TreeMap
크기관계가 불필요할 때는 해시테이블 형태의 자료구조를 - unordered_set, unordered_map / HashSet, HashMap
*/