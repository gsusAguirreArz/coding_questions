/*

Name: First Duplicate Value

Difficulty: Medium Blue

Given an array of integers between 1 and n inclusive, where n is the length of the array, wirite a funciton that returns the first integer that appears more than once (whe the array is read from left to right).

IN other words , out of al lthe integers that might occur more than once in the input aray, your function should return the one whose first duplicate value has the minimum index.

If no integer appears more than once, your function should return -1;

Note that youre allowed to motate the input array.

INPUT
array = [2,1,5,2,3,3,4]

OUTPUT
2 // 2 is the first integer that apopears more than once.
// 3 also appears more than once, but the second 3 appears after the second 2.

INPUT 
array = [2,1,5,3,3,2,4]

OUTPUT
3 // 3 is the first integer that appears more than once
// 2 also appear more than once, but the second 2 appears after the second 3

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

int firstDuplicateValue( std::vector<int> array );

int main() {
    std::vector<int> array;
    int out;

    array = {2, 1, 5, 2, 3, 3, 4};
    // array = {2, 1, 5, 3, 3, 2, 4};

    out = firstDuplicateValue(array);
    std::cout << out << std::endl;
    return 0;
}

// O(n) time | O(n) space first solution
// int firstDuplicateValue( std::vector<int> array ){
//     std::unordered_map<int, std::vector<int>> aux;
//     int best_idx = array.size(), repetitions = 0;
//     for ( int i = 0; i < array.size(); i++ ){
//         if ( aux.find(array[i]) == aux.end() )
//             aux[array[i]] = {i, array[i], 0};
//         else{
//             aux[array[i]][2] += 1;
//             repetitions += 1;
//             best_idx = (aux[array[i]][0] < best_idx && repetitions == 1) ? aux[array[i]][0] : best_idx;
//         }

//     }
//     return best_idx < array.size() ? array[best_idx] : -1;
// }

// O(n) time | O(n) space
// int firstDuplicateValue( std::vector<int> array ){
//     std::unordered_map<int, bool> seen;
//     for ( int value : array ){
//         if ( seen.find(value) != seen.end() )
//             return value;
//         seen[value] = true;
//     }
//     return -1;
// }

// O(n) time | O(1) space ( not yet understanded )
int firstDuplciateValue ( std::vector<int> array ){
    for ( int value : array ){
        int abs_value = std::abs(value);
        if ( array[abs_value - 1] < 0 )
            return value;
        array[abs_value - 1] *= -1;
    }
    return -1;
}