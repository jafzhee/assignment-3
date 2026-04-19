#include "point2d.hpp"
#include <string>

class Triangle {
private:
    Point2D _t1, _t2, _t3;

public:
    Triangle();
    Triangle(Point2D t1, Point2D t2, Point2D t3);

    void SetT1(Point2D t1);
    void SetT2(Point2D t2);
    void SetT3(Point2D t3);

    Point2D GetT1() const;
    Point2D GetT2() const;
    Point2D GetT3() const;

    float distance(Point2D a, Point2D b);
    std::string TriangleType();
};
