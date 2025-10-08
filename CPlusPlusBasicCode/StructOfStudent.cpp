#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char name[20];
    float moadel;
};

Student topStudent = {"", -1};
Student tiedStudents[10]; // supports up to 10 ties
int tieCount = 0;

void insert(Student& max) {
    Student temp;
    cout << "Enter student name: ";
    cin >> temp.name;
    cout << "Enter GPA: ";
    cin >> temp.moadel;

    if (temp.moadel > max.moadel) {
        max = temp;
        tieCount = 0; // reset tie list
    } else if (temp.moadel == max.moadel) {
        tiedStudents[tieCount++] = temp;
    }
}

int main() {
    for (int i = 0; i < 3; ++i) {
        insert(topStudent);
    }

    cout << "\nTop student:\n";
    cout << topStudent.name << " - GPA: " << topStudent.moadel << "\n";

    if (tieCount > 0) {
        cout << "\nOther students with same GPA:\n";
        for (int i = 0; i < tieCount; ++i) {
            cout << tiedStudents[i].name << " - GPA: " << tiedStudents[i].moadel << "\n";
        }
    }

    return 0;
}
