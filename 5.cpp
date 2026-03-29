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

        TreeNode *rr(TreeNode *current){
            TreeNode* t = current->right;
    	    current->right = t->left;
    	    t->left = current;
    	    return(t);
        }

        TreeNode *ll(TreeNode *current){
            TreeNode* t = current->left;
    	    current->left = t->right;
    	    t->right = current;
    	    return(t);
        }

        TreeNode *lr(TreeNode *current){
            TreeNode *t = current->left;
            current->left = rr(t);
            return(ll(current));
        }

        TreeNode *rl(TreeNode *current){
            TreeNode *t = current->right;
            current->right = ll(t);
            return(rr(current));
        }

        TreeNode *balance(TreeNode *current){
            int bal = diff(current);
            if(bal > 1){
                if (diff(current->left) > 0){
                    current = ll(current);
                }
                else{
                    current = lr(current);
                }
            }
            else if(bal < -1){
                if(diff(current->right) > 0){
                    current = rl(current);
                }
                else{
                    current = rr(current);
                }
            }
            return(current);
        }

        TreeNode* insert(TreeNode *r, TreeNode *t){
            if(r == nullptr){
                return(t);
            }

            if(t->word < r->word){
                r->left = insert(r->left, t);
                r = balance(r);
            }
            else{
                r->right = insert(r->right, t);
                r = balance(r);
            }

            return(r);
        }

        void insert(){
            char yn = 'y';
            while(yn == 'y'){
                TreeNode *t = new TreeNode;
                cout << "\nEnter word: ";
                cin >> t->word;
                cout << "Enter meaning: ";
                cin >> t->meaning;
                root = insert(root, t);

                cout << "Enter another word? y/n: ";
                cin >> yn;
            }
        }

        void inorder(TreeNode *current){
            if(current == nullptr){
                return;
            }

            inorder(current->left);
            cout << "Word: " << current->word << "\nMeaning: " << current->meaning << endl << endl;
            inorder(current->right);
        
        }

        void disp(){
            inorder(root);
        }
};

int main(){
    cout << "Hello World" << endl;

    Tree t;
    t.insert();
    t.disp();

    return(0);
}