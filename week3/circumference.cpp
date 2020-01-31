#include <iostream>
using namespace std;

double calculateCircumference(double radius);

const float pi = 3.14159265358979323846;

int main()
{
    double userRadius =  0;
    double result = 0;

    cout << "Please enter the radius of the circle. ";
    cin >> userRadius;
    
    result = calculateCircumference(userRadius);
    cout << "The circumference of the circle is. " << result << endl;

    return 0;
}
double calculateCircumference(double radius)
{
    radius = 2*pi*radius;
    return radius;
}
