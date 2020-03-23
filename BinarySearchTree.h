#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include <cstdio>

using namespace std;

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        Node* left;
        Node* right;
        Node* parent;
        T value;
        Node(T value){
            this->value = value;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
    };
    Node* root;
    void freeTreeMemory(Node* root) {
        if(root == nullptr) return;
        freeTreeMemory(root->left);
        freeTreeMemory(root->right);
        delete root;
    }
    void addItem(Node* root, Node* parent, Node* newNode, bool left) {
        if(root == nullptr) {
            newNode->parent = parent;
            root = newNode;
            if(left)
                parent->left = root;
            else
                parent->right = root;
        } else if(newNode->value < root->value) {
            addItem(root->left, root, newNode, true);
        } else {
            addItem(root->right, root, newNode, false);
        }
    }
    bool printLevel(Node* root, int level, bool forwards = true){
        if(root == nullptr) return false;
        if(level == 1){
            cout << root->value << " ";
            return true;
        }
        bool left, right;
        if(forwards) {
            left = printLevel(root->left, level - 1, forwards);
            right = printLevel(root->right, level - 1, forwards);
        } else {
            right = printLevel(root->right, level - 1, forwards);
            left = printLevel(root->left, level - 1, forwards);
        }
        return left || right;
    }
    Node* inOrderSuccessor(Node* node) {
        if(node->right != nullptr) {
            Node* current = node->right;
            while(current->left != nullptr){
                current = current->left;
            }
            return current;
        }
          Node* parent = node->parent;
          while(parent != nullptr && node == parent->right)
          {
             node = parent;
             parent = parent->parent;
          }
          return parent;
    }
    void deleteNode(Node* node){
        if(node->left == nullptr && node->right == nullptr){
            if(node->parent == nullptr){
                root = nullptr;
            }else if(node->parent->left->value == node->value){
                node->parent->left = nullptr;
            }else {
                node->parent->right = nullptr;
            }
            delete node;
        } else if(node->left == nullptr){
            if(node->parent == nullptr){
                root = node->right;
            } else if(node->parent->left->value == node->value){
                node->parent->left = node->right;
            }else {
                node->parent->right = node->right;
            }
            node->right->parent = node->parent;
            delete node;
        } else if(node->right == nullptr) {
            if(node->parent == nullptr){
                root = node->left;
            } else if(node->parent->left->value == node->value){
                node->parent->left = node->left;
            }else {
                node->parent->right = node->left;
            }
            node->left->parent = node->parent;
            delete node;
        } else {
            Node* ios = inOrderSuccessor(node);
            node->value = ios->value;
            deleteNode(ios);
        }
    }
    void sideView(Node* root, int level, int* maxLevel, bool left) {
        if (root == nullptr) return;
        if (*maxLevel < level)
        {
            cout << root->value << " ";
            *maxLevel = level;
        }
        if(left) {
            sideView(root->left, level + 1, maxLevel, left);
            sideView(root->right, level + 1, maxLevel, left);
        } else {
            sideView(root->right, level + 1, maxLevel, left);
            sideView(root->left, level + 1, maxLevel, left);
        }
    }
public:
    BinarySearchTree() {
        root = nullptr;
    }
    ~BinarySearchTree() {
        freeTreeMemory(root);
    }
    void addItem(T value) {
        Node* newNode = new Node(value);
        if(root == nullptr){
            root = new Node(value);
        }else if(value < root->value) {
            addItem(root->left, root, newNode, true);
        } else {
            addItem(root->right, root, newNode, false);
        }
    }
    bool deleteItem(T value){
        Node* current = root;
        while(current != nullptr) {
            if(current->value == value){
                deleteNode(current);
                return true;
            }
            if(value < current->value) current = current->left;
            else current = current->right;
        }
        return false;
    }
    void levelOrder() {
        int level = 1;
        while(printLevel(root, level)){
            level++;
        }
        cout << endl;
    }
    void spiralLevelOrder() {
        int level = 1;
        while(printLevel(root, level, (level % 2) == 1)){
            level++;
        }
        cout << endl;
    }
    void leftSideView() {
        int maxLevel = 0;
        sideView(root, 1, &maxLevel, true);
        cout << endl;
    }
    void rightSideView() {
        int maxLevel = 0;
        sideView(root, 1, &maxLevel, false);
        cout << endl;
    }
    T inOrderSuccessor(T value) {
        Node* current = root;
        while(current != nullptr){
            if(current->value == value){
                return inOrderSuccessor(current)->value;
            }
            if(value < current->value) current = current->left;
            else current = current->right;
        }
        throw "Value given does not exist";
    }
    T kthSmallestItem(int k) {
        Node* current = root;
        while(current->left != nullptr){
            current = current->left;
        }
        for(int i = 1; i < k; i++){
            current = inOrderSuccessor(current);
        }
        return current->value;
    }
};

#endif // BINARYSEARCHTREE_H_INCLUDED
