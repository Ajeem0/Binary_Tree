#include<iostream>
#include<vector>
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

class Solution {
public:
    BinaryTreeNode* buildBinaryTree(vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty() || preorder.size() != inorder.size()){
            return nullptr;
        }
        return buildBT(preorder,0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    BinaryTreeNode* buildBT(vector<int>& preorder, int preStart, int preEnd,
                            vector<int>& inorder, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;
        int data = preorder[preStart];
        BinaryTreeNode* cur = new BinaryTreeNode(data);
        
        int offset = inStart;
        while(offset <= inEnd && inorder[offset] != data)
            offset++;
        int leftSize = offset - inStart;
        cur->left = buildBT(preorder,preStart + 1, preStart + leftSize, inorder, inStart, offset - 1);
        cur->right = buildBT(preorder, preStart + leftSize + 1 , preEnd, inorder,offset + 1,inEnd);

        return cur;
        }
};

//Print the inorder of the constructed tree
void printInorder(BinaryTreeNode* root){
    if(!root) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}



int main(){
    Solution sol;

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    BinaryTreeNode* root = sol.buildBinaryTree(preorder,inorder);

    cout<< "Inorder Traversal of Constructed Tree: ";
    printInorder(root);  //Should print 9 3 15 20 7
    cout<<endl;

    

    return 0;

}
