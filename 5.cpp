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
        int max(int a, int b){
            return((a >= b) ? a : b);
        }

        int height(TreeNode *current){
            if(current == nullptr){
                return(0);
            }

            int l = height(current->left);
            int r = height(current->right);
            return(max(l , r) + 1);
        }

        int diff(TreeNode *current){
            return(height(current->left) - height(current->right));
        
        }

        TreeNode *rr(TreeNode*);
        TreeNode *ll(TreeNode*);
        TreeNode *lr(TreeNode*);
        TreeNode *rl(TreeNode*);
        TreeNode *balance(TreeNode*);
        TreeNode *insert(TreeNode*, TreeNode*);
        void insert();
        void create();
        void disp(TreeNode*, int);

        void inorder(TreeNode *root){
            if(root == nullptr){
                return;
            }

            inorder(root->left);
            cout << "Word: " << root->word << "\nMeaning: " << root->meaning << endl << endl;
            inorder(root->right);
        
        }

        void preorder(TreeNode *root){
            if(root == nullptr){
                return;
            }

            cout << "Word: " << root->word << "\nMeaning: " << root->meaning << endl << endl;
            inorder(root->left);
            inorder(root->right);
        }

        void postorder(TreeNode *root){
            if(root == nullptr){
                return;
            }

            inorder(root->left);
            inorder(root->right);
            cout << "Word: " << root->word << "\nMeaning: " << root->meaning << endl << endl;
        }
};

void Tree::insert(){
    char yn = 'y';
    while(yn == 'y'){
        TreeNode *t = new TreeNode;
        cout << "\nEnter word: ";
        cin >> t->word;
        cout << "Enter meaning: ";
        cin >> t->meaning;

        if(root == nullptr){
            root = t;
        }

        cout << "Enter another word? y/n: ";
        cin >> yn;
    }
}

int main(){
    cout << "Hello World" << endl;

    Tree t;
    cout << "Created Tree" << endl;
    t.insert();

    return(0);
}