/*

Name: Longest Peak

Difficulty: Medium Blue

Write a funciton thtat takes in an array of integers and returns the length of the longest peak in the array.

Apeak is defined as adjacent integers in the array that are strictly increasing until they reach a tip (the highest value in the peak), at which point they become strictly decreasing. At least three integers are required to form a peak.

For example, the integers 1,4,10,2 form a peak, but integers 4,0,10 dont and neither do the integers 1,2,2,0. SImilarly, the integers 1,2,3 dont form a peak beacaause there arent any strictly decreasing integers after the 3.

INPUT
array = [1, 2, 3, ,3 ,4 ,0, 10, 6, 5 ,-1, -3, 2, 3]

OUTPUT
6 // 0, 10, 6, 5, -1, -3

*/

#include <iostream>
#include <vector>
#include <cstdlib>

int longestPeak(std::vector<int> array);

int main(){
    std::vector<int> array;
    int out;

    array = {};
    // array = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    // array = {1, 3, 2}; // 3
    // array = {5, 4, 3, 2, 1, 2, 1}; // 3
    // array = {1, 2, 3, 4, 5, 6, 10, 100, 1000}; // 0
    // array = {1, 2, 3, 3, 2, 1}; // 0
    // array = {1, 1, 1, 2, 3, 10, 12, -3, -3, 2, 3, 45, 800, 99, 98, 0, -1, -1, 2, 3, 4, 5, 0, -1, -1}; // 9

    out = longestPeak(array);

    std::cout << out << std::endl;

    return 0;
}

int longestPeak(std::vector<int> array){
    int begin_idx = 0, end_idx = -1, peak_idx = -1;
    int best_length = 0;

    for ( int i = 1; i < array.size(); i++ ){

        if ( array[i] > array[i-1] )
            peak_idx = i;
        if ( array[i] == array[i-1] ){
            begin_idx = i;
            peak_idx = -1;
        }
        if ( array[i] < array[i-1] ){
            end_idx = i;

            if ( std::abs(end_idx - begin_idx + 1) >= best_length && peak_idx != -1 )
                best_length = std::abs(end_idx - begin_idx + 1);
            if ( array[i+1] > array[i] )
                begin_idx = i;
        }
    }

    return best_length;
}