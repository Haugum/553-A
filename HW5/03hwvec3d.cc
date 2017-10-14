#include <iostream>
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

    // void print(){
    //     cout << '{';
    //     for (int i = 0; i < 2; i++){
    //         cout << m[i] << ", ";
    //     }
    //     cout << m[2] << '}' << endl;
    // }

    friend Vec3d operator *(const Vec3d& a, int b);
    friend Vec3d operator *(int b, const Vec3d& a);
    friend Vec3d operator +(const Vec3d& a, const Vec3d& b);
    friend ostream& operator <<(ostream& s, const Vec3d& a);
};

Vec3d operator *(const Vec3d& a, int b){
    Vec3d product;
    
    for (int i = 0; i < 3; i++){
        product.m[i] = a.m[i] * b;
    }
    return product;
}
Vec3d operator *(int b, const Vec3d& a){
    Vec3d product;
    
    for (int i = 0; i < 3; i++){
        product.m[i] = a.m[i] * b;
    }
    return product;
}

Vec3d operator +(const Vec3d& a, const Vec3d& b){
    Vec3d sum;
    
    for (int i = 0; i < 3; i++){
        sum.m[i] = a.m[i] + b.m[i];
    }
    return sum;
}

ostream& operator <<(ostream& s, const Vec3d& a){
    s << '{';
    for (int i = 0; i < 2; i++)
        s << a.m[i] << ", ";
    s << a.m[2] << '}';
    return s;
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
        cout << a << endl;
        cout << b << endl;
        cout << g << endl;
        #if 0
        Vec3d h = a - b; // vector subtraction
        double z1 = dot(a,b); // function
        double z2 = a.dot(b); // method
        // add static later
        double w1 = a.dist(b);
        double w2 = dist(a,b);
        #endif
    }