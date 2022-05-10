#include <iostream>
#include <string>
#include <unordered_map>

bool isPanagram( std::string str );

int main(){
    std::string str;

    str = "abcdefghijklmnopqrstuvwxyz";
    
    std::cout << ( isPanagram(str) ? "true": "false" ) << std::endl;
    return 0;
}

bool isPanagram( std::string str ){
    const int N = 2847;
    int S = 0;
    std::unordered_map<char, int> abc;
    for ( char c : str ){
        int char_code = (int) c;
        if ( abc.find(c) == abc.end() ){
            abc[c] = char_code;
            S += char_code;
        }
    }

    return S == N;
}