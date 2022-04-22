/*

Name: Non-constructible change

Difficulty: Easy Green

GIven an array of positive integers representing the values of coins in your possession, write a function that returns the minimum amount of change ( the minimum sum of money ) that you cannot create. The given coins can haveany positive integer valye and arent necessaruly unique (ie you can have multiple coins of the same value ).

For example, if youre given coins = [1,2,5], the minimym amount of chagne that you cant create is 4. If youre given no coins, the minimum amount og change that you cant create is 1.

INPUT
coins = [5,7,1,1,2,3,22]

OUTPUT
20

*/

#include <iostream>
#include <vector>
#include <algorithm>

int nonConstructibleChange( std::vector<int> coins );

int main(){
    std::vector<int> coins;
    // coins = {};
    coins = {1,1,1,1,1};
    // coins = {87};
    // coins = {5,6,1,1,2,3,43}; //19
    // coins = {109, 2000, 8765, 19, 18, 17, 16, 8, 1, 1, 2, 4}; // 87

    std::cout << nonConstructibleChange(coins) << std::endl;
    
    return 0;
}

int nonConstructibleChange( std::vector<int> coins ) {
    std::sort( coins.begin(), coins.end() );

    int S = 0;

    for ( int i = 0; i < coins.size(); i++ ){
        int currentCoin = coins[i];
        if ( currentCoin > S + 1 )
            return S + 1;
        S += currentCoin;
    }

    return S + 1;
}