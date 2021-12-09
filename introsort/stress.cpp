#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include "introsort.cpp"

#define ARRAY_SIZE 1e6
using namespace std;

/**
 * generate 1d vector with size = ARRAY_SIZE
 * 
 * @param
 * 
 * isRandom --> boolean variable to return random or sorted array
 * if isRandom == False, then the array should look like this [0, 1, 2, 3]
 * 
 * @return
 *  a 1d vector with size = ARRAY_SIZE, you have the choice to pass vector by reference or to return a vector
 * make sure to change the code in main to match your change
 * 
 */
int generate_function() {
    return rand() % 1000;
}

void generate_vector( vector<int> &b, bool isRandom)
{
    if (!isRandom){      //return sorted array
        for(int i = 0; i < b.size(); i++)
            b[i] = i;
        return;
    }
    // use srand() to generate different outputs each time
    srand(time(0));
    // Generate value using generate function
    generate(b.begin(), b.end(), generate_function);
}

/**
 * driving stress test for both algorithms
 * 
 * generate 1d vector 
 * compare their output and runnig time
*/
int main(int argc, char **argv)
{

    while (true)
    {
        
        vector<int> a(ARRAY_SIZE);
        generate_vector(a, false);
        vector<int> b = a; //copy array A into array B
        vector<int> sorted_array = a;
        sort(sorted_array.begin(), sorted_array.end());
        
        auto quick_start = std::chrono::high_resolution_clock::now();
        quickSort(a, a.begin(), a.end());
        auto quick_finish = std::chrono::high_resolution_clock::now();

        auto intro_start = std::chrono::high_resolution_clock::now();
        // assign the proper value for max_depth 
        int max_depth = log(b.size());

        introSort(b, b.begin(), b.end(), max_depth);
        auto intro_finish = std::chrono::high_resolution_clock::now();

        auto quick_time = (quick_finish - quick_start).count();
        auto intro_time = (intro_finish - intro_start).count();

        if (a == sorted_array && b==sorted_array)
        {
            cout << "equivalent result ";
            cout << "quick_time ==> " << quick_time;
            cout << "intro_time ==> " << intro_time;
            cout << "performance enhancment ==>" << quick_time / intro_time << endl;
        }
        else
        {
            cout << "error, check your inputs and algortihms " << endl;
            break;
        }
    }
    return 0;
}