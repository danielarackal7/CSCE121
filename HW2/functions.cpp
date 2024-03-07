#include <iostream>
#include "functions.h"

using std::cout, std::endl;

// Check if the input numbers make sense for our range.
bool is_valid_range(int a, int b) {
    //Gotta make sure A is at least 10 and B doesn't go over 9999, also a <= b
    return a >= 10 && a <= b && b < 10000;
}

// Trying to figure out if a number is more like a mountain or a valley.
char classify_mv_range_type(int number) {
    int lastDigit = number % 10; // starting from the end
    number /= 10; // chop off the digit we just looked at

    // haven't decided if it's going up or down yet
    int trend = 0; // 0 means no trend yet, 1 for up, -1 for down

    // Walking through the number from right to left
    while (number > 0) {
        int digit = number % 10; // current digit to check

        if (lastDigit == digit) return 'N'; //Cant be same digits

        // setting the trend based on the first pair of digits we see
        if (trend == 0) {
            trend = (digit > lastDigit) ? 1 : -1;
        } else {
            // if the trend breaks, we flip it or quit
            if ((trend == 1 && digit < lastDigit) || (trend == -1 && digit > lastDigit)) {
                trend *= -1; // switcheroo
            } else {
                // this ain't fitting the pattern
                return 'N';
            }
        }

        lastDigit = digit; // move to the next digit
        number /= 10;
    }

    // let's see what we've got here
    return (trend != 0) ? (trend == 1 ? 'V' : 'M') : 'N';
}

// Let's count how many mountains and valleys we've got in this range.
void count_valid_mv_numbers(int a, int b) {
    int mountains = 0, valleys = 0; // starting count at zero

    // checking each number in the range
    for (int i = a; i <= b; ++i) {
        char terrainType = classify_mv_range_type(i);
        if (terrainType == 'M') {
            mountains++; // found another mountain
        } else if (terrainType == 'V') {
            valleys++; // and here's a valley
        }
    }

    // sharing what we found
    cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "." << endl;
}
