#include <iostream>

using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* addToEmpty(node* head, int data ){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    head = temp;
    return head;
}

node* addAtEnd(node* head, int data ){
    node* ptr;
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    ptr =head;
    while (ptr -> next != NULL){
        ptr = ptr->next;
    }
    ptr->next =temp;
    temp -> prev = ptr;
    return head;
}

node* addAtBegining(node* head, int data ){
    node* ptr;
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head =temp;
    return head;
}

node* insertAfterPos(node* head, int data, int position){
    node* ptr1, *ptr2;
    node* temp = NULL;
    ptr1 = head;
    ptr2 = head;

    temp = addToEmpty(temp, data);

    while (position !=1) {
        ptr1 = ptr1->next;
        position --;
    }
    ptr2 =ptr1->next;

    ptr1->next = temp;
    ptr2->prev = temp;

    temp->next = ptr2;
    temp->prev = ptr1;

    return head;
}

node* del_First (node* head){
    node* temp =head;
    head=head->next;
    free(temp);
    temp =NULL;
    head->prev = NULL;
    return head;
}

node* del_LAST (node* head){
    node* temp =head;
    node* temp2 ;
    while (temp->next !=NULL) {
        temp =temp->next;
    }
    temp2 = temp->prev;
    temp2->next =NULL;


    free(temp);
    temp =NULL;
    return head;
}




int main() {

    node* head =NULL;
    head = addToEmpty(head,10);
    return 0;
}