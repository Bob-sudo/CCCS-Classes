import math
from latextool_basic import *
plot = FunctionPlot(width="6in", height="3in")

plot.add(tuple((n, 3.5 * n**3/(1 + 2 * n + n * sin(2*n))) for n in range(0, 1000, 10)),
         line_width='2', color='red', legend='$f(n)$')

#===============================================================================
# TO BE COMPLETED: Test C * n**k for different values of C and k
#===============================================================================
C = 1
k = 2
plot.add(tuple((n, C * n**k) for n in range(0, 1000, 10)),    # plotting C * n^k
         line_width='2', color='green', legend='$C \cdot g(n) = %s \cdot n^%s$' % (C, k))

print(plot)

