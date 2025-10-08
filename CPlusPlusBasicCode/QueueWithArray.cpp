#include <iostream>
using namespace std;

#define SIZE 100
int num_m = 0;
int num_f = 0;

class Queue {
private:
    int front;
    int rear;
    int a[SIZE];

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool empty() {
        return rear < front;
    }

    void insert(int x, int& overflow) {
        if (rear == SIZE - 1)
            overflow = 1;
        else {
            overflow = 0;
            a[++rear] = x;
        }
    }

    void del(int& x, int& underflow) {
        if (empty())
            underflow = 1;
        else {
            underflow = 0;
            x = a[front++];
        }
    }

    void print() {
        for (int i = front; i <= rear; ++i)
            cout << a[i] << "\t";
        cout << "\n";
    }
};

int main() {
    Queue female, male;
    char turn = 'm';
    char action, gender;
    bool running = true;
    int x = 1, overflow, underflow;

    while (running) {
        cout << "\nMenu:\n";
        cout << "Insert into queue: 'e'\n";
        cout << "Serve next person: 'n'\n";
        cout << "Show queue counts: 's'\n";
        cout << "Exit: 'x'\n";
        cin >> action;

        switch (action) {
        case 'e':
            cout << "Gender? (f = female, m = male): ";
            cin >> gender;
            if (gender == 'm') {
                male.insert(x++, overflow);
                num_m++;
            } else if (gender == 'f') {
                female.insert(x++, overflow);
                num_f++;
            }
            break;

        case 's':
            cout << "Number of males: " << num_m << "\n";
            cout << "Number of females: " << num_f << "\n";
            break;

        case 'n':
            if (turn == 'm') {
                if (!male.empty()) {
                    male.del(x, underflow);
                    num_m--;
                    turn = 'f';
                } else if (!female.empty()) {
                    female.del(x, underflow);
                    num_f--;
                    turn = 'm';
                } else {
                    cout << "Both queues are empty!\n";
                }
            } else {
                if (!female.empty()) {
                    female.del(x, underflow);
                    num_f--;
                    turn = 'm';
                } else if (!male.empty()) {
                    male.del(x, underflow);
                    num_m--;
                    turn = 'f';
                } else {
                    cout << "Both queues are empty!\n";
                }
            }
            break;

        case 'x':
            cout << "End of program!\n";
            running = false;
            break;

        default:
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
