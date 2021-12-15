#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
using namespace std;

template <class T>
class MyTree{

private:

public:
    MyTree(){}

    MyTree(vector<T> elements){}

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