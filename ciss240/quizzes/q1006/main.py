from latextool_basic import *
p = FunctionPlot(domain='0:3', height='1.5in')
p.add('x**2 * sin(x**3)', color='red', python=1, pin='below', num_points=1000,
pin_message='')
p.add('0', color='blue', python=1, pin='below', num_points=10,
pin_message='')
print(p)

