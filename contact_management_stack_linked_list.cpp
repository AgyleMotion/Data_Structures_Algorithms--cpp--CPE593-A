#include <iostream>
#include<cstring>
#define MAX_SIZE 1000

using namespace std;

struct Contact {
    char firstName[50];
    char lastName[50];
    char phone[15];
    char email[100];
    Contact* link;
};
Contact *top = NULL;


void pushContact(Contact* newContact) {
    Contact * newCon = (Contact* )malloc(sizeof(Contact));
    if (newCon == NULL){
        cout << " Memory allocation failed";
        exit (1);
    }
    cout << " Enter the first name" <<endl;
    cin >>newCon->firstName;
    cout  << " Enter the last name" <<endl;
    cin >> newCon->lastName;
    cout  << " Enter phone number" <<endl;
    cin >> newCon->phone;
    cout  << " Enter email" <<endl;
    cin >> newCon->email;

    newCon->link=top;
    top=newCon;
}
int isEmpty(){
    if (top ==NULL)
        return 1;
    else
        return 0;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack underflow";
        exit(1);
    }
    Contact* temp = top;
    top = top->link;
    delete temp;
}

Contact peek() {
    if (isEmpty()) {
        cout << "Stack is empty";
        exit(1);
    }
    return *top;
}
void displayContacts() {
    Contact* temp;
    temp = top;
    if (isEmpty()){
        cout << " Stack underflow";
        exit(1);
    }
    cout << " stack elements are:";
    while (temp != NULL){
        void printContacts() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }

            Contact* temp = top;
            while (temp != NULL) {
                cout << "First Name: " << temp->firstName << endl;
                cout << "Last Name: " << temp->lastName << endl;
                cout << "Phone Number: " << temp->phone << endl;
                cout << "Email: " << temp->email << endl;
                cout << "----------------------" << endl;
                temp = temp->link;
            }
        }
    }
}

void searchContact(char* name) {
    Contact* ptr = top;
    while (ptr != NULL) {
        if (!strcmp(ptr->firstName, name) || !strcmp(ptr->lastName, name)) {
            cout << "Name: " << ptr->firstName << " " << ptr->lastName << endl;
            cout << "Phone number: " << ptr->phone << endl;
            cout << "Email: " << ptr->email << endl;
        }
        ptr = ptr->link;
    }
}


int main() {

    Contact* contacts = nullptr;
    int choice;
    char searchName[50];

    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. pop Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                 pushContact(contacts);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                cout << "Enter the name to search for: ";
                cin >> searchName;
                searchContact( searchName);
                break;
            case 4:
                pop();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}