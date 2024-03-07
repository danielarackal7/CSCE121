#include <iostream>
#include <cmath>
#include "./nth_root.h"

int main() {
    try {
        {   // MINIMUM REQUIREMENT (for this lab)
            // just call the function with various values of n and x
            nth_root(2, 1);
            nth_root(3, 8);
            nth_root(4, 81);

            nth_root(-2,9);
            nth_root(-3,8);

            nth_root(2,9);
            nth_root(3,27);
            nth_root(2,0.25);

            nth_root(1,123);
            nth_root(2,0);
            nth_root(0,123);
            nth_root(2,1);
            nth_root(-1,5);
            
            nth_root(2, -16);
            nth_root(-3, 0);
            nth_root(-1, 2);
            nth_root(-3, -1);
            nth_root(0, 2);
            nth_root(0, 0);
            nth_root(-10, 2);
            nth_root(-2, 2);
            nth_root(10, 2);
            nth_root(3, 2);
            nth_root(2, 0);
            nth_root(5, 1);
            nth_root(3, -8);
            nth_root(3, 27);
            nth_root(3, 2.5);
            nth_root(2, 4);
            
        }
    } catch(std::domain_error &excpt) {
        std::cout << excpt.what();
    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }

    return 0;
}
