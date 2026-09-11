from latextool_basic import Plot, array
def drawarray(*xs):
    p = Plot()
    s = array(x0=0.5, y0=0.5, width=0.8, height=0.8, xs=xs)
    p.add(s)
    print(p)
