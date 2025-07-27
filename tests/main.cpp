#include <iostream>
#include "polyfit2d/polyfit2d.hpp"

int main() {
    using namespace polyfit2d;
    
    std::vector<Point3D> points = {
        {0, 0, 1},
        {1, 0, 2},
        {0, 1, 2},
        {1, 1, 3}
    };

    PolynomialSurface surface(1); // Fit linear surface
    surface.fit(points);

    std::cout << "f(0.5, 0.5) = " << surface.evaluate(0.5, 0.5) << std::endl;
}
