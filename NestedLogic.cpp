Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:

If the book is returned on or before the expected return date, no fine will be charged (i.e.: .
If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, .
If the book is returned after the expected return month but still within the same calendar year as the expected return date, the .
If the book is returned after the calendar year in which it was expected, there is a fixed fine of .
Input Format

The first line contains  space-separated integers denoting the respective , , and  on which the book was actually returned.
The second line contains  space-separated integers denoting the respective , , and  on which the book was expected to be returned (due date).

Constraints

Output Format

Print a single integer denoting the library fine for the book received as input.

Sample Input

9 6 2015
6 6 2015
Sample Output

45


#include <iostream>
using namespace std;

int main() {
    int returnDay, returnMonth, returnYear;
    int dueDay, dueMonth, dueYear;

    // Input actual return date
    cin >> returnDay >> returnMonth >> returnYear;
    
    // Input expected return date
    cin >> dueDay >> dueMonth >> dueYear;
    
    // Check if the book is returned on or before the expected return date
    if (returnYear < dueYear || (returnYear == dueYear && returnMonth < dueMonth) || (returnYear == dueYear && returnMonth == dueMonth && returnDay <= dueDay)) {
        cout << "0" << endl; // No fine is charged
    } 
    // Check if the book is returned after the expected return month but within the same year
    else if (returnYear == dueYear && returnMonth > dueMonth) {
        int monthsLate = returnMonth - dueMonth;
        cout << monthsLate * 500 << endl; // Fine per month is 500
    } 
    // Check if the book is returned after the expected return year
    else if (returnYear > dueYear) {
        cout << "10000" << endl; // Fixed fine for returning after the calendar year
    } 
    // Check if the book is returned after the expected return day but within the same month
    else if (returnYear == dueYear && returnMonth == dueMonth && returnDay > dueDay) {
        int daysLate = returnDay - dueDay;
        cout << daysLate * 15 << endl; // Fine per day is 15
    }

    return 0;
}
