// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// class BinaryTree {
// public:
//     void preorder(Node* root) {
//         if (root) {
//             cout << root->data << " ";
//             preorder(root->left);
//             preorder(root->right);
//         }
//     }

//     void inorder(Node* root) {
//         if (root) {
//             inorder(root->left);
//             cout << root->data << " ";
//             inorder(root->right);
//         }
//     }

//     void postorder(Node* root) {
//         if (root) {
//             postorder(root->left);
//             postorder(root->right);
//             cout << root->data << " ";
//         }
//     }
// };

// int main() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);

//     BinaryTree tree;
//     cout << "Preorder: ";
//     tree.preorder(root);
//     cout << "\nInorder: ";
//     tree.inorder(root);
//     cout << "\nPostorder: ";
//     tree.postorder(root);
//     return 0;
// }
//ques 2
// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// class BST {
// public:
//     Node* insert(Node* root, int val) {
//         if (!root) return new Node(val);
//         if (val < root->data)
//             root->left = insert(root->left, val);
//         else if (val > root->data)
//             root->right = insert(root->right, val);
//         return root;
//     }

//     Node* searchRecursive(Node* root, int key) {
//         if (!root || root->data == key) return root;
//         if (key < root->data)
//             return searchRecursive(root->left, key);
//         else
//             return searchRecursive(root->right, key);
//     }

//     Node* searchIterative(Node* root, int key) {
//         while (root) {
//             if (key == root->data) return root;
//             root = (key < root->data) ? root->left : root->right;
//         }
//         return nullptr;
//     }

//     Node* findMin(Node* root) {
//         while (root && root->left) root = root->left;
//         return root;
//     }

//     Node* findMax(Node* root) {
//         while (root && root->right) root = root->right;
//         return root;
//     }

//     Node* inorderSuccessor(Node* root, Node* target) {
//         if (target->right) return findMin(target->right);
//         Node* succ = nullptr;
//         while (root) {
//             if (target->data < root->data) {
//                 succ = root;
//                 root = root->left;
//             } else if (target->data > root->data)
//                 root = root->right;
//             else break;
//         }
//         return succ;
//     }

//     Node* inorderPredecessor(Node* root, Node* target) {
//         if (target->left) return findMax(target->left);
//         Node* pred = nullptr;
//         while (root) {
//             if (target->data > root->data) {
//                 pred = root;
//                 root = root->right;
//             } else if (target->data < root->data)
//                 root = root->left;
//             else break;
//         }
//         return pred;
//     }

//     void inorder(Node* root) {
//         if (root) {
//             inorder(root->left);
//             cout << root->data << " ";
//             inorder(root->right);
//         }
//     }
// };

// int main() {
//     BST tree;
//     Node* root = nullptr;
//     root = tree.insert(root, 20);
//     tree.insert(root, 10);
//     tree.insert(root, 30);
//     tree.insert(root, 5);
//     tree.insert(root, 15);
//     tree.insert(root, 25);
//     tree.insert(root, 35);

//     cout << "Inorder traversal: ";
//     tree.inorder(root);
//     cout << "\n";

//     int key = 15;
//     Node* found = tree.searchRecursive(root, key);
//     cout << "Recursive Search for " << key << ": " << (found ? "Found" : "Not Found") << "\n";

//     found = tree.searchIterative(root, key);
//     cout << "Iterative Search for " << key << ": " << (found ? "Found" : "Not Found") << "\n";

//     cout << "Minimum: " << tree.findMin(root)->data << "\n";
//     cout << "Maximum: " << tree.findMax(root)->data << "\n";

//     Node* succ = tree.inorderSuccessor(root, tree.searchIterative(root, 15));
//     cout << "Inorder Successor of 15: " << (succ ? to_string(succ->data) : "None") << "\n";

//     Node* pred = tree.inorderPredecessor(root, tree.searchIterative(root, 15));
//     cout << "Inorder Predecessor of 15: " << (pred ? to_string(pred->data) : "None") << "\n";

//     return 0;
// }
//ques 3
// #include <iostream>
// #include <algorithm>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// class BST {
// public:
//     Node* insert(Node* root, int val) {
//         if (!root) return new Node(val);
//         if (val < root->data)
//             root->left = insert(root->left, val);
//         else if (val > root->data)
//             root->right = insert(root->right, val);
//         return root;
//     }

//     Node* findMin(Node* root) {
//         while (root && root->left) root = root->left;
//         return root;
//     }

//     Node* deleteNode(Node* root, int key) {
//         if (!root) return root;
//         if (key < root->data)
//             root->left = deleteNode(root->left, key);
//         else if (key > root->data)
//             root->right = deleteNode(root->right, key);
//         else {
//             if (!root->left) {
//                 Node* temp = root->right;
//                 delete root;
//                 return temp;
//             } else if (!root->right) {
//                 Node* temp = root->left;
//                 delete root;
//                 return temp;
//             }
//             Node* temp = findMin(root->right);
//             root->data = temp->data;
//             root->right = deleteNode(root->right, temp->data);
//         }
//         return root;
//     }

//     int maxDepth(Node* root) {
//         if (!root) return 0;
//         return 1 + max(maxDepth(root->left), maxDepth(root->right));
//     }

//     int minDepth(Node* root) {
//         if (!root) return 0;
//         if (!root->left && !root->right) return 1;
//         if (!root->left) return 1 + minDepth(root->right);
//         if (!root->right) return 1 + minDepth(root->left);
//         return 1 + min(minDepth(root->left), minDepth(root->right));
//     }

//     void inorder(Node* root) {
//         if (root) {
//             inorder(root->left);
//             cout << root->data << " ";
//             inorder(root->right);
//         }
//     }
// };

// int main() {
//     BST tree;
//     Node* root = nullptr;
//     root = tree.insert(root, 50);
//     tree.insert(root, 30);
//     tree.insert(root, 70);
//     tree.insert(root, 20);
//     tree.insert(root, 40);
//     tree.insert(root, 60);
//     tree.insert(root, 80);

//     cout << "Inorder traversal: ";
//     tree.inorder(root);
//     cout << "\n";

//     root = tree.deleteNode(root, 20);
//     root = tree.deleteNode(root, 30);
//     root = tree.deleteNode(root, 50);

//     cout << "After deletions: ";
//     tree.inorder(root);
//     cout << "\n";

//     cout << "Maximum depth: " << tree.maxDepth(root) << "\n";
//     cout << "Minimum depth: " << tree.minDepth(root) << "\n";

//     return 0;
// }
//ques 4.
#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* newNode(int val) {
        return new Node(val);
    }

    bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
        if (!root) return true;
        if (root->data <= minVal || root->data >= maxVal) return false;
        return isBSTUtil(root->left, minVal, root->data) &&
               isBSTUtil(root->right, root->data, maxVal);
    }

    bool isBST(Node* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    BinaryTree tree;
    Node* root = tree.newNode(10);
    root->left = tree.newNode(5);
    root->right = tree.newNode(15);
    root->left->left = tree.newNode(2);
    root->left->right = tree.newNode(7);

    if (tree.isBST(root))
        cout << "The tree is a BST\n";
    else
        cout << "The tree is not a BST\n";

    return 0;
}
