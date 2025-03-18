#include <iostream>
#include <cmath>
#include <stdexcept>

class Triangle {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw std::invalid_argument("All sides must be greater than zero.");
        }
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw std::invalid_argument("Sum of any two sides must be greater than the third side.");
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double area(bool isRightAngled = false) {
        if (isRightAngled) {
            return areaRightAngled();
        } else {
            return areaHeron();
        }
    }

    double areaRightAngled() {
        // Assuming a and b are the legs of the right triangle
        return 0.5 * a * b;
    }

    double areaHeron() {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    try {
        Triangle t1(3, 4, 5); // Right-angled triangle
        std::cout << "Area of right-angled triangle: " << t1.area(true) << std::endl;

        Triangle t2(5, 6, 7); // Any triangle
        std::cout << "Area of triangle using Heron's formula: " << t2.area() << std::endl;

        Triangle t3(-1, 2, 3); // Invalid input
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Triangle t4(1, 2, 4); // Invalid input
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
