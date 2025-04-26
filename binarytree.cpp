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
    BinaryTree();
    BinaryTree(int );
    BinaryTree(const BinaryTree& );
    ~BinaryTree();
    TreeNode* copy(TreeNode* );
    TreeNode* getRoot();
    void insert(int );
    void inorder(TreeNode* );
    void preorder(TreeNode* );
    void postorder(TreeNode* );
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    int height(TreeNode* );
    int height();
    void levelOrderTraversal();
    int count_leaves(TreeNode* );
    int count_leaves();
    bool findbyvalue(TreeNode* , int );
    bool findbyvalue(int );
    void deleteTree(TreeNode* );
    void deleteTree();
    bool isBalanced(TreeNode* );
    BinaryTree operator+(const BinaryTree& other);
};

BinaryTree::BinaryTree(){
    root=nullptr;
}

BinaryTree::BinaryTree(int value){
    root=new TreeNode(value);
}

BinaryTree::BinaryTree(const BinaryTree& other) {
    root=copy(other.root);
}

BinaryTree::~BinaryTree(){
    deleteTree(root);
}

TreeNode* BinaryTree::copy(TreeNode* root1){
    if(root1==nullptr){
        return nullptr;
    }
    TreeNode* newNode=new TreeNode(root1->val);
    newNode->left=copy(root1->left);
    newNode->right=copy(root1->right);
    return newNode;
}

TreeNode* BinaryTree::getRoot(){
    return root;
}

void BinaryTree::insert(int val){
    TreeNode* new_node=new TreeNode(val);
    if(root==nullptr) {
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

void BinaryTree::inorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    std::cout<<root->val<<" ";
    inorder(root->right);
}

void BinaryTree::preorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    std::cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void BinaryTree::postorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->val<<" ";
}

void BinaryTree::inorderTraversal(){
    std::cout<<"Inorder: ";
    inorder(root);
    std::cout<<std::endl;
}

void BinaryTree::preorderTraversal(){
    std::cout<<"Preorder: ";
    preorder(root);
    std::cout<<std::endl;
}

void BinaryTree::postorderTraversal(){
    std::cout<<"Postorder: ";
    postorder(root);
    std::cout<<std::endl;
}

int BinaryTree::height(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    return 1 + std::max(height(root->left), height(root->right));
}
    
int BinaryTree::height(){
    return height(root);
}


void BinaryTree::levelOrderTraversal(){
    if(root==nullptr){
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

int BinaryTree::count_leaves(TreeNode* root){
    if (root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}

int BinaryTree::count_leaves(){
    return count_leaves(root);
}

bool BinaryTree::findbyvalue(TreeNode* root, int val) {
    if(root==nullptr){
        return false;
    }
    if(root->val==val){
        return true;
    }
    return findbyvalue(root->left,val)||findbyvalue(root->right,val);
}

bool BinaryTree::findbyvalue(int val){
    return findbyvalue(root,val);
}

void BinaryTree::deleteTree(TreeNode* root){
    if(root==nullptr){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void BinaryTree::deleteTree(){
    deleteTree(root);
    root=nullptr;
}

bool BinaryTree::isBalanced(TreeNode* root){
    if(root==nullptr){
        return true;
    }
    int lefth=height(root->left);
    int righth=height(root->right);
    if(std::abs(lefth-righth)<=1&& isBalanced(root->right)&&isBalanced(root->left)){
        return true;
    }
    return false;
} 

BinaryTree BinaryTree::operator+(const BinaryTree& other){
    BinaryTree mergedTree;
    if (root!=nullptr&&other.root!=nullptr) {
        std::queue<TreeNode*> q1, q2;
        q1.push(root);
        q2.push(other.root);

        while(q1.empty()==false&&q2.empty()==false){
            TreeNode* node1=q1.front();
            TreeNode* node2=q2.front();
            q1.pop();
            q2.pop();
            mergedTree.insert(node1->val);
            mergedTree.insert(node2->val);

            if(node1->left!=nullptr){
                q1.push(node1->left);
            }
            if(node1->right!=nullptr){
                q1.push(node1->right);
            }
            if(node2->left!=nullptr){
                q2.push(node2->left);
            }
            if(node2->right!=nullptr){
                q2.push(node2->right);
            }
        }
    }
    return mergedTree;
}