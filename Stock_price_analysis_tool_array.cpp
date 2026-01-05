#include <iostream>
#include <string>

using namespace std;

const int MAX_DAYS = 100;

struct StockRecord {
    string date;
    double price;
};

void inputStockPrices(StockRecord records[], int numDays){
    for (int counter = 0; counter < numDays; counter++){
        cout << "Day " << counter + 1 << ": \n";
        cout << "Date (YYYY-MM-DD): ";
        cin >> records[counter].date;
        cout << "Stock Price : ";
        cin >> records[counter].price;
    }
}

void bubbleSort(StockRecord records[], int numDays){
    bool swapped;
    for (int i = 0; i < numDays - 1; i++){
        swapped = false;
        for (int j = 0; j < numDays - i - 1; j++){
            if (records[j].price > records[j + 1].price){
                swap(records[j], records[j + 1]);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
    cout << "Stock prices are sorted successfully." << endl;
}

double calculateAveragePrice(StockRecord records[], int numDays){
    double avg = 0.0;
    for (int i = 0; i < numDays; i++){
        avg += records[i].price;
    }
    return avg / numDays;
}

void findHighestAndLowestPrices(StockRecord records[], int numDays){
    if (numDays <= 0) {
        cout << "No data available." << endl;
        return;
    }

    double highest = records[0].price;
    double lowest = records[0].price;
    string highestDate = records[0].date;
    string lowestDate = records[0].date;

    for (int i = 1; i < numDays; i++){
        if (records[i].price > highest){
            highest = records[i].price;
            highestDate = records[i].date;
        }
        if (records[i].price < lowest){
            lowest = records[i].price;
            lowestDate = records[i].date;
        }
    }

    cout << "Highest stock Price: \n" ;
    cout << "Date : "  << highestDate << ", " << " Price: " << highest << std::endl;

    cout << "Lowest stock Price: \n" ;
    cout << "Date : "  << lowestDate << ", " << " Price: " << lowest << std::endl;

}

void searchStockPricesInRange(StockRecord records[], int numDays){
    string startDate, endDate;
    cout << "Enter start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter end date (YYYY-MM-DD): ";
    cin >> endDate;

    cout << "Stock prices between " << startDate << " and " << endDate << ":" << endl;
    for (int i = 0; i < numDays; i++){
        if (records[i].date >= startDate && records[i].date <= endDate){
            cout << records[i].date << ", " << records[i].price << endl;
        }
    }
}

int countPricesAboveThreshold(StockRecord records[], int numDays){
    double threshold;
    cout << "Enter price threshold: ";
    cin >> threshold;

    int count = 0;
    for (int i = 0; i < numDays; i++){
        if (records[i].price > threshold){
            count++;
        }
    }

    cout << "Number of days with stock price above " << threshold << ": " << count << endl;
    return count;
}

int main() {
    StockRecord records[MAX_DAYS];
    cout << "Welcome to the Enhanced Stock Price Analysis Tool!" << endl;
    cout << "Enter the number of days with historical stock prices (up to 100): ";
    int numDays = 0;
    cin >> numDays;
    inputStockPrices(records, numDays);
    cout << "Entry completed." << endl;
    bubbleSort(records, numDays);

    while (true) {
        cout << "\nAdditional Features: \n";
        cout << "1. Calculate average stock price.\n";
        cout << "2. Find highest and lowest stock prices.\n";
        cout << "3. Search for stock prices within a date range.\n";
        cout << "4. Count days with stock price above a threshold.\n";
        cout << "5. Exit.\n";
        cout << "Select an option (1-5): ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Average Stock Price: " << calculateAveragePrice(records, numDays) << endl;
                break;
            case 2:
                findHighestAndLowestPrices(records, numDays);
                break;
            case 3:
                searchStockPricesInRange(records, numDays);
                break;
            case 4:
                countPricesAboveThreshold(records, numDays);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
