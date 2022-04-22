/*

Name: Two number sum

Difficulty: Easy Green

Write a function that takes in a non empty array of distinct integers and an integer representing a target sum. If any two numbers in the input array sum up to the target sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, the function should return an empty array.

Note that the target sum has to be obtained by summing two different integers in the array; you cant add a single integer to itself in order to obtain the target sum.

You can assume that there will be at most one pir of number summing up to the target sum.

INPUT
array = [3,5,-4,8,11,1,-1,6]
targetSum = 10

OUTPUT
[-1,11]

*/

#include <iostream>
#include <vector>
#include <algorithm> // for second solution
#include <unordered_set> // for third solution

// FIRST SOLUTION
// O(n^2) time | O(1) space

// std::vector<int> twoNumberSum(std::vector<int> array, int targetSum){

//     if ( array.size() == 0 ){
//         std::cout << "The array is empty!!." << std::endl;
//         return {};
//     }

//     for ( int i = 0; i < array.size() - 1; i++ ){
//         int firstNum = array[i];
//         for ( int j = i + 1; j < array.size(); j++ ){
//             int secondNum = array[j];
//             if ( firstNum + secondNum == targetSum )
//                 return std::vector<int>{firstNum, secondNum};  
//         };
//     };

//     return {};
// };

// SECOND SOLUTION
// O(nlogn) time | O(1) space

std::vector<int> twoNumberSum(std::vector<int> array, int targetSum){

    if ( array.size() == 0 ){
        std::cout << "The array is empty!!." << std::endl;
        return {};
    }

    std::sort(array.begin(), array.end());
    int left = 0;
    int right = array.size() - 1;
    while (left < right){
        int currentSum = array[left] + array[right];
        if (currentSum == targetSum)
            return std::vector<int>{array[left], array[right]};
        else if ( currentSum < targetSum )
            left++;
        else if ( currentSum > targetSum )
            right--;
    }

    return {};
};

// THIRD SOLUTION
// O(n) time | O(n) space

// std::vector<int> twoNumberSum(std::vector<int> array, int targetSum){

//     std::unordered_set<int> nums;
//     for ( int num : array ){
//         int potentialMatch = targetSum - num;
//         if ( nums.find(potentialMatch) != nums.end() ){
//             return std::vector<int>{potentialMatch, num};
//         }else{
//             nums.insert(num);
//         }
//     }

//     return {};
// }


int main(){
    // vector<int> array = {3,5,-4,8,11,1,-1,6};
    std::vector<int> array = {3,5,-4,8,11,1,6,-1};
    // vector<int> array = {};
    int targetSum = 10;

    std::vector<int> sol = twoNumberSum(array, targetSum);
    std::cout << "{ ";
    for ( int i = 0; i < sol.size(); i++ ){
        std::cout << sol[i] << " ";
    };
    std::cout << "}" << std::endl;
    return 1;
}