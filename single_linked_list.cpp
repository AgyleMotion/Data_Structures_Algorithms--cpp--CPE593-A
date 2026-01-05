#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    node* link;
};

node* addToEmpty(node* head, int data) {
    if (head != NULL) {
        return head;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    head = temp;
    return head;
}

node* addToEnd(node* head, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;

    if (head == NULL) {
        return temp;
    }

    node* last = head;
    while (last->link != NULL) {
        last = last->link;
    }
    last->link = temp;

    return head;
}

node* addToStart(node* head, int data) {
    node* temp = new node;
    temp->data = data;
    temp->link = head;
    return temp;
}

void print(node* head) {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

int main() {
    node* head = NULL;
    int value;

    cout << "Enter an Integer value to be added to the empty list: ";
    cin >> value;
    head = addToEmpty(head, value);

    cout << "Enter an integer value to be added to the list: ";
    cin >> value;
    head = addToEnd(head, value);

    cout << "Enter an integer value to be added to the beginning of the list: ";
    cin >> value;
    head = addToStart(head, value);

    cout << "The elements of the list are: ";
    print(head);

    return 0;
}
