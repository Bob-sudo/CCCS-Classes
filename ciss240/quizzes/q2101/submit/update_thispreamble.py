import re, os

def readfile(filename='thispreamble.tex'):
    f = open(filename, 'r')
    s = f.read()
    f.close()
    return s
def writefile(filename='thispreamble.tex', s=''):
    f = open(filename, 'w')
    f.write(s)
    f.close()
def getdefaultcourse():
    # get ciss??? or math??? from path
    p = re.compile(r'/((ciss|math)\d\d\d)(/|$)')
    s = os.getcwd()
    srch = p.search(s)
    if srch != None:
        return srch.group(1)
    else:
        return None
def getdefaultassessment():
    p = re.compile('/((a|q|p|t)[0-9]+[-0-9a-z]*)')
    s = os.getcwd()
    srch = p.search(s)
    t = None
    if srch != None:
        return srch.group(1)
    else:
        for root, dirs, files in os.walk('.'):
            for dir_ in dirs:
                path = os.path.abspath(dir_)
                srch = p.search(path)
                if srch != None:
                    return srch.group(1)
            break
        return None
    

s = readfile()

course = getdefaultcourse()
assessment = getdefaultassessment()

p = 'COURSE\{[^}]*\}'
news = 'COURSE{%s}' % course
s = re.sub(p, news, s)

p = 'ASSESSMENT\{[^}]*\}'
news = r'ASSESSMENT{%s}' % assessment
s = re.sub(p, news, s)

writefile('thispreamble.tex', s)




s = readfile(filename='main.txt')
p = 'subject line "[^"]*"'
news = 'subject line "%s %s"' % (course, assessment)
s = re.sub(p, news, s)
writefile('main.txt', s)
