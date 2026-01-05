#include <iostream>
#include <cstring>
#include <string>

#define MAX_SIZE 1000

using namespace std;

string queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if (rear == MAX_SIZE-1) return 1;
    else return 0;
}

int isEmpty() {
    if (front == -1 || front == rear + 1) return 1;
    else return 0;
}

void enqueue(string newContact) {
    if (isFull()) {
        cout << "Queue overflow\n";
        exit(1);
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = newContact;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        exit(1);
    }
    front++;
}

void cancelReservation(string customerName) {
    if (isEmpty()) return;

    int foundIndex = -1;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == customerName) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
    } else {
        cout << "Reservation not found.\n";
    }
}

bool checkAvailability(string customerName) {
    for (int i = front; i <= rear; i++) {
        if (queue[i] == customerName) {
            cout << "Reservation for " << customerName << " exists\n";
            return true;
        }
    }
    cout << "Reservation for " << customerName << " doesn't exist\n";
    return false;
}

void display() {
    if (isEmpty()) {
        cout << "No reservations currently.\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << endl;
    }
}

void clearQueue() {
    front = -1;
    rear = -1;
}

int getQueueSize() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void peekFront() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front of queue: " << queue[front] << endl;
}

void peekRear() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Rear of queue: " << queue[rear] << endl;
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
                checkAvailability(customerName);

                break;
            case 5:
                clearQueue();
                break;
            case 6:
                cout << "Queue size: " << getQueueSize() << "reservations." << endl;
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
