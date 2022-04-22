/*

Name: Spiral traverse

Difficulty: Medium Blue

Write a function that takes in a n x m two dimensional array (that can be square shaped when n == m) and returns a one dimensional array of all the arrays elements in spiral order.

Spiral order starts at the top left corner of the two dimensional array, goes to the right and proceeds in a spiral pattern all the way intul every element has been visited.

INPUT
array = [
    [ 1,  2,  3, 4],
    [12, 13, 14, 5],
    [11, 16, 15, 6],
    [10,  9,  8, 7]
]

OUTPUT
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]

*/

#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

std::vector<int> spiralTraverse( Matrix M );

int main(){
    std::vector<std::vector<int>> array;
    std::vector<int> out;

    // array = {
    //     { 1, 2, 3, 4},
    //     {12,13,14, 5},
    //     {11,16,15, 6},
    //     {10, 9, 8, 7}
    // };
    array = {
        { 1, 2, 3, 4, 5, 6},
        { 7, 8, 9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24}
    };

    out = spiralTraverse(array);
    std::cout << "[ ";
    for ( int i = 0; i < out.size(); i++ ){
        if ( i != out.size() - 1 )
            std::cout << out[i] << ", ";
        else
            std::cout << out[i] << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}

std::vector<int> spiralTraverse( Matrix M ){
    int n = M.size();
    int m = M[0].size();

    std::vector<int> res{};

    int i = 0, j = 0, k;

    while ( i < n && j < m ){

        for ( k = j; k < m; ++k )
            res.push_back( M[i][k] );
        i++;

        for ( k = i; k < n; ++k )
            res.push_back( M[k][m-1] );
        m--;

        if ( i < n ){
            for ( k = m - 1; k >= j; --k )
                res.push_back( M[n-1][k] );
            n--;
        }

        if ( j < m ){
            for ( k = n - 1; k >= i; --k )
                res.push_back( M[k][j] );
            j++;
        }

    }
    return res;
}