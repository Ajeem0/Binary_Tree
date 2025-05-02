#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

class solution{
public:
    vector<vector<int>> zigzaglevelOrder(BinaryTreeNode* root){
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<BinaryTreeNode*> q;
        q.push(root);
        q.push(nullptr);  //level delimiter
        bool leftToRight = true;
        vector<int> curr;

        while (!q.empty()) {
            BinaryTreeNode* tmp = q.front();
            q.pop();

            if(tmp != nullptr) {
                curr.push_back(tmp->data);
                if(tmp->left != nullptr)
                    q.push(tmp->left);
                if(tmp->right != nullptr)
                    q.push(tmp->right);
            } else{
                if(leftToRight) {
                    res.push_back(curr);
                } else {
                    reverse(curr.begin(), curr.end());
                    res.push_back(curr);
                }
                curr.clear();

                if(!q.empty()) {
                    q.push(nullptr);
                    leftToRight = !leftToRight;
                }
            }
        }
        return res;
    }
};

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right = new BinaryTreeNode(3);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(7);

    //Hence Tree is
    //        1
    //       / \ 
    //      2   3
    //     / \ / \ 
    //    4  5 6  7
    // And Zig zag traversal is: 1 \n 3 2 \n 4 5 6 7 
    

    solution sol;
    vector<vector<int>> result = sol.zigzaglevelOrder(root);

    for( const auto& level : result){
        for(int val : level){
            cout<<val<<" ";
        }
        cout<< endl;
    }
    return 0;
}