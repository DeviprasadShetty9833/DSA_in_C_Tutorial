
# 📌 What is Gradient Descent?

Gradient Descent is an iterative optimization algorithm used to find the **minimum of a function**. Think of standing on a mountain at night:

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
x_next = x_current - α • gradient
```
Where:

α = learning rate = step size

gradient tells how far & in which direction to move. (+ve: slope goes up , -ve: slope goes down)

smaller slopes → smaller steps → approach to minimum

---


# 📌 Step-By-Step Example

Starting at x = 2.52:

1. Polynomial: f(x) = x² – 5x + 6
2. Derivative: f'(x) = 2x – 5
3. Cost: J(x) = f(x)²
4. Gradient: G = J'(x) = 2 * f(x) * f'(x)  ...( Derivative of Cost )
5. Update x: x_next = x_current – learning_rate * gradient   ...( eg. α = 0.01 = small safe step )
6. x moves a little to the right:

2.52 → 2.53 → 2.55 → 2.60 → 2.80 → 2.95 → 2.99

7. Slope becomes almost flat
8. Algorithm stops when: |x_next - x_current| < tolerance    ...(near x = 3, steps become small, slope → 0)

> If we minimize f(x): We get x where f'(x) = 0 (minimum point). But we want: x where f(x) = 0 (roots)

f(x) = x² - 5x + 6

- ❌ Minimize f(x) → converges to x=2.5 where f(x)=-0.25 
- ✅ Minimize [f(x)]² → converges to x=2 or x=3 where f(x)=0


![image](https://github.com/DeviprasadShetty9833/DSA_Journal/blob/bfb9bdb30d5732f6957f15f6409ba0d610ac0a65/Gradient_Descent/assets/Min.jpg)

Let's find Root of Quadratic equation f(x) = x² – 5x + 6 using gradient descent for 4 iterations.
Consider Learning rate (α) = 0.01

Now we know that the roots of x² – 5x + 6 are 2 & 3.

Here we have 2 choices to select value of x,

<table>
  <tr>
    <td colspan="3" align="center">
      <strong>Value of x</strong>
    </td>
  </tr>
  <tr>
    <td align="center" width="33%">
      <strong>Inside the range</strong> [x = 2.5 at f'(x) = 0]
    </td>
    <td align="center" width="34%">
      <strong>OR</strong>
    </td>
    <td align="center" width="33%">
      <strong>Outside the range</strong>
    </td>
  </tr>
  <tr>
    <td align="center">
      <table>
        <tr>
          <td align="center"><strong>For root 3</strong></td>
          <td align="center"><strong>For root 2</strong></td>
        </tr>
        <tr>
          <td align="center">x > 2.5</td>
          <td align="center">x < 2.5</td>
        </tr>
      </table>
    </td>
    <td align="center"></td>
    <td align="center">
      <table>
        <tr>
          <td align="center"><strong>For root 3</strong></td>
          <td align="center"><strong>For root 2</strong></td>
        </tr>
        <tr>
          <td align="center">x > 3 i.e 4</td>
          <td align="center">x < 3 i.e 1</td>
        </tr>
      </table>
    </td>
  </tr>
</table>



xₙ
x₀
x₁
x₂
x₃
x₄
x₅
x₆

| Iteration | xₙ | Polynomial f(x) | Derivative f'(x) | Gradient G | x₍ₙ₊₁₎ |
|--|--|--|--|--|--|
| n | xₙ | xₙ² - 5xₙ + 6 | 2xₙ - 5 | 2 * (xₙ² - 5xₙ + 6) * (2xₙ - 5) | xₙ - a * G |

Continue till reaching tolerance limit or number of iteration.

| Iteration | xₙ | Polynomial f(x) | Derivative f'(x) | Gradient G | x₍ₙ₊₁₎ |
|--|--|--|--|--|--|
| 0 | 4.000000 | 2.000000 | 4.000000 | 12.000000
| 1 | 3.880000 | 1.334400 | 1.780623 | 8.363366
| 2 | 3.796366 | 0.889891 | 0.791906 | 5.829456

Let X * 0 = 1 f(x) = x ^ 2 - 7x + 10 (at x = 1 )=4 f' * (x) = 2x - 7(atX = 1) = - 5 G=2*4-5-40 X1XO-aG1-(0.01-40) = 1.4 f(x1)= 1.96 - 9.8 + 10 = 2.16

Root of Quadratic equation using gradient descent

Iteration 2

Let X * 0 = 1.4

f(x) = x ^ 2 - 7x + 10 (at X = 1.4 )=2.16 f' * (x) = 2x - 7 (at X = 1.4) 2.8-7 = -4.2 G22.16-4.2-18.144 X2X1-aG => 1.4-(0.01-18.144)=1.58 f(x1) => (1.581.58)-(71.58) + 10 = 1.436


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

*Algorithm:*

Input:
- Function f(x)
- Derivative f'(x)
- Learning rate α
- Initial guess x₀
- Tolerance ε

Output:
- Approximate value of x where the function is minimum (or root when using f(x)²)

```c
Step 1: Initialize

1. Choose an initial point: x = x₀
2. Set tolerance ε.
3. Set maximum iterations.

---

Step 2: Repeat Until Convergence

For each iteration:

1. Compute function value f = f(x)
2. Compute derivative (slope) f' = f'(x)
3. Compute gradient
    If minimizing : gradient = 2 * f(x) * f'(x)
4. Update x (move opposite to slope)
    x_next = x_current – α * gradient
5. Check convergence
    If: |x_next - x_current| < ε
6. Otherwise: x = x_next

---

Step 3: Return Result

Return the final value of x as the approximate solution.

```

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

        if (fabs(x_next - x_current) < tolerance) {   // fabs() returns the absolute value of a floating-point number. It helps you measure “how much” you moved, not the direction.
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

- Gradient Descent is an algorithm to minimize a function by optimizing parameters.
- Moves in the direction of negative gradient.
- Uses learning rate to control step size.
- Stops when movement between steps is very small.
- Useful for minimizing functions and finding roots.
- Used everywhere in AI, ML, and optimization.

# References 
- Applications: [Coffee Shop Reach Time](https://youtu.be/QoK1nNAURw4?si=pUZbon9PDxsLyYvV)
