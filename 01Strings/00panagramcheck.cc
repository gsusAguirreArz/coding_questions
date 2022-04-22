#include <iostream>
#include <string>

bool isPanagram( std::string str );

int main(){
    std::string str;

    str = "holacomoestzs";

    std::cout << "\u0444";
    
    std::cout << ( isPanagram(str) ? "true": "false" ) << std::endl;
    return 0;
}

bool isPanagram( std::string str ){

    for ( int i = 0; i < str.size(); i++ ){
        break;
    }

    return true;
}