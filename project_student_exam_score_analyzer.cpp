#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const int  MAX_EXAMS =  10;
const int  MAX_STUDENTS  = 100;

void inputStudentDetailsAndSort(string names[], int  scores[][MAX_EXAMS], int numStudents, int numExams) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the name of student " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, names[i]);

        cout << "Enter exam scores for student " << (i + 1) << ": ";
        for (int j = 0; j < numExams; j++) {
            cin >> scores[i][j];
        }

        // Bubble sort for each student in ascending order
        for (int k = 0; k < numExams - 1; k++) {
            bool swapped = false;
            for (int l = 0; l < numExams - k - 1; l++) {
                if (scores[i][l] > scores[i][l + 1]) {
                    swap(scores[i][l], scores[i][l + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
    // Display sorted student scores in ascending order
    cout << "\n \n" << endl ;
    cout << "--------------------------" <<endl;
    cout << "\n\n--------------------------" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(15) << "Student: " << setw(25) << names[i] << "Sorted Scores: ";
        for (int j = 0; j < numExams; j++) {
            cout << setw(4) << scores[i][j];
        }
        cout << endl;
    }
}

void calculateAverageScores(int scores[][MAX_EXAMS], double averages[], int numStudents, int numExams){
    double avg =0;
 for ( int i = 0 ; i < numStudents ; i ++){
      avg = 0.0;
      for ( int j = 0 ; j < numExams ; j++) {
          avg = avg + scores [i][j];
      }
      averages[i] = avg/numExams;
 }
}

double calculateVariance(int scores[][MAX_EXAMS], double averages[], int numStudents, int numExams){
    double totalVariance = 0.0;
    double overallAverage = 0.0;
    int totalNumScores = numStudents * numExams;

    // First, calculate the overall average
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numExams; j++) {
            overallAverage += scores[i][j];
        }
    }
    overallAverage /= totalNumScores;

    // Then, calculate the variance
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numExams; j++) {
            totalVariance += pow(scores[i][j] - overallAverage, 2);
        }
    }

    return totalVariance / totalNumScores;
}

double calculateStandardDeviation(double variance){
    return sqrt(variance);
}

void displayStudentStatistics(string names[], double averages[], double standardDeviation, int numStudents){
    std::cout << "\n \n \n" << endl;
    std::cout << " \t Student Statistics: " << endl;
    std::cout << "------------------------------------" << endl;
    std::cout << " \t Student Name \t Average Score   " << endl;
    std::cout << "------------------------------------" << endl;
    for ( int i = 0; i < numStudents ; i++){
        std::cout << left << setw(15) <<  names[i] << setw(10) <<": " << averages [i] << std::endl;
    }
    std::cout << "------------------------------------" << endl;
    std::cout << "Standard Deviation: " << standardDeviation << endl;
}

int findHighestScore(int scores[][MAX_EXAMS], int numStudents, int numExams){
        int highestScore = scores[0][0];
        for (int i = 0; i < numStudents; i++) {
            for (int j = 0; j < numExams; j++) {
                if (scores[i][j] > highestScore) {
                    highestScore = scores[i][j];
                }
            }
        }
        cout << " highestScore: " << highestScore << endl;
        return highestScore;
}

int findLowestScore(int scores[][MAX_EXAMS], int numStudents, int numExams){
    int lowestScore = scores[0][0];
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numExams; j++) {
            if (scores[i][j] < lowestScore) {
                lowestScore = scores[i][j];
            }
        }
    }
    cout << " LowestScore : " << lowestScore << endl;
    return lowestScore;
}

void displayHistogram(int scores[][MAX_EXAMS], int numStudents, int numExams){
        const int NUM_RANGES = 5;
        int rangeLimits[NUM_RANGES] = {20, 40, 60, 80, 100};
    cout <<"\n \n" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Histogram of Exam Scores for Each Student:" << endl;
    cout << "------------------------------------------" << endl;
        for (int i = 0; i < numStudents; i++) {
            int rangeCounts[NUM_RANGES] = {0};

            for (int j = 0; j < numExams; j++) {
                for (int k = 0; k < NUM_RANGES; k++) {
                    if (scores[i][j] < rangeLimits[k]) {
                        rangeCounts[k]++;
                        break;
                    }
                }
            }

            cout << "Student " << (i + 1) << ": ";
            for (int l = 0; l < NUM_RANGES; l++) {
                if (l == 0) {
                    cout << "[0-19]: ";
                } else {
                    cout << "[" << rangeLimits[l - 1] << "-" << (rangeLimits[l] - 1) << "]: ";
                }
                cout << rangeCounts[l] << " ";
            }
            cout << endl;
        }
    }

char calculateGrade(double average) {

        if (average >= 90) {
            return 'A';
        } else if (average >= 80) {
            return 'B';
        } else if (average >= 70) {
            return 'C';
        } else if (average >= 60) {
            return 'D';
        } else {
            return 'F';
        }
    }

void displayGrades(string names[], double averages[], int numStudents){
    char grade;
    cout << "Grades : " << endl;
    cout << "---------------------------------" << endl;
    cout << " Student Name \t Grade" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << "Student: " << names[i] << "\t " << calculateGrade( averages[i]) << endl;
    }
    cout << "---------------------------------" << endl;
}

bool binarySearch(const int  sortedScores[], int numExams, int target) {
    int low = 0;
    int high = numExams - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (sortedScores[mid] == target) {
            return true;
        } else if (sortedScores[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false; // Target not found
}

int main() {
    int numStudents;
    int numExams;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cout << "Enter the number of exams per student: ";
    cin >> numExams;

    string names[MAX_STUDENTS];

    int scores[MAX_STUDENTS][MAX_EXAMS];
    double averages [MAX_STUDENTS];

    inputStudentDetailsAndSort(names, scores, numStudents, numExams);
    calculateAverageScores(scores,  averages,  numStudents,  numExams);

    double variance = calculateVariance(scores, averages,  numStudents, numExams);
    double standardDeviation = calculateStandardDeviation(variance);
    displayStudentStatistics( names,  averages,  standardDeviation,  numStudents);
    findHighestScore( scores,  numStudents,  numExams);
    findLowestScore( scores,  numStudents,   numExams);
    displayHistogram( scores,  numStudents,  numExams);
    displayGrades( names,  averages,  numStudents);

    // convert 2d array to 1D array !
    int sortedScores[numStudents * numExams];

    for (int i = 0; i < numStudents; ++i) {
        for (int j = 0; j < numExams; ++j) {
            sortedScores[i * numExams + j] = scores[i][j];
        }
    }


    int target;
    cout << "Enter a score to search for: ";
    cin >> target;
    numExams *=  numStudents;
    // Assuming you want to search in the scores of the first student
    if (binarySearch(sortedScores,  numExams,  target)) {
        cout << "--------------------------" <<endl;
        cout << "Score "<< target << " found for Student" <<  endl;
    } else {
        cout << "Score not found." << endl;
    }
    return 0;
}
