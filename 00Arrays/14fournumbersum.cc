/*

Name: Four Number Sum

Difficulty: Hard Red

Write a function that takes in a non empty array of disctinct integers and an integer represinting a target sum. The function should find all quadruplets in the array that sum up to the targetr sum and return a two dimensional array of all these quadruplets in no particular order.

If no four numbers sum up to the target sum, the function should return an empty array.

INPUT
array = [7, 6 ,4 ,-1, 1, 2]
targetSum = 16

OUTPUT
[[7, 6, 4, -1], [7, 6, 1, 2]] // the quadruplets could be ordered differently

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using Matrix = std::vector<std::vector<int>>;

Matrix fourNumberSum( std::vector<int> array , int targetSum );
void upperTriangularMatrix( Matrix M );
void lowerTriangularMatrix( Matrix M );
void printMatrix( Matrix M );

int main() {
    std::vector<int> array;
    int targetSum;
    Matrix out;

    array = {7,6,4,-1,1,2};
    targetSum = 16;

    out = fourNumberSum( array, 16 );
    return 0;
}

Matrix fourNumberSum( std::vector<int> array , int targetSum ){
    Matrix res;
    std::vector<int> quadruplets;
    std::unordered_map<int, std::vector<int>> auxmap;

    int n = array.size(), i, j, k;

    Matrix aux (n, std::vector<int>(n,0) );

    for ( i = 0; i < n; i++ ){
        for ( j = 0; j < n; j++ ){
            if ( j < i )
                aux[i][j] = array[i]+array[j];
        }
    }

    printMatrix(aux);

    i = 0, j = 0;
    int iter = 0, current, valid;
    while ( i < n ){
        k = j;
        while ( k < n ){
            current = aux[i][k];
            if ( i > k ){
                valid = current;
                std::vector<int> coords = {valid, i,k};
                auxmap[iter] = coords;
                iter++;
                std::cout << "Value: " << valid << ", " << "Coords: (" << i << ", " << k << ")" << std::endl;
            }
            k++;
        }
        i++;
    }

    for ( auto value : auxmap ){
        std:: cout << "{" << value.second[0] << ": " << " (" << value.second[1] << ", " << value.second[2] <<") }" << std::endl;
    }


    // i = 0;
    // while ( i < n ){

    //     int i_mem = i;

    //     for ( j = 0; j < n;){
    //         if ( j < i ){
    //             int currentValue = aux[i][j];
    //             std::cout << currentValue << std::endl;
    //         }
    //         i++;
    //     }

    //     i = i_mem;
    //     i++;

    // }
    return res;
}

void printMatrix( Matrix M ){
    int n_row = M.size(),
    m_col = M[0].size();

    std::cout << "[ " << std::endl;
    for ( int i =0; i < n_row; i++ ){
        std::cout << "  [ ";
        for ( int j = 0; j < m_col; j++ )
            std::cout << M[i][j] << ", ";
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

void lowerTriangularMatrix( Matrix M ){
    int n_row = M.size(),
    m_col = M[0].size();

    for ( int i = 0; i < n_row; i++ ){
        for ( int j = 0; j < m_col; j++ ){
            if ( i < j )
                std::cout << "0 ";
            else
                std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void upperTriangularMatrix( Matrix M ){
    int n_row = M.size(),
    m_col = M[0].size();

    for ( int i = 0; i < n_row; i++ ){
        for ( int j = 0; j < m_col; j++ ){
            if ( j >= i )
                std::cout << M[i][j] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}