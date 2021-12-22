#include <iostream>
#include <vector>
#include "my_tree.h"

using namespace std;

int main(int argc, char** argv){
    int n, numOfOper;
    cin>>n>>numOfOper;
    vector<int> nums(n);
    for(auto &e : nums)
        cin>>e;

    // construct a tree from nums
    MyTree *tree = new MyTree(nums);
    auto root = tree -> root;
    cout<<"end code\n";
//    cout<< root -> value << endl;
//    cout<<root -> leftChild -> value << endl;
//    cout<<root -> rightChild -> value;
    tree -> breadth_traversal();

//    string input;
//    cin>>input;
//    if(input.size() == 1){    // size or breadth
//        int op = input[0] - '0';
//        if(op == 6)         // breadth
//        else               // size
//
//    }
//    else{
//
//    }

    return 0;
}


//1 element --> insert element in the tree
//2 element --> search for element
//3 1 --> in_order_rec || 3 2 --> in_order_it
//4 1 --> pre_order_rec || 4 2 --> pre_order_it
//5 1 --> post_order_rec || 5 3 --> post_order_it