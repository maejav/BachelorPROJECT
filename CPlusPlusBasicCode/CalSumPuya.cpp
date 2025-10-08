#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n, sum = 0;
        cout << "How many numbers do you want to enter? ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid size. Try again.\n";
            continue;
        }

        int* p = new int[n];

        for (int i = 0; i < n; ++i) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> p[i];
            sum += p[i];
        }

        cout << "Sum: " << sum << "\n";

        delete[] p;

        char ch;
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
        if (ch == 'n' || ch == 'N') break;
    }

    return 0;
}
