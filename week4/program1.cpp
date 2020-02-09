#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int userInput[10];      // make an array with length 10
    double sum = 0;         // declare variable so I can sum all numbers entered
    double mean = 0;        // mean variable
    double var = 0;         // variance variabled
    double meanVar = 0;     // mean of variances
    double stdDev = 0;      // standard deviaton variable

    for(int i = 0; i < 10; i++)     // start for loop for user to enter 10 whole numbers
    {
        cout << "Enter the number for index " << i << ": ";     // print output for each iteration
        cin >> userInput[i];                                    // store input
        sum += userInput[i];                                    // add all numbers entered by user
        mean = sum / 10;                                        // find the average

        // Do I need a for loop here? 
        var += (userInput[i] - mean)*(userInput[i] - mean);     // adding up (user inputs minus the mean)^squared 
        meanVar = var / 10;                                     // trying to find the variance, then divide by the mean
        stdDev = sqrt(meanVar);                                 // find standard deviation 
    }
    cout << "results, " << mean << ", " << stdDev;
    return 0;
}