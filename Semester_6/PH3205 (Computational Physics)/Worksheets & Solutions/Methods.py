import numpy as np
from typing import Callable, Tuple, Union

Scalar = Union[float, np.ndarray]

# DIFFERENTIATION

# Forward Difference
def forward_diff(f: Callable[[float], float], xn: float, h: float) -> float:
    """
    Compute the first derivative at x_n using the forward difference formula.

    Parameters:
      f: Callable function f(x).
      xn: Point x_n at which to approximate the derivative.
      h: Step size.

    Returns:
      Approximation to f'(x_n) computed as (f(x_n + h) - f(x_n)) / h.
    """
    return (f(xn+h) - f(xn))/h

# Backward Difference
def backward_diff(f: Callable[[float], float], xn: float, h: float) -> float:
  """
  Compute the first derivative at x_n using the backward difference formula.

  Parameters:
    f: Callable function f(x).
    xn: Point x_n at which to approximate the derivative.
    h: Step size.

  Returns:
    Approximation to f'(x_n) computed as (f(x_n) - f(x_n - h)) / h.
  """
  return (f(xn) - f(xn-h))/h

# Central Difference
def central_diff(f: Callable[[float], float], xn: float, h: float) -> float:
  """
  Compute the first derivative at x_n using the central difference formula.

  Parameters:
    f: Callable function f(x).
    xn: Point x_n at which to approximate the derivative.
    h: Step size.

  Returns:
    Approximation to f'(x_n) computed as (f(x_n + h) - f(x_n - h)) / (2*h).
  """
  return (f(xn+h) - f(xn-h))/(2*h)

# Five Point Approximation
def five_point_approx(f: Callable[[float], float], xn: float, h: float) -> float:
  """
  Compute the first derivative at x_n using the five-point stencil.

  Parameters:
    f: Callable function f(x).
    xn: Point x_n at which to approximate the derivative.
    h: Step size.

  Returns:
    Approximation to f'(x_n) computed as
    (f(x_n - 2*h) - 8*f(x_n - h) + 8*f(x_n + h) - f(x_n + 2*h)) / (12*h).
  """
  return (f(xn-2*h) - 8*f(xn-h) + 8*f(xn+h) - f(xn+2*h))/(12*h)



# INTEGRATION

# Trapezoidal Method
def trapezoidal(
  f: Callable[[np.ndarray], np.ndarray],
  m: int,
  lower: float = 0,
  upper: float = 1,
) -> Tuple[float, float]:
  """
  Approximate the definite integral using the composite trapezoidal rule.

  Parameters:
    f: Callable function f(x) that accepts a NumPy array of points.
    m: Number of subinterval pairs; total points are N = 2*m + 1.
    lower: Lower limit of integration.
    upper: Upper limit of integration.

  Returns:
    Tuple (s, h) where s is the integral approximation and h is the step size.
  """
  N = 2*m+1
  h = (upper-lower)/(N-1)
  hs = np.linspace(lower, upper, N)
  fs = np.array(f(hs))

  s = (h/2)*(fs[0] + fs[-1] + 2*sum(fs[1:-1]))
  return (s, h)

# Simpson's 1/3 Method
def simpson_13(
  f: Callable[[np.ndarray], np.ndarray],
  m: int,
  lower: float = 0,
  upper: float = 1,
) -> Tuple[float, float]:
  """
  Approximate the definite integral using composite Simpson's 1/3 rule.

  Parameters:
    f: Callable function f(x) that accepts a NumPy array of points.
    m: Number of subinterval pairs; total points are N = 2*m + 1.
    lower: Lower limit of integration.
    upper: Upper limit of integration.

  Returns:
    Tuple (s, h) where s is the integral approximation and h is the step size.
  """
  N = 2*m+1
  h = (upper-lower)/(N-1)
  hs = np.linspace(lower, upper, N)
  fs = np.array(f(hs))

  s = (h/3)*(fs[0] + fs[-1] + 4*sum(fs[1:-1:2]) + 2*sum(fs[2:-2:2]))
  return (s, h)

# Simpson's 3/8 Method
def simpson_38(
  f: Callable[[np.ndarray], np.ndarray],
  m: int,
  lower: float = 0,
  upper: float = 1,
) -> Tuple[float, float]:
  """
  Approximate the definite integral using composite Simpson's 3/8 rule.

  Parameters:
    f: Callable function f(x) that accepts a NumPy array of points.
    m: Number of subinterval triplets; total points are N = 3*m + 1.
    lower: Lower limit of integration.
    upper: Upper limit of integration.

  Returns:
    Tuple (s, h) where s is the integral approximation and h is the step size.
  """
  N = 3*m+1
  h = (upper-lower)/(N-1)
  hs = np.linspace(lower, upper, N)
  fs = np.array(f(hs))

  s = (3*h/8)*(fs[0] + fs[-1] + 3*(sum(fs[1:-1:3]) + sum(fs[2:-1:3])) + 2*sum(fs[3:-1:3]))
  return (s, h)

# Boole's Method
def boole(
  f: Callable[[np.ndarray], np.ndarray],
  m: int,
  lower: float = 0,
  upper: float = 1,
) -> Tuple[float, float]:
  """
  Approximate the definite integral using composite Boole's rule.

  Parameters:
    f: Callable function f(x) that accepts a NumPy array of points.
    m: Number of subinterval quartets; total points are N = 4*m + 1.
    lower: Lower limit of integration.
    upper: Upper limit of integration.

  Returns:
    Tuple (s, h) where s is the integral approximation and h is the step size.
  """
  N = 4*m+1
  h = (upper-lower)/(N-1)
  hs = np.linspace(lower, upper, N)
  fs = np.array(f(hs))

  s = (2*h/45)*(7*(fs[0] + fs[-1]) + 32*sum(fs[1:-1:2]) + 12*sum(fs[2:-1:4]) + 14*sum(fs[4:-1:4]))
  return (s, h)



# ODE Solving

# Euler
def euler(f: Callable[[float, Scalar], Scalar], x: float, y: Scalar, h: float) -> Scalar:
    """
    Advance one step using Euler's method.

    Parameters:
      f: Callable derivative function f(x, y).
      x: Current x value.
      y: Current y value (can be scalar or array-like).
      h: Step size.

    Returns:
      Estimated y value at x + h.
    """
    return y + h*f(x, y)

# Midpoint
def midpoint(
    f: Callable[[float, Scalar], Scalar],
    x: float,
    y: Scalar,
    h: float,
) -> Scalar:
    """
    Advance one step using the midpoint (RK2) method.

    Parameters:
      f: Callable derivative function f(x, y).
      x: Current x value.
      y: Current y value (can be scalar or array-like).
      h: Step size.

    Returns:
      Estimated y value at x + h.
    """
    k1 = h*f(x, y)
    return y + h*f(x + h/2, y + k1/2)

# RK4
def rk4(
    f: Callable[[float, Scalar], Scalar],
    x: float,
    y: Scalar,
    h: float,
) -> Scalar:
    """
    Advance one step using classical fourth-order Runge-Kutta.

    Parameters:
      f: Callable derivative function f(x, y).
      x: Current x value.
      y: Current y value (can be scalar or array-like).
      h: Step size.

    Returns:
      Estimated y value at x + h.
    """
    k1 = f(x, y)
    k2 = f(x + h/2, y + h*k1/2)
    k3 = f(x + h/2, y + h*k2/2)
    k4 = f(x + h, y + h*k3)

    return y + h*(k1 + 2*k2 + 2*k3 + k4)/6

# Function for calling different methods
def caller(
    f: Callable[[float, np.ndarray], np.ndarray],
    xs: np.ndarray,
    y0: np.ndarray,
    N: int,
    h: float,
    method: Callable[[Callable[[float, np.ndarray], np.ndarray], float, np.ndarray, float], np.ndarray],
) -> np.ndarray:
    """
    Generate solution values by repeatedly applying a one-step method.

    Parameters:
      f: Callable derivative function f(x, y).
      xs: Array of x values to step through.
      y0: Initial y value (array-like).
      N: Number of steps/points to compute.
      h: Step size.
      method: One-step method with signature method(f, x, y, h).

    Returns:
      Array of y values with shape (N, len(y0)).
    """
    y = y0
    ys = np.zeros((N, len(y0)))

    for i in range(N):
        x = xs[i]
        ys[i, :] = y
        y = method(f, x, y, h)
    
    return ys

# Verlet
def verlet(
  f: Callable[[float, Scalar], Scalar],
  x: float,
  yn: Scalar,
  ynm1: Scalar,
  h: float,
) -> Scalar:
  """
  Advance one step using the Verlet position update.

  Parameters:
    f: Callable acceleration function f(x, y).
    x: Current x value.
    yn: Current position y_n.
    ynm1: Previous position y_{n-1}.
    h: Step size.

  Returns:
    Estimated position y_{n+1}.
  """
  return 2*yn - ynm1 + 0.5*f(x, yn)*(h**2)

# Velocity Verlet
def velocity_verlet(
  f: Callable[[float, Scalar], Scalar],
  x: float,
  yn: Scalar,
  vn: Scalar,
  h: float,
) -> Tuple[Scalar, Scalar]:
  """
  Advance one step using the velocity Verlet method.

  Parameters:
    f: Callable acceleration function f(x, y).
    x: Current x value.
    yn: Current position y_n.
    vn: Current velocity v_n.
    h: Step size.

  Returns:
    Tuple (y_{n+1}, v_{n+1}) for the next position and velocity.
  """
  ynp1 = yn + vn*h + f(x, yn)*0.5*(h**2)
  vnp1 = vn + h*(f(x, yn) + f(x + h, ynp1))/2
  return ynp1, vnp1

# Leapfrog
def leapfrog(
  f: Callable[[float, Scalar], Scalar],
  x: float,
  yn: Scalar,
  vn: Scalar,
  h: float,
) -> Tuple[Scalar, Scalar]:
  """
  Advance one step using the leapfrog method.

  Parameters:
    f: Callable acceleration function f(x, y).
    x: Current x value.
    yn: Current position y_n.
    vn: Current velocity v_n.
    h: Step size.

  Returns:
    Tuple (y_{n+1}, v_{n+1}) for the next position and velocity.
  """
  vnph = vn + h*f(x, yn)/2
  ynp1 = yn + h*vnph
  vnp1 = vnph + h*f(x + h, ynp1)/2
  return ynp1, vnp1

# Caller function for verlet
def caller_v(
  f: Callable[[float, Scalar], Scalar],
  xs: np.ndarray,
  y0: Scalar,
  v0: Scalar,
  N: int,
  h: float,
) -> np.ndarray:
  """
  Generate positions using Verlet, given initial position and velocity.

  Parameters:
    f: Callable acceleration function f(x, y).
    xs: Array of x values to step through.
    y0: Initial position.
    v0: Initial velocity.
    N: Number of steps/points to compute.
    h: Step size.

  Returns:
    Array of positions y with length N.
  """
  ys = np.zeros(N)
  x0 = xs[0]
  ys[0] = y0

  # This is given
  ys[1] = y0 + v0*h + 0.5*f(x0, y0)*(h**2)

  for i in range(2, N):
    x = xs[i]
    ys[i] = verlet(f, x, ys[i-1], ys[i-2], h)

  return ys

# Caller function for velocity verlet and leapfrog
def caller_vvl(
  f: Callable[[float, Scalar], Scalar],
  xs: np.ndarray,
  y0: Scalar,
  v0: Scalar,
  N: int,
  h: float,
  method: Callable[
    [Callable[[float, Scalar], Scalar], float, Scalar, Scalar, float],
    Tuple[Scalar, Scalar],
  ],
) -> Tuple[np.ndarray, np.ndarray]:
  """
  Generate positions and velocities using a two-variable one-step method.

  Parameters:
    f: Callable acceleration function f(x, y).
    xs: Array of x values to step through.
    y0: Initial position.
    v0: Initial velocity.
    N: Number of steps/points to compute.
    h: Step size.
    method: One-step method with signature method(f, x, y, v, h).

  Returns:
    Tuple (ys, vs) of positions and velocities, each length N.
  """
  ys = np.zeros(N)
  vs = np.zeros(N)
  ys[0] = y0
  vs[0] = v0

  for i in range(1, N):
    x = xs[i]
    ys[i], vs[i] = method(f, x, ys[i-1], vs[i-1], h)

  return ys, vs
