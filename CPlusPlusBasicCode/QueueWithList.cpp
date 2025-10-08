#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int info;
    Node* next;

    Node(int val) : info(val), next(nullptr) {}
};

class Queue {
private:
    Node* first;
    Node* last;
    string name;

public:
    Queue(string queueName) : first(nullptr), last(nullptr), name(queueName) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!first) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    void remove() {
        if (isEmpty()) {
            cout << "Queue is empty for: " << name << "\n";
            return;
        }
        Node* temp = first;
        first = first->next;
        if (!first) last = nullptr;
        delete temp;
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    int count() const {
        int total = 0;
        for (Node* ptr = first; ptr != nullptr; ptr = ptr->next)
            total++;
        return total;
    }

    void print() const {
        cout << "Queue for " << name << ": ";
        for (Node* ptr = first; ptr != nullptr; ptr = ptr->next)
            cout << ptr->info << " ";
        cout << "\n";
    }
};

int main() {
    Queue male("males"), female("females");
    int maleCount = 0, femaleCount = 0;
    char action, gender, turn = 'm';
    bool running = true;

    while (running) {
        cout << "\nMenu:\n";
        cout << "Insert into queue: 'e'\n";
        cout << "Serve next person: 'n'\n";
        cout << "Show queue counts: 's'\n";
        cout << "Exit: 'x'\n";
        cin >> action;

        switch (action) {
        case 'e':
            cout << "Enter gender (m/f): ";
            cin >> gender;
            if (gender == 'm') {
                male.insert(++maleCount);
            } else if (gender == 'f') {
                female.insert(++femaleCount);
            } else {
                cout << "Invalid gender input.\n";
            }
            break;

        case 'n':
