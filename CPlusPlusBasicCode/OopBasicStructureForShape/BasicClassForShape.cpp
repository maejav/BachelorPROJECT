#include <iostream>
using namespace std;

class Shape {
private:
    string name;
    string color;
    int length;

public:
    // Default constructor
    Shape() {
        length = 0;
        name = "shape";
        color = "";
    }

    // Constructor with length only
    Shape(int a) {
        length = a;
        name = "shape";
        color = "";
    }

    // Constructor with length and name
    Shape(int a, string n) {
        length = a;
        name = n;
        color = "";
    }

    // Constructor with length, color, and name
    Shape(int a, string c, string n) {
        length = a;
        color = c;
        name = n;
    }

    // Copy constructor (by reference, not pointer)
    Shape(const Shape& sh) {
        length = sh.length;
        name = sh.name;
        color = sh.color;
    }

    int area() const {
        return length * length;
    }

    void show() const {
        cout << "This shape is a square named '" << name
             << "' with color '" << color
             << "' and length " << length << ".\n";
    }
};

int main() {
    Shape s;                    // ✅ Default constructor
    Shape sh1(2);               // ✅ Constructor with length
    Shape sh2(2, "abc");        // ✅ Constructor with length and name
    Shape sh3(2, "red", "box"); // ✅ Constructor with length, color, and name
    Shape sh4(sh3);             // ✅ Copy constructor

    s.show();
    sh1.show();
    sh2.show();
    sh3.show();
    sh4.show();

    cout << "Area of sh3: " << sh3.area() << "\n";

    return 0;
}
