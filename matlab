import sympy as sp

x = sp.symbols('x')
y = sp.exp(x)  # Exponential curve y = e^x
dy_dx = sp.diff(y, x)
d2y_dx2 = sp.diff(dy_dx, x)
R = ((1 + dy_dx**2)**(3/2)) / abs(d2y_dx2)
X = x - dy_dx * (1 / sp.sqrt(1 + dy_dx**2))
Y = y + R * (1 / sp.sqrt(1 + dy_dx**2))

R_func = sp.lambdify(x, R, 'numpy')
X_func = sp.lambdify(x, X, 'numpy')
Y_func = sp.lambdify(x, Y, 'numpy')

x_val = 1
radius = R_func(x_val)
center = (X_func(x_val), Y_func(x_val))

print(f"Radius: {radius}")
print(f"Center: {center}")
