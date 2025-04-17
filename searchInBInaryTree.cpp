#include<iostream>
using namespace std;
//Create A class for creating binary tree node
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

static bool findInBT(BinaryTreeNode* root,int data){
    if(root == nullptr)
       return false;
    if(root->data == data)
        return true;
    return findInBT(root->left,data) || findInBT(root->right,data);//Here we traverse the Binary tree
    
}

};

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(6);
    root->left->right = new BinaryTreeNode(4);
    root->left->left = new BinaryTreeNode(8);
    
    int key = 8;
    if(BinaryTreeNode::findInBT(root,key))
        cout<<key<<" Find in Binary Tree";
    else
        cout<<key<<" is Not found";

    return 0;
}
