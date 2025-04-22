#include<iostream>
#include<queue>
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

  int minDepth(BinaryTreeNode* root){
    if(root == nullptr)  return 0;

    queue<BinaryTreeNode*> q;
    q.push(root);
    q.push(nullptr);
    int depth = 1;
    
    while(!q.empty()){
        BinaryTreeNode* current = q.front();
        q.pop();
        if(current != nullptr){
            if(current->left == nullptr && current->right == nullptr)
               return depth;
            if(current->left!=nullptr)
              q.push(current->left);
            if(current->right!= nullptr)
              q.push(current->right);
        }else{
          if(!q.empty()){
            depth++;
            q.push(nullptr);
          }
        }
    }
    return depth;
  }
};

int main(){
  BinaryTreeNode* root = new BinaryTreeNode(1);
  root->left = new BinaryTreeNode(2);
  root->right = new BinaryTreeNode(3);
  root->left->left = new BinaryTreeNode(4);
  root->right->right = new BinaryTreeNode(4);
  root->left->left->right = new BinaryTreeNode(4);


  BinaryTreeNode tree(0);
  cout<<"Minimum Depth of the Tree is : "<<tree.minDepth(root)<<endl;

  delete root->left->left;
  delete root->left;
  // delete root->right;
  delete root;

}