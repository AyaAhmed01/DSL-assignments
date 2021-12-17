#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
using namespace std;

template <class T>
class MyTree{

private:
    struct Node{      // each node has value, parent, children
        T value;
        Node parent, leftChild, rightChild;
    };

    Node root;

    Node buildTree(vector<T> &elements, int l, int h){
        if(l == h){          // base case
            Node node;
            node.value = elements[l];
            node.leftChild = NULL;
            node.rightChild = NULL;
            return node;
        }
        int mid = l + (h - l)/2;
        Node currNode;
        currNode.value = elements[mid];

        Node &leftChild = buildTree(elements, l, mid);
        Node &rightChild = buildTree(elements, mid+1, h);

        currNode.leftChild = leftChild;
        currNode.rightChild = rightChild;
        leftChild.parent = currNode;
        rightChild.parent = currNode;

        return currNode;
    }

public:
    MyTree(){
        root = NULL;
    }

    MyTree(vector<T> elements){
        sort(elements.begin(), elements.end());
        root = buildTree(elements, 0, elements.size() - 1);
    }

    bool search(T key){}

    void insert(T key){}

    void inorder_rec(){}

    void preorder_rec(){}

    void postorder_rec(){}

    void inorder_it(){}

    void preorder_it(){}

    void postorder_it(){}

    void breadth_traversal(){}

    int size(){}
};

#endif