#include <iostream>
#include <cstring>
#define MAX_SIZE 1000

using namespace std;

struct Contact {
    char firstName[50];
    char lastName[50];
    char phone[15];
    char email[100];
};

Contact stack[MAX_SIZE];
int top = -1;

void pushContact(Contact newContact) {
    if (top == MAX_SIZE - 1) {
        cout << " Stack overflow \n";
        return;
    }
    cout << "Enter First Name: ";
    cin >> newContact.firstName;

    cout << "Enter Last Name: ";
    cin >> newContact.lastName;

    cout << "Enter Phone Number: ";
    cin >> newContact.phone;

    cout << "Enter email: ";
    cin >> newContact.email;

    top = top + 1;
    stack[top] = newContact;
}

void searchContactByName(char* searchName) {
    for (int i = top; i >= 0; i--) {
        if (!strcmp(stack[i].firstName, searchName) || !strcmp(stack[i].lastName, searchName)) {
            cout << "Name: " << stack[i].firstName << " " << stack[i].lastName << endl;
            cout << "Phone number: " << stack[i].phone << endl;
            cout << "Email: " << stack[i].email << endl;
        }
    }
}

Contact pop() {
    Contact value;
    if (top == -1) {
        cout << "Stack underflow \n";
        // exit(1);
        return value;  // Return an empty contact
    }
    value = stack[top];
    top = top - 1;
    return value;
}

void displayContacts() {
    if (top == -1) {
        cout << "Stack underflow \n" << endl;
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << stack[i].firstName << " " << stack[i].lastName << endl;
        cout << stack[i].phone << endl;
        cout << stack[i].email << endl;
    }
    cout << endl;
}

int main() {
    int choice;
    char searchName[50];
    Contact newContact;
    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact \n";
        cout << "4. Delete Contact \n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pushContact(newContact);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                cout << "Enter the name to search for: ";
                cin >> searchName;
                searchContactByName(searchName);
                break;

            case 4:
                cout << "Delete Contact ";
                pop();
                break;
            case 5 :
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}




