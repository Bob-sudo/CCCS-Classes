from latextool_basic import *
plot = FunctionPlot(width="3in", height="2in")
plot.add(((100, 1),
          (200, 2),
          (300, 0.5)),
          line_width='2', color='red', legend='bubblesort')
plot.add(((100, 5),
          (200, 3),
          (300, 7)),
          line_width='2', color='green', legend='bubblesort2')
plot.add(((100, 7),
          (200, 4),
          (300, 5)), line_width='2', color='blue', legend='selectionsort')
print(plot)

