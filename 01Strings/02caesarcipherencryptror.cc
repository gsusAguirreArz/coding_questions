/*

Name: Caesar Cypher Encryptor

Difficulty: Easy green

Statement:

Given a non empty string of lowercase letters and a non negative integer representing a key, write a function that returns a new string obtained by shifting every letter in the input string by k positions in the alphavet, where k is the key.

Note that letters should "wrap" around the alphabvet; in other words, the letter z shifted by one return the letter a.

INPUT:
string = "xyz"
key = 2

OUTPUT:
"zab"

*/

#include <iostream>
#include <string>

std::string caesarCypherEncryptor( std::string str, int key );
char shiftChar( int char_code, int value );

int main(void){
    std::string str;
    int key;
    std::string out;

    str = "xyz";
    key = 50;

    out = caesarCypherEncryptor(str, key);
    std::cout << out << std::endl;
    return 0;
}

std::string caesarCypherEncryptor( std::string str, int key ){
    std::string new_str = "";
    int new_key = key % 26;
    for ( char c : str ){
        int char_code = (int) c;
        int new_char_code = shiftChar(char_code, new_key);
        char new_char = (char) new_char_code;
        new_str += new_char;
    }
    return new_str;
}

char shiftChar( int char_code, int key ){
    int new_char_code = char_code + key;
    return new_char_code <= 122 ? new_char_code : 96 + new_char_code % 122;
}