/*

Name: Sorted squared array

Difficulty: Easy Green

Write a fucntion that tales in a non empty array of integers that are sorted in ascending order and return a new array of the same length with the squaresog the original integers also sorted in ascending order.

INPUT
array = [1,2,3,5,6,8,9]

OUTPUT
[1,4,9,25,36,64,81]

*/

#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> sortedSquaredArray(std::vector<int> array){
    int n = array.size();

    if ( n == 0 ){
        std::cout << "The array is empty!!." << std::endl;
        return {};
    }

    std::vector<int> res (n);

    int leftIdx = 0;
    int rightIdx = n - 1;

    int leftNum = array[leftIdx];
    int rightNum = array[rightIdx];

    if ( leftNum >= 0 ){
        for ( int i = 0; i < n; i++ ){
            res.at(i) = array[i]*array[i];
        }
    }else{
        int Idx = n - 1;
        while(leftIdx != rightIdx){
            leftNum = array[leftIdx];
            rightNum = array[rightIdx];
            if ( std::abs(leftNum) >= std::abs(rightNum) ){
                res.at(Idx) = leftNum*leftNum;
                Idx--;
                leftIdx++;
            }else{
                res.at(Idx) = rightNum*rightNum;
                Idx--;
                rightIdx--;
            } 
        }
        res.at(Idx) = array[leftIdx]*array[leftIdx];
    }
    return res;
}

int main(){
    // std::vector<int> input = {1,2,3,5,6,8,9};
    std::vector<int> input = {-1,-1,-1,-1,-1};
    // std::vector<int> input = {-5,-3,-1,3};
    std::vector<int> output = sortedSquaredArray(input);
    std::cout<< "[ ";
    for (auto value : output){
        std::cout << value << ", ";
    }
    std::cout << "]" << std::endl;
    return 0;
}