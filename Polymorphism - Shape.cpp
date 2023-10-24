 #include <bits/stdc++.h>
using namespace std;
class shape
{
public:
    double dm1,dm2;
    shape (double dm1,double dm2)
    {
        this-> dm1 = dm1;
        this -> dm2 = dm2;
    }
    virtual  double area()
    {
        return 0;
    }

};

class triangle : public shape
{
    // dm1,dm2.area()
public:
    triangle(double dm1,double dm2)
        :shape (dm1,dm2)
    {

    }
    double area()
    {
        return 0.5 * dm1 * dm2 ;
    }

};

class rectangle : public shape
{
    // dm1,dm2.area()
public:
    rectangle(double dm1,double dm2)
        :shape (dm1,dm2)
    {

    }
    double area()
    {

        return dm1 *dm2 ;
    }

};

int main()
{
    shape *p;
    triangle t(10,20);
    rectangle r(15,25);

    p = &t;
    cout << "Triangle Area :" << p -> area () << endl;

    p = &r;
    cout << "Rectangle Area :" << p -> area () << endl;

    return 0;
}

