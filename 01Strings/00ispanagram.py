TOTAL = 0

def sumASCII() -> None:
    global TOTAL
    x_i = ord("a")
    x_f = ord("z")
    for i in range(x_i, x_f+1):
        TOTAL += i
    return

def isPanagram( string: str ) -> bool:
    letters = {}
    counter = 0
    for char in string:
        if char not in letters:
            letters[char] = ord(char)
            counter += ord(char)
    return counter == TOTAL

if __name__ == "__main__":
    string = "abcdefghijklmnopqrstuvwxyz"
    sumASCII()
    print(isPanagram(string))