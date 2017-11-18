#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Shape {
private:
    double x,y,z;
public:
    Shape(double x, double y, double z) : x(x), y(y), z(z) {}
    double getX(){return x;} double getY(){return y;} double getZ(){return z;}
    virtual void write(const string &filename) = 0;
};

class Cylinder : public Shape{
private:
	double r, h;
	int facets;
    double triangles;
public:
	Cylinder(double x, double y, double z, double r, double h, int facets) : Shape(x,y,z), r(r), h(h), facets(facets) {}
    void write(const string &filename) {
        ofstream myfile;
        myfile.open (filename, fstream::app);
            int n1, n2, n3 = 0;
            int v1, v2, v3 = 0;
            for (int i = 0; i < triangles; i++){
                myfile << "facet normal" << n1 << ' ' <<  n2 << ' '<< n3 << endl;
                myfile <<  "\touter loop" << endl;
                myfile << "\t\tvertex " << v1 << ' ' << v2 << ' ' << v3 << endl;
                myfile << "\tendloop" << endl;
                myfile << "endfacet" << endl;
            }
        myfile.close();
    }
};

class Cube: public Shape {
private:
	double size;
    const double triangles = 12;
public:
	Cube(double x, double y, double z, double size) : Shape(x,y,z), size(size) {}
    double getSize() {return size;}
    void write(const string &filename) {
        ofstream myfile;
        myfile.open (filename, fstream::app);
            int n1, n2, n3 = 0;
            int v1, v2, v3 = 0;
            for (int i = 0; i < triangles; i++){
                myfile << "facet normal " << n1 << ' ' <<  n2 << ' '<< n3 << endl;
                myfile <<  "  outer loop" << endl;
                myfile << "    vertex " << v1 << ' ' << v2 << ' ' << v3 << endl;
                myfile << "  endloop" << endl;
                myfile << "endfacet" << endl;
            }
        myfile.close();
    }
};

class CAD {
private:
	vector<Shape*> shapes;
public:
    void add(Shape * s){
        shapes.push_back(s);
    }
    void write(string filename){
        ofstream myfile;
        myfile.open(filename);
        myfile << "solid " << filename << endl;
        for (auto s : shapes)
            s->write(filename);

        myfile.close();
    }
};

//https://www.stratasysdirect.com/resources/how-to-prepare-stl-files/
//https://www.viewstl.com/
int main() {
	CAD c;
	c.add(new Cube(0,0,0,   5));
	c.add(new Cylinder(100,0,0,    3, 10, 10));
    c.write("test.stl");
}