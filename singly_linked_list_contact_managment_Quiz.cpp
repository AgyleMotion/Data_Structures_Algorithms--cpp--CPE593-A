#include <iostream>
#include <cstring>

using namespace std;

// Structure for a single contact
struct Contact {

    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
    char email[100];

    Contact* next;
};

// Function to create a new contact and add it to the linked list, returning the new head
Contact* createAndAddContact( Contact* head) {
    Contact* newContact= (Contact *)malloc(sizeof (Contact));

    cout << " Enter the first name" <<endl;
    cin >>newContact->firstName;
    cout  << " Enter the last name" <<endl;
    cin >> newContact->lastName;
    cout  << " Enter phone number" <<endl;
    cin >> newContact->phoneNumber;
    cout  << " Enter email" <<endl;
    cin >> newContact->email;

    newContact->next=head;
    head=newContact;

    return head;
}

// Function to display all contacts
void displayContacts(Contact* head) {

    if (head == NULL){
        printf("Contact list is empty");
    }

    struct Contact* ptr =NULL;

    ptr =head;
    while (ptr!=NULL){
        cout <<"Name :" <<ptr->firstName<<" " << ptr->lastName <<endl;
        cout <<"phone number : " <<ptr->phoneNumber <<endl;
        cout <<"email : " << ptr->email<< endl;
        ptr =ptr->next;
    }
}
// Function to search for a contact by name
void searchContact(Contact* head, char* name) {
    Contact* ptr = head;
    while (ptr != NULL) {
        if (!strcmp(ptr->firstName, name) || !strcmp(ptr->lastName, name)) {
            cout <<"Name :" <<ptr->firstName<<" " << ptr->lastName <<endl;
            cout <<"phone number : " <<ptr->phoneNumber <<endl;
            cout <<"email : " << ptr->email<< endl;
            // Return a pointer to the found contact
        }
        ptr = ptr->next;
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
