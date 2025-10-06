#include <iostream>
#include <cstdlib>
using namespace std;

void error(const char *msg) {
    cout << msg << "\n";
    exit(0);
}

class Array {
private:
    double *a;
    int n;

public:
    // Default constructor
    Array() : a(nullptr), n(0) {}

    // Constructor with one value
    Array(double value) : n(1) {
        a = new double[1];
        a[0] = value;
    }

    // Copy constructor
    Array(const Array &other) {
        n = other.n;
        a = new double[n];
        for (int i = 0; i < n; ++i)
            a[i] = other.a[i];
    }

    // Assignment operator
    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] a;
            n = other.n;
            a = new double[n];
            for (int i = 0; i < n; ++i)
                a[i] = other.a[i];
        }
        return *this;
    }

    // Input method
    void input() {
        cout << "Enter number of elements: ";
        cin >> n;
        if (n <= 0)
            error("Invalid size!");
        a = new double[n];
        cout << "Enter " << n << " numbers:\n";
        for (int i = 0; i < n; ++i) {
            cout << "a[" << i << "]: ";
            cin >> a[i];
        }
    }

    // Print method
    void print() const {
        if (n == 0) {
            cout << "(empty array)\n";
            return;
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << "\n";
    }

    // Destructor
    ~Array() {
        delete[] a;
    }
};

int main() {
    Array m1, m2(2), m3(3), m4;
    m4 = Array(4);  // Assign a single value using constructor

    m1.input();

    cout << "m1:\n";
    m1.print();

    cout << "m2:\n";
    m2.print();

    cout << "m3:\n";
    m3.print();

    cout << "m4:\n";
    m4.print();

    return 0;
}
