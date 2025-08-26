# polyfit2d

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Build with CMake](https://img.shields.io/badge/build%20system-CMake-blue.svg)](https://cmake.org/)
[![Language: C++](https://img.shields.io/badge/language-C++17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-cross--platform-lightgrey.svg)](https://en.wikipedia.org/wiki/Cross-platform_software)

**polyfit2d** is a lightweight, header-based C++17 library for fitting and evaluating 2D polynomial surfaces using least squares. It's built on top of [Eigen](https://eigen.tuxfamily.org/) for matrix operations and provides a clean, simple interface.

---

## ✨ Features

- Fit a polynomial surface of arbitrary degree to 3D data points.
- Efficient least-squares solver using Eigen.
- Easy evaluation of the fitted surface at any (x, y) point.
- Header-only interface.
- MIT licensed and open source.

---

## 📦 Installation

This project uses **CMake** for configuration and building.

### 🔧 Dependencies

- [Eigen 3.3+](https://eigen.tuxfamily.org/)
- C++17 compatible compiler

### 🔨 Build

```bash
git clone https://github.com/gbowne1/polyfit2d.git
cd polyfit2d
mkdir build && cd build
cmake ..
make
./polyfit2d_tests
```

### 🧪 Example

Here's a good way to use it

```cpp
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

    PolynomialSurface surface(1);
    surface.fit(points);

    std::cout << "f(0.5, 0.5) = " << surface.evaluate(0.5, 0.5) << std::endl;

    return 0;
}
```

### 📜 License

This project is licensed under the MIT License — see the LICENSE

### 🤝 Contributing

Contributions, issues and feature requests are welcome!

- Fork the repository

- Create your feature branch (git checkout -b feature/some-feature)

- Commit your changes (git commit -am 'Add new feature')

- Push to the branch (git push origin feature/some-feature)

- Create a new Pull Request
