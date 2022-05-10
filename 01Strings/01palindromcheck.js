main();

function main() {
    let string = "abcdcba";

    console.log(palindromeCheck(string));
}

function palindromeCheck(string) {
    for (
        let left_idx = 0,
        right_idx = string.length - 1;
        left_idx < right_idx;
    )
        if ( string[left_idx++] != string[right_idx--] ) return false;
    
    return true
}