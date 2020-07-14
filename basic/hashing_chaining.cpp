//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#define SIZE 100

//chaining
typedef struct table_node{
    int key;
    struct table_node *next = NULL;
} Node;
//단방향 Linked List로

Node **hash_table = new Node*[SIZE];

int hash_function(int value){
    return value % SIZE;
}

Node* hash_search(int value){
    int hashed = hash_function(value);
    Node *ptr = NULL;
    for(ptr = hash_table[hashed]; ptr != NULL; ptr = ptr->next){
        if(ptr->key == value) break;
    }
    return ptr;
}

Node* hash_insert(int value){
    if(hash_search(value) != NULL) return NULL;
    Node *node = new Node{value};
    int hashed = hash_function(value);
    node->next = hash_table[hashed];
    hash_table[hashed] = node;

    return node;
}

bool hash_delete(int value){
    int hashed = hash_function(value);
    Node *node = hash_table[hashed], *before = NULL;
    while(node != NULL && node->key != value){
        before = node;
        node = node->next;
    }
    if(node == NULL) return false;   //해당 slot-bucket이 아예 처음부터 비어있었거나 찾지 못한경우

    before->next = node->next;

    delete(node);
    return true;
}