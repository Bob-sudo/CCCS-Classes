from latextool_basic import Plot, grid, array
p = Plot()
s = array(x0=0.5, y0=0.5, width=0.8, height=0.8,
          xs=[-8,-7,-7,-3,-1,1,2,3,4,4,8,12,15,16,19])
p.add(s)
print(p)

