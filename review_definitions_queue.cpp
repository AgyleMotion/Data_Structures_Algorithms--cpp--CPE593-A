#include <iostream>
using namespace std;

/*
 * Queue is a linear collection of data types
 * allows insertion at one end and deletion at another
 * Rear ( insertion )
 * Deletion ( Front )
 ***********************
 * Enqueue() stores the elements in the queue
 * Dequeue(): this operation is used to remove elements from the queue
 * isFull() : checks if the queue is full or not
 * isNUll() : evaluates if the queue us empty
 * peek () : get the element from the front of the queue without removing it.
 * **********************
 * A queue is FIFO data structure
 * Insertion at the end, and deletion is perfomred at the begining.
 * Queue vs Stack :
 * The most recently added element will be deleted in stack, where, the most recently added element will be deleted in queues
 *  insertion and deletion is allowed at the top of the stack. Therefore, one variable is enough to keep track of the position of the last element.
 *  stack : last in - first out ( LIFO)
 *  queue : first in - first out
 * stack : push (data) operation
 * - push (10) -> 10 , top =0
 * - push (15) -> 10  15, top =1
 * pop operation:
 *  The element at the top is deleted.
 *  Top is incremented by 1.
 *  It returns the deleted element.
 * *************************************
 * front, rear = -1;  NULL
 * front = 0;  // enqueue (10)
 * rear  = 0; 10
 * front = 0; 10
 * rear  = 1; 10 15
 *
 * Dequeue ()
 * consider a queue containing 10, 15, 20, 30 and 40 as follows:
 * front = 0; // 10 15 20 30 40
 * rear  = 4;
 *  front = 1; rear = 4;
 *
 *  if front == rear, there is one element in the queue, except when front = -1 and rear = -1;
 *  front = rear +1 , the queue is empty
 *
 *  if (front = -1 && rear == -1 || front = rear + 1)
 *  { queue is empty ; }
 *  if ( front = -1 || front = rear + 1 ){
 *  queue is empty ; }
 *  if there is at least one elemnt in the queue, then the front can never be -1
 *
 *
 * - define enqueue()
 * - define dequeue()
 * - define isEmpty ()
 * - define isFull ()
 * - define print ()
 *
 *  If the front equals -1, then increase the font by 1
 *  front = -1
 *  rear = -1
 *  queue is empty
 *
 *  enqueue (10)
 *  enqueue (15)
 *
 *  -------------------------
 *  void enqueue ( int data)
 *  {
 *  if (isFull())
 *  {cout << " Queue overflow. \n";
 *  exit(1);
 *  }
 *
 *  if (front == -1) {
 *  front = 0;
 *  }
 *  rear ++;
 *  queue [rear] = data;
 *
 *  }
 *
 *  int dequeue() {
 *  int data;
 *  if (isEmpty())
 *  {
 *  cout << " Queue is empty.  \n";
 *  exit (1);
 *  }
 *
 *  data = queue [front];
 *  front ++;
 *  return data; // simply ignore the element, the element
 *  }
 *
 *  }
 *********
 * int isEmpty () {
 * if (front == -1 || front == rear + 1) {
 * return 1;
 * }
 * else { return 0;}
 * }
 *
 *
 * int isFull () {
 * if (rear == MAX-1) {
 * return 1;
 * }
 * else {
 * return 0;
 * }
 *
 *
 * int peek () {
 *  if (isEmpty())
 *  {
 *  cout << "queue is empty . \n";
 *  exit (1);
 *  }
 *  return queue [front];
 *  }
 * }
 *
 * void print () {
 * int i;
 * if (isEmpty()){
 * cout << " queue underflow. \n";
 * exit(1);
 * }
 * cout << "Queue: \n";
 * for ( i =front; i<=rear; i++){
 * cout << queue[i]<<" ";
 * }
 * cout <<endl;
 *
 * }
 *
 * ******** Drawbacks of the queue!
 * if front != 0 and rear =MAX-1, the queue is full! we cannot insert new elements, shifting all elements will consume
 * a lot of time.
 * ***********************************
 * Linked list implementation of the queue:
 *
 * Define enqueue () function
 * Define dequeue () function
 * Define isEmpty () and isFull function
 * Define the print function
 * ************************************
 * Each node consists of two parts:
 *
 * struct node {
 * int data;
 *  node* link;
 *  * front = NULL, * rear = NULL;
 * }
 *
 * void enqueue ( int data) {
 * node* temp;
 * temp = (node*) malloc(sizeof(node));
 * if (temp == NULL){
 * cout << " No Spce: \n ";
 * exit(1);
 *
 * temp -> data = data;
 * temp -> link = NULL;
 * if (rear == NULL) {
 * front = rear = temp;
 * }
 * else {
 * rear -> link = temp;
 * rear =temp;
 * }
 *
 * int dequeue() {
 * int data_delete;
 * struct node* temp;
 * if (isEmpty())
 * {
 * cout << "Queue underflow .\n";
 * exit(1);
 *}
 * temp = front;
 * data_delete = temp -> data;
 * front = front->link;
 * free(temp);
 * temp =NULL;
 * return data_delete;
 *
 * }
 *
 * int isEmpty(){
 * if (front == NULL) {
 * return 1;
 *
 * } else{
 * return 0;
 * }
 *
 * void print () {
 * node* temp;
 * temp = front;
 * if (isEmpty()){
 * cout << "Queue underflow .\n";
 * exit (1);
 *
 * }
 * cout << "Queue :\";
 * while (temp!= NULL){
 * cout <<temp ->data << " ";
 * temp = temp->link;
 * }
 * cout <<endl;
 * }
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */



int main() {

   // example :-
   int queue [3] ;






}