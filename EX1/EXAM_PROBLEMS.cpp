//Exam questions and problems
//Daniel Arackal


/* Multiples

Given positive integers n, k and l,
print the first n positive integer numbers that are multiple of k, l or both. 

Example: n = 6, k = 2 and l = 3, you should print:
2 3 4 6 8 9
*/
/*
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string input;
    int n, k, l;
    // n = 6;
    // k = 2;
    // l = 3;

    cout << "Enter values of n, k, l: ";
    getline(cin, input);

    for(char& c : input){
        if(c == ',') c = ' ';
    }

    stringstream ss(input);
    ss >> n >> k >> l;

    int count = 0;
    for(int i = 1; count < n; ++i) {
        if(i % k == 0 || i % l == 0) {
            cout << i << " ";
            ++count;
        }
    }
    return 0;
}
*/

/* Triproduct numbers

A positive integer number n is triproduct if it can be obtained by the product 
of three consecutive positive integers. For example, 120 is triproduct, 
since 4 * 5 * 6 = 120. Given n > 0, determine if n is triproduct.
*/

/*
#include <iostream>

bool isTriproduct(int n) {
    for (int i = 1; ; ++i) {
        int product = i * (i + 1) * (i + 2);
        if (product == n) {
            return true;
        } else if (product > n) {
            return false;
        }
    }
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (isTriproduct(n)) { // it is a boolean function, 
                           // then it will output n and then state if it is a triproduct
        std::cout << n << " is a triproduct number." << std::endl;
    } else {
        std::cout << n << " is not a triproduct number." << std::endl;
    }

    return 0;
}
*/

/* Array Segments

Given n > 0 and a sequence of n integer numbers, print how many segments 
composed by consecutive copies of the same number the sequence has. 

For example: The sequence
5 2 2 3 4 4 4 4 1 1 1
has 5 segments.
*/

/*
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


int segmentCounter(){
    // when n > 0 and integers, n, are given, print the amount of instances 
    // of that specific number there are as their own segment, with a tally 
    // of the total segment count.

    // int n;
    // cout << "Enter the number of elements in the sequence: ";
    // cin >> n

    // need to use sstream to parse through spaces between input of numbers, or is it better to check through each number and have the input numbers as a array where, it iterates through each number?


    // Thinking I put a while statement n > 0    
        // I want a if statement where it iterates through each number of the array
        // if the number is different from the value before, add 1 to the segment counter, the counter already starts at 1 since a segment is already being compared to.


}

int main(){
    // Place the value that the counter displays here
    cout << "The sequence:" << b << "has" << n << "segments." << endl;

}




int segmentCounter(const string& input) {
    istringstream iss(input);
    int current, previous;
    bool isFirstNumber = true;
    int segments = 0;

    while (iss >> current) {
        // If it's the first number, initialize `previous` and increment `segments`
        if (isFirstNumber) {
            isFirstNumber = false;
            segments++;
        } else if (current != previous) {
            // If current number is different from the previous, it's a new segment
            segments++;
        }
        previous = current; // Update `previous` number for the next iteration
    }
    return segments;
}

int main() {
    string input;
    cout << "Enter a sequence of numbers separated by spaces: ";
    getline(cin, input); // Read the entire line of numbers

    int n = segmentCounter(input); // Calculate the number of segments
    cout << "The sequence, " << input << ", has " << n << " segments." << endl;
}

*/


/*
Write a program that given:
    ● n where 0 < n < 5000
    ● a list of n numbers in increasing order
    ● a target number k
prints two distinct elements from the list such that their sum is equal to the target k if such pair
exists and ”none” otherwise.
Examples:
    ● For n = 3, list 2 4 6 and k = 13, the output is none.
    ● For n = 8, list 1 2 3 4 5 6 7 8 and k = 8, valid outputs are:
        ○ 1 7
        ○ 2 6
        ○ 3 5
*/

/*
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
 

int main(){
    string input;
    cout << "n: ";
    getline(cin, input);
    int n = stoi(input);

    // if 0 < n < 5000, execute rest of the code, else, state that n is out of the bounds for the list
    if (n > 0 && n < 5000){
        
        // vector array that hold list of n numbers
        vector<int> intArray(n);

        //list of n numbers loop
        cout << "List of n: ";
        getline(cin, input);
        // used to removes spaces for inputs, 
        istringstream iss(input);
        
        for (int i = 0; i < n; ++i) {
            iss >> intArray[i];
//test
//cout << intArray[i] << endl;
        }



        cout << "k: ";
        getline(cin, input);
        int k = stoi(input);

        // Find two distinct elements that sum up to k

        bool found = false;

        for (int i = 0; i < n - 1; ++i) {
            
            for (int j = i + 1; j < n; ++j) {
                
                if (intArray[i] + intArray[j] == k) {
                    cout << intArray[i] << " " << intArray[j] << endl;
                    found = true;
                }
            }
        }
        // if two distinct elements are not found
        if (!found) {
            cout << "none" << endl;
        }
    } else {
        cout << "n needs to be 0 < n < 5000" << endl;
    }

    return 0;
}

*/

/* Practice Exam Question 1: Identify the common elements of two sorted arrays

You are given two lists of numbers and are interested in the numbers common to both lists. A number x is
common to list1 = <l0, l1, . . . , lp> and list2 = <m0, m1, . . . , mq> if and only if there exists an 0 ≤ i ≤ p
and an 0 ≤ j ≤ q such that li = x = mj . In this question you’re asked to write a C++ function to identify
and return the elements common to two lists provided as input. The input lists are represented as arrays
of ints in sorted (ascending) order and there are no repeated numbers within any one array. You’re given
list1 and its length p, list2 and its length q, and are asked to return the result in out, which can hold
at most outcap elements. If there are more than outcap common elements, return only the first outcap
of them. Your function should return the number of items now stored in out.
Remember: Each list is sorted in ascending order and no number appears more than once in a list.
int get_list_of_common(int list1[], int p, int list2[], int q, int out[], int outcap)
*/

/*
#include <iostream>

// Function to find common elements in two sorted arrays
int get_list_of_common(int list1[], int p, int list2[], int q, int out[], int outcap) {
    int i = 0, j = 0, k = 0; // Initialize pointers for list1, list2, and out arrays

    // Loop through both arrays until one ends or the output capacity is reached
    while (i < p && j < q && k < outcap) {
        if (list1[i] < list2[j]) {
            // If current element in list1 is smaller, move to the next element in list1
            i++;
        } else if (list2[j] < list1[i]) {
            // If current element in list2 is smaller, move to the next element in list2
            j++;
        } else {
            // Common element found, add it to the output array
            out[k++] = list1[i];
            i++;
            j++;
        }
    }

    // Return the number of common elements found
    return k;
}

// Example usage
int main() {
    int list1[] = {1, 3, 5, 7, 9};
    int list2[] = {3, 4, 5, 6, 7};
    int out[5]; // Assuming the output can hold at most 5 elements
    int commonCount = get_list_of_common(list1, 5, list2, 5, out, 5);

    std::cout << "Common elements: ";
    for (int i = 0; i < commonCount; i++) {
        std::cout << out[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

*/

/* Numeric Palindrome

Write a boolean function that takes an integer parameter and returns true if the base 10 number
is a numeric palindrome. Note, you cannot use any type of string to solve this problem.
bool isNumericPalindrome(int n)
For example:
● isNumericPalindrome(121) → true
● isNumericPalindrome(-121) → true
● isNumericPalindrome(220) → false
● isNumericPalindrome(-220) → false
● isNumericPalindrome(18344381) → true
● isNumericPalindrome(12345) → false
● isNumericPalindrome(1) → true
● isNumericPalindrome(0) → true
*/

/*
#include <iostream>
using namespace std;

bool isNumericPalindrome(int n) {
    // Handle negative numbers by converting them to positive
    if (n < 0)
        n = -n;

    int originalNumber = n;
    int reversedNumber = 0;

    // Reverse the number
    while (n > 0) {
        int digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
        n /= 10;
    }

    // Check if the original number is equal to the reversed number
    return originalNumber == reversedNumber;
}



int main() {

    cout << boolalpha;

    std::cout << isNumericPalindrome(121) << std::endl;       // Output: true
    std::cout << isNumericPalindrome(-121) << std::endl;      // Output: true
    std::cout << isNumericPalindrome(220) << std::endl;       // Output: false
    std::cout << isNumericPalindrome(-220) << std::endl;      // Output: false
    std::cout << isNumericPalindrome(18344381) << std::endl;  // Output: true
    std::cout << isNumericPalindrome(12345) << std::endl;     // Output: false
    std::cout << isNumericPalindrome(1) << std::endl;         // Output: true
    std::cout << isNumericPalindrome(0) << std::endl;         // Output: true

    return 0;
}

*/
/*Happy numbers

You should do this without converting numbers to strings and vice versa.
A happy number is a non-negative integer that eventually becomes 1 when iterated over the
sum of squared digits function.

For example, 28 is happy:
    28 -> 2^2 + 8^2 = 68 -> 6^2 + 8^2 = 100 -> 1^2 + 0^2 + 0^2 = 1

But 4 is unhappy (omitting intermediate results), as the chain of numbers led to the
original number.
    4 -> 16 -> 27 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4 ...

In fact, every unhappy number eventually converges with 4.
Write a function bool isHappy(int n) that receives as an argument a non-negative integer
and returns true if the number is happy.

Examples:
● isHappy(4) returns false.
● isHappy(13) returns true.
● isHappy(28) returns true.

*/

#include <iostream>

// Function to split the digits of a number, square each digit, and sum them up
int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
        int digit = n % 10; // Gets the last digit of n
        totalSum += digit * digit; // Squares the digit and adds it to totalSum
        n /= 10; // Removes the last digit from n
    }
    return totalSum;
}

// Function to determine if a number is happy using Floyd's Cycle Detection algorithm
bool isHappy(int n) {
    int slow = n, fast = getNext(n);
    while (fast != 1 && slow != fast) {
        slow = getNext(slow); // Moves at 1x speed
        fast = getNext(getNext(fast)); // Moves at 2x speed
    }
    return fast == 1; // If fast pointer reaches 1, the number is happy
}

int main() {
    // Example usage
    int number;
    std::cout << "enter number here:";
    std::cin >> number; // Change this number to test other numbers
    if (isHappy(number)) {
        std::cout << number << " is a happy number." << std::endl;
    } else {
        std::cout << number << " is not a happy number." << std::endl;
    }

    return 0;
}
