//from (inflearn)영리한 프로그래밍을 위한 알고리즘 강좌 by 권오흠 교수님

//트리를 traverse해보기 - value 값 print
#include <stdio.h>

typedef struct TreeNode{            //클래스로 구현해볼 수도 있다.
    int value = 0;
    struct TreeNode *left = NULL, *right = NULL;
} Node;

void inorder_traverse(Node *root){
    if(root == NULL) return;    //base case
    inorder_traverse(root->left);
    printf("%d ", root->value);
    inorder_traverse(root->right);
}

void preorder_traverse(Node *root){
    if(root == NULL) return;    //base case
    printf("%d ", root->value);
    inorder_traverse(root->left);
    inorder_traverse(root->right);
}

void postorder_traverse(Node *root){
    if(root == NULL) return;    //base case
    inorder_traverse(root->left);
    inorder_traverse(root->right);
    printf("%d ", root->value);
}

#include <queue>
using namespace std;
queue<Node*> que;    //무엇을 큐에 넣을지는.. 조금 다를 수 있을 것 같다. 
void levelorder_traverse(Node *root){
    que.push(root);
    Node *ptr;
    while(!que.empty()){
        ptr = que.front();
        printf("%d ", ptr->value);
        que.pop();
        if(ptr->left != NULL) que.push(ptr->left);
        if(ptr->right != NULL) que.push(ptr->right);
    }
}

int main(void){                 //test
    Node root, child1, child2;
    root.value = 1;
    root.left = &child1;
    root.right = &child2;
    child1.value = 2;
    child2.value = 3;

    inorder_traverse(&root);
    puts("");
    preorder_traverse(&root);
    puts("");
    postorder_traverse(&root);
    puts("");
    levelorder_traverse(&root);

    return 0;
}