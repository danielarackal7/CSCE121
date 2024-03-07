#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;


int main() {
    int a, b; // Hold the start and end of our range.
    
    // Ask the user for the range.
    cout << "Enter numbers 10 <= a <= b < 10000: ";
    
    while (cin >> a >> b) {
        if (!is_valid_range(a, b)) { // Check if the range is within the limits.
            cout << "Invalid Input" << endl; // Ask again if the input is outside the limits.
            cout << "Enter numbers 10 <= a <= b < 10000: ";
        } else {
            count_valid_mv_numbers(a, b);
            break; // Exit the loop after success.
        }
    }
    
    return 0;
}