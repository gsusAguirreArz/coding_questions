function twoNumberSum( array, target_sum ) {
    array.sort((a,b) => a - b);
    let left_idx = 0;
    let right_idx = array.length - 1;
    while ( left_idx < right_idx ){
        let current_sum = array[left_idx] + array[right_idx];
        if ( current_sum == target_sum )
            return [array[left_idx], array[right_idx]];
        if ( current_sum > target_sum )
            right_idx--;
        if ( current_sum < target_sum )
            left_idx++;
    }
    return []
}


let array = [3,5,-4,8,11,1,-1,6]
let target_sum = 10
console.log(twoNumberSum(array, target_sum));