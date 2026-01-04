def falsePosition_method(func,a,b,tol=1e-10,max_iter=100):
  if func(a)*func(b) >= 0:
    raise ValueError("Same sign at the both end.False Position Method Error")

  iter_count = 0
  while(b-a)/2.0 >tol and iter_count < max_iter:
    c = (a+b)/2.0
    if func(c)==0.0:
      return c,iter_count
    elif func(c)*func(a) < 0:
      b=c
    else:
      a=c
    iter_count+=1

  #return the midpoint
  root = (a+b)/2.0
  return root,iter_count

def quadratic_function(x):
  return x**3-2*x-5

initial_interval = (2,3)
root, iterations = falsePosition_method(quadratic_function, *initial_interval)

if root is not None:
  print('Root found at x = ',root,' after ',iterations,' iterations.')
else:
  print('Bisection method did not converge within the specified tolerance.')