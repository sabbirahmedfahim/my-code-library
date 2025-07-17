#include <bits/stdc++.h>
using namespace std;
class Node 
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) 
    {
        this->data = data;
        left = right = nullptr;
    }
};

class BST 
{
public:
    Node* insert(Node* root, int data) 
    {
        if (!root) return new Node(data);

        if (data < root->data) root->left = insert(root->left, data);
        else root->right = insert(root->right, data);

        return root;
    }

    Node* minValueNode(Node* node) 
    {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) return root;

        if (data < root->data) root->left = deleteNode(root->left, data);
        else if (data > root->data) root->right = deleteNode(root->right, data);
        else // data == root->data
        {
            if (root->left == nullptr) // it has either no child, or only a right child.
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) // only a left child
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node has both left and right children (preserve the BST property)
            Node* temp = minValueNode(root->right); // Another valid option is to use the maximum value from the left subtree.
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inOrder(Node* root) 
    {
        if (!root) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    /*
    preOrder(); postOrder(); levelOrder() aka BFS; maxHeight(); countNodes();
    */
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BST tree;
    Node* root = nullptr;

    vector<int> values = {8, 3, 1, 6, 7, 10, 14, 4};
    for (int v : values) root = tree.insert(root, v);

    cout << "Inorder traversal: ";
    tree.inOrder(root);
    cout << "\n";

    root = tree.deleteNode(root, 10);
    cout << "After deleting 10: ";
    tree.inOrder(root);
    cout << "\n";

    return 0;
}