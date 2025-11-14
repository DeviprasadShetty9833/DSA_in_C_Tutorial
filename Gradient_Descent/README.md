
# 📌 What is Gradient Descent?

Gradient Descent is an iterative optimization algorithm used to find the minimum of a function. Think of standing on a mountain at night:

- You cannot see the valley (the minimum),
- You only know the slope at your feet,
- You take small steps downhill,
- Recalculate the slope again,
- Repeat until you reach the valley.

> You follow the negative gradient (direction of steepest decrease) until the function cannot reduce any further.

---

# 📌 Aim

We use Gradient Descent to find a root of the polynomial: f(x) = x² - 5x + 6

This function has roots at x = 2 and x = 3.

---

# 📌 How Does Gradient Descent Work? 

At each step( x ), Gradient Descent:

1. Calculates the value of the function (height of mountain).
2. Calculates the derivative (how steep the slope is).
3. Computes the gradient of the cost function.
4. Moves a little down the slope:

```html
x_next = x_current - η • gradient
```
Where:

η (eta) = learning rate = step size

gradient tells how far & in which direction to move. (+ve: slope goes up , -ve: slope goes down)

smaller slopes → smaller steps → approach to minimum

---


# 📌 Step-By-Step Example

Starting at x = 2.52:

1. Polynomial: f(x) = x² – 5x + 6
2. Derivative: f'(x) = 2x – 5
3. Cost: f(x)²
4. Gradient: 2 * f(x) * f'(x)  ...( Derivative of Cost )
5. Update x: x_next = x_current – learning_rate * gradient   ...( eg. 0.01 = small safe step )
6. x moves a little to the right:

2.52 → 2.53 → 2.55 → 2.60 → 2.80 → 2.95 → 2.99

7. Slope becomes almost flat
8. Algorithm stops when: |x_next - x_current| < tolerance    ...(near x = 3, steps become small, slope → 0)

---

# 📌 Why Are We Minimizing ?

To find roots of , we minimize:

Cost = f(x)²

Because:

At the root, f(x) = 0

So f(x)² = 0 → perfect minimum

- Squaring ensures the value is always positive. This gives a smooth curve easy for gradient descent


Derivative of cost:

d/dx( f(x)² ) = 2 * f(x) * f'(x)


---

# 📌 C Implementation of Gradient Descent

*Code:*
```c
#include <stdio.h>
#include <math.h>

// Polynomial: f(x) = x^2 - 5x + 6
double polynomial(double x) {
    return (x * x) - (5 * x) + 6;
}

// Derivative: f'(x) = 2x - 5
double derivative(double x) {
    return (2 * x) - 5;
}

int main() {
    double x_current = 2.52;      // Starting point
    double learning_rate = 0.01;  // Step size
    double tolerance = 0.0001;    // Stop when change is tiny
    int max_iterations = 100000;

    printf("Finding a root of the polynomial using Gradient Descent...\n");

    for (int i = 0; i < max_iterations; i++) {
        double fx = polynomial(x_current);   // f(x)
        double dfx = derivative(x_current);  // f'(x)

        double gradient = 2 * fx * dfx;      // Gradient of cost

        double x_next = x_current - learning_rate * gradient;

        if (fabs(x_next - x_current) < tolerance) {   // fabs() returns the absolute value of a floating-point number.
            printf("Iterations: %d\n", i);
            x_current = x_next;
            break;
        }

        x_current = x_next;
    }

    printf("Root found at x = %lf\n", x_current);
    printf("Polynomial value at root: %lf\n", polynomial(x_current));

    return 0;
}
```

---


# 📌 Key Takeaways 

- Gradient Descent is an iterative optimization algorithm.
- Moves in the direction of negative gradient.
- Uses learning rate to control step size.
- Stops when movement between steps is very small.
- Useful for minimizing functions and finding roots.
- Used everywhere in AI, ML, and optimization.

