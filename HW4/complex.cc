// Jo Haugum	EE553	Oct 12, 2017
#include <iostream>
using namespace std;

class Complex {
private:
	double real; double imag; 
public:
	Complex(double a = 0.0, double b = 0.0){ real = a; imag = b;}
	double getReal() const {return real;}
	double getImag() const {return imag;}

	Complex operator +(Complex obj){
		Complex temp;
		temp.real = real + obj.real;
		temp.imag = imag + obj.imag;
		return temp;
	}

	Complex operator- (){ // Is this code okay? Slow? Too many copies?
		Complex temp;
		temp.real = -real;
		temp.imag = -imag;
		return temp;
	}

	Complex add(Complex b){ 
		Complex ans;
		ans.real = this->real + b.real;
		ans.imag = this->imag + b.imag;
        return ans;
	}
	friend ostream& operator << (ostream& s, const Complex& a);
};

ostream& operator << (ostream& s, const Complex& a){
	if (a.getImag() >= 0)
		s << a.getReal() << " + " << a.getImag() << 'i';
	if (a.getImag() < 0) // Show different output for negative imag values
		s << a.getReal() << " - " << a.getImag() * -1 << 'i';
	return s;
}

int main() {
	Complex c1(1.5,2.0);
	Complex c2(-1.3); // -1.3 + 0.0i
	Complex c5;  // 0+0i
	Complex c3 = c1 + c2;
	Complex c4 = -c1; // unary operator has only one parameter
	cout << c1 << c3 << c4 << '\n'; // This will cout the numbers without space
									// This is the standard behavior of cout <<
}
