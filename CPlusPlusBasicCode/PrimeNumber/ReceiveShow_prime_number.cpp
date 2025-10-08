#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int p) {
    if (p < 2) return false;
    for (int i = 2; i * i <= p; ++i) {
        if (p % i == 0)
            return false;
    }
    return true;
}

int main() {
    int a, b;
    cout << "Enter range to find prime numbers:\n";
    cout << "Start (a): ";
    cin >> a;
    cout << "End (b): ";
    cin >> b;

    if (a > b) {
        cout << "Invalid range. 'a' should be less than or equal to 'b'.\n";
        return 1;
    }

    cout << "\nPrime numbers between " << a << " and " << b << ":\n";
    for (int i = a; i <= b; ++i) {
        if (isPrime(i))
            cout << i << "\n";
    }

    return 0;
}
