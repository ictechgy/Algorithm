//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

#include <stdio.h>
#define element int

enum { BLACK, RED };    //color값이 0이면 black, 1이면 red로 판단하자

typedef struct tree_node{
    element key = NULL;
    struct tree_node *parent = NULL, *left = NULL, *right = NULL;   
    int color = RED;        //기본 값 RED
} Node;
//혹은 어떤 NIL노드를 직접적으로 만들어야 할까? 만약에 어떤 편이성을 위해서 만들어야만 한다면 color만 BLACK으로 만들어두면 되려나.. 
//scope는 전역으로? 

//기본적으로 가장 필요한 연산인 rotate
Node* left_rotate(Node *root, Node *x){     //x가 부모노드이고 y가 그 오른쪽 자식일 때 이를 시계반대방향으로 rotate
    if(x->right == NULL) return NULL;   //오른쪽 자식이 없다면 바로 종료

    Node *y = x->right; //x의 오른쪽 자식에 대한 포인터 생성
    x->right = y->left;     //x의 오른쪽 자식을 y의 왼쪽자식으로 변경
    y->left->parent = x;    
    y->parent = x->parent;
    
    if(x->parent == NULL) root = y;
    else if(x->parent->left == x) x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    x->parent = y;

    return root;
}

Node* right_rotate(Node *root, Node *x){    //x가 부모노드, y가 그 왼쪽 자식
    if(x->left == NULL) return NULL;

    Node *y = x->left;
    x->left = y->right;
    y->right->parent = x;
    y->parent = x->parent;

    if(x->parent == NULL) root = y;
    else if(x->parent->left = x) x->parent->left = y;
    else x->parent->right = y;

    y->right = x;
    x->parent = y;

    return root;
}

void rb_insert_fixup(Node *root, Node *node){   //Insert된 노드에 의해 위배된 규칙을 맞추기 - rb_insert() 내부에서 호출
    //node는 insert된 노드를 가리킴. color는 RED
    Node *y = NULL;
    while(node->parent != NULL && node->parent->color == RED){
        if(node->parent->parent->left == node->parent){ //case 1, 2, 3인 경우
            y = node->parent->parent->right;
            if(y != NULL && y->color == RED){   //case 1 - parent의 sibling이 RED인 경우
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }else{ //case 2 or 3 - parent의 sibling(y)이 NULL이거나 BLACK인 경우
                if(node->parent->right = node){     //case 2라면 case 3으로 
                    node = node->parent;
                    left_rotate(root, node);
                }
                //case 3
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(root, node->parent->parent);
            }
        }else{  //case 4, 5, 6인 경우 - node->parent->parent->right == node->parent;
            y = node->parent->parent->left; //parent의 sibling
            if(y != NULL && y->color == RED){   //case 4 - parent의 sibling이 RED인 경우
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }else{  //case 5 or 6 - parent의 sibling(y)이 NULL이거나 BLACK인 경우
                if(node->parent->left = node){
                    node = node->parent;
                    right_rotate(root, node);
                }
                //case 6
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(root, node->parent->parent);
            }
        }
    }
    //case 1 or 4가 root까지 올라갔을 수 있으므로..
    root->color = BLACK;
}

Node* rb_insert(Node *root, Node *node){
    Node *y = NULL;     //insert할 위치를 찾기 위한 하나 이전의 위치를 가리키는 포인터
    Node *x = root;
    
    while(x != NULL){   //트리에서 node->key값과 동일 값은 존재하지 않는다고 가정
        y = x;
        x = (x->key > node->key)? x->left : x->right;
    }

    node->parent = y;
    if(y == NULL) root = node;
    else if(y->key > node->key) y->left = node;
    else y->right = node;

    node->left = NULL;
    node->right = NULL;
    node->color = RED;  //새로운 노드의 색은 RED로 설정
    
    rb_insert_fixup(root, node);
    return root;
}