/*

Name: Palindrome Check

Difficulty: Easy green

Statement:

Write a function that takes in a non empty string and that returns a boolean representing whetther the string is a palindrome.

A palindrom is defined as a string that written the same forward and backward. Note that single character strings are palindromes.

INPUT:
string = "abcdcba"

OUTPUT:
true // its written the same forward and backward

*/

#include <iostream>
#include <string>

bool isPalindrome( std::string str );

int main(){
    std::string str;

    str = "holacomoestas";
    str = "abcdcba";

    std::cout << (isPalindrome( str ) ? "true" : "false") << std::endl;
    return 0;
}

bool isPalindrome( std::string str ){
    for (
        int left_idx = 0,
        right_idx = str.size() - 1;
        left_idx < right_idx;
    )
        if ( str[left_idx++] != str[right_idx--] ) return false;
    return true;
}