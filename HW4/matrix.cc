// Jo Haugum	EE575	Oct 12, 2017	Stevens Institute of Technology
// Includes solution for optional matrix multiplication

#include <iostream>
#include <cstdint>
using namespace std;

class Matrix {
	double* m;
	uint32_t rows, cols;
public:
	Matrix(uint32_t rows, uint32_t cols, double val = 0): rows(rows), cols(cols) {
		int len = rows * cols;
		m = new double [len];
		for (int i = 0; i < len; i++)
			m[i] = val;
	}
	int getRows() const { return rows; }
	
	int getCols() const{ return cols; }
	// what do we need here???
	// constructor, destructor, copy constructor, operator =
	/*
		0  1   2  3
    4  5   6  7
    8  9  10 11
	 */

	

	double operator () (uint32_t r, uint32_t c)const {
		return m[r*cols + c];
	}
	double& operator ()(uint32_t r, uint32_t c) {
		return m[r*cols + c];
	}
	/*
		operator +...
		for (int i = 0; i < rows; i++)
		for (int j = ; j < cols; j++)
      ans(i,j) = a(i,j) + b(i,j)
			writing with a single loop is faster
	 */	
    ~Matrix(){
        delete [] m;
	}
	
	// void print(){ // Just for testing, remove before delivery
	// 	int len = rows * cols;
	// 	for (int i = 0; i < rows; i++){
	// 		for (int j = 0; j < cols; j++)
	// 			cout << m[i*cols + j] << '\t';
	// 		cout << '\n';
	// 	}
	// }

	friend Matrix operator +(const Matrix& a, const Matrix& b);
	friend Matrix operator -(const Matrix& a, const Matrix& b);
	friend ostream& operator << (ostream& s, const Matrix& a);
	friend Matrix operator *(const Matrix& a, const Matrix& b);
};


Matrix operator +(const Matrix& a, const Matrix& b) {
	int rows = a.getRows();
	int cols = a.getCols();
	Matrix sum(rows,cols);
    
	for (int i = 0; i < rows*cols; i++)
		sum.m[i] = a.m[i] + b.m[i];
	return sum;
}

Matrix operator -(const Matrix& a, const Matrix& b) {
	int rows = a.getRows();
	int cols = a.getCols();
	Matrix difference(rows,cols);
    
	for (int i = 0; i < rows*cols; i++)
		difference.m[i] = a.m[i] - b.m[i];
	return difference;
}

Matrix operator *(const Matrix& a, const Matrix& b) {
	int acols = a.getCols(); int arows = a.getRows();
	int brows = b.getRows(); int bcols = b.getCols();
	if (acols != brows){
		exit(1);
	}
	Matrix product(a.getRows(), b.getCols());
	int sum;

	for (uint32_t loc = 0; loc < arows * bcols; loc++){
		product.m[loc] = 0;
		for (uint32_t i = 0, j = 0; j < brows * bcols; i++, j += bcols)
			product.m[loc] += a.m[i] * b.m[j];

	}

	return product;

}

ostream& operator << (ostream& s, const Matrix& a){
	int rows = a.getRows();
	int cols = a.getCols();
	for (int i = 0; i < rows * cols; i++){
		s << a.m[i] << '\t';
		if (i % cols == cols - 1 && i != 0)
			s << '\n';
	}

	return s;
}

int main() {
	Matrix a(3,4, 5.2); // create 3 rows of 4 columns containing 5.2
	Matrix b(3,4); // defaults to 0.0
	cout << a << '\n';
	/*
		5.2 5.2 5.2 5.2
		5.2 5.2 5.2 5.2
		5.2 5.2 5.2 5.2
	 */

	Matrix c(3,4,1.2);

	cout << c(2,2);
	c(0,0) = -1.5;
	/*
c=
		-1.5 1.2 1.2 1.2
		 1.2 1.2 1.2 1.2
		 1.2 1.2 1.2 1.2
	 */
	Matrix d = a + c;
	/*
		3.7 6.4 6.4 6.4
		6.4 6.4 6.4 6.4
		6.4 6.4 6.4 6.4
	 */
	cout << d;
	Matrix e = a - c;

	//optional
	Matrix f(4,3,1.5);
	Matrix g = f * b; // matrix multiplication
}