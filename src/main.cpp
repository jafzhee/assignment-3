#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "include/point2d.hpp"
#include "include/triangles.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    vector<Triangle> triangles;
    int n;
    cin >> n; // jumlah segitiga
    /*--------------------------
    Buat loop untuk membuat menginputkan data triangle (3 buah X Y Z data) ke dalam
    variable triangles
    --------------------------*/
    for(int i = 0; i < n; i++)
    {
        float x1,y1,z1,x2,y2,z2,x3,y3,z3;

        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        cin >> x3 >> y3 >> z3;

        Point2D p1(x1,y1,z1);
        Point2D p2(x2,y2,z2);
        Point2D p3(x3,y3,z3);

        triangles.push_back(Triangle(p1,p2,p3));
    }
    /*------------------------*/


    /*--------------------------
    Implementasikan kode untuk melakukan pengecekan apakah data pada variable triangles
    adalah "sama kaki", "sama sisi", "siku-siku", atau "sembarang"
    --------------------------*/
   for(auto t : triangles)
    {
        cout << t.TriangleType() << endl;
    }
    /*------------------------*/

    return 0;
}