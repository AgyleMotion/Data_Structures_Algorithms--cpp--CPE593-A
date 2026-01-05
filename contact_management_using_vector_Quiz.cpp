#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
};

class ContactsManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact() {
        Contact newContact;
        std::cout << "Enter First Name: ";
        std::cin >> newContact.firstName;
        std::cout << "Enter Last Name: ";
        std::cin >> newContact.lastName;
        std::cout << "Enter Phone Number: ";
        std::cin >> newContact.phoneNumber;
        std::cout << "Enter Email Address: ";
        std::cin >> newContact.email;
        contacts.push_back(newContact);
        std::cout << "Contact added successfully." << std::endl;
    }

    void displayContacts() {
        for (const Contact& c : contacts) {
            std::cout << "First Name: " << c.firstName << std::endl;
            std::cout << "Last Name: " << c.lastName << std::endl;
            std::cout << "Phone Number: " << c.phoneNumber << std::endl;
            std::cout << "Email Address: " << c.email << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }

    void searchContact() {
        std::string name;
        std::cout << "Enter the name to search for: ";
        std::cin >> name;
        bool found = false;
        for (const Contact& c : contacts) {
            if (c.firstName == name || c.lastName == name) {
                found = true;
                std::cout << "Contact found:" << std::endl;
                std::cout << "First Name: " << c.firstName << std::endl;
                std::cout << "Last Name: " << c.lastName << std::endl;
                std::cout << "Phone Number: " << c.phoneNumber << std::endl;
                std::cout << "Email Address: " << c.email << std::endl;
                break;
            }
        }
        if (!found) {
            std::cout << "Contact not found." << std::endl;
        }
    }

    void displayMenu() {
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Exit" << std::endl;
    }
};

int main() {
    ContactsManager manager;
    int choice;
    do {
        manager.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                manager.addContact();
                break;
            case 2:
                manager.displayContacts();
                break;
            case 3:
                manager.searchContact();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please select a valid option." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
