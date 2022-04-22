/*

Name: Move element to end

Difficulty: Medium Blue

Youre given an array of integers and an integer. Write a function that moves all instances of that integer in the array to the end of the array and returns the array.

THe function should perform this in place (ie it should mutate the input array) and doesnt need to maintain the order of the other integers.

INPUT
array = [2,1,2,2,2,3,4,2]
toMove = 2

OUTPUT
[1,3,4,2,2,2,2,2] // the numbers 1, 3, and 4 could be ordered differently

*/

#include <iostream>
#include <vector>

// O(n) time | O(1) space
std::vector<int> moveElementToEnd( std::vector<int> array, int toMove );

int main(){
    std::vector<int> array;
    int toMove;
    std::vector<int> out;

    // array = {2, 1, 2, 2, 2, 3, 4, 2};
    // toMove = 2;

    // array = {};
    // toMove = 3;

    // array = {1, 2, 4, 5, 6};
    // toMove = 3;

    // array = {3, 3, 3, 3, 3};
    // toMove = 3;

    array = {5, 5, 5, 5, 5, 5, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12};
    toMove = 5;

    out = moveElementToEnd(array, toMove);

    std::cout << "[ ";
    for ( auto value : out ){
        std::cout << value << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}

std::vector<int> moveElementToEnd( std::vector<int> array, int toMove ){
    int left = 0;
    int right = array.size() - 1;

    while ( left < right ){
        while ( left < right && array[right] == toMove )
            right--;
        if ( array[left] == toMove && left != right ){
            array[left] += array[right];
            array[right] = array[left] - array[right];
            array[left] -= array[right];
        }
        left++;
    }

    return array;
}