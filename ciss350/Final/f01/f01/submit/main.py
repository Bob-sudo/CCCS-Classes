from latextool_basic import *
print(r'''
\begin{center}
%s
\end{center}
''' % graph(shape='circle',
        yscale=1.3,
        minimum_size='5mm',
        layout='''
           a
         b   c
        e d f g
       k l n p
        ''',
        edges='a>b,a>c,b>d,b>e,c>f,c>g,e>k,e>l,f>n,f>p',
        ))

