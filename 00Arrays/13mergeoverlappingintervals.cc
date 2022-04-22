/*

Name: Merge Overlapping Intervals

Difficulty: Medium Blue

Write a function that takes in a non empty array of arbitrary intervals, merges any overlapping intervals, and returns the new intervals in no particulas order.

Each interval interval is an array of two integers, with interval[0] as the start of the interval and interval[1] as the end of the interval.

Note that back-to-back intervals arent considered to be overlapping. FOr example, [1,5] and [6,7] arent overlapping; however, [1,6] and [6,7] are indeed overlapping.

Also note that the start of any particular interval will always be less than or equal to the end of that interval.

INPUT
intervals = [
    [1, 2],
    [3, 5],
    [4, 7],
    [6, 8],
    [9,10]
]

OUTPUT
2 // 2 is the first integer that apopears more than once.
// 3 also appears more than once, but the second 3 appears after the second 2.

INPUT 
array = [2,1,5,3,3,2,4]

OUTPUT
[
    [1, 2],
    [3, 8],
    [9,10]
]
// Merge the intervaks [3,5],[4,7],[6,8]
// the intervals could ve ordered differently

*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> mergeOverlappingIntervals ( std::vector<std::vector<int>> intervals );

int main(){
    std::vector<std::vector<int>> intervals;
    std::vector<std::vector<int>> out;

    intervals = {{1,2},{3,5},{4,7},{6,8},{9,10}};

    out = mergeOverlappingIntervals(intervals);

    std::cout << "[ " << std::endl;
    for ( auto row : out ){
        std::cout << "  [ ";
        for ( int value : row ){
            std::cout << value << ", ";
        }
        std::cout << "], " << std::endl;
    }
    std::cout << "]" << std::endl;
    
    return 0;
}


std::vector<std::vector<int>> mergeOverlappingIntervals ( std::vector<std::vector<int>> intervals ){
    std::sort( intervals.begin(), intervals.end(),
        []( std::vector<int> v1, std::vector<int> v2 ) { return v1[0] < v2[0]; }
    );
    std::vector<std::vector<int>> merged_intervals;
    std::vector<int> new_interval = intervals[0];

    for ( int i = 1; i < intervals.size(); i++ ){

        if ( intervals[i][0] <= new_interval[1] )
            new_interval = {new_interval[0], std::max( new_interval[1], intervals[i][1] )};
        else{
            merged_intervals.push_back(new_interval);
            new_interval = intervals[i];
        }
    }

    merged_intervals.push_back(new_interval);
    return merged_intervals;
}