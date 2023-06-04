#include <iostream>
#include <limits>

int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check for integer overflow/underflow
        if (reversed > std::numeric_limits<int>::max() / 10 || (reversed == std::numeric_limits<int>::max() / 10 && digit > 7))
            return 0;
        if (reversed < std::numeric_limits<int>::min() / 10 || (reversed == std::numeric_limits<int>::min() / 10 && digit < -8))
            return 0;

        reversed = reversed * 10 + digit;
    }

    return reversed;
}

int main() {
    int x = 123; // Example input

    int reversed = reverse(x);

    std::cout << "Input: " << x << std::endl;
    std::cout << "Reversed: " << reversed << std::endl;

    return 0;
}
