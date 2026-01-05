
/*
 * Single Linked List
 * ******************
 * By Mohamed Eraky
 * ******************
 * */

#include <iostream>

using namespace std;

struct node {
    int data;
    node* link;
};

node* addToEmpty(node* head, int data ){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    head = temp;
    return head;
}

int main() {
    node* head =NULL;
    head = addToEmpty(head,10);
    return 0;
}