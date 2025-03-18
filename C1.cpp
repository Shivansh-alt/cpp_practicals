#include <iostream>
#include <cmath> 
using namespace std;

int main(int argc, char* argv[]) {
    int n;

    if (argc > 1) {
        n = atoi(argv[1]); 
    } else {
        
        cout << "Enter the number of terms (n): ";
        cin >> n;
    }

    if (n <= 0) {
        cout << "Invalid input. Number of terms must be a positive integer." << endl;
        return 1; 
    }

    double sum = 0.0; 

    
    for (int i = 1; i <= n; i++) {
        double term = pow(-1, i + 1) / pow(i, i); 
        sum += term; 
    }

    cout << "The sum of the first " << n << " terms of the series is: " << sum << endl;

    return 0;
}
