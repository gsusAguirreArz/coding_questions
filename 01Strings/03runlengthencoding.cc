/*

Name: Run-Length Encoding

Difficulty: Easy green

Statement:

Write a function that takes in a non-empty string and returns its run-length encoding.

From Wikipedia, "run-length encoding is a form of lossless data compression in which reuns of data are stored as a single data value and count, rather than as the original run." For this problem, a run od data is any sequence of consecutive, identical characters. So the run "AAA" would be run-length-encoded as "3A".

To make things more complicated, however, the input string can contain all soirt of special characters, including numbers. And since encoded data must be decodable, this means that we cant naively run-length-encode long runs. For example, the run "AAAAAAAAAAAA" (12 A's) cant naively be encoded as "12A", since this string can be decoded as either "AAAAAAAAAAAA" or "1AA". Thus, long runs (runs of 10 o more characters) should be encoded in a split fashion; the aforementioned run should be encoded as "9A3A".

INPUT:
string = "AAAAAAAAAAAAABBCCCCDD"

OUTPUT:
"9A4A2B4C2D"

*/

#include <iostream>
#include <string>
#include <unordered_map>

std::string runLengthEncoding( std::string str );

int main(void){

    std::string str;
    std::string out;

    str = "AAAAAAAAAAAAABBCCCCDD";

    out = runLengthEncoding(str);

    std::cout << out << std::endl;
    return 0;
}

std::string runLengthEncoding( std::string str ){
    std::string encoded_str = "";
    std::unordered_map<char, int> characters;
    for ( char c : str ){
        if ( characters.find(c) == characters.end() ) characters[c] = 0;
        
    }
    return encoded_str;
}