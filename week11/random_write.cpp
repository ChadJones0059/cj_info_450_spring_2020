#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n = 1000;
    ofstream out;
    out.open("randoms.txt");
    for(int i = 0; i < n; i++)
    {
        out << rand() % 19999 -9999 << endl;
    }
    return 0;
}