
Aspect | Traditional Algorithms	| Genetic Algorithms (GA)
|--|--|--|
Approach | Rule-based, deterministic | Inspired by natural selection; probabilistic
Problem Type | Well-defined problems with known rules | Complex, non-deterministic, combinatorial optimization
Exploration vs Exploitation	| Primarily exploitation | Balanced mix of exploration and exploitation
Search Space | Exhaustive or predefined strategy | Stochastic exploration of large solution spaces
Convergence	| Typically converge to a single optimal solution | May converge to multiple or diverse solutions
User Intervention	| Minimal	| Requires tuning of parameters (mutation rate, crossover rate, population size)

---

Steps:

1. Select Encoding type
2. Choose population size
3. Randomly choose initial population
4. Select parental chromosomes
5. Crossover and mutatio
6. Evaluation of offspring
7. If stopping criteria not reached, go to step 4


Eg. Maximize the f(x) = x², where x ranges from 0 to 31.
