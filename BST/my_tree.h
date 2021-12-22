#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int value;
    Node *parent;       // should be pointers as the struct isn't done yet
    Node *leftChild;
    Node *rightChild;
};

class MyTree{

private:

    Node* newNode(int val){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp -> value = val;
        temp -> leftChild = temp -> rightChild = temp -> parent = NULL;
        return temp;
    }

    Node* buildTree(vector<int> &nums, Node *par, int l, int h){   // MUST be reference
        if(h < l)
            return NULL;

        if(l == h){
            return insert(par, nums[l]);
        }

        int mid = l + (h - l)/2;
        auto curNode = insert(par, nums[mid]);
        buildTree(nums, curNode, l, mid - 1);
        buildTree(nums, curNode, mid + 1, h);
        return curNode;
    }

public:

    Node *root = NULL;

    MyTree(){}

    MyTree(vector<int> &elements){              // MUST be reference
        sort(elements.begin(), elements.end());
        root = buildTree(elements, root, 0, elements.size() - 1);
    }

    bool search(int key){
        auto node = root;
        while(node != NULL){
            if(key > node -> value)
                node = node -> rightChild;
            else if(key < node -> value)
                node = node -> leftChild;
            else
                return true;
        }
        return false;
    }

    Node* insert(Node *node, int key) {       /****** Handle parent *******/
        // make a new root if the tree is empty
        if (node == NULL){
            return newNode(key);
        }
        // Traverse to the right place and insert the node
        if (key < node->value)
            node->leftChild = insert(node->leftChild, key);
        else
            node->rightChild = insert(node->rightChild, key);

        return node;
    }
//
//    void inorder_rec(){}
//
//    void preorder_rec(){}
//
//    void postorder_rec(){}
//
//    void inorder_it(){}
//
//    void preorder_it(){}
//
//    void postorder_it(){}
//
//    void breadth_traversal(){}
//
//    int size(){}
};

#endif