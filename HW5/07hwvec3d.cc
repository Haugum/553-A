// Jo Haugum,   EE553,  Stevens Institute of Technology,    Oct 14, 2017
#include <iostream>
#include <cmath>
using namespace std;

class Vec3d {
private:
    double* m;
    double x, y, z;
public:
    Vec3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {
        m = new double [3];
        m[0] = x; m[1] = y; m[2] = z;
    }

    double dot(const Vec3d& b){
        double dproduct = 0;
        for (int i = 0; i < 3; i++){
        dproduct += this->m[i] * b.m[i];
        }
        return dproduct;
    }

    double dist(const Vec3d& b){
        double distsqd = 0;
        for (int i = 0; i < 3; i++){
            distsqd += (m[i] - b.m[i]) * (m[i] - b.m[i]);
        }
        return sqrt(distsqd); 
        
    }

    friend Vec3d operator *(const Vec3d& a, int b);
    friend Vec3d operator *(int b, const Vec3d& a);
    friend Vec3d operator +(const Vec3d& a, const Vec3d& b);
    friend Vec3d operator -(const Vec3d& a, const Vec3d& b);
    friend ostream& operator <<(ostream& s, const Vec3d& a);
    friend double dot(const Vec3d& a, const Vec3d& b);
    friend double dist(const Vec3d& a, const Vec3d& b);
};
double dot(const Vec3d& a, const Vec3d& b){
    double dproduct = 0;
    for (int i = 0; i < 3; i++){
    dproduct += a.m[i] * b.m[i];
    }
    return dproduct;
}

// Scalar multiplication: vector * scalar
Vec3d operator *(const Vec3d& a, int b){
    Vec3d product;
    
    for (int i = 0; i < 3; i++){
        product.m[i] = a.m[i] * b;
    }
    return product;
}
// Scalar multiplication reverse direction: scalar * vector
Vec3d operator *(int b, const Vec3d& a){
    Vec3d product;
    
    for (int i = 0; i < 3; i++){
        product.m[i] = a.m[i] * b;
    }
    return product;
}
// Vector addition: vector + vector
Vec3d operator +(const Vec3d& a, const Vec3d& b){
    Vec3d sum;
    
    for (int i = 0; i < 3; i++){
        sum.m[i] = a.m[i] + b.m[i];
    }
    return sum;
}
// Vector addition: vector - vector
Vec3d operator -(const Vec3d& a, const Vec3d& b){
    Vec3d diff;
    
    for (int i = 0; i < 3; i++){
        diff.m[i] = a.m[i] - b.m[i];
    }
    return diff;
}

// << operator to support cout <<
ostream& operator <<(ostream& s, const Vec3d& a){
    s << '{';
    for (int i = 0; i < 2; i++)
        s << a.m[i] << ", ";
    s << a.m[2] << '}';
    return s;
}

double dist(const Vec3d& a, const Vec3d& b){
    double distsqd = 0;
    for (int i = 0; i < 3; i++){
        distsqd += (a.m[i] - b.m[i]) * (a.m[i] - b.m[i]);
    }
    return sqrt(distsqd);
}

    int main() {
   
        Vec3d a(1.0, 2.5, 3.0);
        // a.print(); cout << endl;
       
        Vec3d b(1.0, 2.5); // z=0
        // b.print(); cout << endl;
        
        Vec3d c(1.0); // y,z = 0
        // c.print(); cout << endl;

        Vec3d d; // x,y,z=0
        // d.print(); cout << endl;
        
        //Vec3d e(); //THIS IS A FUNCTION!!!
        
        Vec3d e = a * 2; // scalar multiplication
        // e.print();
    
        Vec3d f = 2 * a; // reverse direction
        // f.print();
        
        Vec3d g = a + b; // vector addition
        // cout << a << endl;
        // cout << b << endl;
        // cout << g << endl;
        
        Vec3d h = a - b; // vector subtraction
        cout << a << endl;
        cout << b << endl;
        // cout << h << endl;
        
        double z1 = dot(a,b); // function
        double z2 = a.dot(b); // method
        cout << z1 << endl << z2 << endl;
        
        // add static later
        double w1 = a.dist(b);
        cout << w1 << endl;
        
        double w2 = dist(a,b);
        cout << w2 << endl;
        #if 0
        #endif
    }