#include<iostream>
using namespace std;

class BinaryTreeNode{
public:
 int data;
 BinaryTreeNode* left;
 BinaryTreeNode* right;

 BinaryTreeNode(int val){
    data = val;
    left = nullptr;
    right= nullptr;
 }
 int maxDepthRecursive(BinaryTreeNode* root){
    if(root == nullptr)
        return 0;
    int leftdepth = maxDepthRecursive(root->left);
    int rightdepth = maxDepthRecursive(root->right);

    return (leftdepth > rightdepth) ? leftdepth + 1: rightdepth + 1;
 }
};

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);   
    root->right = new BinaryTreeNode(3);   
    root->left->left = new BinaryTreeNode(4);   
    root->left->right = new BinaryTreeNode(5);   

    BinaryTreeNode* tree;
    cout<<"Height of the Binary tree is : "<<tree->maxDepthRecursive(root)<<endl;
    return 0;

    /*Example Tree
       1
     /   \
    2     3
   / \
  4   5 */
}

//Similar to the Size of the binary tree But Difference is here we check which left or right is high
// and there we add both of the left count and right count because of the size