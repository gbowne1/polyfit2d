#include "polyfit2d/polyfit2d.hpp"
#include <Eigen/Dense>
#include <cmath>
#include <stdexcept>
#include <iostream>

namespace polyfit2d {

namespace {
    // Utility to count number of terms in a 2D polynomial of degree d
    int numTerms(int degree) {
        return (degree + 1) * (degree + 2) / 2;
    }

    // Generate monomials (x^i * y^j) where i + j <= degree
    std::vector<double> monomials(double x, double y, int degree) {
        std::vector<double> result;
        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= degree - i; ++j) {
                result.push_back(std::pow(x, i) * std::pow(y, j));
            }
        }
        return result;
    }
}

PolynomialSurface::PolynomialSurface(int degree)
    : degree_(degree), coefficients_(numTerms(degree), 0.0) {}

void PolynomialSurface::fit(const std::vector<Point3D>& points) {
    const int nTerms = numTerms(degree_);
    
    if (points.size() < nTerms) {
        throw std::runtime_error("Insufficient number of points for fitting.");
    }

    const int nPoints = points.size();

    Eigen::MatrixXd A(nPoints, nTerms);
    Eigen::VectorXd b(nPoints);

    for (int i = 0; i < nPoints; ++i) {
        auto mono = monomials(points[i].x, points[i].y, degree_);
        for (int j = 0; j < nTerms; ++j) {
            A(i, j) = mono[j];
        }
        b(i) = points[i].z;
    }

    // Solve normal equations
    Eigen::VectorXd coeffs = A.colPivHouseholderQr().solve(b);

    for (int i = 0; i < nTerms; ++i)
        coefficients_[i] = coeffs[i];
}

double PolynomialSurface::evaluate(double x, double y) const {
    auto mono = monomials(x, y, degree_);
    double result = 0.0;
    for (size_t i = 0; i < mono.size(); ++i) {
        result += mono[i] * coefficients_[i];
    }
    return result;
}

std::vector<double> PolynomialSurface::getCoefficients() const {
    return coefficients_;
}

} // namespace polyfit2d

