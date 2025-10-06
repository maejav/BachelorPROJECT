#include <iostream>
#include <cstdlib>
using namespace std;

void error(const char *msg) {
    cout << "Error: " << msg << endl;
    exit(0);
}

class Array {
private:
    double *a;
    int n;

public:
    Array() : a(nullptr), n(0) {}

    Array(int value) : n(1) {
        a = new double[1];
        a[0] = value;
    }

    Array(const Array &b) {
        n = b.n;
        a = new double[n];
        for (int i = 0; i < n; i++)
            a[i] = b.a[i];
    }

    ~Array() {
        delete[] a;
    }

    void allocateMemory(int size) {
        a = new double[n = size];
        if (!a) error("Memory allocation failed");
    }

    void input() {
        if (n > 0) {
            delete[] a;
            a = nullptr;
            n = 0;
        }
        cout << "Enter number of terms: ";
        cin >> n;
        allocateMemory(n);
        for (int i = 0; i < n; i++) {
            cout << "Enter a[" << i << "]: ";
            cin >> a[i];
        }
    }

    void print() const {
        for (int i = 0; i < n; i++)
            cout << a[i] << endl;
    }

    Array &operator=(const Array &t) {
        if (this != &t) {
            delete[] a;
            n = t.n;
            a = new double[n];
            for (int i = 0; i < n; i++)
                a[i] = t.a[i];
        }
        return *this;
    }

    friend Array operator+(const Array &a, const Array &b);
    friend Array operator*(const Array &a, const Array &b);
    friend Array operator/(const Array &a, const Array &b);
    friend bool operator<=(const Array &a, const Array &b);
    friend bool operator>=(const Array &a, const Array &b);
};

Array operator+(const Array &a, const Array &b) {
    int maxSize = max(a.n, b.n);
    Array res;
    res.allocateMemory(maxSize);
    int minSize = min(a.n, b.n);
    for (int i = 0; i < minSize; i++)
        res.a[i] = a.a[i] + b.a[i];
    const double *p = (a.n > b.n) ? a.a : b.a;
    for (int i = minSize; i < maxSize; i++)
        res.a[i] = p[i];
    return res;
}

Array operator*(const Array &a, const Array &b) {
    int minSize = min(a.n, b.n);
    Array res;
    res.allocateMemory(minSize);
    for (int i = 0; i < minSize; i++)
        res.a[i] = a.a[i] * b.a[i];
    return res;
}

Array operator/(const Array &a, const Array &b) {
    int minSize = min(a.n, b.n);
    Array res;
    res.allocateMemory(minSize);
    for (int i = 0; i < minSize; i++) {
        if (b.a[i] == 0)
            error("Division by zero");
        res.a[i] = a.a[i] / b.a[i];
    }
    return res;
}

bool operator<=(const Array &a, const Array &b) {
    if (a.n != b.n) return false;
    for (int i = 0; i < a.n; i++)
        if (a.a[i] > b.a[i]) return false;
    return true;
}

bool operator>=(const Array &a, const Array &b) {
    if (a.n != b.n) return false;
    for (int i = 0; i < a.n; i++)
        if (a.a[i] < b.a[i]) return false;
    return true;
}

int main() {
    Array m1, m2, m3, m4;
    m1.input();
    m2.input();
    m3.input();
    m4 = Array(4);

    cout << "m1:\n"; m1.print();
    cout << "m2:\n"; m2.print();
    cout << "m3:\n"; m3.print();
    cout << "m4:\n"; m4.print();

    cout << "m1 = m2 + m4:\n";
    m1 = m2 + m4;
    m1.print();

    cout << "m1 = m2 / m3:\n";
    m1 = m2 / m3;
    m1.print();

    cout << "m1 = m2 * m3:\n";
    m1 = m2 * m3;
    m1.print();

    cout << "m1 <= m2:\n";
    cout << (m1 <= m2 ? "yes <=\n" : "no <=\n");

    cout << "m1 >= m2:\n";
    cout << (m1 >= m2 ? "yes >=\n" : "no >=\n");

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}
