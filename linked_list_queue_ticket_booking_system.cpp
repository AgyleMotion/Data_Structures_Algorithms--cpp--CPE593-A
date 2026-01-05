#include <iostream>
#include <string>

using namespace std;

struct Contact {
    string customerName;
    Contact* link;
};

Contact *front = NULL;
Contact *rear  = NULL;

bool isEmpty() {
    return front == NULL;
}

void enqueue(string newContact) {
    Contact* temp = new Contact;
    if (!temp) {
        cout << "Memory allocation failed";
        exit(1);
    }
    temp->customerName = newContact;
    temp->link = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow.\n";
        exit(1);
    }
    Contact* temp = front;
    front = front->link;
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

void cancelReservation(string customerName) {
    if (isEmpty()) return;

    Contact *prev = NULL, *current = front;
    while (current && current->customerName != customerName) {
        prev = current;
        current = current->link;
    }

    if (current) {
        if (!prev) {
            dequeue();
        } else {
            prev->link = current->link;
            if (current == rear) {
                rear = prev;
            }
            delete current;
        }
    } else {
        cout << "Reservation not found.\n";
    }
}

void display() {
    Contact* temp = front;
    while (temp) {
        cout << temp->customerName << " ,  ";
        temp = temp->link;
    }
    cout << "End" << endl;
}

bool checkAvailability(string customerName) {
    Contact* temp = front;
    while (temp) {
        if (temp->customerName == customerName) {
            return true;
        }
        temp = temp->link;
    }
    return false;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

int getQueueSize() {
    int count = 0;
    Contact* temp = front;
    while (temp) {
        count++;
        temp = temp->link;
    }
    return count;
}

void peekFront() {
    if (front) {
        cout << "Front: " << front->customerName << endl;
    } else {
        cout << "Queue is empty." << endl;
    }
}

void peekRear() {
    if (rear) {
        cout << "Rear: " << rear->customerName << endl;
    } else {
        cout << "Queue is empty." << endl;
    }
}

int main() {
    int choice;
    string customerName;
    cout << "Welcome to the Movie Theater Ticket Booking System!" << endl;
    do {
        cout << "\n1. Book a ticket\n2. Cancel a reservation\n3. Display reservations\n";
        cout << "4. Check availability\n5. Clear all reservations\n6. Get queue size\n";
        cout << "7. Peek at front\n8. Peek at rear\n9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> customerName;
                enqueue(customerName);
                break;
            case 2:
                cout << "Enter customer name to cancel: ";
                cin >> customerName;
                cancelReservation(customerName);
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Enter customer name to check availability: ";
                cin >> customerName;
                if (checkAvailability(customerName)) {
                    cout << "Reservation found for " << customerName << endl;
                } else {
                    cout << "No reservation found for " << customerName << endl;
                }
                break;
            case 5:
                clearQueue();
                cout << "All reservations cleared." << endl;
                break;
            case 6:
                cout << "Queue size: " << getQueueSize() << " reservations." << endl;
                break;
            case 7:
                peekFront();
                break;
            case 8:
                peekRear();
                break;
            case 9:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);
    return 0;
}

