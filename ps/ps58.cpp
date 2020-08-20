#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef int element;
typedef struct treeNode{
    element value;
    struct treeNode *left = NULL, *right = NULL;
    treeNode(element v){
        value = v;
    }
} Node;

void preorder(Node*);
void inorder(Node*);
void postorder(Node*);

int main(void){
    Node n1 = {1}, n2 = {2}, n3 = {3}, n4 = {4}, n5 = {5}, n6 = {6}, n7 = {7};
    Node *root = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    
    preorder(root);
    puts("");
    inorder(root);
    puts("");
    postorder(root);

    return 0;
}

void preorder(Node* node){
    if(node == NULL) return;
    printf("%d ", node->value);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node){
    if(node == NULL) return;
    inorder(node->left);
    printf("%d ", node->value);
    inorder(node->right);
}

void postorder(Node* node){
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->value);
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 8
int tree[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7};

void preorder(int i){
    if(i >= SIZE) return;
    printf("%d ", tree[i]);
    preorder(i*2);
    preorder(i*2+1);
}

void inorder(int i){
    if(i >= SIZE) return;
    inorder(i*2);
    printf("%d ", tree[i]);
    inorder(i*2+1);
}

void postorder(int i){
    if(i >= SIZE) return;
    postorder(i*2);
    postorder(i*2+1);
    printf("%d ", tree[i]);
}

int main(void){
    preorder(1);
    puts("");
    inorder(1);
    puts("");
    postorder(1);

    return 0;
}

//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void D(int v){
    if(v > 7) return;
    else{
        //printf("%d ", v);
        D(v*2);
        //printf("%d ", v);
        D(v*2+1);
        //printf("%d ", v);
    }
}

int main(){
    D(1);
    return 0;
}