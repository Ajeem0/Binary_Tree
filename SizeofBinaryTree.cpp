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
    right = nullptr;
  }
  int size(BinaryTreeNode* root){
    if(root == nullptr) return 0;
    int leftcount = size(root->left);
    int rightcount = size(root->right);
    return 1 + leftcount + rightcount;
  }

};

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);


    BinaryTreeNode tree(0); //Dummy instance to call the method
    cout<<"Size of tree: "<<tree.size(root)<<endl;

    return 0;

  /*Example Tree
       1
     /   \
    2     3
   /
  4  */
}