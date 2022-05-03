def is_valid_subsequence( array: list = None, sequence: list = None ) -> bool:
    seq_idx = 0
    for value in array:
        if value == sequence[seq_idx]:
            seq_idx += 1
    return seq_idx == len(sequence)


if __name__ == "__main__":   
    array = [5,1,22,25,6,-1,8,10]
    sequence = [1,6,-1,10]
    print(is_valid_subsequence(array, sequence))