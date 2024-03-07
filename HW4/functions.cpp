#include <iostream>
#include <stdexcept>
#include <limits>

int Largest(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

bool SumIsEven(int a, int b) {
    return ((a + b) % 2 == 0);
}

int BoxesNeeded(int apples) {
    if (apples <= 0) return 0;
    return (apples + 19) / 20;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
    if (A_total <= 0 || B_total <= 0 || A_correct < 0 || B_correct < 0) {
        throw std::invalid_argument("Total number of students must be greater than 0.");
    }
    double A_percentage = static_cast<double>(A_correct) / A_total;
    double B_percentage = static_cast<double>(B_correct) / B_total;
    return A_percentage > B_percentage;
}

bool GoodDinner(int pizzas, bool is_weekend) {
    if (is_weekend) {
        return pizzas >= 10;
    } else {
        return pizzas >= 10 && pizzas <= 20;
    }
}


int SumBetween(int low, int high) {
    if (low > high) throw std::invalid_argument("Low must be less than or equal to high");

    long long n = static_cast<long long>(high) - low + 1;
    long long sum = n * (static_cast<long long>(low) + high) / 2;

    if (sum > std::numeric_limits<int>::max() || sum < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Integer overflow detected");
    }

    return static_cast<int>(sum);
}

int Product(int a, int b) {
    if (a > 0 && b > 0 && std::numeric_limits<int>::max() / a < b) throw std::overflow_error("Integer overflow detected");
    if (a > 0 && b < 0 && std::numeric_limits<int>::min() / a > b) throw std::overflow_error("Integer overflow detected");
    if (a < 0 && b > 0 && std::numeric_limits<int>::min() / b > a) throw std::overflow_error("Integer overflow detected");
    if (a < 0 && b < 0 && std::numeric_limits<int>::max() / a > b) throw std::overflow_error("Integer overflow detected");
    return a * b;
}
