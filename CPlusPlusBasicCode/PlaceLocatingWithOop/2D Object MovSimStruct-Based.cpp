#include <iostream>
using namespace std;

struct Place {
    int x;
    int y;

    void input() {
        cout << "Enter initial position of the object:\n";
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;
    }

    void move() {
        int dx, dy;
        cout << "Enter movement vector (dx and dy):\n";
        cin >> dx >> dy;
        x += dx;
        y += dy;
    }

    void print() const {
        cout << "Current position: (" << x << ", " << y << ")\n";
    }
};

int main() {
    Place p1;

    p1.input();
    cout << "\nBefore movement:\n";
    p1.print();

    p1.move();
    cout << "\nAfter movement:\n";
    p1.print();

    return 0;
}
