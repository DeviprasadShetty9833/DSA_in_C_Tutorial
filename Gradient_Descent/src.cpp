#include <iostream>
#include <cmath>
using namespace std;

// Polynomial: f(x) = x^2 - 5x + 6
double polynomial(double x) {
    return (x * x) - (5 * x) + 6;
}

// Derivative: f'(x) = 2x - 5
double derivative(double x) {
    return (2 * x) - 5;
}

int main() {
    double x_current = 2.52;        // Starting point
    double learning_rate = 0.01;    // Step size
    double tolerance = 0.0001;      // Stop when change is tiny
    int max_iterations = 100000;

    cout << "Finding a root of the polynomial using Gradient Descent..." << endl;

    for (int i = 0; i < max_iterations; i++) {
        double fx = polynomial(x_current);   // f(x)
        double dfx = derivative(x_current);  // f'(x)

        double gradient = 2 * fx * dfx;      // Gradient of cost: d/dx (f(x)^2)

        double x_next = x_current - learning_rate * gradient;

        // Stop if movement is very small
        if (fabs(x_next - x_current) < tolerance) {
            cout << "Iterations: " << i << endl;
            x_current = x_next;
            break;
        }

        x_current = x_next;
    }

    cout << "Root found at x = " << x_current << endl;
    cout << "Polynomial value at root: " << polynomial(x_current) << endl;

    return 0;
}
