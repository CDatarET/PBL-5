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
        Tree(){
            int n;
            cout << "Enter number of nodes: ";
            cin >> n;            
        }
        
        int height(TreeNode*);
        int diff(TreeNode*);
        TreeNode *rr(TreeNode*);
        TreeNode *ll(TreeNode*);
        TreeNode *lr(TreeNode*);
        TreeNode *rl(TreeNode*);
        TreeNode *balance(TreeNode*);
        TreeNode *insert();
        TreeNode *insert(TreeNode*, TreeNode*);
        void create();
        void disp(TreeNode*, int);
        void inorder(TreeNode *root);
        void preorder(TreeNode *root);
        void postorder(TreeNode *root);
};

void Tree::inorder(TreeNode *root){
    if(root == nullptr){
        return;
    }

    inorder(root->left);
    cout << "Word: " << root->word << "\nMeaning: " << root->meaning << endl << endl;
    inorder(root->right);
}

void Tree::preorder(TreeNode *root){
    if(root == nullptr){
        return;
    }

    cout << "Word: " << root->word << "\nMeaning: " << root->meaning << endl << endl;
    inorder(root->left);
    inorder(root->right);
}

void Tree::postorder(TreeNode *root){
    if(root == nullptr){
        return;
    }

    inorder(root->left);
    inorder(root->right);
    cout << "Word: " << root->word << "\nMeaning: " << root->meaning << endl << endl;
}

int main(){
    cout << "Hello World" << endl;

    Tree t;
    cout << "Created Tree" << endl;

    return(0);
}