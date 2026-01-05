#include <iostream>
#include <string>

using namespace std;

struct DeliveryOrder {
    string recipientName;
    string destination;
    string deliveryAddress;
    int estimatedTime;
    int orderID;
};

int partition(DeliveryOrder orders[], int left, int right) {
    int pivot = orders[right].estimatedTime;
    int pIndex = left;

    for (int i = left ; i < right ; i++){
        if ( orders[i].estimatedTime <= pivot ){
            swap(orders[i].estimatedTime, orders[pIndex].estimatedTime);
            pIndex++;
        }
    }
    swap(orders[pIndex].estimatedTime, orders[right].estimatedTime);
    return pIndex;
}

void quicksortDeliveryOrders(DeliveryOrder orders[], int left, int right) {
    if (left <right) {
        int pIndex = partition( orders,left, right);
        quicksortDeliveryOrders( orders,  left,  pIndex - 1 );
        quicksortDeliveryOrders( orders,  pIndex + 1,  right );

    }
}

void inputDeliveryOrders(DeliveryOrder orders[], int numOrders) {
    for (int counter = 0; counter < numOrders; counter++){
        cout << "Delivery " << counter + 1 << ": \n";
        cout << "Recipient's Name: ";
        cin >> orders[counter].recipientName;
        cout << "Destination : ";
        cin >> orders[counter].destination;
        cout << "Delivery Address: ";
        cin >> orders[counter].deliveryAddress;
        cout << "Estimated Time (minutes): ";
        cin >> orders[counter].estimatedTime;
        cout << "Order ID: ";
        cin >> orders[counter].orderID;
    }
}

void displaySortedOrders(DeliveryOrder orders[], int numOrders) {

    for (int counter = 0; counter < numOrders; counter++){
        cout << "Delivery " << counter + 1 << ": \n";
        cout << "Recipient's Name: ";
        cout << orders[counter].recipientName << endl;
        cout << "Destination : ";
        cout << orders[counter].destination << endl;
        cout << "Delivery Address: ";
        cout << orders[counter].deliveryAddress << endl;
        cout << "Estimated Time (minutes): ";
        cout << orders[counter].estimatedTime << endl;
        cout << "Order ID: ";
        cout << orders[counter].orderID << endl;
    }
}

void searchByRecipientName(DeliveryOrder orders[], int numOrders, const string& recipientName) {
    string temp = recipientName;

    for (int i = 0; i < numOrders; i++){
        if (orders[i].recipientName == temp){
            cout << "Delivery Orders for Recipient:  " << orders[i].recipientName << endl;
            cout << "Order ID: " << orders[i].orderID << endl;
            cout << "Destination: " << orders[i].destination << endl;
            cout << "Estimated Time: " << orders[i].estimatedTime << endl;
        }
    }
}

void calculateTotalEstimatedTime(DeliveryOrder orders[], int numOrders) {
    double totalTime = 0.0;
    for (int i = 0; i < numOrders; i++){
        totalTime += orders[i].estimatedTime;
    }
    cout << " Total Estimated Time for All Delivery Orders: " << totalTime << " minutes " << endl;
}

void findFastestAndSlowest(DeliveryOrder orders[], int numOrders) {

    if (numOrders <= 0) {
        cout << "No data available." << endl;
        return;
    }
    int fastest = orders[0].estimatedTime;
    int slowest = orders[0].estimatedTime;
    int indexF = 0;
    int indexS = 0;
    for (int i = 1; i < numOrders; i++){
        if (orders[i].estimatedTime > slowest){
            slowest = orders[i].estimatedTime;
            indexS =i ;
        }
        if (orders[i].estimatedTime < fastest){
            fastest = orders[i].estimatedTime;
            indexF =i ;
        }
    }

    cout << "Fastest Delivery Order: \n" ;
    cout << "Recipient's Name: "  << orders[indexF].recipientName << endl;
    cout << "Destination: "  << orders[indexF].destination << endl;
    cout << "Estimated Time: "  << orders[indexF].estimatedTime << " minutes "<< endl;
    cout << " \n ";

    cout << "Slowest Delivery Order: \n" ;
    cout << "Recipient's Name: "  << orders[indexS].recipientName << endl;
    cout << "Destination: "  << orders[indexS].destination << endl;
    cout << "Estimated Time: "  << orders[indexS].estimatedTime << " minutes "<< endl;
}

void displayOrdersWithinTimeRange(DeliveryOrder orders[], int numOrders, int minTime, int maxTime) {

    cout << "Delivery Orders within Time Range  " << minTime << " - " << maxTime << "):" << endl;
    for (int i = 0; i < numOrders; i++){
        if (orders[i].estimatedTime >= minTime && orders[i].estimatedTime <= maxTime){

            cout << "Order ID: " << orders->orderID << endl;
            cout << "Destination: " << orders->destination << endl;
            cout << "Estimated Time: " <<orders->estimatedTime << "minutes "<< endl;
        }
    }
}

int main() {
    int numOrders;
    cout << "Welcome to the Delivery Order Management System!\n";
    cout << "Enter the number of delivery orders: ";
    cin >> numOrders;

    DeliveryOrder orders[numOrders];
    // Input delivery orders
    inputDeliveryOrders(orders, numOrders);
    // Perform Quick Sort to sort delivery orders by estimated time
    quicksortDeliveryOrders(orders, 0, numOrders - 1);
    // Display sorted delivery orders
    displaySortedOrders(orders, numOrders);

    // Additional Tasks:

    // Task 3: Search for delivery orders by recipient's name
    string searchRecipient;
    cout << "Enter recipient's name to search for delivery orders: ";
    cin.ignore();
    getline(cin, searchRecipient);
    searchByRecipientName(orders, numOrders, searchRecipient);

    // Task 4: Calculate and display total estimated time
    calculateTotalEstimatedTime(orders, numOrders);

    // Task 5: Find and display the fastest and slowest delivery orders
    findFastestAndSlowest(orders, numOrders);

    // Task 6: Display delivery orders within a specific time range
    int minTime, maxTime;
    cout << "Enter minimum and maximum estimated time range (in minutes): ";
    cin >> minTime >> maxTime;
    displayOrdersWithinTimeRange(orders, numOrders, minTime, maxTime);

    return 0;
}
