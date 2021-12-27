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
                cout<< heap -> changePriority(x, y);
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

//5 7
//4 1 2 8 6 3 5
//1 7
//2 0 5
//3 1
//4
//5
//7
//6

