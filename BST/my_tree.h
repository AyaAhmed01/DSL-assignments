#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
#include <algorithm>
#include <stack>
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

    void inorder_rec(Node *node){
        if(node == NULL)
            return;
        inorder_rec(node -> leftChild);
        cout<<node -> value<<' ';
        inorder_rec(node -> rightChild);
    }

    void preorder_rec(Node *node){
        if(node == NULL)
            return;
        cout<<node -> value<<' ';
        inorder_rec(node -> leftChild);
        inorder_rec(node -> rightChild);
    }

    void postorder_rec(Node *node){
        if(node == NULL)
            return;
        inorder_rec(node -> leftChild);
        inorder_rec(node -> rightChild);
        cout<<node -> value<<' ';
    }

    // since recursion is stack in memory, to replace we should build stack
    void inorder_it(){
        stack<Node*> st;
        Node *curNode = root;

        while(!st.empty() || curNode != NULL){  // It MUST be empty and curNode = null to exist
            while(curNode != NULL){
                st.push(curNode);
                curNode = curNode -> leftChild;
            }
           // now curNode is NULL
            curNode = st.top();
            st.pop();
            cout<<curNode -> value <<" ";
            curNode = curNode -> rightChild;
        }
    }

    void preorder_it(){
        stack<Node*> st;
        st.push(root);
        Node *curNode;

        while(!st.empty()){
            curNode = st.top();
            st.pop();
            cout<<curNode -> value;
            if(curNode -> rightChild != NULL)
                st.push(curNode -> rightChild);
            if(curNode -> leftChild != NULL)
                st.push(curNode -> leftChild);
        }
    }

    void postorder_it(){
        stack<Node*> st1, st2;
        st1.push(root);
        Node *curNode;

        while(!st1.empty()){
            curNode = st1.top();
            st1.pop();
            st2.push(curNode);
            if(curNode -> leftChild != NULL)
                st1.push(curNode -> leftChild);
            if(curNode -> rightChild != NULL)
                st1.push(curNode -> rightChild);
        }
        // printing all elements
        while(!st2.empty()){
            cout<<st2.top() -> value<< " ";
            st2.pop();
        }
    }

//    void breadth_traversal(){}
//
//    int size(){}
};

#endif