#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxConsecutiveOnes = 0;
    int currentConsecutiveOnes = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            currentConsecutiveOnes++;
            if (currentConsecutiveOnes > maxConsecutiveOnes) {
                maxConsecutiveOnes = currentConsecutiveOnes;
            }
        } else {
            currentConsecutiveOnes = 0;
        }
        n /= 2;
    }

    cout << maxConsecutiveOnes << endl;

    return 0;
}
