# Program 8: Genetic Algorithm for optimization
# Maximise f(x) = x * sin(10*pi*x) + 1 on [-1, 2]  (a classic multi-peak function)
import random, math
import matplotlib.pyplot as plt

random.seed(1)
LOW, HIGH = -1.0, 2.0
BITS, POP, GENS = 22, 50, 60
P_CROSS, P_MUT = 0.8, 0.02

f = lambda x: x * math.sin(10 * math.pi * x) + 1

def decode(chrom):                       # binary string -> real number
    return LOW + int("".join(map(str, chrom)), 2) * (HIGH - LOW) / (2 ** BITS - 1)

def select(pop, fit):                    # tournament selection
    a, b = random.sample(range(len(pop)), 2)
    return pop[a][:] if fit[a] > fit[b] else pop[b][:]

def crossover(p1, p2):                   # single-point crossover
    if random.random() < P_CROSS:
        pt = random.randint(1, BITS - 1)
        return p1[:pt] + p2[pt:], p2[:pt] + p1[pt:]
    return p1[:], p2[:]

def mutate(c):                           # bit-flip mutation
    return [1 - g if random.random() < P_MUT else g for g in c]

pop = [[random.randint(0, 1) for _ in range(BITS)] for _ in range(POP)]
best_hist = []
best_x, best_f = None, -1e9

for gen in range(GENS):
    fit = [f(decode(c)) for c in pop]
    i = max(range(POP), key=fit.__getitem__)
    if fit[i] > best_f:
        best_f, best_x = fit[i], decode(pop[i])
    best_hist.append(best_f)
    if gen % 10 == 0 or gen == GENS - 1:
        print(f"Generation {gen:2d}: best x = {best_x:.5f}, f(x) = {best_f:.5f}")
    new = [pop[i][:]]                    # elitism
    while len(new) < POP:
        c1, c2 = crossover(select(pop, fit), select(pop, fit))
        new += [mutate(c1), mutate(c2)]
    pop = new[:POP]

print(f"\nBest solution: x = {best_x:.5f}, f(x) = {best_f:.5f}")

plt.plot(best_hist); plt.xlabel("Generation"); plt.ylabel("Best fitness")
plt.title("Genetic Algorithm convergence"); plt.show()