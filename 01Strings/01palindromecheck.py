def palindromCheck( string: str ) -> bool:
    left_idx = 0;
    right_idx = len(string) - 1;

    while left_idx < right_idx:
        if string[left_idx] != string[right_idx]:
            return False
        left_idx += 1
        right_idx -= 1
    
    return True


if __name__ == "__main__":
    string = "abchcba"
    print(palindromCheck(string))