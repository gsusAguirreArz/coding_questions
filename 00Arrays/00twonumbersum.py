"""

Name: Two number sum

Difficulty: Easy Green

Write a function that takes in a non empty array of distinct integers and an integer representing a target sum. If any two numbers in the input array sum up to the target sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, the function should return an empty array.

Note that the target sum has to be obtained by summing two different integers in the array; you cant add a single integer to itself in order to obtain the target sum.

You can assume that there will be at most one pir of number summing up to the target sum.

INPUT
array = [3,5,-4,8,11,1,-1,6]
targetSum = 10

OUTPUT
[-1,11]

"""

def two_number_sum( array: list, target_sum: int ) -> list:
    array.sort()

    left_idx = 0
    right_idx = len(array) - 1
    while left_idx < right_idx:
        current_sum = array[left_idx] + array[right_idx]
        if current_sum == target_sum:
            return [array[left_idx], array[right_idx]]
        if current_sum > target_sum:
            right_idx = right_idx - 1
        if current_sum < target_sum:
            left_idx = left_idx + 1
    return []

if __name__ == "__main__":
    array = [3,5,-4,8,11,1,-1,6]
    target_sum = 10
    print(two_number_sum(array=array, target_sum=target_sum))