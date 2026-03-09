#include <iostream>
using namespace std;

class TreeNode{
    string word;
    string meaning;
    TreeNode *left;
    TreeNode *right;
    friend class Tree;
};

class Tree{
    TreeNode *root = nullptr;
    public:
        int height(TreeNode*);
        int diff(TreeNode*);
        TreeNode *rr(TreeNode*);
        TreeNode *ll(TreeNode*);
        TreeNode *lr(TreeNode*);
        TreeNode *rl(TreeNode*);
        TreeNode *balance(TreeNode*);
        TreeNode *insert();
        TreeNode *insert(TreeNode*, TreeNode*);
        void disp(TreeNode*, int);
        void inorder(TreeNode *root);
        void preorder(TreeNode *root);
        void postorder(TreeNode *root);

};

int main(){
    cout << "Hello World" << endl;

    Tree t;
    cout << "Created Tree" << endl;

    return(0);
}