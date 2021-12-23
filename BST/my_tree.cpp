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

    //1 element --> insert element in the tree
    //2 element --> search for element
    //3 1 --> in_order_rec || 3 2 --> in_order_it
    //4 1 --> pre_order_rec || 4 2 --> pre_order_it
    //5 1 --> post_order_rec || 5 3 --> post_order_it
    //6 --> breadth
    //7 --> size

    while(numOfOper--) {
        int op1, op2;
        cin>>op1;
        switch (op1) {
            case 1:
            {
                cin>>op2;
                tree -> insert(tree -> root, op2);
                break;
            }
            case 2:
            {
                cin>>op2;
                cout<< tree -> search(op2);
                break;
            }
            case 3:
            {
                cin>>op2;
                if(op2 == 1)
                    tree -> inorder_rec(tree -> root);
                else
                    tree -> inorder_it();
                break;
            }
            case 4:
            {
                cin>>op2;
                if(op2 == 1)
                    tree -> preorder_rec(tree -> root);
                else
                    tree -> preorder_it();
                break;
            }
            case 5:
            {
                cin>>op2;
                if(op2 == 1)
                    tree -> postorder_rec(tree -> root);
                else
                    tree -> postorder_it();
                break;
            }
            case 6:
                tree -> breadth_traversal();
                break;
            default:
                cout<< tree -> size();
        }
        if(op1 != 1)
            cout<< "\r\n";
    }

    return 0;
}



//   "input": "3 3\r\n2 3 1\r\n1 4\r\n7\r\n3 1",
//   "output": "4 \r\n1 2 3 4 \r\n"

//3 3
//
//2 3 1
//
//1 4
//
//7
//
//3 1


//"input": "3 8\r\n8 6 1\r\n1 0\r\n1 7\r\n1 3\r\n1 9\r\n3 2\r\n5 2\r\n2 8\r\n2 11",
//"output": "0 1 3 6 7 8 9 \r\n0 3 1 7 9 8 6 \r\n1 \r\n0 \r\n",

//3 8
//
//8 6 1
//
//1 0
//
//1 7
//
//1 3
//
//1 9
//
//3 2
//
//5 2
//
//2 8
//
//2 11


//"input": "7 8\r\n6 7 3 4 2 1 5\r\n3 1\r\n3 2\r\n4 1\r\n4 1\r\n5 1\r\n5 3\r\n6\r\n7",
//"output": "1 2 3 4 5 6 7 \r\n1 2 3 4 5 6 7 \r\n4 2 1 3 6 5 7 \r\n4 2 1 3 6 5 7 \r\n1 3 2 5 7 6 4 \r\n1 3 2 5 7 6 4 \r\n4 2 6 1 3 5 7 \r\n7 \r\n",

//7 8
//
//6 7 3 4 2 1 5
//
//3 1
//
//3 2
//
//4 1
//
//4 1
//
//5 1
//
//5 3
//
//6
//
//7