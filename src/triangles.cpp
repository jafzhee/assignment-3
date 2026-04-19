/* 
Anda diminta untuk mengimplementasikan class dengan nama Triangle 
yang didalamnya memuat 3 data dalam class Point2D yang telah diimplementasikan

Tujuan dari program adalah menentukan apakah suatua Triangle adalah 
sama kaki, sama sisi, siku-siku, dan sembarang

Input:
    vector dari suatu Triangle (dengan banyak sebesar 3*N) --> N = total Triangle

Output
    print setiap line dengan "sama kaki", "sama sisi", "siku-siku", atau "sembarang"


Silahkan gunakan teori dan implementasi yang telah diajarkan dikelas
*/

#include "include/triangles.hpp"
#include <cmath>
#include <algorithm>

Triangle::Triangle() {}

Triangle::Triangle(Point2D t1, Point2D t2, Point2D t3)
{
    _t1 = t1;
    _t2 = t2;
    _t3 = t3;
}

void Triangle::SetT1(Point2D t1) { _t1 = t1; }
void Triangle::SetT2(Point2D t2) { _t2 = t2; }
void Triangle::SetT3(Point2D t3) { _t3 = t3; }

Point2D Triangle::GetT1() const { return _t1; }
Point2D Triangle::GetT2() const { return _t2; }
Point2D Triangle::GetT3() const { return _t3; }

// menghitung jarak
float Triangle::distance(Point2D a, Point2D b)
{
    return sqrt(
        pow(a.GetX() - b.GetX(), 2) +
        pow(a.GetY() - b.GetY(), 2) +
        pow(a.GetZ() - b.GetZ(), 2)
    );
}

// menenentukan tipe segitiga
std::string Triangle::TriangleType()
{
    float a = distance(_t1, _t2);
    float b = distance(_t2, _t3);
    float c = distance(_t1, _t3);

    float sides[3] = {a, b, c};
    std::sort(sides, sides + 3);

    // sama sisi
    if (abs(a - b) < 1e-6 && abs(b - c) < 1e-6)
        return "sama sisi";

    // sama kaki
    if (abs(a - b) < 1e-6 || abs(b - c) < 1e-6 || abs(a - c) < 1e-6)
        return "sama kaki";

    // siku-siku 
    if (abs(sides[0]*sides[0] + sides[1]*sides[1] - sides[2]*sides[2]) < 1e-6)
        return "siku-siku";

    return "sembarang";
}