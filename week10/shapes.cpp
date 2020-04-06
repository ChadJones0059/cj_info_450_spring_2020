#include <iostream>
using namespace std;

const int PI = 3; // for simplicity, we'll preten PI is 3

class shape
{
    public:
        virtual int get_perimeter_length() = 0;
        virtual int get_area() = 0;
};

class circle : public shape{
    public:
    int r = 0;
    circle(int radius){r = radius;}
    int get_perimeter_length(){return PI * 2 * r;}
    int get_area(){return PI * r * r;}
};
class rectangle : public shape{
    public:
    int w = 0;
    int h = 0;
    rectangle(int height, int width){h = height, w = width;}
    int get_perimeter_length(){return (h * 2) + (w * 2);}
    int get_area(){return h * w;}
};
class square : public rectangle{
    public:
    int s = 0;
    square(int side){s = side;}
    int get_perimeter_length(){return s * 4;}
    int get_area(){s * s;}
};
int main(){
    shape *s1;
    circle c(3);
    s1 = &c;
    cout << "Perimeter: " << s1->get_perimeter_length() << " : Area " << s1->get_area() << endl;
    square s(3);
    s1 = &s;
    cout << "Perimeter: " << s1->get_perimeter_length() << " : Area " << s1->get_area() << endl;
    rectangle r(4,5);
    s1 = &r;
    cout << "Perimeter: " << s1->get_perimeter_length() << " : Area " << s1->get_area() << endl;
    return 0;
}