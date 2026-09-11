freq = {}
s = "this is a secret"
for c in s:
    if c not in freq:
        freq[c] = 1
    else:
        freq[c] = freq[c] + 1
    # Shortcut
    # freq[c] = freq.get(c, 0) + 1
    print(c, ":", freq[c])

print(freq)

asadsaa

x = [1,2,3]
y = ["a", 42, 4.5, True]
print(x)
print(y)

y.append(42)
print(y)
y[0] = 3 #OK

y = (1, 2, 3, "a")
print(y)
#y[0] = 42 # WRONG

y = "hello world"
print(y[1])
print(y[1:5])
print(y[1:10:2])
print(y[:])
print(y[::-1])
x = "hello"
print(x[:1])
print(x[3:])
x1 = x[:1] + "xy" + x[3:]
print(x1)


height = {'john':5.5}
height['jane'] = 5.6
height['john'] = 6.1
print(height)
print(height.keys())
for name in height.keys():
    print(name, "has height", height[name])

print('john' in height)
asdasd

def add(x, y):
    return x + y
x = input("x: ")
x = int(x)
y = input("y: ")
y = int(y)
print(add(x, y))
print(add(5, "hello"))

      
