#include <iostream>
using namespace std;

struct Student {
    char name[20];
    float GPA;
};

Student current;
Student topStudent = {'\0', -1};
Student tiedStudents[2];
int hasTie = 0;
int tieIndex = 0;

void insert(Student& max) {
    cout << "Enter student name:\n";
    cin >> current.name;
    cout << "Enter GPA:\n";
    cin >> current.GPA;

    if (current.GPA > max.GPA) {
        max = current;
        hasTie = 0;
        tieIndex = 0;
    } else if (current.GPA == max.GPA) {
        hasTie = 1;
        tiedStudents[tieIndex++] = current;
    }
}

int main() {
    for (int i = 0; i < 3; ++i) {
        insert(topStudent);
    }

    cout << "\nTop student:\n" << topStudent.name << "\nGPA: " << topStudent.GPA << "\n";

    if (hasTie) {
        cout << "\nOther students with the same GPA:\n";
        for (int i = 0; i < tieIndex; ++i) {
            cout << tiedStudents[i].name << "\nGPA: " << tiedStudents[i].GPA << "\n";
        }
    }

    return 0;
}
