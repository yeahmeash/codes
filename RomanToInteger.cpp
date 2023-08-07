#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanToIntMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        int currentValue = romanToIntMap[s[i]];
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }
        prevValue = currentValue;
    }

    return result;
}

int main() {
    string romanNumeral = "MCMXCIV";  // Example input
    int result = romanToInt(romanNumeral);
    cout << "Integer equivalent: " << result << endl;
    return 0;
}


/*  
Certainly! Let's walk through the "Roman to Integer" algorithm using the example input "MCMXCIV."

The Roman numeral "MCMXCIV" represents the integer 1994. Here's how the algorithm converts it step by step:

Initialize the romanToIntMap map that maps each Roman numeral character to its corresponding integer value.

Initialize the result variable to store the final integer result and the prevValue variable to keep track of the value of the previous Roman numeral.

Iterate through the Roman numeral string from right to left:

The last numeral is 'V'. Its value is 5. Since it's greater than the previous value of 0, we add 5 to the result, making it 5. Set prevValue to 5.
The next numeral is 'I'. Its value is 1. Since it's smaller than the previous value of 5, we subtract 1 from the result, making it 4. Set prevValue to 1.
The next numeral is 'C'. Its value is 100. Since it's greater than the previous value of 1, we add 100 to the result, making it 104. Set prevValue to 100.
The last numeral is 'M'. Its value is 1000. Since it's greater than the previous value of 100, we add 1000 to the result, making it 1104. Set prevValue to 1000.
The final integer value is 1104, which corresponds to the Roman numeral "MCMXCIV."

The algorithm correctly converts the Roman numeral "MCMXCIV" to the integer 1104*/
