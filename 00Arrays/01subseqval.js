function isValidSubseq(array, sequence) {
    // let arr_idx = 0;
    // let seq_idx = 0;
    // while ( arr_idx < array.length ){
    //     if ( array[arr_idx] == sequence[seq_idx] )
    //         seq_idx++;
    //     arr_idx++;
    // }
    // return seq_idx == sequence.length;

    seq_idx = 0;
    for ( let value of array ){
        if ( value == sequence[seq_idx] )
            seq_idx++;
    }
    return seq_idx == sequence.length;
}

let array = [5,1,22,25,6,-1,8,10]
let sequence = [1,6,-1,10]
console.log(isValidSubseq(array,sequence));