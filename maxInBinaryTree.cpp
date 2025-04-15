#include<iostream>
#include<climits>
using namespace std;

class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

};

class BinaryTree{
public:
BinaryTreeNode* root;
BinaryTree(){
    root = nullptr;
}
int maxInBinaryTree(BinaryTreeNode* node){
    int max_value = INT_MIN;
    if(node!= nullptr){
        int left_max = maxInBinaryTree(node->left);
        int right_max = maxInBinaryTree(node->right);

        if(left_max>right_max)
            max_value = left_max;
        else
            max_value = right_max;
        
        if(node->data > max_value){
            max_value = node->data;
        }

    }
    return max_value;

}

};

int main(){
    BinaryTree tree;
    
    tree.root = new BinaryTreeNode(10);
    tree.root->left = new BinaryTreeNode(20);
    tree.root->right = new BinaryTreeNode(30);
    tree.root->left->right = new BinaryTreeNode(50);
    tree.root->left->left = new BinaryTreeNode(40);

    cout<<"MAximum Value is : "<<tree.maxInBinaryTree(tree.root) << endl;

    return 0;

}
