//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#define element int

typedef struct TreeNode{
    element key = NULL;
    struct TreeNode *left = NULL, *right = NULL;
    struct TreeNode *parent = NULL; //부모에 대한 포인터. 필요에 따라 사용
} Node;

//아래 함수들의 매개변수부분에는 특정 값 element value를 지칭하였지만 Node 그 자체를 받게 만들 수도 있다.(Node*포인터로)
Node* tree_search(Node *node, element value){  //recursive
    if(node == NULL || (node->key) == value) return node;
    return ((node->key) > value)? tree_search(node->left, value) : tree_search(node->right, value);
    //if-else로 처리 할 수도 있음 
}

Node* iterative_tree_search(Node *node, element value){
    while(node != NULL && (node->key) != value){
        node = ((node->key) > value)? node->left : node->right;
    }
    return node;
}

Node* tree_minimum(Node *node){
    while((node->left) != NULL) node = node->left;
    return node;
}

Node* tree_maximum(Node *node){
    while((node->right) != NULL) node = node->right;
    return node;
}

Node* tree_successor(Node *node){   //나보다 큰 수 중 가장 작은 수(다음 크기의 수)  <-> predecessor: 나보다 작은 수 중 가장 큰 수(이전 크기의 수)
    if(node->right != NULL) return tree_minimum(node->right);   //우측 부트리 중 최소 값이 successor
    //우측 부트리가 없는 경우 위쪽으로 올라가야하는데, 이 때 노드별로 부모에 대한 포인터가 있다면 찾기가 훨씬 쉬울 것이다.
    Node *parent = node->parent;
    while(parent != NULL && (parent->right) == node){
        node = parent;
        parent = parent->parent;
    }
    return parent;
}
//만약 부모에 대한 포인터가 없다면? -> 최소한 root노드에 대한 주소는 주어져야 한다. 
Node* tree_successor2(Node *node, Node *root){
    if(node->right != NULL) return tree_minimum(node->right);
    Node *parent = root;
    while(tree_maximum(parent->left) != node) parent = ((parent->key) > (node->key))? parent->left : parent->right;
    return parent;
}   //이런 식으로 하면 될 것 같다.. 

Node* tree_insert(Node* root, element value){
    Node *parent = NULL;
    Node *child = root;
    while(child != NULL){
        parent = child;
        if((child->key) == value) return NULL;  //같은 값이 이미 존재하는 경우 실패.. (또는 이미 존재하는 해당 노드를 반환할수도.)
        else if((child->key) > value) child = child->left;
        else child = child->right;
    }
    Node *node_new = new Node{value, NULL, NULL, parent};   //각각의 값을 별개로 넣을 수도..
    if(parent == NULL) return node_new; //root노드가 된다. 
    if((parent->key) > value) parent->left = node_new;
    else parent->right = node_new;
    return node_new;
}

Node* tree_delete(Node* root, element value){

}