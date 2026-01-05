#include <iostream>
#include <cstring>
using namespace std;

struct Contact{
    char firstName[50];
    char lastName[50];
    char phone[15];
    char email[100];
    Contact* link;
};

Contact* createAndAddContact( Contact* head){

    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    // new contact data
    cout << "Enter the first name" <<endl;
    cin>> newContact->firstName;
    cout << "Enter the last name" <<endl;
    cin>> newContact->lastName;
    cout << "Enter phone number" <<endl;
    cin>> newContact->phone;
    cout << "Enter email address" <<endl;
    cin>> newContact->email;

    newContact->link = head;
    head = newContact;
    return head;
}

void displayContacts(Contact* head) {
    if (head == NULL) {
        cout << "Contact list is empty" << endl;
        return;
    }
    Contact* temp = head;
    while (temp != NULL) {
        cout << temp->firstName << " " << temp->lastName <<endl;
        cout << temp->phone <<endl;
        cout << temp->email <<endl;
        temp = temp->link;
    }
    cout << endl;
}

void searchContact(Contact* head, char* name) {

    Contact* ptr = head;
    while (ptr != NULL) {
        if (!strcmp(ptr->firstName, name) || !strcmp(ptr->lastName, name)) {
            cout <<"Name :" <<ptr->firstName<<" " << ptr->lastName <<endl;
            cout <<"phone number : " <<ptr->phone <<endl;
            cout <<"email : " << ptr->email<< endl;
            // Return a pointer to the found contact
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
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                contacts = createAndAddContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                cout << "Enter the name to search for: ";
                cin >> searchName;
                searchContact(contacts, searchName);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
