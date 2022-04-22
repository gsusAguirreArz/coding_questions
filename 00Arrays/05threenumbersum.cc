/*

Name: Three Number Sum

Difficulty: Medium Blue

Write a function that talkes in a non empty array of disctinct integers and an integer representing a target sum. The function should find all triplets in the array that sum up to the target sum and return a two dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascenfing orde with respect to the numbers they hold.

If no three numbers sum up to the targfet sum, the function should return an empty array.

INPUT
array = [12,3,1,2,-6,5,-8,6]
targetSum = 0;

OUTPUT
[[-8,2,6],[-8,3,5],[-6,1,5]]

*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeNumberSum( std::vector<int> array, int targetSum );

int main(){
    std::vector<int> array;
    int targetSum;
    std::vector<std::vector<int>> out;

    array = {12, 3, 1, 2, -6, 5, -8, 6};
    targetSum = 0;
    
    // array = {1,2,3};
    // targetSum = 6;
    // targetSum = 7;

    // array = {12, 3, 1, 2, -6, 5, 0, -8, -1, 6, -5};
    // targetSum = 0;

    // array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    // targetSum = 5;

    out = threeNumberSum(array, targetSum); 

    std::cout<< "[ " << std::endl;
    for ( auto value : out ){
        std::cout<< "   [ ";
        for ( int x : value ){
            std::cout<< x << ", ";
        }
        std::cout<<"],"<<std::endl;
    }
    std::cout<<"]"<<std::endl;

    return 0;
}

std::vector<std::vector<int>> threeNumberSum( std::vector<int> array, int targetSum ){

    std::sort( array.begin(), array.end() );

    std::vector<std::vector<int>> res = {}; 
    std::vector<int> aux;

    int vIdx, lIdx, rIdx, v, l, r, s;
    // A  = ( 2, 3, 4, 7, 8)
    // i  = ( 0, 1, 2, 3, 4)
    // IDX= ( .. v, l,.., r)

    for ( int i = 0; i < (array.size() - 2); i++ ){
        vIdx = i;
        lIdx = vIdx + 1;
        rIdx = array.size() - 1;

        aux = {};

        while ( lIdx < rIdx ){
            v = array[vIdx];
            l = array[lIdx];
            r = array[rIdx];

            s = v + l + r;

            if ( s == targetSum ){
                aux = {v,l,r};
                res.push_back(aux);
                rIdx--;
            }else if ( s > targetSum )
                rIdx--;
            else if ( s < targetSum )
                lIdx++;
        }
    }

    return res;

}