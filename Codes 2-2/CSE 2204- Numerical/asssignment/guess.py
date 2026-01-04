import numpy as np
from scipy.optimize import fsolve

# Define the function
def equation(x):
    return 3639932 * np.exp(0.012 * x) - 10000000

# Use fsolve to find a root
initial_guess = 3  # You can change this to other values as well
root = fsolve(equation, initial_guess)

print("Initial guess:", initial_guess)
print("Approximate root:", root[3])
