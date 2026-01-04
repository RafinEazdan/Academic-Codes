import pandas as pd
import csv
import numpy as np
import matplotlib.pyplot as plt

file = open("E:/.D/Codes 2-2/CSE 2204- Numerical/asssignment/interpolation.csv")
type(file)

years= []
populations = []
with open ('E:/.D/Codes 2-2/CSE 2204- Numerical/asssignment/interpolation.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter = ',')
    next(reader)
    for row in reader:
        year,population = row
        years.append(int(year))
        populations.append(int(population))

def print_fd(forward_diff):
  for index in forward_diff:
    for element in index:
      print(element, end=' ')
    print('\n')

def gauss_forward_difference(x,y,xi):
  n = len(x)
  h = x[1] - x[0]
  forward_diff = [y]

  for i in range (1,n):
    next_diff = []
    for j in range(n - i):
      next_diff.append(forward_diff[i - 1][j+1] - forward_diff[i-1][j])
    forward_diff.append(next_diff)

  dif = pd.DataFrame(forward_diff).transpose()
  dif.index = x
  dif.colums = [f'D{n}' for n in range(n)]

  result = y[0]
  u = (xi-x[0]) / h
  for i in range(1,n):
    term = forward_diff[i][0]
    for j in range(i):
      term *= (u-j)
      term /= (j+1)
    result += term
  return result,dif

x = years
y = populations

xi = 2007

interpolated_value, difference_table = gauss_forward_difference(x,y,xi)

print('Forward Difference Table: ')
print(difference_table)

print('\nInterpolated value at ',xi,'is: ',interpolated_value)

#root finding
def newton_raphson(func,func_derivative, x0,tol=1e-10,max_iter=1000):
  x= x0
  iter_count = 0

  while iter_count < max_iter:
    f_x = func(x)
    f_prime_x = func_derivative(x)

    if abs(f_x) < tol:
      return x,iter_count

    if f_prime_x == 0:
      return None, iter_count

    x = x - f_x / f_prime_x
    iter_count +=1
  return None, iter_count

def cubic_function(x):
  return x**3 -4*x**2 -10000000

def cubic_function_derivative(x):
  return 3*x**2 - 8*x

initial_guess = 5
root,iterations = newton_raphson(cubic_function, cubic_function_derivative,initial_guess)

if root is not None:
  print('Root found at x= ',root,' after: ',iterations,'iterations.')
  print('The population would be 10 million after ', round(root),'years.')
else:
  print('Newton-Raphson method did not converge for the guess')

#curve fitting  
def linear_least_squares(x,y):
  x = np.array(x)
  y = np.array(y)

  n = len(x)
  sum_x = np.sum(x)
  sum_y = np.sum(y)
  sum_xy = np.sum(x*y)
  sum_x_squared = np.sum(x**2)

  m = (n*sum_xy - sum_x * sum_y)/(n * sum_x_squared - sum_x**2)
  b = (sum_y - m* sum_x)/n

  return m,b

def predict_values(x,m,b):
  x = np.array(x)
  y_predicted = m*x+b
  return y_predicted

def plot_linear_fit(x,y,m,b,x_predict,y_predict):
  x = np.array(x)
  plt.scatter(x,y,label='Data Points')
  plt.plot(x, m*x+b,color='red',label=f'linear fit: y = {m:.2f}x+{b:.2f}')
  plt.scatter(x_predict, y_predict, color='green',label='Predicted Values')
  plt.xlabel('X-axis')
  plt.ylabel('Y-axis')
  plt.legend()
  plt.show()

x_data = years
y_data = populations

m,b = linear_least_squares(x_data,y_data)
print(f'Linear Equation: y = {m:.2f}x + {b:.2f}')
#predict values x_data
x_predict = [2023,2024,2025,2026,2027,2028,2029,2030,2031,2032]
y_predict = predict_values(x_predict,m,b)
print(f'Predicted values for x_predict: {y_predict}')

plot_linear_fit(x_data,y_data,m,b,x_predict,y_predict)