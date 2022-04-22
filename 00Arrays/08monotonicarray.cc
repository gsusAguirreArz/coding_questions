/*

Name: Monotonic array

Difficulty: Medium Blue

Write a function that takes in an array of integers and returns a boolean representing whether the array is monotonic.

AN array is said to be monotonic if its elements, from left to right, are entirely non increasing or entirely non decreasing.

Non increasing elements arent necessarily exclusively decreasing; they simply dont increase. Similarly, non decreasing elements arent necessarily exclusively increasing; they simply dont decrease.

Note that empty arrays and arrays of one elmeent are monotonic.

INPUT
array = [-1,-5,-10,-1100,-1100,-1101,-1102,-9001]

OUTPUT
true

*/

#include <iostream>
#include <vector>

bool isMonotonic(std::vector<int> array);

int main(){
    std::vector<int> array;

    // array = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001}; //true
    // array = {}; //true
    array = {1, 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 7, 9, 10, 11}; //false

    std::cout << ( isMonotonic(array) ? "true" : "false" ) << std::endl;
    return 0;
}

bool isMonotonic( std::vector<int> array ){
    bool isNonIncreasing = true, isNonDecreasing = true;

    for ( int idx = 1; idx < array.size(); idx++ ){

        if ( array[idx] < array[idx-1] )
            isNonIncreasing = false;
        else if ( array[idx] > array[idx-1] )
            isNonDecreasing = false;
    
    }

    return isNonDecreasing || isNonIncreasing;
}