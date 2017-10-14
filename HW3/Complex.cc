#include <iostream>
using namespace std;

class Complex {
private:
	double real; // Let a + bi be a complex number. Then a is the real part
	double imag; // and b is the imaginary part.
public:
	Complex() {
		// Initiate values for real and imag to avoid garbage values
		real = 0.0;
		imag = 0.0;
	}
	Complex(double a, double b){
		real = a;
		imag = b;
	}
	double getReal() const {
		return real;
	}
	double getImag() const {
		return imag;
	}

	void print() const {
		cout << this->real << " + " << this->imag << 'i';
	}
	Complex add(Complex b){
		Complex ans;
		ans.real = this->real + b.real;
		ans.imag = this->imag + b.imag;
        return ans;
	}
};

int main(){
	Complex c1(1.0, 2.5); // real=1.0, imag = 2.5
	Complex c2(2.0, 1.5);
	const Complex c3 = c1.add(c2);  // add two complex numbers
	c3.print(); cout << "\n";
	cout << c3.getReal() << ", " << c3.getImag();
}
