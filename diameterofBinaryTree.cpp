#include<iostream>
#include<algorithm>
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

class BinaryTree
{
private:
    int diameterValue = 0;
public:
    // Approach 1: Efficient method with class variable
    int diameterOfTree(BinaryTreeNode* root){
        calculateDiameter(root);
        return diameterValue;
    }
    int calculateDiameter(BinaryTreeNode* root){
        if(root == nullptr)
            return 0;
        int left = calculateDiameter(root->left);
        int right = calculateDiameter(root->right);

        diameterValue = max(diameterValue, left + right);
        return max(left, right) + 1;
    }

    //Approach 2: Alternative method without using class/global variable
    int diameter(BinaryTreeNode* root){
        if(root == nullptr)
            return 0;
        

        //Diameter passing through root
        int len1 = height(root->left) + height(root->right);

        //Diameter not passing through root
        int len2 = max(diameter(root->left),diameter(root->right));

        return max(len1, len2);
    }
    
    int height(BinaryTreeNode* root){
        if(root == nullptr)
            return 0;
        
        int leftDepth = height(root->left);
        int rightDepth = height(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};


int main(){
    BinaryTree tree;
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(6);

    //Approach 1
    int dia1 = tree.diameterOfTree(root);
    cout<< "Diameter (Approach 1): "<<dia1 << endl;

    //Approach 2
    int dia2 = tree.diameter(root);
    cout<< "Diameter (Approach 2): "<<dia2<<endl;

    return 0;
}

//output is: 
// Diameter (Approach 1): 4
// Diameter (Approach 2): 4


