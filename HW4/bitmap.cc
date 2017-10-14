#include <iostream>
#include <iomanip>
using namespace std;

class Bitmap {
private:
	uint32_t* rgba;
	uint32_t rows,cols;
public:
    Bitmap(uint32_t rows, uint32_t cols, double val = 0): rows(rows), cols(cols) {
		int len = rows * cols;
		rgba = new uint32_t [len];
		for (int i = 0; i < len; i++)
            rgba[i] = 0x000000;
    }

    int getRows() const {return rows;}
    int getCols() const {return cols;}

    void horizLine(uint32_t col1, uint32_t col2, uint32_t row, uint32_t color)const{
        for (int i = col1; i <= col2; i++){
            rgba[row * this->cols + i] = color;
        }
    }

    void vertLine(uint32_t row1, uint32_t row2, uint32_t col, uint32_t color) const{
        for (int i = row1; i <= row2; i++){
            rgba[col + i * this->cols] = color;
        }
    }

    uint32_t getColor(uint32_t x) const{
        return rgba[x];
    }

    friend ostream& operator << (ostream& s, const Bitmap& a);

    ~Bitmap(){
        delete [] rgba;
    }

};

ostream& operator << (ostream& s, const Bitmap& a){
    int rows = a.rows;
	int cols = a.cols;
	for (int i = 0; i < rows * cols; i++){
        s << ((a.rgba[i] & 0xFF0000) >> 16) << ',' << ((a.rgba[i] & 0x00FF00) >> 8) << ',' << (a.rgba[i] & 0x0000FF) << '\t';
        if (i % cols == cols - 1 && i != 0)
            s << '\n';
    }
    return s;

}
int main() {
	Bitmap b1(3,5); // rows,cols or y,x (NOT x,y)
	cout << b1;
	/*
r,g,b   rgb = ((r*256 + g)*256 + b
this is the same as:
rgb = ((r << 8) + g) << 8) + b
 use setw(4) in iomanip
		0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
		0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
		0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
	 */
	Bitmap b2(10,20);
	b2.horizLine(3, 15, 0, 0xFF00FF); // go from (3,0) to (15,0) writing color

	
    b2.vertLine(0, 8, 0, 0x000100);// go from (0,0) to (0,8) writing color
    cout << b2;
}	