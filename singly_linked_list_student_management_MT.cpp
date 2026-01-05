#include <iostream>
#include <string>

using namespace std;
// define student structure
struct Student {
    string firstName;
    string lastName;
    int rollNumber;
    float gpa;
    Student* next;
};
// add student function
Student* addStudent(Student* head) {
    Student* newStudent = new Student;

    cout << "Enter first name: ";
    cin >> newStudent->firstName;
    cout << "Enter last name: ";
    cin >> newStudent->lastName;
    cout << "Enter roll number: ";
    cin >> newStudent->rollNumber;
    cout << "Enter GPA: ";
    cin >> newStudent->gpa;

    newStudent->next = head;
    head = newStudent;
    cout << "Student added successfully"<<endl;
    return head;
}

// remove student
void removeStudent(Student* head, int roll_Number) {
    Student* current = head;
    Student* prev = nullptr;

    while (current && current->rollNumber != roll_Number) {
        prev = current;
        current = current->next;
    }

    if (!current){
        cout << " student not found" <<endl;
        return;
    }  // Student not found

    if (!prev) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    cout << " Student removed successfully" <<endl;
    delete current;
}


void calculateAverageGPA(Student* head) {
    if (!head) {
        cout << "GPA cannot be calculated, Student list is empty!" << endl;
        return;
    }

    float gpaSum = 0.0;
    int studentCount = 0;
    Student* temp = head;

    while (temp) {
        gpaSum += temp->gpa;
        studentCount++;
        temp = temp->next;
    }

    cout << "Average GPA: " << gpaSum / studentCount << endl;
    cout << endl;
}

void displayStudents(Student* head) {
    if (!head) {
        cout << "Student list is empty" << endl;
        return;
    }

    Student* temp = head;
    while (temp) {
        cout << temp->firstName << " " << temp->lastName << endl;
        cout << "Roll Number: " << temp->rollNumber << endl;
        cout << "GPA: " << temp->gpa << endl << endl;
        temp = temp->next;
    }
}

int main() {
    Student* students = nullptr;
    int choice;
    int roll_Number;

    while (true) {
        cout << "\nStudent list \n";
        cout << "1. Add a student \n";
        cout << "2. Remove a student\n";
        cout << "3. Display all students\n";
        cout << "4. Calculate the average GPA of all students \n";
        cout << "5. Quit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                students = addStudent(students);
                break;
            case 2:
                cout << "Enter Roll Number: ";
                cin >> roll_Number;
                removeStudent(students, roll_Number);
                break;
            case 3:
                displayStudents(students);
                break;
            case 4:
                calculateAverageGPA(students);
                break;
            case 5:
                return 0;  // Exit the program

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
