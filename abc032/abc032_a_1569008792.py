import math
a,b,n = map(int,open(0).read().split())
print(int(a*b*(math.ceil(n/(a*b)))))