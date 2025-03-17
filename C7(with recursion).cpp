#include <iostream>

int gcdRecursive(int a, int b) {
    if(b == 0) return a;
    return gcdRecursive(b, a % b);
}

int main() {
    int num1, num2;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    int result = gcdRecursive(num1, num2);
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << result << std::endl;

    return 0;
}
