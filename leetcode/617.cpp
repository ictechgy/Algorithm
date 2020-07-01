/**
 * LeetCode 617. Merge Two Binary Trees
 * This answer was made by ajh on July 1st.
 */
#include <stdio.h>

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
TreeNode* merge(TreeNode*, TreeNode*);

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1, t2);
    }
};

TreeNode* merge(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL && t2 == NULL) return NULL;       //base cases
    else if(t1 == NULL) t1 = new TreeNode();
    else if(t2 == NULL) t2 = new TreeNode();
    TreeNode* t = new TreeNode((t1->val) + (t2->val));
    t->left = merge(t1->left, t2->left);
    t->right = merge(t1->right, t2->right);
    return t;
}
//시간 소요가 평균보다 길다. 합치려는 노드 중 한쪽이 없는 경우 해당 노드에 대해 동적할당 해주기 때문인듯(일회성으로만 쓰이는 노드를 계속 생성)


TreeNode* merge(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL && t2 == NULL) return NULL;    
    else if(t1 == NULL) return new TreeNode(t2->val, t2->left, t2->right);
    else if(t2 == NULL) return new TreeNode(t1->val, t1->left, t1->right);
    TreeNode* t = new TreeNode((t1->val) + (t2->val));
    t->left = merge(t1->left, t2->left);
    t->right = merge(t1->right, t2->right);
    return t;
}
//이렇게 하니 더 빨라졌다. 


//새 노드를 만드는게 아니라 아예 t1에 병합시켜보자.
TreeNode* merge(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL && t2 == NULL) return NULL;   
    else if(t1 == NULL) return t2;
    else if(t2 == NULL) return t1;
    t1->val += t2->val;
    t1->left = merge(t1->left, t2->left);
    t1->right = merge(t1->right, t2->right);
    return t1;
}
//가장 빠르게 나왔다. -> 다만 문제에서는 new binary tree로 만들으라고 했으니 정확히는 첫번째 or 두번째 해답이 맞지 않을까. 
//두번째 해답도 명확히는 정답은 아닐 것 같다. 포인터로 단순히 가리키기만 하는 부분이 존재. 
//따라서 가장 정확히 하려면 한쪽이 NULL일 경우 NULL이 아닌 노드부터 자식노드 전부를 복사하여 새로 만들어 가져와 가리키게 해야할 듯.

//다른 방법으로는 Stack을 이용한 방법이 존재한다. 