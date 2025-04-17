#include <iostream>
#include <queue>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    // constructor
    BinaryTreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

BinaryTreeNode *insertInBinaryTreeLevelOrder(BinaryTreeNode *root, int data)
{
    if (root == nullptr)
        return new BinaryTreeNode(data); // create a new node and return it
    queue<BinaryTreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode *temp = q.front();
        q.pop();

        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = new BinaryTreeNode(data);
            return root;
        }
        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = new BinaryTreeNode(data);
            return root;
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode *root = new BinaryTreeNode(10);
    insertInBinaryTreeLevelOrder(root, 20);// it is stored in the left of the root because in that function first we check the left child
    insertInBinaryTreeLevelOrder(root, 30);// it is stored in the right of the root

    cout << "root : " << root->data << endl;
    cout << "left child : " << root->left->data << endl;
    cout << "rightr child : " << root->right->data << endl;

    return 0;
}