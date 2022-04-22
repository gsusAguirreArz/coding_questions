/*

Name: Validate Subsequence

Difficulty: Easy Green

Given two non-empty arrays of integers, write a function that determines whether the second array is a subsequence of the first one.

A subsequence of an array is a set of numbers that arent necessarily adjacen in the array but that are in the same order as they appear in the array. FOr instance the number [1,3,4] form a subsequence of the array [1,2,3,4], and so do the numebrs [2,4]. Note that a single number in an array and the array itself are both valid subsequences of the array.

INPUT
array = [5,1,22,25,6,-1,8,10]
sequence = [1,6,-1,10]

OUTPUT
true

*/

#include <iostream>
#include <vector>

// O(n) time | O(1) space

// Using while

// bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence){
//     int arrIdx = 0;
//     int seqIdx = 0;
//     while ( arrIdx < array.size() && seqIdx < sequence.size()){
//         if ( array[arrIdx] == sequence[seqIdx]){
//             seqIdx++;
//         }
//         arrIdx++;
//     }
//     return seqIdx == sequence.size();
// }

// Using for

bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence){
    int seqIdx = 0;
    for ( auto value : array ){
        if ( seqIdx == sequence.size() )
            break;
        if ( value == sequence[seqIdx] )
            seqIdx++;
    }
    return seqIdx == sequence.size();
}

int main(){
    std::vector<int> array = {5,1,22,25,6,-1,8,10};
    std::vector<int> sequence = {1,6,-1,-1,10};
    bool output = isValidSubsequence(array, sequence);
    std::cout << ( output ? "true" : "false" ) << std::endl;
    return 0;
}