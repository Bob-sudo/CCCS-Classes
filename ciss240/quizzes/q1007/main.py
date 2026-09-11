from latextool_basic import *
p = FunctionPlot(domain='0:3.5', height='1.5in')
p.add('2 * x**2.3 * cos(x**4.5 + 1) + 20', color='red', python=1, pin='below', num_points=2000,
pin_message='')
print(p)

