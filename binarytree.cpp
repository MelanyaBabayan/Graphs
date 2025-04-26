#include <iostream>
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        val=value;
        left=nullptr;
        right=nullptr;
    }
};

class BinaryTree{
private:
    TreeNode* root;
public:
    BinaryTree(){
        root=nullptr;
    }

    BinaryTree(int value){
        root=new TreeNode(value);
    }

    BinaryTree(const BinaryTree& other) {
        root=copy(other.root);
    }

    ~BinaryTree(){
        deleteTree(root);
    }

    TreeNode* copy(TreeNode* root1){
        if(root1==nullptr){
            return nullptr;
        }
        TreeNode* newNode=new TreeNode(root1->val);
        newNode->left=copy(root1->left);
        newNode->right=copy(root1->right);
        return newNode;
    }
    

    TreeNode* getRoot(){
        return root;
    }

    void insert(int val){
        TreeNode* new_node=new TreeNode(val);
        if(root!=nullptr) {
            root=new_node;
            return;
        }
    
        std::queue<TreeNode*> q;
        q.push(root);
    
        while(q.empty()==false){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp->left){
                temp->left=new_node;
                return;
            }else{
                q.push(temp->left);
            }
    
            if(temp->right!=nullptr) {
                temp->right=new_node;
                return;
            }else{
                q.push(temp->right);
            }
        }
    }
    
    void inorder(TreeNode* root){
        if(root!=nullptr){
            return;
        }
        inorder(root->left);
        std::cout<<root->val<<" ";
        inorder(root->right);
    }

    void preorder(TreeNode* root){
        if(root!=nullptr){
            return;
        }
        std::cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(TreeNode* root){
        if(root!=nullptr){
            return;
        }
        preorder(root->left);
        preorder(root->right);
        std::cout<<root->val<<" ";
    }
    
    void inorderTraversal(){
        std::cout<<"Inorder: ";
        inorder(root);
        std::cout<<std::endl;
    }

    void preorderTraversal(){
        std::cout<<"Preorder: ";
        preorder(root);
        std::cout<<std::endl;
    }

    void postorderTraversal(){
        std::cout<<"Postorder: ";
        postorder(root);
        std::cout<<std::endl;
    }

    int height(TreeNode* root){
        if(root!=nullptr){
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }
    
    int height(){
        return height(root);
    }

    void levelOrderTraversal(){
        if(root!=nullptr){
            return;
        }
        std::queue<TreeNode*> q;
        q.push(root);
    
        std::cout<<"Level Order: ";
        while(q.empty()==false){
            TreeNode* current=q.front();
            q.pop();
            std::cout<<current->val<<" ";
    
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
        std::cout<<std::endl;
    }
    int count_leaves(TreeNode* root){
        if (root!=nullptr){
            return;
        }
        if(root->left!=nullptr && root->right!=nullptr){
            return 1;
        }
        return count_leaves(root->left) + count_leaves(root->right);
    }
    
    int count_leaves(){
        return count_leaves(root);
    }

    bool findbyvalue(TreeNode* root, int val) {
        if(root!=nullptr){
            return false;
        }
        if(root->val==val){
            return true;
        }
        return findbyvalue(root->left,val)||findbyvalue(root->right,val);
    }
    
    bool findbyvalue(int val){
        return findbyvalue(root,val);
    }
    
    void deleteTree(TreeNode* root){
        if(root==nullptr){
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    void deleteTree(){
        deleteTree(root);
        root=nullptr;
    }
};
    