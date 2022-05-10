let TOTAL = 0;

main();


function main() {
    let string = "abcdefghijklmnopqrstuvwxyz";
    sumASCII();
    console.log(isPanagram(string));
}

function sumASCII() {
    let auxsum = 0;
    let aux = ["a", "z"];
    let x_i = aux[0].charCodeAt(0);
    let x_f = aux[1].charCodeAt(0);
    
    for ( let i = x_i; i <= x_f; i++ )
        auxsum += i;
    
    TOTAL = auxsum;
    return;
}

function isPanagram(string) {
    let acum = 0;
    let letters = {};
    for ( let char of string ){
        if ( !letters[char] ){
            letters[char] = char.charCodeAt(0);
            acum += char.charCodeAt(0);
        }
    }
    return acum == TOTAL;
}