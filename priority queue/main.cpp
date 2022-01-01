#include <iostream>
#include <vector>
#include "my_pq.h"

using namespace std;

int main(){
    int n, numOfOper;
    cin>>n>>numOfOper;
    vector<int> nums(n);
    for(auto &e : nums)
        cin>>e;

    // construct a heap from nums
    My_PQ *heap = new My_PQ(nums);

    while(numOfOper--) {
        int op1, x, y;
        cin>>op1;
        switch (op1) {
            case 1:
            {
                cin>>x;
                try{
                    heap->insert(x);
                }
                catch (int size){
                    printf("Invalid insertion, the priority queue is complete with size %d\n", size);
                }
                break;
            }
            case 2:
            {
                cin>>x>>y;
                heap -> changePriority(x, y);
                break;
            }
            case 3:
            {
                cin>>x;
                heap -> remove(x);
                break;
            }
            case 4:
            {
                heap -> extractMax();
                break;
            }
            case 5:
            {
                cout<< heap -> peek()<< endl;
                break;
            }
            case 6:
                while(!heap -> empty()){
                    cout<<heap -> extractMax()<<' ';
                }
                cout<<endl;
                break;
            default:     // case 7
                cout<< heap -> size();
        }
    }

    return 0;
}

//- 7 7 // the initial heap size is 5, you are expecting 7 operations
//- 4 1 2 8 6 3 5 // the elements to be inserted in the heap
//- 1 7 // first operation, insert 7
//- 2 0 5 // second operation, change priority of element at index 0 to 5
//- 3 1   // remove element at index 1, which is supposed to be 6
//- 4     // remove the root, which is supposed to be 7
//- 5     // print max element, which is supposed to be 5
//- 7     // print size, which is supposed to be 6
//- 6     // print all eleemnts in PQ ==> 5 5 4 3 2 1
