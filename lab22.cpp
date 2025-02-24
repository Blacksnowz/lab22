#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{                
    public:
        double real;
        double imag;
        ComplexNumber(double,double);
        ComplexNumber operator+(const ComplexNumber &);
        ComplexNumber operator-(const ComplexNumber &);
        ComplexNumber operator*(const ComplexNumber &);
        ComplexNumber operator/(const ComplexNumber &);
        bool operator==(const ComplexNumber &);
        double abs();
        double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
    real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
    return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
    return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denominator,
                         (imag * c.real - real * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    return (real == c.real) && (imag == c.imag);
}

double ComplexNumber::abs(){
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle(){
    return atan2(imag, real) * (180.0 / M_PI);
}

ostream &operator<<(ostream &out, const ComplexNumber &c){
    if (c.real == 0 && c.imag == 0) {
        out << "0";
    } else if (c.real == 0) {
        out << c.imag << "i";
    } else if (c.imag == 0) {
        out << c.real;
    } else {
        out << c.real;
        if (c.imag < 0) {
            out << c.imag << "i";
        } else {
            out << "+" << c.imag << "i";
        }
    }
    return out;
}

ComplexNumber operator+(double s, const ComplexNumber &c){
    return ComplexNumber(s+c.real, c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c){
    return ComplexNumber(s-c.real, -c.imag);
}

ComplexNumber operator*(double s, const ComplexNumber &c){
    return ComplexNumber(s * c.real, s * c.imag);
}

ComplexNumber operator/(double s, const ComplexNumber &c){
    double denominator = c.real*c.real + c.imag*c.imag;
    return ComplexNumber((s*c.real)/denominator, (-s*c.imag)/denominator);
}

bool operator==(double d, const ComplexNumber &c){
    return (d == c.real && c.imag == 0);
}
