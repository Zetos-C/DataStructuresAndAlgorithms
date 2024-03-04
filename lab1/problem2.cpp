#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Student {
    char name[30];
    char classs[10];
    float mMath;
    float mPhysical;
};

Student *students;
int numStudents;

void addStudent() {
    Student *newStudent = (Student *) malloc(sizeof(Student));
    cout << "Enter name: ";
    cin.getline(newStudent->name, sizeof(newStudent->name));
    cout << "Enter class: ";
    cin.getline(newStudent->classs, sizeof(newStudent->classs));
    cout << "Enter math score: ";
    cin >> newStudent->mMath;
    cout << "Enter physical score: ";
    cin >> newStudent->mPhysical;
    students = (Student *) realloc(students, (numStudents + 1) * sizeof(Student));
    students[numStudents] = *newStudent;
    numStudents++;
}

void searchStudentByName() {
    char name[30];
    cout << "Enter name to search for: ";
    cin.getline(name, sizeof(name));
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            cout << "Name: " << students[i].name << endl;
            cout << "Class: " << students[i].classs << endl;
            cout << "Math Score: " << students[i].mMath << endl;
            cout << "Physical Score: " << students[i].mPhysical << endl;
        }
    }
}

void searchStudentByNameAndEditClass() {
    char name[30];
    char classs[10];
    cout << "Enter name to search for: ";
    cin.getline(name, sizeof(name));
    cout << "Enter new class: ";
    cin.getline(classs, sizeof(classs));
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            strcpy(students[i].classs, classs);
            cout << "Class updated." << endl;
        }
    }
}

int main() {
    students = (Student *) malloc(sizeof(Student));
    numStudents = 0;
    while (true) {
        cout << "1. Add student" << endl;
        cout << "2. Search student by name" << endl;
        cout << "3. Search student by name and edit class" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;
        char a[1];
        cin.getline(a, sizeof(a));
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudentByName();
                break;
            case 3:
                searchStudentByNameAndEditClass();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}