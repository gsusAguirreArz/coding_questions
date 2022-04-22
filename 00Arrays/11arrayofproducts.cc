/*

Name: Array Of Products

Difficulty: Medium Blue

Write a function that takes in a non empty array of integers and returns an array of the same length, where each element in the output array is equal to the product of every other number in the input array.

In other words, the value at output[i] is equal to the product of every number in the input array other than input[i].

Note that youre expected to solve this problem without using division

INPUT
array = [5, 1, 4, 2]

OUTPUT
[8, 40, 10, 20] 
// 8  = 1 x 4 x 2
// 40 = 5 x 4 x 2
// 10 = 5 x 1 x 2
// 20 = 5 x 1 x 4

*/

#include <iostream>
#include <vector>

std::vector<int> arrayOfProducts( std::vector<int> array );

int main() {
    std::vector<int> array;
    std::vector<int> out;

    // array = {5, 1, 4, 2};
    // array = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array = {-5, 2, -4, 14, -6};

    out = arrayOfProducts(array);

    std::cout << "[ ";
    for ( int value : out ){
        std::cout << value << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}


std::vector<int> arrayOfProducts( std::vector<int> array ){
    std::vector<int> aux(array.size(), 1);
    int left_mult = 1, right_mult = 1;

    for ( int i = 0; i < array.size(); i++ ){
        aux[i] = left_mult;
        left_mult *= array[i];
    }
    for ( int i = array.size() - 1; i >= 0; i-- ){
        aux[i] *= right_mult;
        right_mult *= array[i];
    }

    return aux;
}