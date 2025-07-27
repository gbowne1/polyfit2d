#ifndef POLYFIT2D_HPP
#define POLYFIT2D_HPP

#include <vector>
#include <utility>

namespace polyfit2d {

struct Point3D {
    double x, y, z;
};

class PolynomialSurface {
public:
    PolynomialSurface(int degree);  // Constructor: specify degree of polynomial

    void fit(const std::vector<Point3D>& points);  // Fit the model to data
    double evaluate(double x, double y) const;     // Evaluate f(x, y)
    std::vector<double> getCoefficients() const;   // Get internal coefficients

private:
    int degree_;
    std::vector<double> coefficients_; // Order: [1, x, y, x², xy, y², ...]
};

}

#endif // POLYFIT2D_HPP

