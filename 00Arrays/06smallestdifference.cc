/*

Name: Smallest Difference

Difficulty: Medium Blue

Write a function that talkes in two non empty arrays integers, finds the pair of numbers (one from each array) whose absolute difference is closest to zero, and return an array containning these two numbers, with the number from the first array in the first position.

Note that the absolute differnece of two integers is the distance between them on the real number line. FOr example, the absollute difference of -5 and 5 is 10, and the absolute difference of -5 and -4 is 1.

You can assume that there will only be one pair of numbers with the smallest difference.

INPUT
arrayOne = [-1,5,10,20,28,3]
arrayTwo = [26,134,135,15,17]

OUTPUT
[28,26]

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// O(nlogn + mlogn) time | O(1) space
std::vector<int> smallestDifference( std::vector<int> arrayOne, std::vector<int> arrayTwo );

int main(){
    std::vector<int> arrayOne;
    std::vector<int> arrayTwo;
    std::vector<int> out;

    arrayOne = {-1, 5, 10, 20, 28, 3};
    arrayTwo = {26, 134, 135, 15, 17};
    
    out = smallestDifference(arrayOne,arrayTwo);

    std::cout<< "[ ";
    for ( auto value : out ){
        std::cout<< value << ", ";
    }
    std::cout <<"]"<<std::endl;

    return 0;
}

std::vector<int> smallestDifference( std::vector<int> arrayOne, std::vector<int> arrayTwo ){
    std::sort( arrayOne.begin(), arrayOne.end() );
    std::sort( arrayTwo.begin(), arrayTwo.end() );

    int a1Idx = 0, a2Idx = 0, best = INT32_MAX, x ,y, c;

    std::vector<int> bestPair = {};

    while ( a1Idx < arrayOne.size() && a2Idx < arrayTwo.size() ){
        x = arrayOne[a1Idx];
        y = arrayTwo[a2Idx];
        
        c = std::abs( x - y );

        if ( c < best ){
            best = c;
            bestPair = {x,y};
        }

        if ( x < y )
            a1Idx++;
        else
            a2Idx++;

    }
    return bestPair;
}