#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

void error(const char* msg) {
    cout << msg << "\n";
    getch();
    exit(1);
}

class Poly {
private:
    double* coe;
    int* exp;
    int n;

public:
    // Default constructor
    Poly() : coe(nullptr), exp(nullptr), n(0) {}

    // Parameterized constructor
    Poly(int value) {
        n = 1;
        coe = new double[n];
        exp = new int[n];
        coe[0] = value;
        exp[0] = value;
    }

    // Copy constructor
    Poly(const Poly& other) {
        n = other.n;
        coe = new double[n];
        exp = new int[n];
        for (int i = 0; i < n; ++i) {
            coe[i] = other.coe[i];
            exp[i] = other.exp[i];
        }
    }

    // Assignment operator
    Poly& operator=(const Poly& other) {
        if (this != &other) {
            delete[] coe;
            delete[] exp;
            n = other.n;
            coe = new double[n];
            exp = new int[n];
            for (int i = 0; i < n; ++i) {
                coe[i] = other.coe[i];
                exp[i] = other.exp[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Poly() {
        delete[] coe;
        delete[] exp;
        coe = nullptr;
        exp = nullptr;
        n = 0;
    }

    void input() {
        cout << "Enter number of terms: ";
        cin >> n;
        if (n <= 0) error("Invalid number of terms");

        coe = new double[n];
        exp = new int[n];
        if (!coe || !exp) error("Memory allocation failed");

        for (int i = 0; i < n; ++i) {
            cout << "Enter coefficient[" << i << "]: ";
            cin >> coe[i];
            cout << "Enter exponent[" << i << "]: ";
            cin >> exp[i];
        }
    }

    void display() const {
        for (int i = 0; i < n; ++i) {
            if (coe[i] == 0) continue;

            if (i > 0 && coe[i] > 0) cout << "+";
            cout << coe[i];

            if (exp[i] != 0) {
                cout << "x";
                if (exp[i] != 1) cout << "^" << exp[i];
            }
        }
        cout << "\n";
    }

    // Friend function for addition
    friend Poly operator+(const Poly& a, const Poly& b) {
        Poly result;
        result.n = a.n + b.n;
        result.coe = new double[result.n];
        result.exp = new int[result.n];

        int r = 0;
        // Add matching exponents
        for (int i = 0; i < a.n; ++i) {
            for (int j = 0; j < b.n; ++j) {
                if (a.exp[i] == b.exp[j]) {
                    result.coe[r] = a.coe[i] + b.coe[j];
                    result.exp[r] = a.exp[i];
                    ++r;
                }
            }
        }

        // Add unmatched terms from a
        for (int i = 0; i < a.n; ++i) {
            bool found = false;
            for (int j = 0; j < r; ++j) {
                if (a.exp[i] == result.exp[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.coe[r] = a.coe[i];
                result.exp[r] = a.exp[i];
                ++r;
            }
        }

        // Add unmatched terms from b
        for (int i = 0; i < b.n; ++i) {
            bool found = false;
            for (int j = 0; j < r; ++j) {
                if (b.exp[i] == result.exp[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.coe[r] = b.coe[i];
                result.exp[r] = b.exp[i];
                ++r;
            }
        }

        result.n = r;
        return result;
    }

    // Friend function for multiplication
    friend Poly operator*(const Poly& a, const Poly& b) {
        Poly result;
        result.n = a.n * b.n;
        result.coe = new double[result.n];
        result.exp = new int[result.n];

        int r = 0;
        for (int i = 0; i < a.n; ++i) {
            for (int j = 0; j < b.n; ++j) {
                result.coe[r] = a.coe[i] * b.coe[j];
                result.exp[r] = a.exp[i] + b.exp[j];
                ++r;
            }
        }

        // Merge like terms
        for (int i = 0; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                if (result.exp[i] == result.exp[j]) {
                    result.coe[i] += result.coe[j];
                    for (int k = j; k < r - 1; ++k) {
                        result.coe[k] = result.coe[k + 1];
                        result.exp[k] = result.exp[k + 1];
                    }
                    --r;
                    --j;
                }
            }
        }

        result.n = r;
        return result;
    }
};

int main() {
    Poly p1(3); // single-term polynomial
    Poly p2, p3;

    p2.input();
    p3.input();

    cout << "p1:\n"; p1.display();
    cout << "p2:\n"; p2.display();
    cout << "p3:\n"; p3.display();

    p1 = p2 + p3;
    cout << "p1 = p2 + p3:\n"; p1.display();

    p1 = p2 * p3;
    cout << "p1 = p2 * p3:\n"; p1.display();

    system("PAUSE");
    return 0;
}
